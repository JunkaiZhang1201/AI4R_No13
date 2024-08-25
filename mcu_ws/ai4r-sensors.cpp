// This code is based on ST's VL53L5CX ULD examples
// which is under BSD 3-clause "New" or "Revised" License(shown at the last part of this file)

/***********************************/
/*   VL53L5CX ULD basic example    */
/***********************************/
/*
* This example is the most basic. It initializes the VL53L5CX ULD, and starts
* a ranging to capture 10 frames.
*
* By default, ULD is configured to have the following settings :
* - Resolution 4x4
* - Ranging period 1Hz
*
* In this example, we also suppose that the number of target per zone is
* set to 1 , and all output are enabled (see file platform.h).
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/interp.h"
#include "hardware/timer.h"
#include "hardware/watchdog.h"
#include "hardware/clocks.h"
extern "C" {
    #include "vl53l5cx_library/vl53l5cx_api.h"
}
#include "bno08x.h"
#include "utils.h"


BNO08x IMU;

// change below to your settings
#define I2C_SDA 2
#define I2C_SCL 3
i2c_inst_t vl53l5cx_i2c = {i2c1_hw, false};

int main(void) {
    // pico settings
    stdio_init_all();
    sleep_ms(3000);
    printf("start\n");
    /* Setup VL53L5CX */ 
    i2c_init(&vl53l5cx_i2c, 400 * 1000); // 400kHz
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);

	uint8_t 				status, isAlive, isReady;
	VL53L5CX_Configuration 	Dev;			/* Sensor configuration */
	VL53L5CX_ResultsData 	Results;		/* Results data from VL53L5CX */

	
	Dev.platform.address = (uint8_t)((VL53L5CX_DEFAULT_I2C_ADDRESS >> 1) & 0xFF);
    Dev.platform.i2c     = &vl53l5cx_i2c; // set i2c bus

    uint8_t one_hot_encoding[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
    //int enabled[8];
    // Try to enable a tof on each mux output, and add whether that position is enabled
    // to the enabled array can select which tof is selected by writing one byte to 
    // the mux with one hot encoding
    i2c_write_blocking(&vl53l5cx_i2c, 0x70, 0x00,1,false);

    for (int i = 0; i < 8; i++) {
        i2c_write_blocking(&vl53l5cx_i2c, 0x70, &one_hot_encoding[i],1,false);
        sleep_ms(5);
        status = vl53l5cx_is_alive(&Dev, &isAlive);
        if(!isAlive || status) {
            printf("skip %d\n",i);
            continue; //no tof found at this mux position
        }

        /* (Mandatory) Init VL53L5CX sensor */
        status = vl53l5cx_init(&Dev);
        status = vl53l5cx_set_resolution(&Dev, 16U);
        status = vl53l5cx_set_ranging_frequency_hz(&Dev, 30);
        if(status) {
            printf("vl53l5cx_set_ranging_frequency_hz failed, status %u\n", status);
            return status;
        }
        status = vl53l5cx_start_ranging(&Dev);
        printf("TOF %d Done\n",i);
    }
    
    printf("imu\n");
    /* Setup IMU (BNO08X) */
    i2c_inst_t* i2c0_imu;
    initI2C(i2c0_imu, false);
    
    while (IMU.begin(CONFIG::BNO08X_ADDR, i2c0_imu) == false) {
        printf("BNO08x not detected at default I2C address. Check wiring. Freezing\n");
        sleep_ms(1000);
    }
    IMU.enableRotationVector();
    IMU.enableAccelerometer();
    IMU.enableMagnetometer();
    IMU.tareNow();
    IMU.saveTare();

    absolute_time_t curr_time = get_absolute_time();
    absolute_time_t imu_timestamp= curr_time;
    absolute_time_t tof_timestamp[8] = {curr_time,curr_time,curr_time,curr_time,curr_time,curr_time,curr_time,curr_time};
	int i = 0;

	while(true) {   
        // 
        // IMU
        //
		curr_time = get_absolute_time();
        if (IMU.wasReset()) {
            printf("sensor was reset\n");
            IMU.enableRotationVector();
            IMU.enableAccelerometer();
            IMU.enableMagnetometer();
        }
		
        if (IMU.getSensorEvent() == true) {
    
                float yaw = IMU.getYaw();
                float pitch = IMU.getPitch();
                float roll = IMU.getRoll();
				float ax = IMU.getAccelX();
                float ay = IMU.getAccelY();
                float az = IMU.getAccelZ();
				float mx = IMU.getMagX();
                float my = IMU.getMagY();
                float mz = IMU.getMagZ();
                uint8_t m_accur = IMU.getMagAccuracy();
                printf("IMU %lld ",absolute_time_diff_us(imu_timestamp,curr_time));
                imu_timestamp = curr_time;
				curr_time = get_absolute_time();
				printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %d\n", yaw, pitch, roll, ax, ay, az, mx, my, mz, m_accur); 
		}


		// Poll TOF's
		i = (i >= 7) ? 0 : i+1;
		i2c_write_blocking(&vl53l5cx_i2c, 0x70, &one_hot_encoding[i],1,false);
		vl53l5cx_is_alive(&Dev, &isAlive);
		status = vl53l5cx_check_data_ready(&Dev, &isReady);
		if(isReady) {
			vl53l5cx_get_ranging_data(&Dev, &Results);
			printf("TOF %d %lld ",i, absolute_time_diff_us(tof_timestamp[i],curr_time));
			tof_timestamp[i] = curr_time;
			curr_time = get_absolute_time();
			for(int j = 0; j < 16; j++) {
				printf(" %d",
					Results.distance_mm[VL53L5CX_NB_TARGET_PER_ZONE*j]);
			}
			printf("\n");
        }
	}

	return status;
}

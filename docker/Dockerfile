# Use ROS 2 Humble Hawksbill on Ubuntu Jammy as the base image
FROM ros:humble-ros-base-jammy

# Install libraries
RUN apt-get update && apt-get install -y --no-install-recommends \
    mosh \
    i2c-tools \
    libi2c-dev \
    gpiod \
    libgpiod-dev \
    libgpiod-doc \
    git \
    ros-humble-perception=0.10.0-1* \
    v4l-utils \
    libv4l-dev \
    qv4l2 \
    uvcdynctrl \
    python3-pip \
    ros-humble-rosbridge-server \
    apache2 \
    php \
    ffmpeg \
    motion \
    && rm -rf /var/lib/apt/lists/* \
    # Upgrade pip and install python packages including OpenCV contrib modules
    && pip3 install --upgrade pip setuptools wheel numpy opencv-contrib-python

# Copy the web interface script and testing script
COPY setup_web_interface.sh docker_tests.sh /
# Give executable permission to scripts
RUN chmod +x /setup_web_interface.sh /docker_tests.sh
# Run the script to set up the web interface
RUN chmod +x /setup_web_interface.sh && /setup_web_interface.sh

# Run Apache2 server in foreground and Expose port 80
CMD ["apachectl", "-D", "FOREGROUND"]
# Expose port 80 for the webserver and port 9090 for the rosbridge server
EXPOSE 80
EXPOSE 9090
# AI4R-System Docker Container

## ai4r:1.0.0 [latest]

| Issue | Notes | Commit |
| ----- | ----- | ------ |
| Dockerfile Cleanup | Removed comments, stack installs | #724625d6 |
| Automation | Added docker-compose file, launch container on boot | #6da40cf6 |
| Volume | Added volume to store data | #6da40cf6 |
| Update docs | Updated changelog.md README.md | #3f74dda1 |

## ai4r:0.2.2 [04-04-2024]

### Recently Resolved Issues:

| Issue | Solution | Notes |
| ----- | -------- | ----- |
| Git Pull: Permission Denied | Add `sudo chown -R www-data:www-data /home/asc-share/asclinic-system` to `setup_web_interface.sh` | Gives the apache user ownership permissions to the git repository |
| Websocket not connecting | Add to `docker run` : `-p 9090:9090` | Forward port 9090 (default port for ROS websocket) from docker container to host |
| Issues accessing the I2C Device | Change I2C Address in `asclinic-system:ai4rweb_sudo` branch | Commit [#2a3c128f](https://gitlab.unimelb.edu.au/ai4r/ai4r-system/-/commit/2a3c128f628245e623dec924474e6a68a44913a6)|
| Unreliable launch: Policy Node | Add `../updatewebinterface.sh` to `setup_web_interface.sh` | Resets/updates the web interface, name space variables, resolving the issue |
| Issues running the bash scripts from the web interface |1. Add `echo "www-data ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers` to `setup_web_interface.sh` | Enables sudo permissions for the `www-data` user by modifying the sudoers file |
| |2. Manually add `sudo` permissions to all the bashscripts and create a new branch `asclinic-system:ai4rweb_sudo` | Commit: [#4f8469ef](https://gitlab.unimelb.edu.au/ai4r/ai4r-system/-/commit/4f8469efb2cf3b7aa8849150d9bc04e0fb4c1dbd)  |


## Todo: 

- [x] Cleanup dockerfile (Remove comments, Stack Installs)
- [ ] Update the docker tests file for checking other functionality such as - 
    - Git access
    - www-data user access
    - Check apache2 server status
    - Device Access: 
        - I2C Accesss
        - Camera Access
    - Network Access: 
        - Open ports
        - Forwarded ports
- [x] Use a Docker Compose file to spinup containers quickly
- [x] Automatically run and spinup containers with the launch of the Pi
- [ ] Add an option to do the colcoln build from within the docker container setup
- [x] Add volume to store data
- [ ] Resolve `ai4r-pkg` warning during installation
- [x] Update README.md

## Docs

- Build docker image: (while in the root directory)

    `docker build -t ai4r:latest .`

- Docker Compose for running container: 
    
    `docker-compose up -d`

-  Run a docker container manually:
    - in detached mode with interactive terminal available for 
    debugging purposes
    - Devices: I2C Bus: `/dev/i2c-1`, Camera: `/dev/video0`
    - Forward internal port `80` to external port `8080` for web interface
    - Forward port `9090` for ROS WebSocket.
    - Container name: `web_server`
    - Source docker image: `ai4r:latest`


    **Command:**

    ```bash
    docker run -dit \
        --device=/dev/i2c-1:/dev/i2c-1 \
        --device=/dev/video0:/dev/video0 \
        -p 8080:80 -p 9090:9090 \
        --name web_server ai4r:latest
    ```

    - Privileged mode for all device access: `--privileged` (not recommended)

- Accessing Interactive Terminal within a running container for debugging purposes: 

    `docker exec -it web_server /bin/bash`

- List existing docker images: `docker images`

- Remove docker images: `docker rmi <image_name>`

- Stopping docker containers: `docker stop <container_name>`
 
- List all running docker containers: `docker ps -a`

- Prune all stopped containers: `docker container prune -f`

- Prune everything to free up drive: `docker system prune -a`

## Unresolved Issues

- Workaround for RPLidar Symlink - Not included
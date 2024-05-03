# Docker Image for AI4R Web Interface

This repository contains the Dockerfile for the AI4R Web Interface. The Dockerfile is used to build a Docker image that can be used to run the AI4R in a container.

## Docker Installation

### Install docker using convenience script

```bash
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh ./get-docker.sh --dry-run
```

### Install docker-compose

```bash
sudo apt install docker-compose
```

---

> For the next steps (build image/run container for the first time) you need to clone this repository and navigate to the root directory of the repository.

## Build Docker Image

```bash
docker build -t ai4r:latest .
```

## Run Docker Container

The details of the Docker container are found in the `docker-compose.yml` file. To run the Docker container, use the following command:

```bash
docker-compose up -d
```

Once you have the container up and running, you will be able to access the web interface as soon as your device boots up. You only need to run the docker build and compose commands once.

## Accessing the Web Interface

The web interface should be accessible at `http://localhost:8080` if you are running the Docker container on your local machine. If you are running the Docker container on a remote machine, replace `localhost` with the IP address of the remote machine. Make sure to plug-in the camera and the I2C device before running the Docker container.
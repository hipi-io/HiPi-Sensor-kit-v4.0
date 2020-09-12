#!/bin/sh

sudo apt-get update;
#sudo apt-get install RPi.GPIO

# Installing Python tools
sudo apt-get install -y python3-pip;
pip3 install --upgrade setuptools;

# Installing GPIO library for Raspberry Pi
pip3 install RPI.GPIO;


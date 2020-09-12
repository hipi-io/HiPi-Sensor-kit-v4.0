#!/bin/sh

########################################
# File part of the HiPi Project kit    #
# 2020-09-02 Martin-HIPI               #
########################################
# 
# Update package list
sudo apt-get update


# Remove installed package
sudo apt-get purge wiringpi
hash -r

# Install the updated package
cd /tmp
wget https://project-downloads.drogon.net/wiringpi-latest.deb
sudo dpkg -i wiringpi-latest.deb

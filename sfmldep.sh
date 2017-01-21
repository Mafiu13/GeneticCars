#!/bin/sh

# sfml-window
apt-get install libx11-dev -y
apt-get install libxcb1-dev -y
apt-get install libx11-xcb-dev -y
apt-get install libxcb-randr0-dev -y
apt-get install libxcb-image0-dev -y
apt-get install libgl1-mesa-dev -y
wget http://mirrors.kernel.org/ubuntu/pool/main/u/udev/libudev0_175-0ubuntu9_amd64.deb
gdebi libudev0_175-0ubuntu9_amd64.deb
rm libudev0_175-0ubuntu9_amd64.deb
apt-get install libudev-dev -y

# sfml-graphics
apt-get install libfreetype6-dev -y
apt-get install libjpeg-dev -y

# sfml-audio
apt-get install libopenal-dev -y
apt-get install libflac-dev -y
apt-get install libvorbis-dev -y

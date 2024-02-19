#!/bin/bash

eFLL_ROOTDIR=/mnt/e/GitHub
eFLL_DIR="$eFLL_ROOTDIR/eFLL"

# google test
echo -e "\nInstalling google test\n"
sudo apt install -y libgtest-dev cmake
cd /usr/src/googletest/googletest
sudo mkdir build
cd build
sudo cmake ..
cd ..
sudo make
sudo cp /usr/lib/libgtest* /usr/local/lib/

# eFLL
echo -e "\nInstalling eFLL\n"
cd $eFLL_ROOTDIR
git clone https://github.com/alvesoaj/eFLL.git
cd $eFLL_DIR
make

# eFLL examples
cd $eFLL_DIR/examples
echo -e "\ngeneral_simple_sample"
general_simple_sample/general_simple_sample.bin
echo -e "\ngeneral_advanced_sample"
general_advanced_sample/general_advanced_sample.bin

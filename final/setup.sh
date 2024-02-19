#!/bin/bash

# google test
sudo apt install -y libgtest-dev cmake
cd /usr/src/googletest/googletest
sudo mkdir build
cd build
sudo cmake ..
cd ..
sudo make
sudo cp /usr/lib/libgtest* /usr/local/lib/

# eFLL
cd /mnt/e/GitHub/
git clone https://github.com/alvesoaj/eFLL.git
cd eFLL
make

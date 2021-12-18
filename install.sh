#!/bin/sh

# Check whether cmake is installed
if ! command -v cmake &> /dev/null
then
    echo -e "[Error] CMake is not installed.\nAborting installation.\n"
    exit
fi

# Compile and install
cmake -S. -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Check whether has root access
if ! [ $(id -u) = 0 ]
then
    echo -e "\nProvide root access for installation."
fi

#
sudo cmake --install build
#! /bin/bash

mkdir build
cd build
cmake ..
make -j 4
mv Exame ../
cd ..

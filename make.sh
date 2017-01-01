#!/bin/bash
mkdir -p build
cd build
cmake -D CMAKE_BUILD_TYPE=Debug -D update_gtest_switch=ON ..
# cmake -D CMAKE_BUILD_TYPE=Debug ..
# make clean;make 
make 
# echo ""
# echo ""
# echo ""
# make test
# ./test_bin/test_cmake

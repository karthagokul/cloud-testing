#!/bin/sh

rootpath=`pwd`
mkdir $rootpath/include
mkdir $rootpath/libs

mkdir -p third-party
cd third-party 

echo "Checking out Google Test"
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip

echo "Checking out Google Mock"
wget http://googlemock.googlecode.com/files/gmock-1.7.0.zip

unzip gtest-1.7.0.zip
unzip gmock-1.7.0.zip

cd gtest-1.7.0
./configure
make
cp -rvf lib/.libs/* $rootpath/libs
cp -rvf include/* $rootpath/include
cd ..

cd gmock-1.7.0
./configure
make
cp -rvf lib/.libs/* $rootpath/libs
cp -rvf include/* $rootpath/include

cd $rootpath
rm -rf third-party

#!/bin/sh
set -e


rootpath=`pwd`
mkdir $rootpath/include
mkdir $rootpath/lib

mkdir -p third-party
cd third-party 

#Lets Install Google test and Mock

echo "Checking out Google Test"
wget http://googletest.googlecode.com/files/gtest-1.7.0.zip

echo "Checking out Google Mock"
wget http://googlemock.googlecode.com/files/gmock-1.7.0.zip

unzip gtest-1.7.0.zip
unzip gmock-1.7.0.zip

cd gtest-1.7.0
./configure
make
cp -rvf lib/.libs/* $rootpath/lib
cp -rvf include/* $rootpath/include
cd ..

cd gmock-1.7.0
./configure
make
cp -rvf lib/.libs/* $rootpath/lib
cp -rvf include/* $rootpath/include

#Lets install Curl
wget http://curl.haxx.se/download/curl-7.37.0.tar.gz
tar -xvzf curl-7.37.0.tar.gz
cd curl-7.37.0
./configure --prefix=$rootpath
make
make install 

cd $rootpath

rm -rf third-party



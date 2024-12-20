@echo off

cd build

cmake.exe -S .. -B . -G "MinGW Makefiles"
mingw32-make.exe

cls

.\bin\main.exe %*
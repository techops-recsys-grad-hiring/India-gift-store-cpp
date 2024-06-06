@echo off
rmdir /s /q build
cmake -S . -B build
cmake --build build
cd build
ctest
cd ..
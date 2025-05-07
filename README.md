# Cache-Simulator
Simulates the cache of multiply different systems and records their efficiency based on a consistent instruction set

# Design environment
Platform: Ubuntu 22.04 on Windows Subsystem for Linux (WSL)
Compiler: g++ 
Build System: CMake 3.10


# How to use
- ensure cmake and g++ are installed
- add whatever trace file you want to run to the build folder with name "test.trace"
- open the build directory in terminal and execute the following commands
	- cmake ..
	- make
	- ./cachesim
- the output should be saved to a file name test.result in the build file
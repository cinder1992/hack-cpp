# Hack++
A project to port my first game, Hack+, to C++, adding features that were not previously possible in perl.

## Installation

### Requirements

* SDL2 >= 2.0.3
* cmake >= 2.8.4
**Windows ONLY**
* MinGW

## Compiling
### Linux
If your distrobution has SDL2 and SDL2-devel, Compiling Hack++ is as simple as the following:

```
cmake CMakeLists.txt
make
```
### Windows
On Windows, one extra step is required before compiling:
1. Download the SDL2 development libraries for MinGW from https://www.libsdl.org/download-2.0.php
2. Extract the file to any location
3. Copy the x86_64-w64-MinGW and i686-w64-MinGW folders to the include directory in the repository.

Afterwords, it can be compiled with the following (Assuming MinGW is in your %path%):

**Note for windows users: You may have to manually select a generator for cmake! e.g.:**
```
cmake -G "MinGW Makefiles" CMakeLists.txt
make

```
**NOTE: Visual Studio is not officially supported!**

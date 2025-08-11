# smart_ptr

## Overview
A lightweight C++ header-only library providing smart pointer implementations for safe and efficient memory management.

## Requirements
- CMake (version 3.x or higher)
- A C++ compiler that supports C++11 or higher

## Building the Library
To build the library, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/cricketjanoon/smart_ptr.git
   cd smart_ptr
   ```

2. Create a build directory:
   ```
   mkdir build
   cd build
   ```

3. Run CMake to configure the project:
   ```
   cmake ..
   ```

4. Build the library:
   ```
   cmake --build .
   ```

## Installing the Library
To install the library on your system, run:
```
sudo make install
```

This will copy the library files to the appropriate system directories.

## Usage
To use the library in your CMake project, include the following in your `CMakeLists.txt`:
```cmake
find_package( Rsmart_ptrEQUIRED)
target_link_libraries(your_target_name smart_ptr)
```

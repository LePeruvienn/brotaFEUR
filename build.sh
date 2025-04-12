#!/bin/bash

# Set build directory
BUILD_DIR="build"

# Navigate to the build directory
cd "$BUILD_DIR"

# Run CMake to generate the build files
cmake .. &&

# Compile the project
make &&

# Run main
./bin/main

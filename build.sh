#!/bin/bash

# Stop script if error
set -e 

# Set build directory
BUILD_DIR="build"

# Navigate to the build directory (create it if dont exist)
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Run CMake to generate the build files
cmake .. &&

# Compile the project
make &&

# Run main
./bin/main

# Cmake version
cmake_minimum_required(VERSION 3.7)

# Project details
project(ParticleFireSimulation)

# Build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Add subdirectories
add_subdirectory(bin)

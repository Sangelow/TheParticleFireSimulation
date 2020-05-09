# Cmake version
cmake_minimum_required(VERSION 3.7)

# Project details
project(ParticleFireSimulation)

# Set the executables directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fopenmp")
set(CMAKE_CXX_FLAGS_PROFILE "-pg -fopenmp")

# Find SDL2 package https://stackoverflow.com/questions/23850472/how-to-use-sdl2-and-sdl-image-with-cmake
find_package(SDL2 REQUIRED COMPONENTS SDL2::SDL2)

# Find OpenMP
find_package(OpenMP REQUIRED)


# Compile
add_executable(main src/main.cpp src/Screen.cpp src/Particle.cpp src/Swarm.cpp)

# Link
target_link_libraries(main SDL2::SDL2 OpenMP::OpenMP_CXX)

# Find SDL2 package https://stackoverflow.com/questions/23850472/how-to-use-sdl2-and-sdl-image-with-cmake
find_package(SDL2 REQUIRED COMPONENTS SDL2::SDL2)

# Compile
add_executable(main ../src/main.cpp)

# Link
target_link_libraries(main SDL2::SDL2)

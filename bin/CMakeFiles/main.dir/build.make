# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation

# Include any dependencies generated for this target.
include bin/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/main.dir/flags.make

bin/CMakeFiles/main.dir/__/src/main.cpp.o: bin/CMakeFiles/main.dir/flags.make
bin/CMakeFiles/main.dir/__/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/main.dir/__/src/main.cpp.o"
	cd /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main.dir/__/src/main.cpp.o -c /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/src/main.cpp

bin/CMakeFiles/main.dir/__/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/__/src/main.cpp.i"
	cd /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/src/main.cpp > CMakeFiles/main.dir/__/src/main.cpp.i

bin/CMakeFiles/main.dir/__/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/__/src/main.cpp.s"
	cd /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/src/main.cpp -o CMakeFiles/main.dir/__/src/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/__/src/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

bin/main: bin/CMakeFiles/main.dir/__/src/main.cpp.o
bin/main: bin/CMakeFiles/main.dir/build.make
bin/main: /usr/lib/libSDL2-2.0.so.0.12.0
bin/main: bin/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main"
	cd /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/main.dir/build: bin/main

.PHONY : bin/CMakeFiles/main.dir/build

bin/CMakeFiles/main.dir/clean:
	cd /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/main.dir/clean

bin/CMakeFiles/main.dir/depend:
	cd /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin /home/floiseau/Dropbox/Scripts/cpp/cpp_tutorial_for_complete_beginners/TheParticleFireSimulation/bin/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/main.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.qOuezNMjU7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.qOuezNMjU7/cmake-build-debug-remote-host-1

# Include any dependencies generated for this target.
include CMakeFiles/Task1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Task1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task1.dir/flags.make

CMakeFiles/Task1.dir/main.cpp.o: CMakeFiles/Task1.dir/flags.make
CMakeFiles/Task1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.qOuezNMjU7/cmake-build-debug-remote-host-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Task1.dir/main.cpp.o -c /tmp/tmp.qOuezNMjU7/main.cpp

CMakeFiles/Task1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.qOuezNMjU7/main.cpp > CMakeFiles/Task1.dir/main.cpp.i

CMakeFiles/Task1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.qOuezNMjU7/main.cpp -o CMakeFiles/Task1.dir/main.cpp.s

# Object files for target Task1
Task1_OBJECTS = \
"CMakeFiles/Task1.dir/main.cpp.o"

# External object files for target Task1
Task1_EXTERNAL_OBJECTS =

Task1: CMakeFiles/Task1.dir/main.cpp.o
Task1: CMakeFiles/Task1.dir/build.make
Task1: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi_cxx.so
Task1: /usr/lib/x86_64-linux-gnu/openmpi/lib/libmpi.so
Task1: CMakeFiles/Task1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.qOuezNMjU7/cmake-build-debug-remote-host-1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Task1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task1.dir/build: Task1

.PHONY : CMakeFiles/Task1.dir/build

CMakeFiles/Task1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Task1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Task1.dir/clean

CMakeFiles/Task1.dir/depend:
	cd /tmp/tmp.qOuezNMjU7/cmake-build-debug-remote-host-1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.qOuezNMjU7 /tmp/tmp.qOuezNMjU7 /tmp/tmp.qOuezNMjU7/cmake-build-debug-remote-host-1 /tmp/tmp.qOuezNMjU7/cmake-build-debug-remote-host-1 /tmp/tmp.qOuezNMjU7/cmake-build-debug-remote-host-1/CMakeFiles/Task1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task1.dir/depend

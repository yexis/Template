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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yex/CPP/Template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yex/CPP/Template/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/quick_power_matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/quick_power_matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quick_power_matrix.dir/flags.make

CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.o: CMakeFiles/quick_power_matrix.dir/flags.make
CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.o: ../quick_power/matrix/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yex/CPP/Template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.o -c /Users/yex/CPP/Template/quick_power/matrix/main.cpp

CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yex/CPP/Template/quick_power/matrix/main.cpp > CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.i

CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yex/CPP/Template/quick_power/matrix/main.cpp -o CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.s

# Object files for target quick_power_matrix
quick_power_matrix_OBJECTS = \
"CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.o"

# External object files for target quick_power_matrix
quick_power_matrix_EXTERNAL_OBJECTS =

quick_power_matrix: CMakeFiles/quick_power_matrix.dir/quick_power/matrix/main.cpp.o
quick_power_matrix: CMakeFiles/quick_power_matrix.dir/build.make
quick_power_matrix: CMakeFiles/quick_power_matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yex/CPP/Template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quick_power_matrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quick_power_matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quick_power_matrix.dir/build: quick_power_matrix

.PHONY : CMakeFiles/quick_power_matrix.dir/build

CMakeFiles/quick_power_matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quick_power_matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quick_power_matrix.dir/clean

CMakeFiles/quick_power_matrix.dir/depend:
	cd /Users/yex/CPP/Template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yex/CPP/Template /Users/yex/CPP/Template /Users/yex/CPP/Template/cmake-build-debug /Users/yex/CPP/Template/cmake-build-debug /Users/yex/CPP/Template/cmake-build-debug/CMakeFiles/quick_power_matrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quick_power_matrix.dir/depend


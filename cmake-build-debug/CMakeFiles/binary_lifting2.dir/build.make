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
include CMakeFiles/binary_lifting2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary_lifting2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary_lifting2.dir/flags.make

CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.o: CMakeFiles/binary_lifting2.dir/flags.make
CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.o: ../binary_lifting/tree/main2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yex/CPP/Template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.o -c /Users/yex/CPP/Template/binary_lifting/tree/main2.cpp

CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yex/CPP/Template/binary_lifting/tree/main2.cpp > CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.i

CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yex/CPP/Template/binary_lifting/tree/main2.cpp -o CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.s

# Object files for target binary_lifting2
binary_lifting2_OBJECTS = \
"CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.o"

# External object files for target binary_lifting2
binary_lifting2_EXTERNAL_OBJECTS =

binary_lifting2: CMakeFiles/binary_lifting2.dir/binary_lifting/tree/main2.cpp.o
binary_lifting2: CMakeFiles/binary_lifting2.dir/build.make
binary_lifting2: CMakeFiles/binary_lifting2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yex/CPP/Template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binary_lifting2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary_lifting2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary_lifting2.dir/build: binary_lifting2

.PHONY : CMakeFiles/binary_lifting2.dir/build

CMakeFiles/binary_lifting2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary_lifting2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary_lifting2.dir/clean

CMakeFiles/binary_lifting2.dir/depend:
	cd /Users/yex/CPP/Template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yex/CPP/Template /Users/yex/CPP/Template /Users/yex/CPP/Template/cmake-build-debug /Users/yex/CPP/Template/cmake-build-debug /Users/yex/CPP/Template/cmake-build-debug/CMakeFiles/binary_lifting2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary_lifting2.dir/depend


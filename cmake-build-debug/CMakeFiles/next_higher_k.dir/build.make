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
include CMakeFiles/next_higher_k.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/next_higher_k.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/next_higher_k.dir/flags.make

CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.o: CMakeFiles/next_higher_k.dir/flags.make
CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.o: ../next_higher_k/base/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yex/CPP/Template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.o -c /Users/yex/CPP/Template/next_higher_k/base/main.cpp

CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yex/CPP/Template/next_higher_k/base/main.cpp > CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.i

CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yex/CPP/Template/next_higher_k/base/main.cpp -o CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.s

# Object files for target next_higher_k
next_higher_k_OBJECTS = \
"CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.o"

# External object files for target next_higher_k
next_higher_k_EXTERNAL_OBJECTS =

next_higher_k: CMakeFiles/next_higher_k.dir/next_higher_k/base/main.cpp.o
next_higher_k: CMakeFiles/next_higher_k.dir/build.make
next_higher_k: CMakeFiles/next_higher_k.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yex/CPP/Template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable next_higher_k"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/next_higher_k.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/next_higher_k.dir/build: next_higher_k

.PHONY : CMakeFiles/next_higher_k.dir/build

CMakeFiles/next_higher_k.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/next_higher_k.dir/cmake_clean.cmake
.PHONY : CMakeFiles/next_higher_k.dir/clean

CMakeFiles/next_higher_k.dir/depend:
	cd /Users/yex/CPP/Template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yex/CPP/Template /Users/yex/CPP/Template /Users/yex/CPP/Template/cmake-build-debug /Users/yex/CPP/Template/cmake-build-debug /Users/yex/CPP/Template/cmake-build-debug/CMakeFiles/next_higher_k.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/next_higher_k.dir/depend


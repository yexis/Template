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
CMAKE_SOURCE_DIR = /Users/yex/CPP/template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yex/CPP/template/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/comb_base.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/comb_base.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/comb_base.dir/flags.make

CMakeFiles/comb_base.dir/comb/base/main.cpp.o: CMakeFiles/comb_base.dir/flags.make
CMakeFiles/comb_base.dir/comb/base/main.cpp.o: ../comb/base/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yex/CPP/template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/comb_base.dir/comb/base/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/comb_base.dir/comb/base/main.cpp.o -c /Users/yex/CPP/template/comb/base/main.cpp

CMakeFiles/comb_base.dir/comb/base/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/comb_base.dir/comb/base/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yex/CPP/template/comb/base/main.cpp > CMakeFiles/comb_base.dir/comb/base/main.cpp.i

CMakeFiles/comb_base.dir/comb/base/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/comb_base.dir/comb/base/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yex/CPP/template/comb/base/main.cpp -o CMakeFiles/comb_base.dir/comb/base/main.cpp.s

# Object files for target comb_base
comb_base_OBJECTS = \
"CMakeFiles/comb_base.dir/comb/base/main.cpp.o"

# External object files for target comb_base
comb_base_EXTERNAL_OBJECTS =

comb_base: CMakeFiles/comb_base.dir/comb/base/main.cpp.o
comb_base: CMakeFiles/comb_base.dir/build.make
comb_base: CMakeFiles/comb_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yex/CPP/template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable comb_base"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/comb_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/comb_base.dir/build: comb_base

.PHONY : CMakeFiles/comb_base.dir/build

CMakeFiles/comb_base.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/comb_base.dir/cmake_clean.cmake
.PHONY : CMakeFiles/comb_base.dir/clean

CMakeFiles/comb_base.dir/depend:
	cd /Users/yex/CPP/template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yex/CPP/template /Users/yex/CPP/template /Users/yex/CPP/template/cmake-build-debug /Users/yex/CPP/template/cmake-build-debug /Users/yex/CPP/template/cmake-build-debug/CMakeFiles/comb_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/comb_base.dir/depend


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
include CMakeFiles/djset_rank.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/djset_rank.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/djset_rank.dir/flags.make

CMakeFiles/djset_rank.dir/djset/rank/main.cpp.o: CMakeFiles/djset_rank.dir/flags.make
CMakeFiles/djset_rank.dir/djset/rank/main.cpp.o: ../djset/rank/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yex/CPP/template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/djset_rank.dir/djset/rank/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/djset_rank.dir/djset/rank/main.cpp.o -c /Users/yex/CPP/template/djset/rank/main.cpp

CMakeFiles/djset_rank.dir/djset/rank/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/djset_rank.dir/djset/rank/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yex/CPP/template/djset/rank/main.cpp > CMakeFiles/djset_rank.dir/djset/rank/main.cpp.i

CMakeFiles/djset_rank.dir/djset/rank/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/djset_rank.dir/djset/rank/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yex/CPP/template/djset/rank/main.cpp -o CMakeFiles/djset_rank.dir/djset/rank/main.cpp.s

# Object files for target djset_rank
djset_rank_OBJECTS = \
"CMakeFiles/djset_rank.dir/djset/rank/main.cpp.o"

# External object files for target djset_rank
djset_rank_EXTERNAL_OBJECTS =

djset_rank: CMakeFiles/djset_rank.dir/djset/rank/main.cpp.o
djset_rank: CMakeFiles/djset_rank.dir/build.make
djset_rank: CMakeFiles/djset_rank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yex/CPP/template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable djset_rank"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/djset_rank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/djset_rank.dir/build: djset_rank

.PHONY : CMakeFiles/djset_rank.dir/build

CMakeFiles/djset_rank.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/djset_rank.dir/cmake_clean.cmake
.PHONY : CMakeFiles/djset_rank.dir/clean

CMakeFiles/djset_rank.dir/depend:
	cd /Users/yex/CPP/template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yex/CPP/template /Users/yex/CPP/template /Users/yex/CPP/template/cmake-build-debug /Users/yex/CPP/template/cmake-build-debug /Users/yex/CPP/template/cmake-build-debug/CMakeFiles/djset_rank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/djset_rank.dir/depend

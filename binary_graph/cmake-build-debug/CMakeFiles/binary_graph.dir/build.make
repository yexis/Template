# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /Users/liguoyang/CPP/LC/binary_graph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liguoyang/CPP/LC/binary_graph/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/binary_graph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary_graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary_graph.dir/flags.make

CMakeFiles/binary_graph.dir/main.cpp.o: CMakeFiles/binary_graph.dir/flags.make
CMakeFiles/binary_graph.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liguoyang/CPP/LC/binary_graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary_graph.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary_graph.dir/main.cpp.o -c /Users/liguoyang/CPP/LC/binary_graph/main.cpp

CMakeFiles/binary_graph.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_graph.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liguoyang/CPP/LC/binary_graph/main.cpp > CMakeFiles/binary_graph.dir/main.cpp.i

CMakeFiles/binary_graph.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_graph.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liguoyang/CPP/LC/binary_graph/main.cpp -o CMakeFiles/binary_graph.dir/main.cpp.s

# Object files for target binary_graph
binary_graph_OBJECTS = \
"CMakeFiles/binary_graph.dir/main.cpp.o"

# External object files for target binary_graph
binary_graph_EXTERNAL_OBJECTS =

binary_graph: CMakeFiles/binary_graph.dir/main.cpp.o
binary_graph: CMakeFiles/binary_graph.dir/build.make
binary_graph: CMakeFiles/binary_graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liguoyang/CPP/LC/binary_graph/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binary_graph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary_graph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary_graph.dir/build: binary_graph

.PHONY : CMakeFiles/binary_graph.dir/build

CMakeFiles/binary_graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary_graph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary_graph.dir/clean

CMakeFiles/binary_graph.dir/depend:
	cd /Users/liguoyang/CPP/LC/binary_graph/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liguoyang/CPP/LC/binary_graph /Users/liguoyang/CPP/LC/binary_graph /Users/liguoyang/CPP/LC/binary_graph/cmake-build-debug /Users/liguoyang/CPP/LC/binary_graph/cmake-build-debug /Users/liguoyang/CPP/LC/binary_graph/cmake-build-debug/CMakeFiles/binary_graph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary_graph.dir/depend

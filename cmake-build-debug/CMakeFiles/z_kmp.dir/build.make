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
include CMakeFiles/z_kmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/z_kmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/z_kmp.dir/flags.make

CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.o: CMakeFiles/z_kmp.dir/flags.make
CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.o: ../kmp/z-kmp/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yex/CPP/template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.o -c /Users/yex/CPP/template/kmp/z-kmp/main.cpp

CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yex/CPP/template/kmp/z-kmp/main.cpp > CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.i

CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yex/CPP/template/kmp/z-kmp/main.cpp -o CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.s

# Object files for target z_kmp
z_kmp_OBJECTS = \
"CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.o"

# External object files for target z_kmp
z_kmp_EXTERNAL_OBJECTS =

z_kmp: CMakeFiles/z_kmp.dir/kmp/z-kmp/main.cpp.o
z_kmp: CMakeFiles/z_kmp.dir/build.make
z_kmp: CMakeFiles/z_kmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yex/CPP/template/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable z_kmp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/z_kmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/z_kmp.dir/build: z_kmp

.PHONY : CMakeFiles/z_kmp.dir/build

CMakeFiles/z_kmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/z_kmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/z_kmp.dir/clean

CMakeFiles/z_kmp.dir/depend:
	cd /Users/yex/CPP/template/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yex/CPP/template /Users/yex/CPP/template /Users/yex/CPP/template/cmake-build-debug /Users/yex/CPP/template/cmake-build-debug /Users/yex/CPP/template/cmake-build-debug/CMakeFiles/z_kmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/z_kmp.dir/depend


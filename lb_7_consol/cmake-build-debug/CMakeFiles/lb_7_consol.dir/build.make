# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lb_7_consol.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lb_7_consol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lb_7_consol.dir/flags.make

CMakeFiles/lb_7_consol.dir/main.cpp.o: CMakeFiles/lb_7_consol.dir/flags.make
CMakeFiles/lb_7_consol.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lb_7_consol.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lb_7_consol.dir/main.cpp.o -c /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/main.cpp

CMakeFiles/lb_7_consol.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lb_7_consol.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/main.cpp > CMakeFiles/lb_7_consol.dir/main.cpp.i

CMakeFiles/lb_7_consol.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lb_7_consol.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/main.cpp -o CMakeFiles/lb_7_consol.dir/main.cpp.s

# Object files for target lb_7_consol
lb_7_consol_OBJECTS = \
"CMakeFiles/lb_7_consol.dir/main.cpp.o"

# External object files for target lb_7_consol
lb_7_consol_EXTERNAL_OBJECTS =

lb_7_consol: CMakeFiles/lb_7_consol.dir/main.cpp.o
lb_7_consol: CMakeFiles/lb_7_consol.dir/build.make
lb_7_consol: CMakeFiles/lb_7_consol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lb_7_consol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lb_7_consol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lb_7_consol.dir/build: lb_7_consol
.PHONY : CMakeFiles/lb_7_consol.dir/build

CMakeFiles/lb_7_consol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lb_7_consol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lb_7_consol.dir/clean

CMakeFiles/lb_7_consol.dir/depend:
	cd /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/cmake-build-debug /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/cmake-build-debug /Users/glebchanskiy/Desktop/subjects/AOiP/lb_7_consol/cmake-build-debug/CMakeFiles/lb_7_consol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lb_7_consol.dir/depend


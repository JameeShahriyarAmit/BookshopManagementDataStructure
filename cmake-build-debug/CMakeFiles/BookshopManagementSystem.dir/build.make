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
CMAKE_COMMAND = /snap/clion/162/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/162/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BookshopManagementSystem.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/BookshopManagementSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BookshopManagementSystem.dir/flags.make

CMakeFiles/BookshopManagementSystem.dir/main.cpp.o: CMakeFiles/BookshopManagementSystem.dir/flags.make
CMakeFiles/BookshopManagementSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BookshopManagementSystem.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BookshopManagementSystem.dir/main.cpp.o -c /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/main.cpp

CMakeFiles/BookshopManagementSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BookshopManagementSystem.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/main.cpp > CMakeFiles/BookshopManagementSystem.dir/main.cpp.i

CMakeFiles/BookshopManagementSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BookshopManagementSystem.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/main.cpp -o CMakeFiles/BookshopManagementSystem.dir/main.cpp.s

# Object files for target BookshopManagementSystem
BookshopManagementSystem_OBJECTS = \
"CMakeFiles/BookshopManagementSystem.dir/main.cpp.o"

# External object files for target BookshopManagementSystem
BookshopManagementSystem_EXTERNAL_OBJECTS =

BookshopManagementSystem: CMakeFiles/BookshopManagementSystem.dir/main.cpp.o
BookshopManagementSystem: CMakeFiles/BookshopManagementSystem.dir/build.make
BookshopManagementSystem: CMakeFiles/BookshopManagementSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BookshopManagementSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BookshopManagementSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BookshopManagementSystem.dir/build: BookshopManagementSystem
.PHONY : CMakeFiles/BookshopManagementSystem.dir/build

CMakeFiles/BookshopManagementSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BookshopManagementSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BookshopManagementSystem.dir/clean

CMakeFiles/BookshopManagementSystem.dir/depend:
	cd /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/cmake-build-debug /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/cmake-build-debug /home/jameeshahriyar/Projects/New_Projects/cpp/BookshopManagementSystem/cmake-build-debug/CMakeFiles/BookshopManagementSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BookshopManagementSystem.dir/depend


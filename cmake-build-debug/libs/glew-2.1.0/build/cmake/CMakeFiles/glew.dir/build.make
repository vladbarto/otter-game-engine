# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug

# Include any dependencies generated for this target.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/progress.make

# Include the compile flags for this target's objects.
include libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/flags.make

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/flags.make
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o: /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/libs/glew-2.1.0/src/glew.c
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o"
	cd /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o -MF CMakeFiles/glew.dir/__/__/src/glew.c.o.d -o CMakeFiles/glew.dir/__/__/src/glew.c.o -c /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/libs/glew-2.1.0/src/glew.c

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glew.dir/__/__/src/glew.c.i"
	cd /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/libs/glew-2.1.0/src/glew.c > CMakeFiles/glew.dir/__/__/src/glew.c.i

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glew.dir/__/__/src/glew.c.s"
	cd /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/libs/glew-2.1.0/src/glew.c -o CMakeFiles/glew.dir/__/__/src/glew.c.s

# Object files for target glew
glew_OBJECTS = \
"CMakeFiles/glew.dir/__/__/src/glew.c.o"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

lib/libGLEWd.2.1.0.dylib: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.o
lib/libGLEWd.2.1.0.dylib: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/build.make
lib/libGLEWd.2.1.0.dylib: libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library ../../../../lib/libGLEWd.dylib"
	cd /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glew.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../lib/libGLEWd.2.1.0.dylib ../../../../lib/libGLEWd.2.1.dylib ../../../../lib/libGLEWd.dylib

lib/libGLEWd.2.1.dylib: lib/libGLEWd.2.1.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libGLEWd.2.1.dylib

lib/libGLEWd.dylib: lib/libGLEWd.2.1.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libGLEWd.dylib

# Rule to build all files generated by this target.
libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/build: lib/libGLEWd.dylib
.PHONY : libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/build

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/clean:
	cd /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake && $(CMAKE_COMMAND) -P CMakeFiles/glew.dir/cmake_clean.cmake
.PHONY : libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/clean

libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/depend:
	cd /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/libs/glew-2.1.0/build/cmake /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake /Users/vladbarto/Documents/PERSONAL_PROJECTS/F1_OpenGL/cmake-build-debug/libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libs/glew-2.1.0/build/cmake/CMakeFiles/glew.dir/depend


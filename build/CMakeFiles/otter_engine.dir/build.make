# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build

# Include any dependencies generated for this target.
include CMakeFiles/otter_engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/otter_engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/otter_engine.dir/flags.make

CMakeFiles/otter_engine.dir/app/main.cpp.o: CMakeFiles/otter_engine.dir/flags.make
CMakeFiles/otter_engine.dir/app/main.cpp.o: ../app/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/otter_engine.dir/app/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/otter_engine.dir/app/main.cpp.o -c /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/app/main.cpp

CMakeFiles/otter_engine.dir/app/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otter_engine.dir/app/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/app/main.cpp > CMakeFiles/otter_engine.dir/app/main.cpp.i

CMakeFiles/otter_engine.dir/app/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otter_engine.dir/app/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/app/main.cpp -o CMakeFiles/otter_engine.dir/app/main.cpp.s

CMakeFiles/otter_engine.dir/app/glad.c.o: CMakeFiles/otter_engine.dir/flags.make
CMakeFiles/otter_engine.dir/app/glad.c.o: ../app/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/otter_engine.dir/app/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/otter_engine.dir/app/glad.c.o   -c /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/app/glad.c

CMakeFiles/otter_engine.dir/app/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/otter_engine.dir/app/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/app/glad.c > CMakeFiles/otter_engine.dir/app/glad.c.i

CMakeFiles/otter_engine.dir/app/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/otter_engine.dir/app/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/app/glad.c -o CMakeFiles/otter_engine.dir/app/glad.c.s

CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.o: CMakeFiles/otter_engine.dir/flags.make
CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.o: ../src/view/utils/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.o -c /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/src/view/utils/Window.cpp

CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/src/view/utils/Window.cpp > CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.i

CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/src/view/utils/Window.cpp -o CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.s

# Object files for target otter_engine
otter_engine_OBJECTS = \
"CMakeFiles/otter_engine.dir/app/main.cpp.o" \
"CMakeFiles/otter_engine.dir/app/glad.c.o" \
"CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.o"

# External object files for target otter_engine
otter_engine_EXTERNAL_OBJECTS =

otter_engine: CMakeFiles/otter_engine.dir/app/main.cpp.o
otter_engine: CMakeFiles/otter_engine.dir/app/glad.c.o
otter_engine: CMakeFiles/otter_engine.dir/src/view/utils/Window.cpp.o
otter_engine: CMakeFiles/otter_engine.dir/build.make
otter_engine: /usr/lib/x86_64-linux-gnu/libGLX.so
otter_engine: /usr/lib/x86_64-linux-gnu/libOpenGL.so
otter_engine: CMakeFiles/otter_engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable otter_engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/otter_engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/otter_engine.dir/build: otter_engine

.PHONY : CMakeFiles/otter_engine.dir/build

CMakeFiles/otter_engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/otter_engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/otter_engine.dir/clean

CMakeFiles/otter_engine.dir/depend:
	cd /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build /home/vlad/Documents/FACULTA/PERSONAL_PROJ/otter-game-engine/build/CMakeFiles/otter_engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/otter_engine.dir/depend

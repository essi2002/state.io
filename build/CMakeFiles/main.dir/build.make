# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ehsan/Desktop/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ehsan/Desktop/test/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/test.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/test.c.o: ../test.c
CMakeFiles/main.dir/test.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main.dir/test.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/test.c.o -MF CMakeFiles/main.dir/test.c.o.d -o CMakeFiles/main.dir/test.c.o -c /Users/ehsan/Desktop/test/test.c

CMakeFiles/main.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/test.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/test.c > CMakeFiles/main.dir/test.c.i

CMakeFiles/main.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/test.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/test.c -o CMakeFiles/main.dir/test.c.s

CMakeFiles/main.dir/graphics.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/graphics.c.o: ../graphics.c
CMakeFiles/main.dir/graphics.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/graphics.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/graphics.c.o -MF CMakeFiles/main.dir/graphics.c.o.d -o CMakeFiles/main.dir/graphics.c.o -c /Users/ehsan/Desktop/test/graphics.c

CMakeFiles/main.dir/graphics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/graphics.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/graphics.c > CMakeFiles/main.dir/graphics.c.i

CMakeFiles/main.dir/graphics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/graphics.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/graphics.c -o CMakeFiles/main.dir/graphics.c.s

CMakeFiles/main.dir/color.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/color.c.o: ../color.c
CMakeFiles/main.dir/color.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main.dir/color.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/color.c.o -MF CMakeFiles/main.dir/color.c.o.d -o CMakeFiles/main.dir/color.c.o -c /Users/ehsan/Desktop/test/color.c

CMakeFiles/main.dir/color.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/color.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/color.c > CMakeFiles/main.dir/color.c.i

CMakeFiles/main.dir/color.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/color.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/color.c -o CMakeFiles/main.dir/color.c.s

CMakeFiles/main.dir/movement.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/movement.c.o: ../movement.c
CMakeFiles/main.dir/movement.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main.dir/movement.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/movement.c.o -MF CMakeFiles/main.dir/movement.c.o.d -o CMakeFiles/main.dir/movement.c.o -c /Users/ehsan/Desktop/test/movement.c

CMakeFiles/main.dir/movement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/movement.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/movement.c > CMakeFiles/main.dir/movement.c.i

CMakeFiles/main.dir/movement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/movement.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/movement.c -o CMakeFiles/main.dir/movement.c.s

CMakeFiles/main.dir/potion.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/potion.c.o: ../potion.c
CMakeFiles/main.dir/potion.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/main.dir/potion.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/potion.c.o -MF CMakeFiles/main.dir/potion.c.o.d -o CMakeFiles/main.dir/potion.c.o -c /Users/ehsan/Desktop/test/potion.c

CMakeFiles/main.dir/potion.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/potion.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/potion.c > CMakeFiles/main.dir/potion.c.i

CMakeFiles/main.dir/potion.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/potion.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/potion.c -o CMakeFiles/main.dir/potion.c.s

CMakeFiles/main.dir/menu.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/menu.c.o: ../menu.c
CMakeFiles/main.dir/menu.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/main.dir/menu.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/menu.c.o -MF CMakeFiles/main.dir/menu.c.o.d -o CMakeFiles/main.dir/menu.c.o -c /Users/ehsan/Desktop/test/menu.c

CMakeFiles/main.dir/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/menu.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/menu.c > CMakeFiles/main.dir/menu.c.i

CMakeFiles/main.dir/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/menu.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/menu.c -o CMakeFiles/main.dir/menu.c.s

CMakeFiles/main.dir/ai.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/ai.c.o: ../ai.c
CMakeFiles/main.dir/ai.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/main.dir/ai.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/ai.c.o -MF CMakeFiles/main.dir/ai.c.o.d -o CMakeFiles/main.dir/ai.c.o -c /Users/ehsan/Desktop/test/ai.c

CMakeFiles/main.dir/ai.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/ai.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/ai.c > CMakeFiles/main.dir/ai.c.i

CMakeFiles/main.dir/ai.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/ai.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/ai.c -o CMakeFiles/main.dir/ai.c.s

CMakeFiles/main.dir/alghoritm.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/alghoritm.c.o: ../alghoritm.c
CMakeFiles/main.dir/alghoritm.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/main.dir/alghoritm.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/alghoritm.c.o -MF CMakeFiles/main.dir/alghoritm.c.o.d -o CMakeFiles/main.dir/alghoritm.c.o -c /Users/ehsan/Desktop/test/alghoritm.c

CMakeFiles/main.dir/alghoritm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/alghoritm.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ehsan/Desktop/test/alghoritm.c > CMakeFiles/main.dir/alghoritm.c.i

CMakeFiles/main.dir/alghoritm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/alghoritm.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ehsan/Desktop/test/alghoritm.c -o CMakeFiles/main.dir/alghoritm.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/test.c.o" \
"CMakeFiles/main.dir/graphics.c.o" \
"CMakeFiles/main.dir/color.c.o" \
"CMakeFiles/main.dir/movement.c.o" \
"CMakeFiles/main.dir/potion.c.o" \
"CMakeFiles/main.dir/menu.c.o" \
"CMakeFiles/main.dir/ai.c.o" \
"CMakeFiles/main.dir/alghoritm.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/test.c.o
main: CMakeFiles/main.dir/graphics.c.o
main: CMakeFiles/main.dir/color.c.o
main: CMakeFiles/main.dir/movement.c.o
main: CMakeFiles/main.dir/potion.c.o
main: CMakeFiles/main.dir/menu.c.o
main: CMakeFiles/main.dir/ai.c.o
main: CMakeFiles/main.dir/alghoritm.c.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ehsan/Desktop/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/ehsan/Desktop/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ehsan/Desktop/test /Users/ehsan/Desktop/test /Users/ehsan/Desktop/test/build /Users/ehsan/Desktop/test/build /Users/ehsan/Desktop/test/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /home/ange/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/ange/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ange/Documents/Programmation_C/Partie_2/TP/TP8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main-Huffman.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main-Huffman.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main-Huffman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main-Huffman.dir/flags.make

CMakeFiles/main-Huffman.dir/main-Huffman.c.o: CMakeFiles/main-Huffman.dir/flags.make
CMakeFiles/main-Huffman.dir/main-Huffman.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/main-Huffman.c
CMakeFiles/main-Huffman.dir/main-Huffman.c.o: CMakeFiles/main-Huffman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/main-Huffman.dir/main-Huffman.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main-Huffman.dir/main-Huffman.c.o -MF CMakeFiles/main-Huffman.dir/main-Huffman.c.o.d -o CMakeFiles/main-Huffman.dir/main-Huffman.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/main-Huffman.c

CMakeFiles/main-Huffman.dir/main-Huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main-Huffman.dir/main-Huffman.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/main-Huffman.c > CMakeFiles/main-Huffman.dir/main-Huffman.c.i

CMakeFiles/main-Huffman.dir/main-Huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main-Huffman.dir/main-Huffman.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/main-Huffman.c -o CMakeFiles/main-Huffman.dir/main-Huffman.c.s

CMakeFiles/main-Huffman.dir/binary_tree.c.o: CMakeFiles/main-Huffman.dir/flags.make
CMakeFiles/main-Huffman.dir/binary_tree.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/binary_tree.c
CMakeFiles/main-Huffman.dir/binary_tree.c.o: CMakeFiles/main-Huffman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main-Huffman.dir/binary_tree.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main-Huffman.dir/binary_tree.c.o -MF CMakeFiles/main-Huffman.dir/binary_tree.c.o.d -o CMakeFiles/main-Huffman.dir/binary_tree.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/binary_tree.c

CMakeFiles/main-Huffman.dir/binary_tree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main-Huffman.dir/binary_tree.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/binary_tree.c > CMakeFiles/main-Huffman.dir/binary_tree.c.i

CMakeFiles/main-Huffman.dir/binary_tree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main-Huffman.dir/binary_tree.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/binary_tree.c -o CMakeFiles/main-Huffman.dir/binary_tree.c.s

CMakeFiles/main-Huffman.dir/image.c.o: CMakeFiles/main-Huffman.dir/flags.make
CMakeFiles/main-Huffman.dir/image.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image.c
CMakeFiles/main-Huffman.dir/image.c.o: CMakeFiles/main-Huffman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/main-Huffman.dir/image.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main-Huffman.dir/image.c.o -MF CMakeFiles/main-Huffman.dir/image.c.o.d -o CMakeFiles/main-Huffman.dir/image.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image.c

CMakeFiles/main-Huffman.dir/image.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main-Huffman.dir/image.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image.c > CMakeFiles/main-Huffman.dir/image.c.i

CMakeFiles/main-Huffman.dir/image.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main-Huffman.dir/image.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image.c -o CMakeFiles/main-Huffman.dir/image.c.s

CMakeFiles/main-Huffman.dir/image-proba.c.o: CMakeFiles/main-Huffman.dir/flags.make
CMakeFiles/main-Huffman.dir/image-proba.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image-proba.c
CMakeFiles/main-Huffman.dir/image-proba.c.o: CMakeFiles/main-Huffman.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/main-Huffman.dir/image-proba.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main-Huffman.dir/image-proba.c.o -MF CMakeFiles/main-Huffman.dir/image-proba.c.o.d -o CMakeFiles/main-Huffman.dir/image-proba.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image-proba.c

CMakeFiles/main-Huffman.dir/image-proba.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/main-Huffman.dir/image-proba.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image-proba.c > CMakeFiles/main-Huffman.dir/image-proba.c.i

CMakeFiles/main-Huffman.dir/image-proba.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/main-Huffman.dir/image-proba.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/image-proba.c -o CMakeFiles/main-Huffman.dir/image-proba.c.s

# Object files for target main-Huffman
main__Huffman_OBJECTS = \
"CMakeFiles/main-Huffman.dir/main-Huffman.c.o" \
"CMakeFiles/main-Huffman.dir/binary_tree.c.o" \
"CMakeFiles/main-Huffman.dir/image.c.o" \
"CMakeFiles/main-Huffman.dir/image-proba.c.o"

# External object files for target main-Huffman
main__Huffman_EXTERNAL_OBJECTS = \
"/home/ange/Documents/Programmation_C/Partie_2/TP/TP8/list-teacher.o" \
"/home/ange/Documents/Programmation_C/Partie_2/TP/TP8/huffman_method-teacher.o"

main-Huffman: CMakeFiles/main-Huffman.dir/main-Huffman.c.o
main-Huffman: CMakeFiles/main-Huffman.dir/binary_tree.c.o
main-Huffman: CMakeFiles/main-Huffman.dir/image.c.o
main-Huffman: CMakeFiles/main-Huffman.dir/image-proba.c.o
main-Huffman: /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/list-teacher.o
main-Huffman: /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/huffman_method-teacher.o
main-Huffman: CMakeFiles/main-Huffman.dir/build.make
main-Huffman: CMakeFiles/main-Huffman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable main-Huffman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main-Huffman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main-Huffman.dir/build: main-Huffman
.PHONY : CMakeFiles/main-Huffman.dir/build

CMakeFiles/main-Huffman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main-Huffman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main-Huffman.dir/clean

CMakeFiles/main-Huffman.dir/depend:
	cd /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ange/Documents/Programmation_C/Partie_2/TP/TP8 /home/ange/Documents/Programmation_C/Partie_2/TP/TP8 /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug /home/ange/Documents/Programmation_C/Partie_2/TP/TP8/cmake-build-debug/CMakeFiles/main-Huffman.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main-Huffman.dir/depend

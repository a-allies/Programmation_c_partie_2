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
CMAKE_SOURCE_DIR = /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/leakDetector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/leakDetector.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/leakDetector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leakDetector.dir/flags.make

CMakeFiles/leakDetector.dir/main.c.o: CMakeFiles/leakDetector.dir/flags.make
CMakeFiles/leakDetector.dir/main.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/main.c
CMakeFiles/leakDetector.dir/main.c.o: CMakeFiles/leakDetector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/leakDetector.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/leakDetector.dir/main.c.o -MF CMakeFiles/leakDetector.dir/main.c.o.d -o CMakeFiles/leakDetector.dir/main.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/main.c

CMakeFiles/leakDetector.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/leakDetector.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/main.c > CMakeFiles/leakDetector.dir/main.c.i

CMakeFiles/leakDetector.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/leakDetector.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/main.c -o CMakeFiles/leakDetector.dir/main.c.s

CMakeFiles/leakDetector.dir/myAlloc.c.o: CMakeFiles/leakDetector.dir/flags.make
CMakeFiles/leakDetector.dir/myAlloc.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myAlloc.c
CMakeFiles/leakDetector.dir/myAlloc.c.o: CMakeFiles/leakDetector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/leakDetector.dir/myAlloc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/leakDetector.dir/myAlloc.c.o -MF CMakeFiles/leakDetector.dir/myAlloc.c.o.d -o CMakeFiles/leakDetector.dir/myAlloc.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myAlloc.c

CMakeFiles/leakDetector.dir/myAlloc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/leakDetector.dir/myAlloc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myAlloc.c > CMakeFiles/leakDetector.dir/myAlloc.c.i

CMakeFiles/leakDetector.dir/myAlloc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/leakDetector.dir/myAlloc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myAlloc.c -o CMakeFiles/leakDetector.dir/myAlloc.c.s

CMakeFiles/leakDetector.dir/myFunctions.c.o: CMakeFiles/leakDetector.dir/flags.make
CMakeFiles/leakDetector.dir/myFunctions.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myFunctions.c
CMakeFiles/leakDetector.dir/myFunctions.c.o: CMakeFiles/leakDetector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/leakDetector.dir/myFunctions.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/leakDetector.dir/myFunctions.c.o -MF CMakeFiles/leakDetector.dir/myFunctions.c.o.d -o CMakeFiles/leakDetector.dir/myFunctions.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myFunctions.c

CMakeFiles/leakDetector.dir/myFunctions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/leakDetector.dir/myFunctions.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myFunctions.c > CMakeFiles/leakDetector.dir/myFunctions.c.i

CMakeFiles/leakDetector.dir/myFunctions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/leakDetector.dir/myFunctions.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/myFunctions.c -o CMakeFiles/leakDetector.dir/myFunctions.c.s

CMakeFiles/leakDetector.dir/memoryList.c.o: CMakeFiles/leakDetector.dir/flags.make
CMakeFiles/leakDetector.dir/memoryList.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/memoryList.c
CMakeFiles/leakDetector.dir/memoryList.c.o: CMakeFiles/leakDetector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/leakDetector.dir/memoryList.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/leakDetector.dir/memoryList.c.o -MF CMakeFiles/leakDetector.dir/memoryList.c.o.d -o CMakeFiles/leakDetector.dir/memoryList.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/memoryList.c

CMakeFiles/leakDetector.dir/memoryList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/leakDetector.dir/memoryList.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/memoryList.c > CMakeFiles/leakDetector.dir/memoryList.c.i

CMakeFiles/leakDetector.dir/memoryList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/leakDetector.dir/memoryList.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/memoryList.c -o CMakeFiles/leakDetector.dir/memoryList.c.s

CMakeFiles/leakDetector.dir/test.c.o: CMakeFiles/leakDetector.dir/flags.make
CMakeFiles/leakDetector.dir/test.c.o: /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/test.c
CMakeFiles/leakDetector.dir/test.c.o: CMakeFiles/leakDetector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/leakDetector.dir/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/leakDetector.dir/test.c.o -MF CMakeFiles/leakDetector.dir/test.c.o.d -o CMakeFiles/leakDetector.dir/test.c.o -c /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/test.c

CMakeFiles/leakDetector.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/leakDetector.dir/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/test.c > CMakeFiles/leakDetector.dir/test.c.i

CMakeFiles/leakDetector.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/leakDetector.dir/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/test.c -o CMakeFiles/leakDetector.dir/test.c.s

# Object files for target leakDetector
leakDetector_OBJECTS = \
"CMakeFiles/leakDetector.dir/main.c.o" \
"CMakeFiles/leakDetector.dir/myAlloc.c.o" \
"CMakeFiles/leakDetector.dir/myFunctions.c.o" \
"CMakeFiles/leakDetector.dir/memoryList.c.o" \
"CMakeFiles/leakDetector.dir/test.c.o"

# External object files for target leakDetector
leakDetector_EXTERNAL_OBJECTS =

leakDetector: CMakeFiles/leakDetector.dir/main.c.o
leakDetector: CMakeFiles/leakDetector.dir/myAlloc.c.o
leakDetector: CMakeFiles/leakDetector.dir/myFunctions.c.o
leakDetector: CMakeFiles/leakDetector.dir/memoryList.c.o
leakDetector: CMakeFiles/leakDetector.dir/test.c.o
leakDetector: CMakeFiles/leakDetector.dir/build.make
leakDetector: CMakeFiles/leakDetector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable leakDetector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leakDetector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leakDetector.dir/build: leakDetector
.PHONY : CMakeFiles/leakDetector.dir/build

CMakeFiles/leakDetector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/leakDetector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/leakDetector.dir/clean

CMakeFiles/leakDetector.dir/depend:
	cd /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug /home/ange/Documents/Programmation_C/Partie_2/TP/TP6/leakDetector/cmake-build-debug/CMakeFiles/leakDetector.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/leakDetector.dir/depend

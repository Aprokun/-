# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/code1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/code1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/code1.dir/flags.make

CMakeFiles/code1.dir/main.c.obj: CMakeFiles/code1.dir/flags.make
CMakeFiles/code1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/code1.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\code1.dir\main.c.obj   -c "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\main.c"

CMakeFiles/code1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/code1.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\main.c" > CMakeFiles\code1.dir\main.c.i

CMakeFiles/code1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/code1.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\main.c" -o CMakeFiles\code1.dir\main.c.s

# Object files for target code1
code1_OBJECTS = \
"CMakeFiles/code1.dir/main.c.obj"

# External object files for target code1
code1_EXTERNAL_OBJECTS =

code1.exe: CMakeFiles/code1.dir/main.c.obj
code1.exe: CMakeFiles/code1.dir/build.make
code1.exe: CMakeFiles/code1.dir/linklibs.rsp
code1.exe: CMakeFiles/code1.dir/objects1.rsp
code1.exe: CMakeFiles/code1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable code1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\code1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/code1.dir/build: code1.exe

.PHONY : CMakeFiles/code1.dir/build

CMakeFiles/code1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\code1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/code1.dir/clean

CMakeFiles/code1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1" "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1" "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\cmake-build-debug" "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\cmake-build-debug" "C:\Users\lagri\Desktop\papka s prikolom\OP\C\lr7\code1\cmake-build-debug\CMakeFiles\code1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/code1.dir/depend


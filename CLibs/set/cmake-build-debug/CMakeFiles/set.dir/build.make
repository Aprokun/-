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
CMAKE_COMMAND = "D:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\lagri\Desktop\-\CLibs\set

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\lagri\Desktop\-\CLibs\set\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/set.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/set.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/set.dir/flags.make

CMakeFiles/set.dir/set.c.obj: CMakeFiles/set.dir/flags.make
CMakeFiles/set.dir/set.c.obj: ../set.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\lagri\Desktop\-\CLibs\set\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/set.dir/set.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\set.dir\set.c.obj   -c C:\Users\lagri\Desktop\-\CLibs\set\set.c

CMakeFiles/set.dir/set.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/set.dir/set.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\lagri\Desktop\-\CLibs\set\set.c > CMakeFiles\set.dir\set.c.i

CMakeFiles/set.dir/set.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/set.dir/set.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\lagri\Desktop\-\CLibs\set\set.c -o CMakeFiles\set.dir\set.c.s

# Object files for target set
set_OBJECTS = \
"CMakeFiles/set.dir/set.c.obj"

# External object files for target set
set_EXTERNAL_OBJECTS =

libset.dll: CMakeFiles/set.dir/set.c.obj
libset.dll: CMakeFiles/set.dir/build.make
libset.dll: CMakeFiles/set.dir/linklibs.rsp
libset.dll: CMakeFiles/set.dir/objects1.rsp
libset.dll: CMakeFiles/set.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\lagri\Desktop\-\CLibs\set\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libset.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\set.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/set.dir/build: libset.dll

.PHONY : CMakeFiles/set.dir/build

CMakeFiles/set.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\set.dir\cmake_clean.cmake
.PHONY : CMakeFiles/set.dir/clean

CMakeFiles/set.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\lagri\Desktop\-\CLibs\set C:\Users\lagri\Desktop\-\CLibs\set C:\Users\lagri\Desktop\-\CLibs\set\cmake-build-debug C:\Users\lagri\Desktop\-\CLibs\set\cmake-build-debug C:\Users\lagri\Desktop\-\CLibs\set\cmake-build-debug\CMakeFiles\set.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/set.dir/depend


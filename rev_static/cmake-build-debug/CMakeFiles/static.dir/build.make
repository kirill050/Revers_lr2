# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/static.dir/flags.make

CMakeFiles/static.dir/rev_static.c.obj: CMakeFiles/static.dir/flags.make
CMakeFiles/static.dir/rev_static.c.obj: ../rev_static.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/static.dir/rev_static.c.obj"
	D:\Kirill\Files\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\static.dir\rev_static.c.obj   -c D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\rev_static.c

CMakeFiles/static.dir/rev_static.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/static.dir/rev_static.c.i"
	D:\Kirill\Files\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\rev_static.c > CMakeFiles\static.dir\rev_static.c.i

CMakeFiles/static.dir/rev_static.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/static.dir/rev_static.c.s"
	D:\Kirill\Files\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\rev_static.c -o CMakeFiles\static.dir\rev_static.c.s

# Object files for target static
static_OBJECTS = \
"CMakeFiles/static.dir/rev_static.c.obj"

# External object files for target static
static_EXTERNAL_OBJECTS =

static.exe: CMakeFiles/static.dir/rev_static.c.obj
static.exe: CMakeFiles/static.dir/build.make
static.exe: CMakeFiles/static.dir/linklibs.rsp
static.exe: CMakeFiles/static.dir/objects1.rsp
static.exe: CMakeFiles/static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable static.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\static.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/static.dir/build: static.exe

.PHONY : CMakeFiles/static.dir/build

CMakeFiles/static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\static.dir\cmake_clean.cmake
.PHONY : CMakeFiles/static.dir/clean

CMakeFiles/static.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\cmake-build-debug D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\cmake-build-debug D:\Kirill\VUZ\5_Semestr\Revers\4stud_2020\LR2\LR_2\rev_static\cmake-build-debug\CMakeFiles\static.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/static.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/final.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/final.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/final.dir/flags.make

src/CMakeFiles/final.dir/ArgParser.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/ArgParser.cpp.o: ../src/ArgParser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/ArgParser.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/ArgParser.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/ArgParser.cpp"

src/CMakeFiles/final.dir/ArgParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/ArgParser.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/ArgParser.cpp" > CMakeFiles/final.dir/ArgParser.cpp.i

src/CMakeFiles/final.dir/ArgParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/ArgParser.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/ArgParser.cpp" -o CMakeFiles/final.dir/ArgParser.cpp.s

src/CMakeFiles/final.dir/ArgParser.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/ArgParser.cpp.o.requires

src/CMakeFiles/final.dir/ArgParser.cpp.o.provides: src/CMakeFiles/final.dir/ArgParser.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/ArgParser.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/ArgParser.cpp.o.provides

src/CMakeFiles/final.dir/ArgParser.cpp.o.provides.build: src/CMakeFiles/final.dir/ArgParser.cpp.o

src/CMakeFiles/final.dir/CubeMap.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/CubeMap.cpp.o: ../src/CubeMap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/CubeMap.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/CubeMap.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/CubeMap.cpp"

src/CMakeFiles/final.dir/CubeMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/CubeMap.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/CubeMap.cpp" > CMakeFiles/final.dir/CubeMap.cpp.i

src/CMakeFiles/final.dir/CubeMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/CubeMap.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/CubeMap.cpp" -o CMakeFiles/final.dir/CubeMap.cpp.s

src/CMakeFiles/final.dir/CubeMap.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/CubeMap.cpp.o.requires

src/CMakeFiles/final.dir/CubeMap.cpp.o.provides: src/CMakeFiles/final.dir/CubeMap.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/CubeMap.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/CubeMap.cpp.o.provides

src/CMakeFiles/final.dir/CubeMap.cpp.o.provides.build: src/CMakeFiles/final.dir/CubeMap.cpp.o

src/CMakeFiles/final.dir/main.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/main.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/main.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/main.cpp"

src/CMakeFiles/final.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/main.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/main.cpp" > CMakeFiles/final.dir/main.cpp.i

src/CMakeFiles/final.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/main.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/main.cpp" -o CMakeFiles/final.dir/main.cpp.s

src/CMakeFiles/final.dir/main.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/main.cpp.o.requires

src/CMakeFiles/final.dir/main.cpp.o.provides: src/CMakeFiles/final.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/main.cpp.o.provides

src/CMakeFiles/final.dir/main.cpp.o.provides.build: src/CMakeFiles/final.dir/main.cpp.o

src/CMakeFiles/final.dir/stb.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/stb.cpp.o: ../src/stb.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/stb.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/stb.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/stb.cpp"

src/CMakeFiles/final.dir/stb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/stb.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/stb.cpp" > CMakeFiles/final.dir/stb.cpp.i

src/CMakeFiles/final.dir/stb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/stb.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/stb.cpp" -o CMakeFiles/final.dir/stb.cpp.s

src/CMakeFiles/final.dir/stb.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/stb.cpp.o.requires

src/CMakeFiles/final.dir/stb.cpp.o.provides: src/CMakeFiles/final.dir/stb.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/stb.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/stb.cpp.o.provides

src/CMakeFiles/final.dir/stb.cpp.o.provides.build: src/CMakeFiles/final.dir/stb.cpp.o

src/CMakeFiles/final.dir/Camera.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/Camera.cpp.o: ../src/Camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/Camera.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/Camera.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Camera.cpp"

src/CMakeFiles/final.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/Camera.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Camera.cpp" > CMakeFiles/final.dir/Camera.cpp.i

src/CMakeFiles/final.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/Camera.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Camera.cpp" -o CMakeFiles/final.dir/Camera.cpp.s

src/CMakeFiles/final.dir/Camera.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/Camera.cpp.o.requires

src/CMakeFiles/final.dir/Camera.cpp.o.provides: src/CMakeFiles/final.dir/Camera.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/Camera.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/Camera.cpp.o.provides

src/CMakeFiles/final.dir/Camera.cpp.o.provides.build: src/CMakeFiles/final.dir/Camera.cpp.o

src/CMakeFiles/final.dir/Image.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/Image.cpp.o: ../src/Image.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/Image.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/Image.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Image.cpp"

src/CMakeFiles/final.dir/Image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/Image.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Image.cpp" > CMakeFiles/final.dir/Image.cpp.i

src/CMakeFiles/final.dir/Image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/Image.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Image.cpp" -o CMakeFiles/final.dir/Image.cpp.s

src/CMakeFiles/final.dir/Image.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/Image.cpp.o.requires

src/CMakeFiles/final.dir/Image.cpp.o.provides: src/CMakeFiles/final.dir/Image.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/Image.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/Image.cpp.o.provides

src/CMakeFiles/final.dir/Image.cpp.o.provides.build: src/CMakeFiles/final.dir/Image.cpp.o

src/CMakeFiles/final.dir/Mesh.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/Mesh.cpp.o: ../src/Mesh.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/Mesh.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/Mesh.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Mesh.cpp"

src/CMakeFiles/final.dir/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/Mesh.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Mesh.cpp" > CMakeFiles/final.dir/Mesh.cpp.i

src/CMakeFiles/final.dir/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/Mesh.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Mesh.cpp" -o CMakeFiles/final.dir/Mesh.cpp.s

src/CMakeFiles/final.dir/Mesh.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/Mesh.cpp.o.requires

src/CMakeFiles/final.dir/Mesh.cpp.o.provides: src/CMakeFiles/final.dir/Mesh.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/Mesh.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/Mesh.cpp.o.provides

src/CMakeFiles/final.dir/Mesh.cpp.o.provides.build: src/CMakeFiles/final.dir/Mesh.cpp.o

src/CMakeFiles/final.dir/Noise.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/Noise.cpp.o: ../src/Noise.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/Noise.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/Noise.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Noise.cpp"

src/CMakeFiles/final.dir/Noise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/Noise.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Noise.cpp" > CMakeFiles/final.dir/Noise.cpp.i

src/CMakeFiles/final.dir/Noise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/Noise.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Noise.cpp" -o CMakeFiles/final.dir/Noise.cpp.s

src/CMakeFiles/final.dir/Noise.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/Noise.cpp.o.requires

src/CMakeFiles/final.dir/Noise.cpp.o.provides: src/CMakeFiles/final.dir/Noise.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/Noise.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/Noise.cpp.o.provides

src/CMakeFiles/final.dir/Noise.cpp.o.provides.build: src/CMakeFiles/final.dir/Noise.cpp.o

src/CMakeFiles/final.dir/Octree.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/Octree.cpp.o: ../src/Octree.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/Octree.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/Octree.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Octree.cpp"

src/CMakeFiles/final.dir/Octree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/Octree.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Octree.cpp" > CMakeFiles/final.dir/Octree.cpp.i

src/CMakeFiles/final.dir/Octree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/Octree.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Octree.cpp" -o CMakeFiles/final.dir/Octree.cpp.s

src/CMakeFiles/final.dir/Octree.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/Octree.cpp.o.requires

src/CMakeFiles/final.dir/Octree.cpp.o.provides: src/CMakeFiles/final.dir/Octree.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/Octree.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/Octree.cpp.o.provides

src/CMakeFiles/final.dir/Octree.cpp.o.provides.build: src/CMakeFiles/final.dir/Octree.cpp.o

src/CMakeFiles/final.dir/PerlinNoise.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/PerlinNoise.cpp.o: ../src/PerlinNoise.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/PerlinNoise.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/PerlinNoise.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/PerlinNoise.cpp"

src/CMakeFiles/final.dir/PerlinNoise.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/PerlinNoise.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/PerlinNoise.cpp" > CMakeFiles/final.dir/PerlinNoise.cpp.i

src/CMakeFiles/final.dir/PerlinNoise.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/PerlinNoise.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/PerlinNoise.cpp" -o CMakeFiles/final.dir/PerlinNoise.cpp.s

src/CMakeFiles/final.dir/PerlinNoise.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/PerlinNoise.cpp.o.requires

src/CMakeFiles/final.dir/PerlinNoise.cpp.o.provides: src/CMakeFiles/final.dir/PerlinNoise.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/PerlinNoise.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/PerlinNoise.cpp.o.provides

src/CMakeFiles/final.dir/PerlinNoise.cpp.o.provides.build: src/CMakeFiles/final.dir/PerlinNoise.cpp.o

src/CMakeFiles/final.dir/Renderer.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/Renderer.cpp.o: ../src/Renderer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/Renderer.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/Renderer.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Renderer.cpp"

src/CMakeFiles/final.dir/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/Renderer.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Renderer.cpp" > CMakeFiles/final.dir/Renderer.cpp.i

src/CMakeFiles/final.dir/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/Renderer.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Renderer.cpp" -o CMakeFiles/final.dir/Renderer.cpp.s

src/CMakeFiles/final.dir/Renderer.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/Renderer.cpp.o.requires

src/CMakeFiles/final.dir/Renderer.cpp.o.provides: src/CMakeFiles/final.dir/Renderer.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/Renderer.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/Renderer.cpp.o.provides

src/CMakeFiles/final.dir/Renderer.cpp.o.provides.build: src/CMakeFiles/final.dir/Renderer.cpp.o

src/CMakeFiles/final.dir/SceneParser.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/SceneParser.cpp.o: ../src/SceneParser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/SceneParser.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/SceneParser.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/SceneParser.cpp"

src/CMakeFiles/final.dir/SceneParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/SceneParser.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/SceneParser.cpp" > CMakeFiles/final.dir/SceneParser.cpp.i

src/CMakeFiles/final.dir/SceneParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/SceneParser.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/SceneParser.cpp" -o CMakeFiles/final.dir/SceneParser.cpp.s

src/CMakeFiles/final.dir/SceneParser.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/SceneParser.cpp.o.requires

src/CMakeFiles/final.dir/SceneParser.cpp.o.provides: src/CMakeFiles/final.dir/SceneParser.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/SceneParser.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/SceneParser.cpp.o.provides

src/CMakeFiles/final.dir/SceneParser.cpp.o.provides.build: src/CMakeFiles/final.dir/SceneParser.cpp.o

src/CMakeFiles/final.dir/Texture.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/Texture.cpp.o: ../src/Texture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/Texture.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/Texture.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Texture.cpp"

src/CMakeFiles/final.dir/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/Texture.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Texture.cpp" > CMakeFiles/final.dir/Texture.cpp.i

src/CMakeFiles/final.dir/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/Texture.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/Texture.cpp" -o CMakeFiles/final.dir/Texture.cpp.s

src/CMakeFiles/final.dir/Texture.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/Texture.cpp.o.requires

src/CMakeFiles/final.dir/Texture.cpp.o.provides: src/CMakeFiles/final.dir/Texture.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/Texture.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/Texture.cpp.o.provides

src/CMakeFiles/final.dir/Texture.cpp.o.provides.build: src/CMakeFiles/final.dir/Texture.cpp.o

src/CMakeFiles/final.dir/VecUtils.cpp.o: src/CMakeFiles/final.dir/flags.make
src/CMakeFiles/final.dir/VecUtils.cpp.o: ../src/VecUtils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/CMakeFiles" $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/final.dir/VecUtils.cpp.o"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/final.dir/VecUtils.cpp.o -c "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/VecUtils.cpp"

src/CMakeFiles/final.dir/VecUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/final.dir/VecUtils.cpp.i"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/VecUtils.cpp" > CMakeFiles/final.dir/VecUtils.cpp.i

src/CMakeFiles/final.dir/VecUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/final.dir/VecUtils.cpp.s"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src/VecUtils.cpp" -o CMakeFiles/final.dir/VecUtils.cpp.s

src/CMakeFiles/final.dir/VecUtils.cpp.o.requires:
.PHONY : src/CMakeFiles/final.dir/VecUtils.cpp.o.requires

src/CMakeFiles/final.dir/VecUtils.cpp.o.provides: src/CMakeFiles/final.dir/VecUtils.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/final.dir/build.make src/CMakeFiles/final.dir/VecUtils.cpp.o.provides.build
.PHONY : src/CMakeFiles/final.dir/VecUtils.cpp.o.provides

src/CMakeFiles/final.dir/VecUtils.cpp.o.provides.build: src/CMakeFiles/final.dir/VecUtils.cpp.o

# Object files for target final
final_OBJECTS = \
"CMakeFiles/final.dir/ArgParser.cpp.o" \
"CMakeFiles/final.dir/CubeMap.cpp.o" \
"CMakeFiles/final.dir/main.cpp.o" \
"CMakeFiles/final.dir/stb.cpp.o" \
"CMakeFiles/final.dir/Camera.cpp.o" \
"CMakeFiles/final.dir/Image.cpp.o" \
"CMakeFiles/final.dir/Mesh.cpp.o" \
"CMakeFiles/final.dir/Noise.cpp.o" \
"CMakeFiles/final.dir/Octree.cpp.o" \
"CMakeFiles/final.dir/PerlinNoise.cpp.o" \
"CMakeFiles/final.dir/Renderer.cpp.o" \
"CMakeFiles/final.dir/SceneParser.cpp.o" \
"CMakeFiles/final.dir/Texture.cpp.o" \
"CMakeFiles/final.dir/VecUtils.cpp.o"

# External object files for target final
final_EXTERNAL_OBJECTS =

src/final: src/CMakeFiles/final.dir/ArgParser.cpp.o
src/final: src/CMakeFiles/final.dir/CubeMap.cpp.o
src/final: src/CMakeFiles/final.dir/main.cpp.o
src/final: src/CMakeFiles/final.dir/stb.cpp.o
src/final: src/CMakeFiles/final.dir/Camera.cpp.o
src/final: src/CMakeFiles/final.dir/Image.cpp.o
src/final: src/CMakeFiles/final.dir/Mesh.cpp.o
src/final: src/CMakeFiles/final.dir/Noise.cpp.o
src/final: src/CMakeFiles/final.dir/Octree.cpp.o
src/final: src/CMakeFiles/final.dir/PerlinNoise.cpp.o
src/final: src/CMakeFiles/final.dir/Renderer.cpp.o
src/final: src/CMakeFiles/final.dir/SceneParser.cpp.o
src/final: src/CMakeFiles/final.dir/Texture.cpp.o
src/final: src/CMakeFiles/final.dir/VecUtils.cpp.o
src/final: src/CMakeFiles/final.dir/build.make
src/final: vecmath/libvecmath.a
src/final: src/CMakeFiles/final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable final"
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/final.dir/build: src/final
.PHONY : src/CMakeFiles/final.dir/build

src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/ArgParser.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/CubeMap.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/main.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/stb.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/Camera.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/Image.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/Mesh.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/Noise.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/Octree.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/PerlinNoise.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/Renderer.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/SceneParser.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/Texture.cpp.o.requires
src/CMakeFiles/final.dir/requires: src/CMakeFiles/final.dir/VecUtils.cpp.o.requires
.PHONY : src/CMakeFiles/final.dir/requires

src/CMakeFiles/final.dir/clean:
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/final.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/final.dir/clean

src/CMakeFiles/final.dir/depend:
	cd "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup" "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/src" "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build" "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src" "/afs/athena.mit.edu/user/m/i/missdeeh/Documents/6.837_F15/final_project backup/build/src/CMakeFiles/final.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/final.dir/depend


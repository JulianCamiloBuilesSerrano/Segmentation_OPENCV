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
CMAKE_SOURCE_DIR = "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build"

# Include any dependencies generated for this target.
include CMakeFiles/Segmentacion_regiones.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Segmentacion_regiones.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Segmentacion_regiones.dir/flags.make

CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.o: CMakeFiles/Segmentacion_regiones.dir/flags.make
CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.o: ../Segmentacion_regiones.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.o -c "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/Segmentacion_regiones.cxx"

CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/Segmentacion_regiones.cxx" > CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.i

CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/Segmentacion_regiones.cxx" -o CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.s

# Object files for target Segmentacion_regiones
Segmentacion_regiones_OBJECTS = \
"CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.o"

# External object files for target Segmentacion_regiones
Segmentacion_regiones_EXTERNAL_OBJECTS =

Segmentacion_regiones: CMakeFiles/Segmentacion_regiones.dir/Segmentacion_regiones.cxx.o
Segmentacion_regiones: CMakeFiles/Segmentacion_regiones.dir/build.make
Segmentacion_regiones: /usr/local/lib/libopencv_gapi.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_highgui.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_ml.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_objdetect.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_photo.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_stitching.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_video.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_videoio.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_dnn.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_imgcodecs.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_calib3d.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_features2d.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_flann.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_imgproc.so.4.5.1
Segmentacion_regiones: /usr/local/lib/libopencv_core.so.4.5.1
Segmentacion_regiones: CMakeFiles/Segmentacion_regiones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Segmentacion_regiones"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Segmentacion_regiones.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Segmentacion_regiones.dir/build: Segmentacion_regiones

.PHONY : CMakeFiles/Segmentacion_regiones.dir/build

CMakeFiles/Segmentacion_regiones.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Segmentacion_regiones.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Segmentacion_regiones.dir/clean

CMakeFiles/Segmentacion_regiones.dir/depend:
	cd "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build/CMakeFiles/Segmentacion_regiones.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Segmentacion_regiones.dir/depend


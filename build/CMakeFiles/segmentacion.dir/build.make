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
include CMakeFiles/segmentacion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/segmentacion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/segmentacion.dir/flags.make

CMakeFiles/segmentacion.dir/segmentacion.cxx.o: CMakeFiles/segmentacion.dir/flags.make
CMakeFiles/segmentacion.dir/segmentacion.cxx.o: ../segmentacion.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/segmentacion.dir/segmentacion.cxx.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/segmentacion.dir/segmentacion.cxx.o -c "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/segmentacion.cxx"

CMakeFiles/segmentacion.dir/segmentacion.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segmentacion.dir/segmentacion.cxx.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/segmentacion.cxx" > CMakeFiles/segmentacion.dir/segmentacion.cxx.i

CMakeFiles/segmentacion.dir/segmentacion.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segmentacion.dir/segmentacion.cxx.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/segmentacion.cxx" -o CMakeFiles/segmentacion.dir/segmentacion.cxx.s

# Object files for target segmentacion
segmentacion_OBJECTS = \
"CMakeFiles/segmentacion.dir/segmentacion.cxx.o"

# External object files for target segmentacion
segmentacion_EXTERNAL_OBJECTS =

segmentacion: CMakeFiles/segmentacion.dir/segmentacion.cxx.o
segmentacion: CMakeFiles/segmentacion.dir/build.make
segmentacion: /usr/local/lib/libopencv_gapi.so.4.5.1
segmentacion: /usr/local/lib/libopencv_highgui.so.4.5.1
segmentacion: /usr/local/lib/libopencv_ml.so.4.5.1
segmentacion: /usr/local/lib/libopencv_objdetect.so.4.5.1
segmentacion: /usr/local/lib/libopencv_photo.so.4.5.1
segmentacion: /usr/local/lib/libopencv_stitching.so.4.5.1
segmentacion: /usr/local/lib/libopencv_video.so.4.5.1
segmentacion: /usr/local/lib/libopencv_videoio.so.4.5.1
segmentacion: /usr/local/lib/libopencv_dnn.so.4.5.1
segmentacion: /usr/local/lib/libopencv_imgcodecs.so.4.5.1
segmentacion: /usr/local/lib/libopencv_calib3d.so.4.5.1
segmentacion: /usr/local/lib/libopencv_features2d.so.4.5.1
segmentacion: /usr/local/lib/libopencv_flann.so.4.5.1
segmentacion: /usr/local/lib/libopencv_imgproc.so.4.5.1
segmentacion: /usr/local/lib/libopencv_core.so.4.5.1
segmentacion: CMakeFiles/segmentacion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable segmentacion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/segmentacion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/segmentacion.dir/build: segmentacion

.PHONY : CMakeFiles/segmentacion.dir/build

CMakeFiles/segmentacion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/segmentacion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/segmentacion.dir/clean

CMakeFiles/segmentacion.dir/depend:
	cd "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build" "/mnt/d/Documentos/Vision artificial/Talleres/Taller_segmentacion/Segmentation_OPENCV/build/CMakeFiles/segmentacion.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/segmentacion.dir/depend


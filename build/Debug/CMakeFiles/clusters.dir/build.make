# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/v.bezugly/work/clusters

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/v.bezugly/work/clusters/build/Debug

# Include any dependencies generated for this target.
include CMakeFiles/clusters.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/clusters.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clusters.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clusters.dir/flags.make

CMakeFiles/clusters.dir/main.cpp.o: CMakeFiles/clusters.dir/flags.make
CMakeFiles/clusters.dir/main.cpp.o: /Users/v.bezugly/work/clusters/main.cpp
CMakeFiles/clusters.dir/main.cpp.o: CMakeFiles/clusters.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/v.bezugly/work/clusters/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clusters.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clusters.dir/main.cpp.o -MF CMakeFiles/clusters.dir/main.cpp.o.d -o CMakeFiles/clusters.dir/main.cpp.o -c /Users/v.bezugly/work/clusters/main.cpp

CMakeFiles/clusters.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clusters.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/v.bezugly/work/clusters/main.cpp > CMakeFiles/clusters.dir/main.cpp.i

CMakeFiles/clusters.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clusters.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/v.bezugly/work/clusters/main.cpp -o CMakeFiles/clusters.dir/main.cpp.s

# Object files for target clusters
clusters_OBJECTS = \
"CMakeFiles/clusters.dir/main.cpp.o"

# External object files for target clusters
clusters_EXTERNAL_OBJECTS =

clusters: CMakeFiles/clusters.dir/main.cpp.o
clusters: CMakeFiles/clusters.dir/build.make
clusters: /opt/homebrew/lib/libopencv_gapi.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_stitching.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_alphamat.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_aruco.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_bgsegm.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_bioinspired.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_ccalib.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_dnn_objdetect.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_dnn_superres.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_dpm.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_face.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_freetype.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_fuzzy.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_hfs.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_img_hash.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_intensity_transform.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_line_descriptor.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_mcc.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_quality.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_rapid.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_reg.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_rgbd.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_saliency.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_sfm.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_stereo.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_structured_light.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_superres.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_surface_matching.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_tracking.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_videostab.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_viz.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_wechat_qrcode.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_xfeatures2d.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_xobjdetect.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_xphoto.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_shape.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_highgui.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_datasets.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_plot.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_text.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_ml.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_phase_unwrapping.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_optflow.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_ximgproc.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_video.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_videoio.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_imgcodecs.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_objdetect.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_calib3d.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_dnn.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_features2d.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_flann.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_photo.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_imgproc.4.9.0.dylib
clusters: /opt/homebrew/lib/libopencv_core.4.9.0.dylib
clusters: CMakeFiles/clusters.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/v.bezugly/work/clusters/build/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable clusters"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clusters.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clusters.dir/build: clusters
.PHONY : CMakeFiles/clusters.dir/build

CMakeFiles/clusters.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clusters.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clusters.dir/clean

CMakeFiles/clusters.dir/depend:
	cd /Users/v.bezugly/work/clusters/build/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/v.bezugly/work/clusters /Users/v.bezugly/work/clusters /Users/v.bezugly/work/clusters/build/Debug /Users/v.bezugly/work/clusters/build/Debug /Users/v.bezugly/work/clusters/build/Debug/CMakeFiles/clusters.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/clusters.dir/depend

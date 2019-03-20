cmake_minimum_required(VERSION 3.13)
project(manual_segmentation_tool)

set(CMAKE_CXX_STANDARD 17)

add_executable(manual_segmentation_tool manual_segmentation_tool.cpp application_win32.h application_win32.cpp
        image_processing.cpp image_processing.h application.cpp application.h application_glfw_opengl3.cpp
        application_glfw_opengl3.h segment_by_polygon_fit.cpp segment_by_polygon_fit.h segmentation_method.cpp
        segmentation_method.h mouse_control_functions.cpp mouse_control_functions.h imgui/imgui_demo.cpp
        imgui/imgui_impl_opengl2.h imgui/imgui_impl_opengl2.cpp imgui/imgui_impl_glfw.h)
include_directories(imgui)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenCV REQUIRED)
if (OpenCV_FOUND)
    message("Opencv has been found!")
endif()
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${OpenCV_DIR})


target_link_libraries(manual_segmentation_tool ${OPENGL_LIBRARIES})
target_link_libraries(manual_segmentation_tool ${OPENGL_gl_LIBRARY})
target_link_libraries(manual_segmentation_tool ${OPENGL_glu_LIBRARY})
target_link_libraries(manual_segmentation_tool glfw ${GLFW_LIBRARIES})
target_link_libraries(manual_segmentation_tool ${OpenCV_LIBS} )
target_link_libraries(manual_segmentation_tool /usr/lib/gcc/x86_64-linux-gnu/8/libstdc++fs.a)

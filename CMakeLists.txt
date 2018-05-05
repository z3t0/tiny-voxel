cmake_minimum_required(VERSION 2.6)
project(tiny-voxel)

# GLFW
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})

# GLEW
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

# Build executable
add_executable(tiny-voxel main.c)
target_link_libraries(tiny-voxel ${GLFW_LIBRARIES})

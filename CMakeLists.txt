cmake_minimum_required(VERSION 3.0.0)
project(RPGE VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

#Add source files
file(GLOB_RECURSE rpgeSourceFiles
    "source/*.h"
    "source/*.hpp"
    "source/*.c"
    "source/*.cc"
    "source/*.cpp"
    "source/System/*.h"
    "source/System/*.hpp"
    "source/System/*.c"
    "source/System/*.cc"
    "source/System/*.cpp"
)

add_subdirectory(libraries/imgui-sfml)
add_subdirectory(libraries/SFML-2.5.1)
add_executable(RPGE ${rpgeSourceFiles})
target_include_directories(RPGE PRIVATE "${PROJECT_BINARY_DIR}")
#target_link_libraries(RPGE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
# Cannot find SFML Audio for some reason? Not important for now, but needs to be fixed
target_link_libraries(RPGE sfml-system sfml-window sfml-graphics sfml-network ImGui-SFML::ImGui-SFML)

set_target_properties( RPGE
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/debug/lib"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/debug/lib"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/debug"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/release/lib"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/release/lib"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/release"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/bin/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/bin/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/bin"
    
)
file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/bin)
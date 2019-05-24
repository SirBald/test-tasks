cmake_minimum_required(VERSION 3.0.0)


project(poi-on-map VERSION 0.0.1)
message(STATUS "Configuring '${PROJECT_NAME}' project")

# configure compiler
if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  message(FATAL_ERROR "!!! UNSUPPROTED COMPILER !!!")
endif(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(
  CMAKE_CXX_FLAGS
  "${CMAKE_CXX_FLAGS} -std=c++11 -fcheck-new -Wall -Wconversion -Werror -pedantic -Wno-ignored-qualifiers -D_CPLUS_PLUS"
)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_FLAGS_RELEASE} -g -O2 -fno-gcse")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_FLAGS_DEBUG} -g")

# define default build type
if(NOT CMAKE_BUILD_TYPE)
  set(_default_build_type "Debug")
  set(CMAKE_BUILD_TYPE ${_default_build_type})
  message(STATUS "CMAKE_BUILD_TYPE is not defined, default is '${CMAKE_BUILD_TYPE}'")
endif(NOT CMAKE_BUILD_TYPE)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(_main_source_file "${CMAKE_CURRENT_SOURCE_DIR}/poi_on_map_main.cc")
set(
  _project_source_files
  "${CMAKE_CURRENT_SOURCE_DIR}/point_cartesian.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/point_cartesian.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/point_poi-inl.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/point_polar.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/point_polar.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/shape_circle.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/shape_circle.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/shape_rectangle.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/shape_rectangle.h"
)

add_executable(
  ${PROJECT_NAME}
  ${_main_source_file}
  ${_project_source_files}
)

set(_executable_build_dir "${CMAKE_CURRENT_BINARY_DIR}/bin")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${_executable_build_dir})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${_executable_build_dir})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${_executable_build_dir})

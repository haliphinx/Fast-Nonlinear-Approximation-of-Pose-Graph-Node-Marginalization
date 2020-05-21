cmake_minimum_required(VERSION 2.8)
project(FNA)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 3.0 QUIET)
if(NOT OpenCV_FOUND)
   find_package(OpenCV 2.4.3 QUIET)
   if(NOT OpenCV_FOUND)
      message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
   endif()
endif()


include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} SHARED
src/Edge.cc
src/Nam.cc
src/Node.cc
src/Topology.cc
)

target_link_libraries(${PROJECT_NAME}
${OpenCV_LIBS}
)

# Build examples

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/example)

add_executable(test example/test.cc)
target_link_libraries(test ${PROJECT_NAME})




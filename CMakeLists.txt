################################################################################
# Set minimum required version of cmake, project name and compile options
################################################################################
cmake_minimum_required(VERSION 3.5)
project(sh_slam)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

# -std=gnu++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-unused-parameter -Wno-pedantic -Wno-missing-field-initializers -Wno-conversion-null")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-ignored-qualifiers -Wno-reorder -Wall -Wextra -Wno-unused-parameter -Wno-pedantic -Wno-missing-field-initializers -Wno-conversion-null)
endif()

################################################################################
# Find ament packages and libraries for ament and system dependencies
################################################################################
#find_package(ament_cmake REQUIRED)
find_package(Eigen3 REQUIRED)
#find_package(PCL REQUIRED)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" "${CMAKE_MODULE_PATH}")
find_package(JETSONMM REQUIRED)
find_package(CUDA)

find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)

################################################################################
# Build
################################################################################

# build library
file(GLOB jetson_tools_src
  src/frontend/*.cpp)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIR}
  ${GLEW_INCLUDE_DIRS}
  ${GLUT_INCLUDE_PATH}
  ${OpenCV_INCLUDE_DIRS}
)

link_directories(
  ${GLEW_LIBRARY_DIRS}
  ${GLUT_LIBRARY_DIRS}
  ${OpenGL_LIBRARY_DIRS}
)

target_link_libraries(sh_slam
  ${GLUT_LIBRARY}
  ${GLEW_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${OpenCV_LIBRARIES}
  stdc++fs)

################################################################################
# Install
################################################################################
install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

################################################################################
# Test
################################################################################
#if(BUILD_TESTING)
#  find_package(ament_lint_auto REQUIRED)
#  ament_lint_auto_find_test_dependencies()
#endif()

################################################################################
# Macro for ament package
################################################################################
#ament_export_include_directories(include)
#ament_export_libraries(${PROJECT_NAME})
#ament_package()
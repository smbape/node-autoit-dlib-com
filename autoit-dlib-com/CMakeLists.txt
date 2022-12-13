cmake_minimum_required(VERSION 3.16)

# Name of the project (will be the name of the plugin)
project(autoit_dlib_com)

set(DEFAULT_BUILD_TYPE "Release")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(/MP)

# https://github.com/scivision/cmake-patch-file/blob/main/cmake/PatchFile.cmake
if(WIN32)
  # prioritize Git Patch on Windows as other Patches may be very old and incompatible.
  find_package(Git)
  if(Git_FOUND)
    get_filename_component(GIT_DIR ${GIT_EXECUTABLE} DIRECTORY)
    get_filename_component(GIT_DIR ${GIT_DIR} DIRECTORY)
  endif()
endif()

find_program(PATCH
  NAMES patch
  HINTS ${GIT_DIR}
  PATH_SUFFIXES usr/bin
)

if(NOT PATCH)
  message(FATAL_ERROR "Did not find GNU Patch")
endif()

# Tell cmake that we will need opencv.
get_filename_component(OPENCV_DOWNLOAD_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
set(OPENCV_VERSION 4.6.0)
set(OPENCV_DOWNLOAD_NAME  opencv-${OPENCV_VERSION}-vc14_vc15.exe)
set(OPENCV_URL            https://github.com/opencv/opencv/releases/download/${OPENCV_VERSION}/${OPENCV_DOWNLOAD_NAME})
set(OPENCV_URL_HASH       SHA256=3fb046e14dc5b50719a86ea0395b5b1e3299e2343111ebd2e31828aa31d6d477)

include(FetchContent)
FetchContent_Declare(opencv
  URL                 ${OPENCV_URL}
  URL_HASH            ${OPENCV_URL_HASH}
  DOWNLOAD_NO_EXTRACT TRUE
  DOWNLOAD_DIR        "${OPENCV_DOWNLOAD_DIR}"
  SOURCE_DIR          "${OPENCV_DOWNLOAD_DIR}"
  PATCH_COMMAND       "<DOWNLOAD_DIR>/${OPENCV_DOWNLOAD_NAME}" "-o<DOWNLOAD_DIR>/opencv-${OPENCV_VERSION}-vc14_vc15" -y
)

include(FetchContent)
FetchContent_Declare(opencv-patch
  URL                 ${OPENCV_URL}
  URL_HASH            ${OPENCV_URL_HASH}
  DOWNLOAD_NO_EXTRACT TRUE
  DOWNLOAD_DIR        "${OPENCV_DOWNLOAD_DIR}"
  SOURCE_DIR          "${OPENCV_DOWNLOAD_DIR}"
  PATCH_COMMAND       "${PATCH}" -p 1 -d "<DOWNLOAD_DIR>/opencv-${OPENCV_VERSION}-vc14_vc15/opencv/sources/"
                        -i "${CMAKE_CURRENT_SOURCE_DIR}/patches/001-opencv-src.patch"
)

# Tell cmake that we will need dlib. These command will pull in dlib.
include(FetchContent)
FetchContent_Declare(dlib
  GIT_REPOSITORY https://github.com/davisking/dlib.git
  GIT_TAG        v19.24

  # PATCH_COMMAND is run once for each BUILD_TYPE
  # however, source download is only done once when it is a git repository
  # use a custom patch command to perform patch only once
  PATCH_COMMAND "${CMAKE_COMMAND}"
                  -DBUILD_STEP=patch
                  "-DGIT_EXECUTABLE=${GIT_EXECUTABLE}"
                  "-DPATCH_FILE=${CMAKE_CURRENT_SOURCE_DIR}/patches/001-dlib-src.patch"
                  -P "${CMAKE_CURRENT_SOURCE_DIR}/project_build_steps.cmake"
)

# Tell cmake that we will need autoit-opencv-com.
include(ExternalProject)
ExternalProject_Add(autoit-opencv-com
  URL               https://github.com/smbape/node-autoit-opencv-com/releases/download/v2.2.1/autoit-opencv-${OPENCV_VERSION}-com-v2.2.1.7z
  URL_HASH          SHA256=26235cee7ef6cd272442b8a0b8bdac0daa6261aa6028e55d59164afb9a946067
  DOWNLOAD_NO_EXTRACT TRUE
  DOWNLOAD_DIR      "${OPENCV_DOWNLOAD_DIR}"
  SOURCE_DIR        "${OPENCV_DOWNLOAD_DIR}"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   7z x "<DOWNLOAD_DIR>/autoit-opencv-${OPENCV_VERSION}-com-v2.2.1.7z" -aoa "-o<DOWNLOAD_DIR>/autoit-opencv-com" -y
)

FetchContent_Populate(opencv)
FetchContent_Populate(opencv-patch)
FetchContent_Populate(dlib)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../examples/faces")
  execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${dlib_SOURCE_DIR}/examples/faces ${CMAKE_CURRENT_SOURCE_DIR}/../examples/faces)
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../examples/video_frames")
  execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${dlib_SOURCE_DIR}/examples/video_frames ${CMAKE_CURRENT_SOURCE_DIR}/../examples/video_frames)
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../examples/data")
  file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../examples/data")
endif()

get_filename_component(OpenCV_DIR "${opencv_SOURCE_DIR}/opencv-${OPENCV_VERSION}-vc14_vc15/opencv/build" REALPATH)
set(opencv_SOURCE_DIR "${opencv_SOURCE_DIR}/opencv-${OPENCV_VERSION}-vc14_vc15/opencv/sources")

get_filename_component(OpenCV_BINARY_DIR "${OpenCV_DIR}/x64/vc15/bin" REALPATH)
file(TO_NATIVE_PATH "${OpenCV_BINARY_DIR}" OpenCV_BINARY_DIR)

find_package(OpenCV REQUIRED)

execute_process(
  COMMAND node --unhandled-rejections=strict --trace-uncaught --trace-warnings src/gen.js --skip=vs
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
  COMMAND_ECHO STDERR
  COMMAND_ERROR_IS_FATAL ANY
)

add_subdirectory(${dlib_SOURCE_DIR}/dlib ${dlib_BINARY_DIR})
add_definitions(-DDLIB_VERSION=${DLIB_VERSION})
add_definitions(-DCVAPI_EXPORTS)

file(GLOB_RECURSE project_source_resources "src/*.rc" "src/*.rgs")
file(GLOB_RECURSE project_source_headers "src/*.h*")
file(GLOB_RECURSE project_sources_files "src/*.c" "src/*.cpp" "src/*.def")

file(GLOB_RECURSE project_generated_resources "generated/*.rc" "generated/*.rgs")
file(GLOB_RECURSE project_generated_headers "generated/*.h*")
file(GLOB_RECURSE project_generated_files "generated/*.cpp" "generated/*_i.c")

source_group("Source Resources" FILES ${project_source_resources})
source_group("Source Headers" FILES ${project_source_headers})
source_group("Source Files" FILES ${project_sources_files})

source_group("Generated Resources" FILES ${project_generated_resources})
source_group("Generated Headers" FILES ${project_generated_headers})
source_group("Generated Files" FILES ${project_generated_files})

set(SRC_FILES
  ${project_source_resources}
  ${project_source_headers}
  ${project_sources_files}

  ${project_generated_resources}
  ${project_generated_headers}
  ${project_generated_files}
)

# Build a shared library named as the project
add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
target_precompile_headers(${PROJECT_NAME} PRIVATE
  "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/generated/autoit_bridge_generated_pch.h>"
)

target_link_libraries(${PROJECT_NAME} PRIVATE dlib::dlib ${OpenCV_LIBS})

set(OpenCV_DLLVERSION "${OpenCV_VERSION_MAJOR}${OpenCV_VERSION_MINOR}${OpenCV_VERSION_PATCH}")
set(PROJECT_VERSION "${DLIB_VERSION}-${OpenCV_DLLVERSION}")
set(DEBUG_POSTFIX d)

set_target_properties(${PROJECT_NAME} PROPERTIES
  OUTPUT_NAME "${PROJECT_NAME}-${PROJECT_VERSION}"
  DEBUG_POSTFIX "${DEBUG_POSTFIX}"
  COMPILE_PDB_NAME "${PROJECT_NAME}-${PROJECT_VERSION}"
  COMPILE_PDB_NAME_DEBUG "${PROJECT_NAME}-${PROJECT_VERSION}${DEBUG_POSTFIX}"
  VS_DEBUGGER_ENVIRONMENT "PATH=${OpenCV_BINARY_DIR};%PATH%"
)

target_include_directories(${PROJECT_NAME} PUBLIC "src")
target_include_directories(${PROJECT_NAME} PUBLIC "generated")

# /Zc:__cplusplus is required to make __cplusplus accurate
# /Zc:__cplusplus is available starting with Visual Studio 2017 version 15.7
# (according to https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus)
# That version is equivalent to _MSC_VER==1914
# (according to https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=vs-2019)
# CMake's ${MSVC_VERSION} is equivalent to _MSC_VER
# (according to https://cmake.org/cmake/help/latest/variable/MSVC_VERSION.html#variable:MSVC_VERSION)
if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))
  target_compile_options(${PROJECT_NAME} PRIVATE "/Zc:__cplusplus")
  target_compile_options(${PROJECT_NAME} PRIVATE "/bigobj")
endif()

IF ((WIN32) AND CMAKE_GENERATOR STREQUAL Ninja)
  target_compile_options(${PROJECT_NAME} PRIVATE "/Zc:__cplusplus")
  target_compile_options(${PROJECT_NAME} PRIVATE "/bigobj")
  target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32)
  target_compile_definitions(${PROJECT_NAME} PRIVATE _WINDOWS)
  target_compile_definitions(${PROJECT_NAME} PRIVATE _WINDLL)
ENDIF()

# ===============
# cpp_test target
# ===============
file(GLOB test_files "test/*.h*" "test/*.cpp")

add_executable (cpp_test ${test_files})

target_precompile_headers(cpp_test PRIVATE
  "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/test/test.h>"
)
set_source_files_properties(test/test.cpp PROPERTIES COMPILE_FLAGS "/MP1")

target_link_libraries(cpp_test PRIVATE ${PROJECT_NAME} dlib::dlib ${OpenCV_LIBS})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT cpp_test)
set_property(TARGET cpp_test PROPERTY VS_DEBUGGER_ENVIRONMENT "PATH=${OpenCV_BINARY_DIR};%PATH%")

target_include_directories(cpp_test PRIVATE ${dlib_SOURCE_DIR}/tools)

# /Zc:__cplusplus is required to make __cplusplus accurate
# /Zc:__cplusplus is available starting with Visual Studio 2017 version 15.7
# (according to https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus)
# That version is equivalent to _MSC_VER==1914
# (according to https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=vs-2019)
# CMake's ${MSVC_VERSION} is equivalent to _MSC_VER
# (according to https://cmake.org/cmake/help/latest/variable/MSVC_VERSION.html#variable:MSVC_VERSION)
if ((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))
  target_compile_options(cpp_test PRIVATE "/Zc:__cplusplus")
endif()

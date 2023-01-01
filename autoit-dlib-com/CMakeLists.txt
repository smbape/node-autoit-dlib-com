cmake_minimum_required(VERSION 3.19)

# Name of the project (will be the name of the plugin)
project(autoit_dlib_com)

set(DEFAULT_BUILD_TYPE "Release")

if(NOT DEFINED CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build.")
endif()

# Set the possible values of build type for cmake-gui
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;MinSizeRel;RelWithDebInfo" CACHE STRING "Configs" FORCE)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${CMAKE_CONFIGURATION_TYPES}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(WIN32 AND MSVC)
  add_compile_options(/MP)
endif()

set(DLIB_VERSION 19.24 CACHE STRING "Choose the dlib version.")
set_property(CACHE DLIB_VERSION PROPERTY STRINGS "19.24" "19.23")

# Tell cmake that we will need dlib. These command will pull in dlib.
include(FetchContent)
FetchContent_Declare(dlib
  GIT_REPOSITORY https://github.com/davisking/dlib.git
  GIT_TAG        v${DLIB_VERSION}

  # PATCH_COMMAND is run once for each BUILD_TYPE
  # however, source download is only done once when it is a git repository
  # use a custom patch command to perform patch only once
  PATCH_COMMAND "${CMAKE_COMMAND}"
                  "-DGIT_EXECUTABLE=${GIT_EXECUTABLE}"
                  "-DPATCH_FILE=${CMAKE_CURRENT_SOURCE_DIR}/patches/001-dlib-src.patch"
                  -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/git_patch_once.cmake"
)
FetchContent_Populate(dlib)

# Tell cmake that we will need autoit-opencv-com.
set(opencv_com_VERSION 2.3.0)
include(ExternalProject)
ExternalProject_Add(autoit-opencv-com
  URL               https://github.com/smbape/node-autoit-opencv-com/releases/download/v${opencv_com_VERSION}/autoit-opencv-${OpenCV_VERSION}-com-v${opencv_com_VERSION}.7z
  URL_HASH          SHA256=cf297ba161c5c5536f604f02ca347828837b3631eef993082d301dde5ecc583d
  DOWNLOAD_NO_EXTRACT TRUE
  DOWNLOAD_DIR      "${OPENCV_DOWNLOAD_DIR}"
  SOURCE_DIR        "${OPENCV_DOWNLOAD_DIR}"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   7z x "<DOWNLOAD_DIR>/autoit-opencv-${OpenCV_VERSION}-com-v${opencv_com_VERSION}.7z" -aoa "-o<DOWNLOAD_DIR>/autoit-opencv-com" -y
)

include(cmake/RequireOpenCV.cmake)
include(cmake/vcpkg_regex_replace_string.cmake)

# update version in files
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/install.bat" "autoit_dlib_com-[0-9]+\\.[0-9]+-[0-9]+" "autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/install.bat" "opencv-[0-9]+\\.[0-9]+\\.[0-9]+-(vc14_vc15|windows)\\\\opencv\\\\build\\\\x64\\\\vc[^\\\\]*\\\\bin" "${OpenCV_RELATIVE_BINARY_DIR_ESC}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/src/dlibCOM.rc" "autoit_dlib_com-[0-9]+\\.[0-9]+-[0-9]+" "autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp" "autoit_dlib_com-[0-9]+\\.[0-9]+-[0-9]+" "autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/udf/dlib_udf.au3" "(opencv_world|opencv_videoio_ffmpeg)[0-9]+" "\\1${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/udf/dlib_udf.au3" "autoit_dlib_com-[0-9]+\\.[0-9]+-[0-9]+" "autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/udf/dlib_udf_utils.au3" "opencv-[0-9]+\\.[0-9]+\\.[0-9]+" "opencv-${OpenCV_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../scripts/build.js" "autoit_dlib_com-[0-9]+\\.[0-9]+-[0-9]+" "autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../scripts/build.js" "opencv-[0-9]+\\.[0-9]+\\.[0-9]+" "opencv-${OpenCV_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../scripts/build.js" "dlib-[0-9]+\\.[0-9]+" "dlib-${DLIB_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../src/gen.js" "opencv-[0-9]+\\.[0-9]+\\.[0-9]+" "opencv-${OpenCV_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../src/gen.js" "DLIB_VERSION = \"[0-9]+\\.[0-9]+\"" "DLIB_VERSION = \"${DLIB_VERSION}\"")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "autoit_dlib_com-[0-9]+\\.[0-9]+-[0-9]+" "autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "opencv-[0-9]+\\.[0-9]+\\.[0-9]+-(vc14_vc15|windows)\\.(exe|zip)" "${OpenCV_DOWNLOAD_NAME}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "opencv-[0-9]+\\.[0-9]+\\.[0-9]+-(vc14_vc15|windows)" "${OpenCV_OUTPUT_DIR}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "opencv-[0-9]+\\.[0-9]+\\.[0-9]+" "opencv-${OpenCV_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "dlib-[0-9]+\\.[0-9]+" "dlib-${DLIB_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "dlib-v[0-9]+\\.[0-9]+" "dlib-v${DLIB_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "/[0-9]+\\.[0-9]+\\.[0-9]+/" "${OpenCV_VERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "opencv_world[0-9]+" "opencv_world${OpenCV_DLLVERSION}")
vcpkg_regex_replace_string("${CMAKE_CURRENT_SOURCE_DIR}/../README.md" "(autoit-opencv-com/releases/download/|autoit-opencv-[0-9]+\\.[0-9]+\\.[0-9]+-com-)v[0-9]+\\.[0-9]+\\.[0-9]+" "\\1v${opencv_com_VERSION}")

file(GLOB_RECURSE files_to_change "../examples/*.au3" "../examples/*.cs" "../examples/*.ps1")
foreach(item ${files_to_change})
  vcpkg_regex_replace_string("${item}" "(opencv_world|autoit_dlib_com-\\*-)[0-9]+" "\\1${OpenCV_DLLVERSION}")
endforeach()

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin" CACHE PATH "Output directory for applications")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib" CACHE PATH "Output directory for libraries")

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../examples/faces")
  execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${dlib_SOURCE_DIR}/examples/faces ${CMAKE_CURRENT_SOURCE_DIR}/../examples/faces)
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../examples/video_frames")
  execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${dlib_SOURCE_DIR}/examples/video_frames ${CMAKE_CURRENT_SOURCE_DIR}/../examples/video_frames)
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../examples/data")
  file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../examples/data")
endif()

# generate source files
execute_process(
  COMMAND node --unhandled-rejections=strict --trace-uncaught --trace-warnings src/gen.js
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/.."
  COMMAND_ECHO STDERR
  COMMAND_ERROR_IS_FATAL ANY
)

# dlib subdirectory defines a patch version while git tag does not
# for consistency with code, keep the git tag version
set(DLIB_GIT_TAG "${DLIB_VERSION}")
add_subdirectory("${dlib_SOURCE_DIR}/dlib" "${dlib_BINARY_DIR}")
set(DLIB_VERSION "${DLIB_GIT_TAG}")

add_definitions(-DDLIB_VERSION=${DLIB_VERSION})
add_definitions(-DCVAPI_EXPORTS)

file(GLOB_RECURSE project_source_resources "src/*.rc" "src/*.rgs")
file(GLOB_RECURSE project_source_headers "src/*.h*")
file(GLOB_RECURSE project_sources_files "src/*.c" "src/*.cpp" "src/*.def")

file(GLOB_RECURSE project_generated_resources "generated/*.rc" "generated/*.rgs")
file(GLOB_RECURSE project_generated_headers "generated/*.h*")
file(GLOB_RECURSE project_generated_files "generated/*.cpp" "generated/*_i.c")

list(APPEND project_generated_resources "$<$<CONFIG:Debug>:${EXECUTABLE_OUTPUT_PATH}/Debug/autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}d.sxs.manifest>")
list(APPEND project_generated_resources "$<$<NOT:$<CONFIG:Debug>>:${EXECUTABLE_OUTPUT_PATH}/Release/autoit_dlib_com-${DLIB_VERSION}-${OpenCV_DLLVERSION}.sxs.manifest>")

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
target_compile_definitions(${PROJECT_NAME}
  PRIVATE ISOLATION_AWARE_ENABLED
  PRIVATE _WIN32_FUSION=0x0100
)

target_link_libraries(${PROJECT_NAME} PRIVATE dlib::dlib ${OpenCV_LIBS})

set(PROJECT_VERSION "${DLIB_VERSION}-${OpenCV_DLLVERSION}")

set_target_properties(${PROJECT_NAME} PROPERTIES
  OUTPUT_NAME "${PROJECT_NAME}-${PROJECT_VERSION}"
  DEBUG_POSTFIX "${OpenCV_DEBUG_POSTFIX}"
  COMPILE_PDB_NAME "${PROJECT_NAME}${OpenCV_DLLVERSION}"
  COMPILE_PDB_NAME_DEBUG "${PROJECT_NAME}${OpenCV_DLLVERSION}${OpenCV_DEBUG_POSTFIX}"
  ARCHIVE_OUTPUT_DIRECTORY "${LIBRARY_OUTPUT_PATH}"
  COMPILE_PDB_OUTPUT_DIRECTORY "${LIBRARY_OUTPUT_PATH}"
  LIBRARY_OUTPUT_DIRECTORY "${LIBRARY_OUTPUT_PATH}"
  RUNTIME_OUTPUT_DIRECTORY "${EXECUTABLE_OUTPUT_PATH}"
)

# Always generate debug files
if(MSVC AND NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/DEBUG")
endif()

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

IF ((WIN32) AND CMAKE_GENERATOR STREQUAL Ninja)
  target_compile_definitions(cpp_test PRIVATE WIN32)
  target_compile_definitions(cpp_test PRIVATE _WINDOWS)
ENDIF()

# Always generate debug files
if(MSVC AND NOT "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
  set_target_properties(cpp_test PROPERTIES LINK_FLAGS "/DEBUG")
endif()

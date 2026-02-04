cmake_minimum_required(VERSION 3.21)

# vcpkg integration - use if available
if(DEFINED ENV{VCPKG_ROOT})
    set(VCPKG_CMAKE_PATH $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE FILEPATH "Location of vcpkg.cmake")
    if(EXISTS ${VCPKG_CMAKE_PATH})
        include(${VCPKG_CMAKE_PATH})
    endif()
endif()

project(liboai)

find_package(ZLIB REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(CURL REQUIRED)

option(BUILD_EXAMPLES "Build example applications" OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(liboai)

if(BUILD_EXAMPLES)
    add_subdirectory(documentation)
endif()

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT oai)

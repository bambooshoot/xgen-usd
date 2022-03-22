# 3.13 for target_link_directories.
cmake_minimum_required(VERSION 3.13)

# Define project.
project(
    xGen
    VERSION 0.0.0
    DESCRIPTION "A collection of example plugins for Pixar's USD (Universal Scene Description)."
    LANGUAGES CXX
)

# Discover cmake modules.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/packages
)

if(WIN32)
    set(USD_ROOT D:/packages/usd/21.08/platform-windows)
    set(PYTHON_ROOT C:/Python27)
else()
    set(USD_ROOT /l/packages/pg/third_party/app/usd/20.11/platform-linux)
    set(PYTHON_ROOT /usr)
endif()

set(CMAKE_INSTALL_LIBDIR install)
set(CMAKE_INSTALL_DIR install)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "${CMAKE_INSTALL_PREFIX}")

set(USD_INCLUDE_DIR ${USD_ROOT}/include)
set(USD_LIBRARY_DIR ${USD_ROOT}/lib)

set(XGEN_COMPILE 0)
set(Boost_INCLUDE_DIR ${USD_ROOT}/include/boost-1_70)

if(WIN32)
    set(TBB_LIBRARIES ${USD_ROOT}/lib/tbb.lib)
    set(PYTHON_INCLUDE_DIR ${PYTHON_ROOT}/include)
    set(PYTHON_LIBRARIES ${PYTHON_ROOT}/libs/python27.lib)
else()
    set(TBB_LIBRARIES ${USD_ROOT}/lib/libtbb.so)
    set(PYTHON_INCLUDE_DIR ${PYTHON_ROOT}/include/python2.7)
    set(PYTHON_LIBRARIES ${PYTHON_ROOT}/lib64/libpython2.7.so)
endif()

set(TBB_INCLUDE_DIRS ${USD_ROOT}/include/tbb)
set(TBB_LIBRARY_DIR ${USD_ROOT}/lib)

# Exposes build options (with default values) for this project.
include(Options)

# Set project defaults.
include(Defaults)

# Import the package dependencies (USD, TBB, ...).
# include(Packages)

# Include USD plugin building CMake utilities.
include(USDPluginTools)

# Recurse into source tree.
add_subdirectory(pxr)

# Export targets and install package files.
# This must come after source tree recursion as exporting targets
# requires the targets to be defined in the first place!
# include(Export)

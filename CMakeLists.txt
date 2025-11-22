cmake_minimum_required(VERSION 3.10)

project(smart_ptr VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(smart_ptr INTERFACE)

# Set target properties for INTERFACE library
target_include_directories(smart_ptr INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install header files
install(FILES include/smart_ptr.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install the target
install(TARGETS smart_ptr
    EXPORT smart_ptrTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install the export targets
install(EXPORT smart_ptrTargets
    FILE smart_ptrTargets.cmake
    NAMESPACE smart_ptr::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/smart_ptr
)

# Create and install package config file
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/smart_ptrConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/smart_ptrConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/smart_ptr
    PATH_VARS
)

# Create and install version file
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/smart_ptrConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/smart_ptrConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/smart_ptrConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/smart_ptr
)

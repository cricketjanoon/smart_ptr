cmake_minimum_required(VERSION 3.10)

project(smart_ptr VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(smart_ptr INTERFACE)

install(TARGETS smart_ptr 
        EXPORT smart_ptrTargets 
        LIBRARY DESTINATION lib 
        ARCHIVE DESTINATION lib 
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/smart_ptrConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(EXPORT smart_ptrTargets FILE smart_ptrTargets.cmake 
        NAMESPACE smart_ptr:: DESTINATION lib/cmake/smart_ptr)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/smart_ptrConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/smart_ptrConfigVersion.cmake"
    DESTINATION lib/cmake/smart_ptr
)

# Add a test executable if the smart_ptr library is available
find_package(smart_ptr)
if(TARGET smart_ptr::smart_ptr)
    message(STATUS "smart_ptr library is available.")
    add_executable(test_smartptr test/test_main.cpp)
    target_link_libraries(test_smartptr PRIVATE smart_ptr::smart_ptr)
else()
    message(WARNING "smart_ptr library is not available. Test executable will not be built.")
endif()

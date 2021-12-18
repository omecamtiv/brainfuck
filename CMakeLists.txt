cmake_minimum_required(VERSION 3.5)

project(BrainFuck)

find_package(Boost REQUIRED COMPONENTS program_options filesystem)

set(bf_VERSION_MAJOR 1)
set(bf_VERSION_MINOR 0)
set(bf_VERSION_PATCH 0)
set(bf_VERSION "${bf_VERSION_MAJOR}.${bf_VERSION_MINOR}.${bf_VERSION_PATCH}")

configure_file(include/ver.hpp.in ${PROJECT_BINARY_DIR}/ver.h)

add_library(bfuck STATIC src/Interpreter.cpp)

target_include_directories(bfuck PUBLIC ${PROJECT_SOURCE_DIR}/include ${CMAKE_BINARY_DIR} ${Boost_INCLUDE_DIRS})

add_executable(brainfuck src/main.cpp)

target_link_libraries(brainfuck PRIVATE bfuck ${Boost_LIBRARIES})

install(TARGETS brainfuck DESTINATION bin)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A BrainFuck interpreter written in C++")
set(CPACK_PACKAGE_VENDOR "Omecamtiv")
set(CPACK_RESOURCE_FILE_README ${CMAKE_CURRENT_SOURCE_DIR}/README.md)
set(CPACK_PACKAGE_VERSION ${bf_VERSION})
set(CPACK_SOURCE_GENERATOR TGZ)
set(CPACK_SOURCE_IGNORE_FILES "/build/")

include(CPack)

# uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY
    )

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

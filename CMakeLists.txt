# Sets Minimum Allowed CMake Version 
cmake_minimum_required(VERSION 2.8)

# Project Name 
project(homework)
set(SOURCE_NAME "OSHomeworkSource")

# Sets Language to C++, Uses C++11
enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

# Release Build : Compiles Optimized Code
set(CMAKE_BUILD_TYPE Release)

# Adds Compile Warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wredundant-decls -Wcast-align -Wshadow")

# Will Include Files in Current Directory
set(hw_INCDIR ${CMAKE_CURRENT_SOURCE_DIR})
set(src_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE_NAME})

##################### 
## GOOGLETEST      ##
#####################
include(FetchContent)
if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.5)
    set(GTEST_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850)
else()
    set(GTEST_TAG e2239ee6043f73722e7aa812a459f54a28552929)
endif()
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  # Specify the commit you depend on and update it regularly.
  GIT_TAG ${GTEST_TAG} 
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
#####################

include_directories(${src_DIR})
include_directories(${hw_DIR})

# Add SRC Directory with Professor's Starter Code
add_subdirectory(${SOURCE_NAME})

# Create Library
# TODO : Include your new file here!
add_library(homework STATIC
    ${src_SOURCES}
    processes.cpp
    scheduler.cpp
    )

# Add Directory with Professor's Unit Tests
add_subdirectory(${SOURCE_NAME}/tests)

# Subdirectory with Example Programs
add_subdirectory(examples)

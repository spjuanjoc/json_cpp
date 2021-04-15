cmake_minimum_required(VERSION 3.19)
project(json_cpp)

add_executable(${PROJECT_NAME}
    src/main.cpp)

set(PROJECT_OPTIONS
    -O3
    -Wpedantic
    -Wall
    -Wextra
    -Werror
    )
target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
#target_include_directories(${PROJECT_NAME} PRIVATE include)

# -- Find third-party libs --
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)
#message(" - Conan libs: ${CONAN_LIBS}")
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)

if (fmt_FOUND)
  message("fmt found")
else()
  message("NOT found")
endif ()

target_link_libraries(${PROJECT_NAME}
    pthread
    fmt::fmt
    nlohmann_json::nlohmann_json
    )

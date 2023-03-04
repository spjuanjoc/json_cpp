cmake_minimum_required(VERSION 3.19)
project(json_cpp
  VERSION "0.1.0"
  DESCRIPTION "json c++ with nlohmann and fmt"
  LANGUAGES CXX
  )

set(PROJECT_OPTIONS
  -Wpedantic
  -Wall
  -Wextra
  -Werror
)

add_executable(${PROJECT_NAME} src/main.cpp)

target_compile_options(${PROJECT_NAME} INTERFACE ${PROJECT_OPTIONS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)


# -- Find third-party libs --
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})
find_package(fmt REQUIRED)
find_package(nlohmann_json REQUIRED)


target_link_libraries(${PROJECT_NAME}
  PRIVATE
    ${fmt_LIBRARIES}
    pthread
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    ${nlohmann_json_INCLUDE_DIRS}
)

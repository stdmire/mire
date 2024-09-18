cmake_minimum_required(VERSION 3.28)
project(mireExample LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

file(COPY assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
set_directory_properties(PROPERTIES COMPILE_DEFINITIONS ROOT_DIR=${CMAKE_CURRENT_BINARY_DIR}/)

file(COPY assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
file(GLOB SRC "*.cpp" "*.h")

add_executable(mireExample ${SRC})
target_compile_features(mireExample PRIVATE cxx_std_17)
target_link_libraries(mireExample PRIVATE mire)
target_link_libraries(mireExample PRIVATE mire)
include_directories(mireExample ../mire)

cmake_minimum_required(VERSION 3.28)
project(mireExample LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

file(COPY assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
set_directory_properties(PROPERTIES COMPILE_DEFINITIONS ROOT_DIR=${CMAKE_CURRENT_BINARY_DIR}/)
add_subdirectory(mire)

file(COPY assets/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets)
file(GLOB SRC "src/*.cpp" "src/*.h")

add_executable(mireExample ${SRC})
target_compile_features(mireExample PRIVATE cxx_std_17)
target_link_libraries(mireExample PRIVATE mire)
target_link_libraries(mireExample PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_ttf SDL2_image)
include_directories(mireExample mire vendor ${SDL_IMAGE_SOURCE_DIR}/include)

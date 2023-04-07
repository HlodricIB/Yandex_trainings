cmake_minimum_required(VERSION 3.5)

project(Stack_with_error_defence LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES ./src/main.cpp)

add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)

target_compile_options(${PROJECT_NAME} PUBLIC -g -O0 -Wall -Wextra)
target_link_options(${PROJECT_NAME} PUBLIC -dynamic)

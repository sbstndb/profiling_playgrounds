cmake_minimum_required(VERSION 3.19)

project(profiling_playgrounds)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=native -march=native -mavx2 -g -O3 -fno-inline")


add_executable(add src/main.cpp)


add_custom_target(
        perf
        COMMAND perf record -g ./add
        DEPENDS add
        COMMENT "Profiling with perf..."
)



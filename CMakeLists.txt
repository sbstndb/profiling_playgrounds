cmake_minimum_required(VERSION 3.19)

project(profiling_playgrounds)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=native -march=native -mavx2 -g -Ofast -fno-inline")


add_executable(add src/main.cpp)

set(KERNEL "/home/sbstndbs/profiling_playgrounds/build/add")


# perf scripts
add_subdirectory(profilers/perf)

# maqao scripts
add_subdirectory(profilers/maqao)



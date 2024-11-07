cmake_minimum_required(VERSION 3.19)

project(profiling_playgrounds)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mtune=native -march=native -mavx2 -g -O3 -fno-inline")


add_executable(add src/main.cpp)

# run simple perf profile


# from 
# https://www.brendangregg.com/perf.html
add_custom_target(
        perf
        COMMAND perf record -g ./add && perf report
        DEPENDS add
        COMMENT "Profiling with perf..."
)


# run perf only in compute function
add_custom_target(
	perf_compute
	COMMAND perf record
	DEPENDS add
	COMMENT "Profiling with perf..."
)

# get general profiling infos
add_custom_target(
        perf_stat
        COMMAND sudo perf stat -a ./add 
        DEPENDS add
        COMMENT "Profiling with perf..."
)



set(PERF_GENERAL "cycles,instructions")
set(PERF_CACHE "cache-references,cache-misses,bus-cycles")
set(PERF_L1 "L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores")
set(PERF_SYSCALL "raw_syscalls:sys_enter")

# get complete profiling infos
add_custom_target(
        perf_complete
	COMMAND sudo perf stat -e ${PERF_GENERAL},${PERF_CACHE},${PERF_L1},${PERF_SYSCALL} ./add
        DEPENDS add
        COMMENT "Profiling with perf..."
)








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

set(PERF_STAT_HW "branches,branch-misses,bus-cycles,cache-misses,cache-references,cpu-cycles,instructions,ref-cycles")

set(PERF_STAT_SW "alignment-faults,context-switches,cpu-clock,cpu-migrations" )

set(PERF_STAT_CACHE_L1 "L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores")
set(PERF_STAT_CACHE_LLC "LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses")
set(PERF_STAT_CACHE_BRANCH "branch-load,branch-load-misses")
set(PERF_STAT_CACHE ${PERF_STAT_CACHE_L1},${PERF_STAT_CACHE_LLC},${PERF_STAT_CACHE_BRANCH})

set(PERF_STAT_SYSCALL "raw_syscalls:sys_enter")

# get HW profiling infos
add_custom_target(
        perf_hw
	COMMAND sudo perf stat -e ${PERF_STAT_HW} ./add
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get SW profiling infos
add_custom_target(
        perf_sw
	COMMAND sudo perf stat -e ${PERF_STAT_SW} ./add
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get CACHE profiling infos
add_custom_target(
        perf_cache
	COMMAND sudo perf stat -e ${PERF_STAT_CACHE} ./add
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get SYSCALL profiling infos
add_custom_target(
        perf_syscall
	COMMAND sudo perf stat -e ${PERF_STAT_SYSCALL} ./add
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get complete profiling infos
add_custom_target(
        perf_complete
	COMMAND sudo perf stat -e ${PERF_STAT_HW},${PERF_STAT_SW},${PERF_STAT_CACHE},${PERF_STAT_SYSCALL} ./add
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# Usage: perf list [<options>] [hw|sw|cache|tracepoint|pmu|sdt|metric|metricgroup|event_glob]









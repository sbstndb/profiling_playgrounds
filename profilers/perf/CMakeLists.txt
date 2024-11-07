##############################################################
## VARIABLES 
##############################################################
set(PERF_STAT_HW "branches,branch-misses,bus-cycles,cache-misses,cache-references,cpu-cycles,instructions,ref-cycles")

set(PERF_STAT_SW "alignment-faults,context-switches,cpu-clock,cpu-migrations" )

set(PERF_STAT_CACHE_L1 "L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores")
set(PERF_STAT_CACHE_LLC "LLC-loads,LLC-load-misses,LLC-stores,LLC-store-misses")
set(PERF_STAT_CACHE_BRANCH "branch-load,branch-load-misses")
set(PERF_STAT_CACHE ${PERF_STAT_CACHE_L1},${PERF_STAT_CACHE_LLC},${PERF_STAT_CACHE_BRANCH})

set(PERF_STAT_SYSCALL "raw_syscalls:sys_enter")


################################################################
## MAKE COMMANDS
################################################################
# get HW profiling infos
add_custom_target(
        perf_hw
	COMMAND sudo perf stat -e ${PERF_STAT_HW} ${KERNEL}
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get SW profiling infos
add_custom_target(
        perf_sw
	COMMAND sudo perf stat -e ${PERF_STAT_SW} ${KERNEL}
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get CACHE profiling infos
add_custom_target(
        perf_cache
	COMMAND sudo perf stat -e ${PERF_STAT_CACHE} ${KERNEL}
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get SYSCALL profiling infos
add_custom_target(
        perf_syscall
	COMMAND sudo perf stat -e ${PERF_STAT_SYSCALL} ${KERNEL}
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# get complete profiling infos
add_custom_target(
        perf_complete
	COMMAND sudo perf stat -e ${PERF_STAT_HW},${PERF_STAT_SW},${PERF_STAT_CACHE},${PERF_STAT_SYSCALL} ${KERNEL}
        DEPENDS add
        COMMENT "Profiling with perf..."
)

# Usage: perf list [<options>] [hw|sw|cache|tracepoint|pmu|sdt|metric|metricgroup|event_glob]





# get record profiling 
add_custom_target(
        perf_record
	COMMAND sudo perf record -g ${KERNEL} && sudo perf report --stdio
        COMMENT "Profiling with perf..."
)




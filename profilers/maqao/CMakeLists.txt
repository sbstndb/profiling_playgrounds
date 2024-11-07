############ TO DELETE 
add_custom_target(
        cqa
	COMMAND maqao cqa ${KERNEL} fct-loops=compute_vector conf=all
	COMMENT "Analyzing with MAQAO..."
)

add_custom_target(
        cqa_html
        COMMAND maqao cqa ${KERNEL} fct-loops=compute_vector --output-format=html 
        COMMENT "Analyzing with MAQAO..."
)


add_custom_target(
        lprof
        COMMAND maqao lprof ${KERNEL}
        COMMENT "Analyzing with MAQAO..."
)

# not working for now ...
#add_custom_target(
#        lprof_show
#	COMMAND  maqao lprof -df xp=$(ls -td maqao_lprof_* | head -n 1)
#        COMMENT "Analyzing with MAQAO..."
#)


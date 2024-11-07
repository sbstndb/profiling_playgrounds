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


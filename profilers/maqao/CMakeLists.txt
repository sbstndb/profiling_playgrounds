############ TO DELETE 
add_custom_target(
        cqa
	COMMAND maqao cqa ${KERNEL} fct-loops=compute_vector conf=hint
	COMMENT "Analyzing with MAQAO..."
)

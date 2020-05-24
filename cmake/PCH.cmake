function(enable_PCH project_options)
	option(ENABLE_PCH 
		"Enable Precompiled Headers" 
		OFF)

	if(ENABLE_PCH)
		target_precompile_headers(project_options INTERFACE 
			<vector>
			<string>
			<utility>)
	endif()
endfunction()
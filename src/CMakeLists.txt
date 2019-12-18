add_llvm_library( libCSAnalysis MODULE
			    csanalysis.cpp
					utils.cpp
					DEPENDS
					PLUGIN_TOOL
					opt
)

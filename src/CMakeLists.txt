target_sources(ChokoBalls PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/chokoballs.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/world.cpp
)

add_subdirectory(types)
add_subdirectory(object)
add_subdirectory(backend/cpu)

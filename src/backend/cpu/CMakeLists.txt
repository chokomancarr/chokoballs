target_sources(ChokoBalls PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/backend_cpu.cpp
)

add_subdirectory(object)
add_subdirectory(collider)
add_subdirectory(collision)
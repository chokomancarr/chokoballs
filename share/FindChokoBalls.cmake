# This module defines
#   CB_LIBRARIES
#   CB_FOUND
#   CB_INCLUDE_DIRS

SET(CB_SEARCH_PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local
	/usr
	/sw # Fink
	/opt/local # DarwinPorts
	/opt/csw # Blastwave
	/opt
	${CB_PATH}
)

FIND_PATH(CB_INCLUDE_TEMP chokoballs.hpp
	HINTS
	$ENV{CBDIR}
	PATH_SUFFIXES include/cb include
	PATHS ${CB_SEARCH_PATHS}
)

FIND_LIBRARY(CB_LIBRARY_TEMP
	NAMES ChokoBalls
	HINTS
	$ENV{CBDIR}
	PATH_SUFFIXES lib64 lib
	PATHS ${CB_SEARCH_PATHS}
)

IF(CB_LIBRARY_TEMP)
	find_package(Threads REQUIRED)
	find_package(glm REQUIRED)

	if (MSVC)
		add_definitions(-DWIN32)
	elseif (LINUX)
		add_definitions()
	elseif (APPLE)
		add_definitions(-DCL_SILENCE_DEPRECATION)
	else()
		message(FATAL_ERROR "Platform not supported for ChokoBalls!")
	endif()

	SET(CB_INCLUDE_DIRS
		${CB_INCLUDE_TEMP}
		${GLM_INCLUDE_DIR}
	)

	IF(NOT APPLE)
		SET(CB_LIBRARY_TEMP
			${CB_LIBRARY_TEMP}
			${CMAKE_THREAD_LIBS_INIT}
			${GLEW_INCLUDE_DIR}
		)
	ENDIF(NOT APPLE)

	SET(CB_LIBRARIES
		${CB_LIBRARY_TEMP}
		${GLM_LIBRARY}
	)
	if(MSVC)
		set(CB_LIBRARIES
			${CB_LIBRARIES}
			-Profile
		)
	elseif(APPLE)
		set(CB_LIBRARIES
			${CB_LIBRARIES}
			pthread
		)
	else()
		set(CB_LIBRARIES
			${CB_LIBRARIES}
			pthread
			-Wl,-z,defs
		)
	endif()

	set(CB_INCLUDE_TEMP "${CB_INCLUDE_TEMP}" CACHE INTERNAL "")
	set(CB_INCLUDE_DIRS "${CB_INCLUDE_DIRS}" CACHE STRING "")
	set(CB_LIBRARY_TEMP "${CB_LIBRARY_TEMP}" CACHE INTERNAL "")
	set(CB_LIBRARIES "${CB_LIBRARIES}" CACHE STRING "")

ENDIF()

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(CB REQUIRED_VARS CB_LIBRARIES CB_INCLUDE_DIRS)


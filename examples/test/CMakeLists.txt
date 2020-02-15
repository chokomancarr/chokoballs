cmake_minimum_required(VERSION 3.3)
project (test_example)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
	"${CMAKE_SOURCE_DIR}/../../share/"
	"${CMAKE_SOURCE_DIR}/../../../share/"
)

find_package(ChokoBalls REQUIRED)
find_package(ChokoEngine REQUIRED)

if (MSVC)
	SET(CMAKE_CXX_FLAGS "/EHsc /W3")
else()
	SET(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wno-unknown-pragmas -Wno-sign-compare -Wno-unused-parameter -Wno-ignored-attributes")
	add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-std=c++1y> $<$<COMPILE_LANGUAGE:C>:-std=c99>)
if (LINUX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
else()
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")
endif()
endif()

include_directories(${CE2_INCLUDE_DIRS} ${CB_INCLUDE_DIRS})
add_executable(test_example main.cpp)
target_link_libraries(test_example ${CE2_LIBRARIES} ${CB_LIBRARIES})
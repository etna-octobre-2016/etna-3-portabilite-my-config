cmake_minimum_required(VERSION 3.5.2)
project(simplejson)

if(WIN32)

	set(LIB_TYPE STATIC)

else()

	set(LIB_TYPE SHARED)
	
endif()

add_library(
	${PROJECT_NAME}
	${LIB_TYPE}
	JSON.h
	JSONValue.h
	JSON.cpp
	JSONValue.cpp
)
cmake_minimum_required (VERSION 2.6) 

set (PROJECT fastbinaryformatter) 

project (${PROJECT}) 

set (HEADERS 
	src/fastbinaryformatter.hpp)

set (SOURCES 
	src/fastbinaryformatter.cpp) 
 
#add_library(${PROJECT} SHARED ${HEADERS} ${SOURCES})
add_library(${PROJECT} SHARED ${HEADERS} ${SOURCES})

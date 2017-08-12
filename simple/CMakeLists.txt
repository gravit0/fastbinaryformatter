cmake_minimum_required (VERSION 2.6) 

set (PROJECT fastbinaryformatter_simply) 

project (${PROJECT}) 

set (HEADERS 
	src/fastbinaryformatter.hpp)

set (SOURCES 
	src/main.cpp) 

add_executable(${PROJECT} ${HEADERS} ${SOURCES})
add_subdirectory(../lib lib)				# Добавление подпроекта, указывается имя дирректории
target_link_libraries(fastbinaryformatter_simply fastbinaryformatter)	

cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.

									
set(PROJECT_NAME tutorial)				 	 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)		
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_executable("${PROJECT_NAME}" var5_lab6.cpp 

)
																  
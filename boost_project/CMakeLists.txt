# CMakeList.txt : CMake project for boost_project, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


set(SDL2_DIR "C:/Users/PiVal/Workspace/BoostProjects/SDL2-2.0.9") # either set it here or from the command line  
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(BOOST_ROOT "C:/Users/PiVal/Workspace/BoostProjects/boost_1_66_0") # either set it here or from the command line  
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
include(FindBoost)
find_package(
    Boost 1.66
    REQUIRED
)
#find_package(Boost REQUIRED COMPONENTS system) # header only libraries must not be added here

# Add source to this project's executable.
add_executable (boostproject "boost_project.cpp" "boost_project.h" "graphic_engine.cpp" "graphic_engine.h")

target_include_directories(boostproject PUBLIC ${Boost_INCLUDE_DIRS}) 
target_link_libraries(boostproject ${Boost_LIBRARIES})
target_link_libraries(boostproject ${SDL2_LIBRARIES})
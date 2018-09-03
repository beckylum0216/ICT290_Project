cmake_minimum_required(VERSION 3.10)
project(CAMPUS_TOUR)
set(CMAKE_CXX_STANDARD 14)
#D:\Murdoch\ICT290\Tutorial1\CAMPUS TOUR\SDL2-devel-2.0.8-VC\SDL2-2.0.8\FindSDL2.cmake
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8)
set(GLUT_LIBRARIES ${CMAKE_CURRENT_LIST_DIR}/glut_bin/glut32.lib)
set(GLUT_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/glut_bin)
set(GLUT_glut_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/glut_bin/glut32.lib)
set(SDL2_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8/lib/x86/SDL2.lib)
#set(SDL2_LIBRARY_TEMP "D:/SDL2/SDL/lib")
set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8/include)
set(SDL2_SDLMAIN_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/SDL2-devel-2.0.8-VC/SDL2-2.0.8/lib/x86/SDL2main.lib)
#set(SDL2_DIR "D:/SDL2/SDL2-2.0.8")
FIND_PATH(GLUT_INCLUDE_DIR NAMES GL/freeglut.h)
include_directories(.)
include_directories(Debug)
include_directories(data)
include_directories(sounds)
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR})
add_executable(
		CAMPUS_TOUR
        Debug/houses.pch
        AABB.CPP
        AABB.H
        AABBLinkedList.cpp
        AABBLinkedList.h
        AABBNode.cpp
        AABBNode.h
        camera.cpp
        camera.h
        cameraMap.cpp
        cameraMap.h
        collision.cpp
        collision.h
        EasySound.cpp
        EasySound.h
        main.cpp
        PlainLinkedList.cpp
        PlainLinkedList.h
        PlainNode.cpp
        PlainNode.h
        Sound.cpp
        Sound.h
        SoundTime.cpp
        SoundTime.h
        texturedPolygons.cpp
        texturedPolygons.h
		Shay.h 
		Shay.cpp
		Model.h
		Model.cpp
		Texture.h
		Texture.cpp
		lodepng.h
		lodepng.cpp
		)

#find_file(SDL2_INCLUDE_DIR NAMES SDL.h HINTS SDL2)
#find_file(SDL2_LIBRARY NAMES SDL2.lib)
#find_library(SDL2_LIBRARY NAMES SDL2)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(SDL2 REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS}  ${SDL2_INCLUDE_DIR})
target_link_libraries(CAMPUS_TOUR ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${SDL2_LIBRARY} ${SDL2_SDLMAIN_LIBRARY})

install(TARGETS CAMPUS_TOUR DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin )
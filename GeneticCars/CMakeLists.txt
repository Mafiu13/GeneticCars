cmake_minimum_required(VERSION 2.8)

project(geneticcars)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

add_definitions(-DBOOST_ALL_NO_LIB)

#set(Boost_ROOT "/usr")
#set(Boost_INCLUDE_DIRS "${Boost_ROOT}/include")
#set(Boost_LIBRARY_DIRS "${Boost_ROOT}/lib")

find_package(Boost COMPONENTS
	system
	regex
        coroutine
        context
	thread
        chrono
	unit_test_framework
	REQUIRED
)

find_package(SFML COMPONENTS
	System
	Window
	Graphics
	REQUIRED
)

find_package(Box2D REQUIRED)

find_package(SFGUI REQUIRED)

#set(SFML_INCLUDE_DIRS ${SFML_INCLUDE_DIR})
#set(BOX2D_INCLUDE_DIRS ${BOX2D_INCLUDE_DIR})
include_directories(
	${Boost_INCLUDE_DIRS}
)

include_directories(
	${SFML_INCLUDE_DIR}
)

include_directories(
	${BOX2D_INCLUDE_DIR}
)

include_directories(
	${SFGUI_INCLUDE_DIR}
)

include_directories(
	include
)

add_library(geneticcars
	src/MainController.cpp
    src/PhysSimulation.cpp
    src/AppWindow.cpp
	src/BodyShape.cpp
	src/Car.cpp 
	src/Chromosome.cpp
	src/Drawing.cpp
	src/EvolutionaryService.cpp
	src/IndividualService.cpp
	src/PhysBodyShape.cpp
	src/PhysCar.cpp
	src/PhysElement.cpp
	src/PhysPopulation.cpp
	src/PhysTrack.cpp
	src/PhysWheel.cpp
	src/PopulationManager.cpp
	src/RandomService.cpp
	src/ShapePoint.cpp
	src/Wheel.cpp
)

target_link_libraries(
	geneticcars
	${Boost_LIBRARIES}
	${SFGUI_LIBRARY}
	${SFGUI_DEPENDENCIES}
	${SFML_LIBRARIES}
	${BOX2D_LIBRARIES}
	${SFML_DEPENDENCIES}
)

add_executable(program
	src/main.cpp
)

target_link_libraries(program
	geneticcars
)



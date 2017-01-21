cmake_minimum_required(VERSION 2.8)

project(geneticcars)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})



IF(MSVC)
#	set(BOOST_ROOT "C:/Boost")
ELSE()
#	set(BOOST_ROOT "/usr")
ENDIF()
#set(BOOST_ROOT "C:/Boost")
#set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include/boost-1_63")
#set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
set(Boost_ADDITIONAL_VERSIONS "1.63" "1.63.0")

add_definitions(-DBOOST_ALL_NO_LIB)

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

enable_testing()

add_subdirectory(test)


add_test ( NAME bodyshapetest COMMAND Test_BodyShape )
add_test ( NAME testcar COMMAND Test_Car )
add_test ( NAME testchromosome COMMAND Test_Chromosome )
add_test ( NAME testbodyshape COMMAND Test_PhysBodyShape )
add_test ( NAME testphyscar COMMAND Test_PhysCar )
add_test ( NAME testphyselement COMMAND Test_PhysElement )
add_test ( NAME testphyspopulation COMMAND Test_PhysPopulation )
add_test ( NAME testphyssimulation COMMAND Test_PhysSimulation )
add_test ( NAME testphystrack COMMAND Test_PhysTrack )
add_test ( NAME testphyswheel COMMAND Test_PhysWheel )
add_test ( NAME testshapepoint COMMAND Test_ShapePoint )
add_test ( NAME testwheel COMMAND Test_Wheel )

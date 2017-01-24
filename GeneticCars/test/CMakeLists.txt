add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (Test_AppWindow
  TestAppWindow.cpp
)

target_link_libraries (Test_AppWindow
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_BodyShape
  TestBodyShape.cpp
)

target_link_libraries (Test_BodyShape
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_Car
  TestCar.cpp
)

target_link_libraries (Test_Car
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_Chromosome
  TestChromosome.cpp
)

target_link_libraries (Test_Chromosome
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_Drawing
  TestDrawing.cpp
)

target_link_libraries (Test_Drawing
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_MainController
  TestMainController.cpp
)

target_link_libraries (Test_MainController
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_PhysBodyShape
  TestPhysBodyShape.cpp
)

target_link_libraries (Test_PhysBodyShape
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_PhysCar
  TestPhysCar.cpp
)

target_link_libraries (Test_PhysCar
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_PhysElement
  TestPhysElement.cpp
)

target_link_libraries (Test_PhysElement
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_PhysPopulation
  TestPhysPopulation.cpp
)

target_link_libraries (Test_PhysPopulation
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_PhysSimulation
  TestPhysSimulation.cpp
)

target_link_libraries (Test_PhysSimulation
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_PhysTrack
  TestPhysTrack.cpp
)

target_link_libraries (Test_PhysTrack
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_PhysWheel
  TestPhysWheel.cpp
)

target_link_libraries (Test_PhysWheel
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_ShapePoint
  TestShapePoint.cpp
)

target_link_libraries (Test_ShapePoint
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

add_executable (Test_Wheel
  TestWheel.cpp
)

target_link_libraries (Test_Wheel
  geneticcars
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

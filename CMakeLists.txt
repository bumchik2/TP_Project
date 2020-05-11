cmake_minimum_required(VERSION 2.8)


project(project)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

add_executable(main 
  src/main.cpp 
  src/ArmyFactory.cpp 
  src/Soldier.cpp 
  src/Units.cpp 
  src/Heroes.cpp
  src/Action.cpp
  src/Gameplay.cpp
  src/Army.cpp
  src/Observer.cpp
  src/Command.cpp
)

target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)

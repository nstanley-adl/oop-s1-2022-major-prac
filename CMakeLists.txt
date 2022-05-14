cmake_minimum_required(VERSION 3.16)
project(oop_s1_2022_major_prac)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_s1_2022_major_prac main.cpp BaseApplication.cpp BaseApplication.h AppState.cpp AppState.h Game.cpp Game.h  EntityRenderer.cpp EntityRenderer.h Entity.cpp Entity.h GreenCircleEntity.cpp GreenCircleEntity.h TestAppState.cpp TestAppState.h GameConstants.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(oop_s1_2022_major_prac sfml-system sfml-window sfml-graphics sfml-audio)



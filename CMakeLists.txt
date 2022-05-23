cmake_minimum_required(VERSION 3.16)
project(oop_s1_2022_major_prac)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop_s1_2022_major_prac main.cpp util/GentleAssert.h engine/BaseApplication.cpp engine/BaseApplication.h appstates/AppState.cpp appstates/AppState.h engine/Game.cpp engine/Game.h engine/EntityRenderer.cpp engine/EntityRenderer.h entities/Entity.cpp entities/Entity.h entities/PlayerEntity.cpp entities/PlayerEntity.h appstates/GamePlayAppState.cpp appstates/GamePlayAppState.h engine/GameConstants.h entities/DamageableEntity.cpp entities/DamageableEntity.h entities/TileEntity.cpp entities/TileEntity.h util/TileMapLevel.cpp util/TileMapLevel.h appstates/TitleScreenAppState.cpp appstates/TitleScreenAppState.h entities/ScreenLabelEntity.cpp entities/ScreenLabelEntity.h appstates/EndScreenAppState.h appstates/EndScreenAppState.cpp entities/EntityHealthBar.cpp entities/EntityHealthBar.h entities/Monster.cpp entities/Monster.h entities/BulletStream.cpp entities/BulletStream.h entities/AmmoLabel.cpp entities/AmmoLabel.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(oop_s1_2022_major_prac sfml-system sfml-window sfml-graphics sfml-audio)



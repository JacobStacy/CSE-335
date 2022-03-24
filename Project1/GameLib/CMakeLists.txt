project(GameLib)

set(SOURCE_FILES GameView.cpp GameView.h MainFrame.cpp MainFrame.h
        pch.h ids.h Item.h ItemBackground.h ItemBackground.cpp Item.cpp Game.cpp Game.h SpartyGnome.cpp SpartyGnome.h Platform.cpp Platform.h Money.cpp Money.h ItemVisitor.cpp ItemVisitor.h Vector.cpp Vector.h Villain.cpp Villain.h Food.cpp Food.h Wall.cpp Wall.h Stanley.cpp Stanley.h Scoreboard.cpp Scoreboard.h Level.cpp Level.h Clock.cpp Clock.h Door.cpp Door.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)

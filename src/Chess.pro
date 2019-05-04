TEMPLATE = app
TARGET = Chess

QT = core gui

CONFIG += static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES     = GuiGame\main.cpp \
    GuiGame/GameTab.cpp \
    GuiGame/ControlsWidget.cpp \
    GameBase/figures/Bishop.cpp \
    GameBase/figures/King.cpp \
    GameBase/figures/Knight.cpp \
    GameBase/figures/Pawn.cpp \
    GameBase/figures/Queen.cpp \
    GameBase/figures/Rook.cpp \
    GameBase/Enums.cpp \
    GameBase/FigureBase.cpp \
    GameBase/FigureFactory.cpp \
    GameBase/Game.cpp \
    GameBase/Move.cpp \
    GameBase/Position.cpp \
    GuiGame/ChessBoardWidget.cpp

HEADERS += \
    GuiGame/GameTab.h \
    GuiGame/ControlsWidget.h \
    GameBase/figures/Bishop.h \
    GameBase/figures/King.h \
    GameBase/figures/Knight.h \
    GameBase/figures/Pawn.h \
    GameBase/figures/Queen.h \
    GameBase/figures/Rook.h \
    GameBase/ClassDeclarations.h \
    GameBase/Enums.h \
    GameBase/FigureBase.h \
    GameBase/FigureFactory.h \
    GameBase/Game.h \
    GameBase/Language.h \
    GameBase/Move.h \
    GameBase/Position.h \
    GuiGame/ChessBoardWidget.h

RESOURCES += \
    GuiGame/images.qrc

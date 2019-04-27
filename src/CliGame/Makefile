CC=g++
CFLAGS=-ggdb -Wall
SRCDIR = ../                             
OBJDIR = build/obj
BUILDDIR = build

GAMEBASE = ../GameBase
GAMEBASE_FIGURES = $(GAMEBASE)/figures

ALL_OBJ = $(OBJDIR)/FigureBase.o $(OBJDIR)/FigureFactory.o $(OBJDIR)/Game.o $(OBJDIR)/Move.o $(OBJDIR)/Position.o  $(OBJDIR)/Enums.o
ALL_OBJ+= $(OBJDIR)/Bishop.o $(OBJDIR)/King.o $(OBJDIR)/Knight.o $(OBJDIR)/Pawn.o $(OBJDIR)/Queen.o $(OBJDIR)/Rook.o
ALL_OBJ+= $(OBJDIR)/main.o

TARGETS = $(BUILDDIR)/main.out

all: $(TARGETS)

$(OBJDIR)/FigureBase.o: $(GAMEBASE)/FigureBase.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/FigureFactory.o: $(GAMEBASE)/FigureFactory.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Game.o: $(GAMEBASE)/Game.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Move.o: $(GAMEBASE)/Move.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Position.o: $(GAMEBASE)/Position.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Enums.o: $(GAMEBASE)/Enums.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJDIR)/main.o: main.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJDIR)/Bishop.o: $(GAMEBASE_FIGURES)/Bishop.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/King.o: $(GAMEBASE_FIGURES)/King.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Knight.o: $(GAMEBASE_FIGURES)/Knight.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Pawn.o: $(GAMEBASE_FIGURES)/Pawn.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Queen.o: $(GAMEBASE_FIGURES)/Queen.cpp
	$(CC) -c $< -o $@ $(CFLAGS)
$(OBJDIR)/Rook.o: $(GAMEBASE_FIGURES)/Rook.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

$(BUILDDIR)/main.out: $(ALL_OBJ)
	$(CC) $^ -o $@



$(OBJDIR)/main.o: main.cpp ../GameBase/Move.h ../GameBase/ClassDeclarations.h \
 ../GameBase/Enums.h ../GameBase/Position.h ../GameBase/FigureBase.h \
 ../GameBase/Move.h ../GameBase/Game.h ../GameBase/FigureFactory.h

$(OBJDIR)/Bishop.o: ../GameBase/figures/Bishop.cpp ../GameBase/figures/Bishop.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../ClassDeclarations.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../Position.h \
 ../GameBase/figures/../Move.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../Game.h ../GameBase/figures/../FigureFactory.h \
 ../GameBase/figures/../Move.h
$(OBJDIR)/King.o: ../GameBase/figures/King.cpp ../GameBase/figures/King.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../ClassDeclarations.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../Position.h \
 ../GameBase/figures/../Move.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../Game.h ../GameBase/figures/../FigureFactory.h \
 ../GameBase/figures/../Move.h
$(OBJDIR)/Knight.o: ../GameBase/figures/Knight.cpp ../GameBase/figures/Knight.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../ClassDeclarations.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../Position.h \
 ../GameBase/figures/../Move.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../Game.h ../GameBase/figures/../FigureFactory.h \
 ../GameBase/figures/../Move.h
$(OBJDIR)/Pawn.o: ../GameBase/figures/Pawn.cpp ../GameBase/figures/Pawn.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../ClassDeclarations.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../Position.h \
 ../GameBase/figures/../Move.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../Game.h ../GameBase/figures/../FigureFactory.h \
 ../GameBase/figures/../Move.h
$(OBJDIR)/Queen.o: ../GameBase/figures/Queen.cpp ../GameBase/figures/Queen.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../ClassDeclarations.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../Position.h \
 ../GameBase/figures/../Move.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../Game.h ../GameBase/figures/../FigureFactory.h \
 ../GameBase/figures/../Move.h
$(OBJDIR)/Rook.o: ../GameBase/figures/Rook.cpp ../GameBase/figures/Rook.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../ClassDeclarations.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../Position.h \
 ../GameBase/figures/../Move.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../Game.h ../GameBase/figures/../FigureFactory.h \
 ../GameBase/figures/../Move.h
$(OBJDIR)/Enums.o: ../GameBase/Enums.h
$(OBJDIR)/FigureBase.o: ../GameBase/FigureBase.cpp ../GameBase/FigureBase.h \
 ../GameBase/ClassDeclarations.h ../GameBase/Enums.h \
 ../GameBase/Position.h ../GameBase/Move.h ../GameBase/Game.h \
 ../GameBase/FigureFactory.h
$(OBJDIR)/FigureFactory.o: ../GameBase/FigureFactory.cpp \
 ../GameBase/FigureFactory.h ../GameBase/ClassDeclarations.h \
 ../GameBase/Enums.h ../GameBase/FigureBase.h ../GameBase/Position.h \
 ../GameBase/Move.h ../GameBase/Game.h ../GameBase/figures/Bishop.h \
 ../GameBase/figures/../Enums.h ../GameBase/figures/../FigureBase.h \
 ../GameBase/figures/../Move.h ../GameBase/figures/King.h \
 ../GameBase/figures/Knight.h ../GameBase/figures/Pawn.h \
 ../GameBase/figures/Queen.h ../GameBase/figures/Rook.h
$(OBJDIR)/Game.o: ../GameBase/Game.cpp ../GameBase/Game.h \
 ../GameBase/ClassDeclarations.h ../GameBase/Enums.h ../GameBase/Move.h \
 ../GameBase/Position.h ../GameBase/FigureBase.h \
 ../GameBase/FigureFactory.h
$(OBJDIR)/Move.o: ../GameBase/Move.cpp ../GameBase/Move.h \
 ../GameBase/ClassDeclarations.h ../GameBase/Enums.h \
 ../GameBase/Position.h ../GameBase/FigureBase.h ../GameBase/Game.h \
 ../GameBase/FigureFactory.h
$(OBJDIR)/Position.o: ../GameBase/Position.cpp ../GameBase/Position.h
$(OBJDIR)/Enums.o: ../GameBase/Enums.cpp ../GameBase/Enums.h




clear:
	rm -rf $(TARGETS) $(ALL_OBJ)
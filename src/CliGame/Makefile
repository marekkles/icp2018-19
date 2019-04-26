CC=g++
CFLAGS=
SRCDIR = ../                                       
OBJDIR = build/obj
BUILDDIR = build

GAMEBASE = ../GameBase
GAMEBASE_FIGURES = $(GAMEBASE)/figures

ALL_OBJ = $(OBJDIR)/FigureBase.o $(OBJDIR)/FigureFactory.o $(OBJDIR)/Game.o $(OBJDIR)/Move.o $(OBJDIR)/Position.o
ALL_OBJ+= $(OBJDIR)/Bishop.o $(OBJDIR)/King.o $(OBJDIR)/Knight.o $(OBJDIR)/Pawn.o $(OBJDIR)/Queen.o $(OBJDIR)/Rook.o
ALL_OBJ+= $(OBJDIR)/main.o

TARGETS = $(BUILDDIR)/main.out

all: $(TARGETS)

$(OBJDIR)/FigureBase.o: $(GAMEBASE)/FigureBase.cpp
	$(CC) -c $< -o $@ 
$(OBJDIR)/FigureFactory.o: $(GAMEBASE)/FigureFactory.cpp
	$(CC) -c $< -o $@ 
$(OBJDIR)/Game.o: $(GAMEBASE)/Game.cpp
	$(CC) -c $< -o $@
$(OBJDIR)/Move.o: $(GAMEBASE)/Move.cpp
	$(CC) -c $< -o $@
$(OBJDIR)/Position.o: $(GAMEBASE)/Position.cpp
	$(CC) -c $< -o $@ 

$(OBJDIR)/main.o: main.cpp
	$(CC) -c $< -o $@ 

$(OBJDIR)/Bishop.o: $(GAMEBASE_FIGURES)/Bishop.cpp
	$(CC) -c $< -o $@ 
$(OBJDIR)/King.o: $(GAMEBASE_FIGURES)/King.cpp
	$(CC) -c $< -o $@
	$(CC) -c $< -o $@ 
$(OBJDIR)/Knight.o: $(GAMEBASE_FIGURES)/Knight.cpp
	$(CC) -c $< -o $@
	$(CC) -c $< -o $@ 
$(OBJDIR)/Pawn.o: $(GAMEBASE_FIGURES)/Pawn.cpp
	$(CC) -c $< -o $@
	$(CC) -c $< -o $@ 
$(OBJDIR)/Queen.o: $(GAMEBASE_FIGURES)/Queen.cpp
	$(CC) -c $< -o $@
	$(CC) -c $< -o $@ 
$(OBJDIR)/Rook.o: $(GAMEBASE_FIGURES)/Rook.cpp
	$(CC) -c $< -o $@

$(BUILDDIR)/main.out: $(ALL_OBJ)
	$(CC) $^ -o $@

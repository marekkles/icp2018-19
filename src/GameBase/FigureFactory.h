#ifndef __FIGURE_FACTORY_H

#define __FIGURE_FACTORY_H
#include <list>

#include "ClassDeclarations.h"
#include "Enums.h"
#include "FigureBase.h"
#include "Game.h"

class Game;

class FigureFactory {
private:
public:
	std::list<FigureBase *> Figures;
    FigureBase * CreateFigure(FigureType_t type, FigureColor_t color, Position & initialPosition, Game * game);
	FigureBase * FigureAtPosition(Position & position);
	FigureBase * GetKing(FigureColor_t color);
	void TakeFigure(FigureBase * figure, int turnNumber);
	void UnTakeFigure(Position & wasAt, int turnNumber);
	FigureType_t FigureTypeAtPosition(Position & position);
	FigureColor_t FigureColorAtPosition(Position & position);
	void DeleteFigure(FigureBase * figure);
	FigureBase * ChangeFigureTo(FigureBase * figure, FigureType_t figureType);
	FigureFactory() = default;
	~FigureFactory();
};


#endif
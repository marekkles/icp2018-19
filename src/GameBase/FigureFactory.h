#ifndef __FIGURE_FACTORY_H

#define __FIGURE_FACTORY_H
#include <vector>

#include "FigureBase.h"
#include "Game.h"

class FigureFactory {
private:
	Game * _game;
public:
	std::vector<FigureBase> Figures;
    void CreateFigure(FigureType_t type, FigureColor_t color, Position & initialPosition, Game * game);
	FigureBase & FigureAtPosition(Position & position);
	FigureBase & GetKing(FigureColor_t color);
	FigureType_t FigureTypeAtPosition(Position & position);
	FigureColor_t FigureColorAtPosition(Position & position);
	void DeleteFigure(FigureBase & figure);
	FigureFactory();
	FigureFactory(Game * game);
	~FigureFactory();
};


#endif
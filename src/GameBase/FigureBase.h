#ifndef __FIGURE_BASE_H

#define __FIGURE_BASE_H

#include "Game.h"
#include "Move.h"
#include "Position.h"

typedef enum {NONE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN} FigureType_t;
typedef enum {WHITE, BLACK, NO_COLOR} FigureColor_t;

FigureType_t FigureCharToFigureType(const char figureChar);

class FigureBase
{
public:
	bool InGame;
	explicit FigureBase(FigureType_t figureType, FigureColor_t figureColor, Position & initialPosition, Game * game);
	~FigureBase();
	FigureType_t GetType();
	Position & GetPosition();
	FigureColor_t GetColor();
	FigureColor_t GetOpositeColor();
	void ForceMove(Move & move);
	bool TryMove(Move & move);
	bool operator==(FigureBase & op1);
	virtual bool VerifyMove(Move & move) = 0; 
protected:
	Game * _game;
	Position _position;
	FigureType_t _type;
	FigureColor_t _color;
	void MoveTo(Position & position);
};

#endif
#ifndef __FIGURE_BASE_H

#define __FIGURE_BASE_H

#include "ClassDeclarations.h"
#include "Enums.h"
#include "Position.h"
#include "Move.h"
#include "Game.h"



FigureType_t FigureCharToFigureType(const char figureChar);

class FigureBase
{
public:
	bool InGame;
	explicit FigureBase(FigureType_t figureType, FigureColor_t figureColor, Position & initialPosition, Game * game);
	~FigureBase() = default;
	void SetPosition(const Position & position);
	FigureType_t GetType() const;
	const Position & GetPosition() const;
	FigureColor_t GetColor() const;
	FigureColor_t GetOpositeColor() const;
	Game * GetGame() const;
	void ForceMove(Move & move);
	void ForceMove(Position & to);
	bool TryMove(Move & move);
	bool operator==(const FigureBase & op1) const;
	virtual bool VerifyMove(Move & move) = 0;
	virtual void LoadValidMoves() = 0; 
protected:
	Game * _game;
	Position _position;
	FigureType_t _type;
	FigureColor_t _color;
	void MoveTo(Position & position);
};

#endif
#ifndef __FIGURE_BASE_H

#define __FIGURE_BASE_H

#include "Move.h"
#include "Position.h"

typedef enum {NONE, KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN} FigureType_t;
typedef enum {WHITE, BLACK} FigureColor_t;
typedef enum {IN_GAME, TAKEN} FigureState_t;

class FigureBase
{
public:
	FigureBase();
	~FigureBase();
	FigureType_t GetType();
	Position * GetPosition();
	FigureColor_t GetColor();
	FigureState_t GetState();
	bool TryMove(Move * move);
	virtual bool VerifyMove(Move * move) = 0; 
private:
	FigureType_t _type;
	Position * _position;
	FigureColor_t _color;
	FigureState_t _inGame;
	void MoveTo(Position * position);
};

#endif
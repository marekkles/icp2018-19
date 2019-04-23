#ifndef __BISHOP_H

#define __BISHOP_H

#include "../FigureBase.h"
#include "../Move.h"

class Bishop : public FigureBase
{
public:
    Bishop(FigureColor_t color, Position * position);
    virtual bool VerifyMove(Move * move); 
	virtual ~Bishop() = default;
};


#endif
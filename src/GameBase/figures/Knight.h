#ifndef __KNIGHT_H

#define __KNIGHT_H
#include "../FigureBase.h"

#include "../FigureBase.h"
#include "../Move.h"

class Knight : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move); 
	virtual ~Knight() = default;
};

#endif
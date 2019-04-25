#ifndef __KING_H

#define __KING_H

#include "../FigureBase.h"
#include "../Move.h"

class King : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move); 
	virtual ~King() = default;
};

#endif
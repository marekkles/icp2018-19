#ifndef __BISHOP_H

#define __BISHOP_H

#include "../FigureBase.h"
#include "../Move.h"

class Bishop : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move); 
	virtual ~Bishop() = default;
};


#endif
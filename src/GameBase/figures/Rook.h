#ifndef __ROOK_H

#define __ROOK_H

#include "../Enums.h"
#include "../FigureBase.h"
#include "../Move.h"

class Rook : public FigureBase
{
public:
    using FigureBase::FigureBase;
    virtual bool VerifyMove(Move & move); 
	virtual ~Rook() = default;
};

#endif
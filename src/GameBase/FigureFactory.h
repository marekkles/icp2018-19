#ifndef __FIGURE_FACTORY_H

#define __FIGURE_FACTORY_H

#include "figures/Bishop.h"
#include "figures/King.h"
#include "figures/Knight.h"
#include "figures/Pawn.h"
#include "figures/Queen.h"
#include "figures/Rook.h"

#include "FigureBase.h"

class FigureFactory {
protected:
public:
	
    virtual FigureBase* CreateFigure(FigureType_t type);
	
	virtual void FreeFigure(FigureBase *figure);
	
	FigureFactory();
	
	virtual ~FigureFactory();
};


#endif
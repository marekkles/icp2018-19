#ifndef __MOVE_H

#define __MOVE_H

#include <string>
#include "Position.h"
#include "FigureBase.h"

class Move
{
public:
    Move(std::string * inputMove);
    ~Move();
    FigureType_t FigureType;
    Position * From;
    Position * To;
};


#endif
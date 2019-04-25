#ifndef __MOVE_H

#define __MOVE_H

#include <string>
#include "Position.h"
#include "FigureBase.h"

class Move
{
public:
    Move(FigureType_t figureType, Position & to);
    Move(std::string & inputMove);
    ~Move();
    FigureType_t FigureType;
    FigureType_t ChangeTo;
    Position From;
    Position To;
    bool ValidMove;
    bool UseFrom;
    bool Checkmate;
    bool Check;
    bool Take;
};


#endif
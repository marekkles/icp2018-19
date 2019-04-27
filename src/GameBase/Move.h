#ifndef __MOVE_H

#define __MOVE_H

#include <string>
#include <iostream>
#include <fstream>

#include "ClassDeclarations.h"
#include "Enums.h"
#include "Position.h"
#include "FigureBase.h"

class Move
{
public:
    void SaveMove(std::ostream & outputFile);
    Move() = default;
    Move(FigureType_t figureType, const Position & to);
    Move(std::string & inputMove);
    ~Move() = default;
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
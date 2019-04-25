#include "FigureBase.h"

FigureType_t FigureCharToFigureType(const char figureChar)
{
    switch (figureChar)
    {
    case 'K':
        return KING;
        break;
    case 'D':
        return QUEEN;
        break;
    case 'V':
        return ROOK;
        break;
    case 'S':
        return BISHOP;
        break;
    case 'J':
        return KNIGHT;
        break;
    case 'p':
        return PAWN;
        break;
    default:
        return NONE;
        break;
    }
}

FigureBase::FigureBase(FigureType_t figureType, FigureColor_t figureColor, Position & initialPosition, Game * game)
{
    this->InGame = true;
    this->_game = game;
    this->_color = figureColor;
    this->_position = Position(initialPosition);
    this->_type = figureType;
}

FigureType_t FigureBase::GetType()
{
    return this->_type;
}

Position & FigureBase::GetPosition()
{
    return this->_position;
}

FigureColor_t FigureBase::GetColor()
{
    return this->_color;
}

FigureColor_t FigureBase::GetOpositeColor()
{
    return (this->_color == WHITE)?BLACK:WHITE;
}

void FigureBase::ForceMove(Move & move)
{
    _position.Update(move.To);
}

bool FigureBase::TryMove(Move & move)
{
    if(this->VerifyMove(move))
    {
        this->MoveTo(move.To);
        return true;
    }
    else
    {
        return false;
    }
    
}

bool FigureBase::operator==(FigureBase & op1)
{
    return this->_color == op1.GetColor && this->_position == op1.GetPosition && this->_type == op1.GetType;
}

void FigureBase::MoveTo(Position & position)
{
    this->_position.Update(position);
}
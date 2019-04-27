#include "FigureBase.h"

FigureBase::FigureBase(FigureType_t figureType, FigureColor_t figureColor, Position & initialPosition, Game * game)
{
    this->TakenAtTurnNumber = 0;
    this->_game = game;
    this->_color = figureColor;
    this->_position = Position(initialPosition);
    this->_type = figureType;
}

void FigureBase::SetPosition(const Position & position)
{
    _position.Update(position);
}

FigureType_t FigureBase::GetType() const
{
    return this->_type;
}

const Position & FigureBase::GetPosition() const
{
    return this->_position;
}

FigureColor_t FigureBase::GetColor() const
{
    return this->_color;
}

FigureColor_t FigureBase::GetOpositeColor() const
{
    return (this->_color == WHITE)?BLACK:WHITE;
}
Game * FigureBase::GetGame() const
{
    return _game;
}

void FigureBase::ForceMove(Move & move)
{
    _position.Update(move.To);
}

void FigureBase::ForceMove(Position & to)
{
    _position.Update(to);
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

bool FigureBase::operator==(const FigureBase & op1) const
{
    return this->_color == op1.GetColor() && this->_position == op1.GetPosition() && this->_type == op1.GetType();
}

void FigureBase::MoveTo(Position & position)
{
    this->_position.Update(position);
}
#include "Pawn.h"
#include <stdlib.h>

bool Pawn::VerifyMove(Move & move)
{
    _game->BitfieldSet(this);
    if(
        !move.ValidMove ||
        !_game->BitfieldGet(move.To) ||
        move.FigureType != _type ||
        (move.UseFrom && move.From != _position) ||
        (move.Take && _game->GetFigureAt(move.To) == NULL)
        )
        return false;
    return true;
}

void Pawn::LoadValidMoves()
{
    _game->BitfieldClear();
    int directionSign = (_color == WHITE)?1:-1;
    int startingRow = (_color == WHITE)?2:7;
    Position positionToTest = Position(_position);
    positionToTest.Row += directionSign;
    if(_game->GetFigureColorAt(positionToTest) != NO_COLOR)
    {
        positionToTest.Coulumn++;
        if(_game->GetFigureColorAt(positionToTest) == GetOpositeColor())
            _game->BitfieldSet(positionToTest);
        positionToTest.Coulumn -= 2;
        if(_game->GetFigureColorAt(positionToTest) == GetOpositeColor())
            _game->BitfieldSet(positionToTest);
    }
    else
    {
        _game->BitfieldSet(positionToTest);
        positionToTest.Row += directionSign;
        if(_game->GetFigureColorAt(positionToTest) == NO_COLOR && _position.Row == startingRow)
            _game->BitfieldSet(positionToTest);
    }
}
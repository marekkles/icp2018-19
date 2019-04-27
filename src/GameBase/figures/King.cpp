#include "King.h"

#include <iostream>
#include <stdlib.h>

bool King::VerifyMove(Move & move)
{
    _game->BitfieldSet(this);
    if(
        !move.ValidMove ||
        !_game->BitfieldGet(move.To) ||
        move.ChangeTo ||
        move.FigureType != _type ||
        (move.UseFrom && move.From != _position) ||
        (move.Take && _game->GetFigureAt(move.To) == NULL)
        )
        return false;
    return true;
}

void King::LoadValidMoves(bool writeOver)
{
    if(writeOver)
        _game->BitfieldClear();
    Position positionToTest = Position(_position);
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            positionToTest.Row = _position.Row + i;
            positionToTest.Coulumn = _position.Coulumn + j;
            if(positionToTest != _position && _game->GetFigureColorAt(positionToTest) != _color)
                _game->BitfieldSet(positionToTest);
        }
    }
}
#include "Knight.h"
#include <stdlib.h>

bool Knight::VerifyMove(Move & move)
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

void Knight::LoadValidMoves()
{
    _game->BitfieldClear();
    int positionsToTest[2][8] ={
        {1 , -1, 2,  2, -1,  1, -2, -2},
        {2 ,  2, 1, -1, -2, -2, -1,  1}
    };
    Position positionToTest = Position(_position);
    for (size_t i = 0; i < sizeof(positionsToTest)/2/sizeof(int); i++)
    {
        positionToTest.Coulumn = _position.Coulumn + positionsToTest[0][i];
        positionToTest.Row = _position.Row + positionsToTest[1][i];
        if(_game->GetFigureColorAt(positionToTest) != _color)
            _game->BitfieldSet(positionToTest);
    }
}
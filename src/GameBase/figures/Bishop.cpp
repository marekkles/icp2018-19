#include "Bishop.h"
#include <stdlib.h> 

bool Bishop::VerifyMove(Move & move)
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

void Bishop::LoadValidMoves(bool writeOver)
{
    if(writeOver)
        _game->BitfieldClear();
    Position positionToTest = Position(_position);
    int testDirections[2][4] = {
        {1,  1, -1, -1},
        {1, -1, -1,  1}};
    for(size_t i = 0 ; i < sizeof(testDirections)/2/sizeof(int); i++)
    {
        positionToTest.Update(_position);
        for (int j = 0; j < 8; j++)
        {
            positionToTest.Coulumn += testDirections[0][i];
            positionToTest.Row += testDirections[1][i];
            if(_game->GetFigureColorAt(positionToTest) == GetOpositeColor())
            {
                _game->BitfieldSet(positionToTest);
                break;
            }
            else if (_game->GetFigureColorAt(positionToTest) == NO_COLOR)
            {
                _game->BitfieldSet(positionToTest);
            }
            else
            {
                break;
            }
        }
    }
}
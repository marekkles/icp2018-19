#include "Bishop.h"
#include <stdlib.h> 

bool Bishop::VerifyMove(Move & move)
{
    Position targetPosition = move.To;
    Position figurePosition = Position(GetPosition());
    if(move.FigureType != _type  && move.FigureType != NONE)
        return false;
    if(!move.ValidMove)
        return false;
    if(move.UseFrom && move.From != figurePosition)
        return false;
    if(targetPosition == figurePosition)
        return false;
    if(abs(targetPosition.Coulumn - figurePosition.Coulumn) != abs(targetPosition.Row - figurePosition.Row))
        return false;
    if(move.Take == true && _game->GetFigureColorAt(targetPosition) != GetOpositeColor())
        return false;
    if(move.ChangeTo == true)
        return false;
    Position positionToTest = Position(GetPosition());
    /**
     * +-+-+-+-+-+-+-+-+
     * | | | | | | | |*|
     * +-+-+-+-+-+-+-+-+
     * |*| | | | | |*| |
     * +-+-+-+-+-+-+-+-+
     * | |*| | | |*| | |
     * +-+-+-+-+-+-+-+-+
     * | | |*| |*| | | |
     * +-+-+-+-+-+-+-+-+
     * | | | |B| | | | |
     * +-+-+-+-+-+-+-+-+
     * | | |*| |*| | | |
     * +-+-+-+-+-+-+-+-+
     * | |*| | | |*| | |
     * +-+-+-+-+-+-+-+-+
     * |*| | | | | |*| |
     * +-+-+-+-+-+-+-+-+
    */
    int testDirections[2][8] = {
        {1,  1, -1, -1},
        {1, -1, -1,  1}};
    for(int i = 0 ; i < sizeof(testDirections)/2/sizeof(int); i++)
    {
        positionToTest.Update(figurePosition);
        for (int j = 0; j < 8; j++)
        {
            positionToTest.Coulumn += testDirections[0][i];
            positionToTest.Row += testDirections[1][i];
            if (positionToTest == targetPosition && 
                (_game->GetFigureColorAt(positionToTest) == GetOpositeColor() ||
                _game->GetFigureColorAt(positionToTest) == NO_COLOR))
                return true;
            else if(_game->GetFigureColorAt(positionToTest) != NO_COLOR)
                break;
        }
    }
    return false;
}
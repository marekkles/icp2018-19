#include "Rook.h"


bool Rook::VerifyMove(Move & move)
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
    if(targetPosition.Coulumn != figurePosition.Coulumn && targetPosition.Row != figurePosition.Row )
        return false;
    if(move.Take == true && _game->GetFigureColorAt(targetPosition) != GetOpositeColor())
        return false;
    if(move.ChangeTo == true)
        return false;
    Position positionToTest = Position(figurePosition);
    /**
     * +-+-+-+-+-+-+-+-+
     * | | | |*| | | | |
     * +-+-+-+-+-+-+-+-+
     * | | | |*| | | | |
     * +-+-+-+-+-+-+-+-+
     * | | | |*| | | | |
     * +-+-+-+-+-+-+-+-+
     * | | | |*| | | | |
     * +-+-+-+-+-+-+-+-+
     * |*|*|*|R|*|*|*|*|
     * +-+-+-+-+-+-+-+-+
     * | | | |*| | | | |
     * +-+-+-+-+-+-+-+-+
     * | | | |*| | | | |
     * +-+-+-+-+-+-+-+-+
     * | | | |*| | | | |
     * +-+-+-+-+-+-+-+-+
    */
    int testDirections[2][8] = {
        {0,  1,  0, -1},
        {1,  0, -1,  0}};
    for(int i = 0 ; i < sizeof(testDirections)/2/sizeof(int); i++)
    {
        positionToTest.Update(figurePosition);
        for (int j = 0; j < 8; j++)
        {
            positionToTest.Coulumn += testDirections[0][i];
            positionToTest.Row += testDirections[1][i];
            if ((_game->GetFigureColorAt(positionToTest) == GetOpositeColor() && positionToTest == targetPosition)||
                (_game->GetFigureColorAt(positionToTest) == NO_COLOR && positionToTest == targetPosition))
                return true;
            else if(_game->GetFigureColorAt(positionToTest) != NO_COLOR)
                break;
        }
    }
    return false;
}
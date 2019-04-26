#include "Knight.h"
#include <stdlib.h>

bool Knight::VerifyMove(Move & move)
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
    if(abs(targetPosition.Coulumn - figurePosition.Coulumn) != 2 &&
        abs(targetPosition.Row - figurePosition.Row) != 2 &&
        abs(targetPosition.Coulumn - figurePosition.Coulumn) != 1 &&
        abs(targetPosition.Row - figurePosition.Row) != 1)
        return false;
    if(move.ChangeTo == true)
        return false;
    if(move.Take == true && (_game->GetFigureColorAt(targetPosition) == GetOpositeColor() || _game->GetFigureColorAt(targetPosition) == NO_COLOR))
        return true;
    return false;
}
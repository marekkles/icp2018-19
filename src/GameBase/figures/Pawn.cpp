#include "Pawn.h"
#include <stdlib.h>

bool Pawn::VerifyMove(Move & move)
{
    Position targetPosition = move.To;
    Position figurePosition = Position(GetPosition());
    if(move.FigureType != _type  && move.FigureType != NONE)
        return false;
    if(!move.ValidMove)
        return false;
    if(move.FigureType != GetType())
        return false;
    if(move.UseFrom && move.From != figurePosition)
        return false;
    if(targetPosition == figurePosition)
        return false;
    if((targetPosition.Row - figurePosition.Row > 2 && GetColor() == WHITE) ||
        (targetPosition.Row - figurePosition.Row < -2 && GetColor() == BLACK) ||
        abs(targetPosition.Coulumn - figurePosition.Coulumn) > 1)
        return false;
    if(abs(targetPosition.Row - figurePosition.Row) == 2 &&
        ((GetColor() == WHITE && figurePosition.Row != 2)||
        (GetColor() == BLACK && figurePosition.Row != 7)))
        return false;
    if(move.ChangeTo == true && 
        ((targetPosition.Row != 8 && GetColor() == WHITE) || 
        (targetPosition.Row != 1 && GetColor() == BLACK)))
        return false;
    if(abs(targetPosition.Coulumn - figurePosition.Coulumn) == 1 && 
        _game->GetFigureColorAt(targetPosition) == NO_COLOR)
        return false;
    if(abs(targetPosition.Row - figurePosition.Row == 2))
    {
        Position temporatyPosition = Position(figurePosition);
        if(GetColor() == WHITE)
        {
            temporatyPosition.Row++;
            if(_game->GetFigureColorAt(temporatyPosition) != NO_COLOR)
                return false;
        }
        else
        {
            temporatyPosition.Row--;
            if(_game->GetFigureColorAt(temporatyPosition) != NO_COLOR)
                return false;
        }
    }
    if((move.Take == true && 
        _game->GetFigureColorAt(targetPosition) == GetOpositeColor()) || 
        _game->GetFigureColorAt(targetPosition) == NO_COLOR)
        return true;
    return false;
}
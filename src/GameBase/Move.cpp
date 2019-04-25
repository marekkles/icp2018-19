#include "Move.h"

typedef enum {
    MoveState_FirstPositon1, 
    MoveState_Figure, 
    MoveState_Take,
    MoveState_Change, 
    MoveState_FirstPositon2, 
    MoveState_SecondPosition1,
    MoveState_SecondPosition2,
    MoveState_SecondPosition3,
    MoveState_End,
    MoveState_Error
} MoveFsmStates_t;

Move::Move(FigureType_t figureType, Position & to)
{
    FigureType = figureType;
    To = Position(to);
    ValidMove = true;
    UseFrom = false;
    Checkmate = false;
    Check = false;
    Take = false;
}

Move::Move(std::string & inputMove) 
{
    /**
     * Definitions of final states of FSM
    */
    const MoveFsmStates_t FinalStates[] = {
        MoveState_SecondPosition1,
        MoveState_SecondPosition3,
        MoveState_Change,
        MoveState_End
    };
    /**
     * Limiting variable
    */
    int len = inputMove.length();
    /**
     * Initial values definitions
    */
    this->FigureType = PAWN;
    this->ChangeTo = NONE;
    this->ValidMove = true;
    this->UseFrom = false;
    this->Take = false;
    this->Check = false;
    this->Checkmate = false;
    /**
     * Helper variables
    */
    char positionRow;
    char positionCoulumn;
    /**
     * Main FSM cycle
    */
    MoveFsmStates_t fsmState= MoveState_FirstPositon1;
    for (size_t i = 0; i < len; i++)
    {
        char currentChar = inputMove[i];
        switch (fsmState)
        {
        case MoveState_FirstPositon1:
            if (currentChar == 'K' || 
                currentChar == 'D' || 
                currentChar == 'V' || 
                currentChar == 'S' ||
                currentChar == 'J')
            {
                fsmState = MoveState_Figure;
                this->FigureType = FigureCharToFigureType(currentChar);
            }
            else if (currentChar == 'x')
            {
                fsmState = MoveState_Take;
                this->Take = true;
                this->FigureType = FigureCharToFigureType('p');
            }
            else if (currentChar >= 'a' && currentChar <= 'h')
            {
                fsmState = MoveState_FirstPositon2;
                positionCoulumn = currentChar;
                this->FigureType = FigureCharToFigureType('p');
            }
            else
            {
                fsmState = MoveState_Error;
            }
            break;
        case MoveState_Figure:
            if (currentChar == 'x')
            {
                fsmState = MoveState_Take;
                this->Take = true;
            }
            else if (currentChar >= 'a' && currentChar <= 'h')
            {
                fsmState = MoveState_FirstPositon2;
                positionCoulumn = currentChar;
            }
            else
            {
                fsmState = MoveState_Error;
            }
            break;
        case MoveState_Take:
            if (currentChar >= 'a' && currentChar <= 'h')
            {
                fsmState = MoveState_FirstPositon2;
                positionCoulumn = currentChar;
            }
            else
            {
                fsmState = MoveState_Error;
            }
            break;
        case MoveState_FirstPositon2:
            if (currentChar >= '1' && currentChar <= '8')
            {
                fsmState = MoveState_SecondPosition1;
                positionRow = currentChar;
                this->To = Position(positionRow, positionCoulumn);
            }
            else
            {
                fsmState = MoveState_Error;
            }
            break;
        case MoveState_SecondPosition1:
            if (currentChar >= 'a' && currentChar <= 'h')
            {
                fsmState = MoveState_SecondPosition2;
                positionCoulumn = currentChar;
            }
            else if(currentChar == '#')
            {
                fsmState = MoveState_End;
                this->Checkmate = true;
            }
            else if(currentChar == '+')
            {
                fsmState = MoveState_End;
                this->Check = true;
            }
            else if (currentChar == 'D' || 
                currentChar == 'V' || 
                currentChar == 'S' ||
                currentChar == 'J')
            {
                fsmState = MoveState_Change;
                this->ChangeTo = FigureCharToFigureType(currentChar);
            }
            else
            {
                fsmState = MoveState_Error;
            }
        case MoveState_SecondPosition2:
            if (currentChar >= '1' && currentChar <= '8')
            {
                fsmState = MoveState_SecondPosition3;
                positionRow = currentChar;
                this->UseFrom = true;
                this->From = this->To;
                this->To = Position(positionRow, positionCoulumn);
            }
            else
            {
                fsmState = MoveState_Error;
            }
            break;
        case MoveState_SecondPosition3:
            if (currentChar == '+')
            {
                fsmState = MoveState_End;
                this->Check = true;
            }
            else if (currentChar == '#')
            {
                fsmState = MoveState_End;
                this->Checkmate = true;
            }
            else if (currentChar == 'D' || 
                currentChar == 'V' || 
                currentChar == 'S' ||
                currentChar == 'J')
            {
                fsmState = MoveState_Change;
                this->ChangeTo = FigureCharToFigureType(currentChar);
            }
            else
            {
                fsmState = MoveState_Error;
            }
            break;
        case MoveState_Change:
            if (currentChar == '+')
            {
                fsmState = MoveState_End;
                this->Check = true;
            }
            else if (currentChar == '#')
            {
                fsmState = MoveState_End;
                this->Checkmate = true;
            }
            else
            {
                fsmState = MoveState_Error;
            }
            break;
        case MoveState_End:
            fsmState = MoveState_Error;
            break;
        default:
            break;
        }
    }
    /**
     * Check if state is in final states of FSM
    */
    for (size_t i = 0; i < sizeof(FinalStates)/sizeof(MoveFsmStates_t); i++)
    {
        if(fsmState == FinalStates[i])
        {
            break;
        }
        fsmState = MoveState_Error;
    }
    /**
     * Set error if FSM is in error state
    */
    if(fsmState == MoveState_Error)
    {
        this->ValidMove = false;
    }
}
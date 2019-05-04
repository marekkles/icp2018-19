#include "Enums.h"

char FigureTypeToChar(FigureType_t figureType)
{
    if(figureType == BISHOP)
        return 'S';
    if(figureType == KING)
        return 'K';
    if(figureType == KNIGHT)
        return 'J';
    if(figureType == QUEEN)
        return 'D';
    if(figureType == ROOK)
        return 'V';
    if(figureType == PAWN)
        return 'p';
    return 'n';
}

char FigureColorToChar(FigureColor_t figureType)
{
    if(figureType == WHITE)
        return 'b';
    if(figureType == BLACK)
        return 'c';
    return 'n';
}

FigureType_t FigureTypeCharToType(char typeChar)
{
    if(typeChar == 'S')
        return BISHOP;
    if(typeChar == 'K')
        return KING;
    if(typeChar == 'J')
        return KNIGHT;
    if(typeChar == 'p')
        return PAWN;
    if(typeChar == 'D')
        return QUEEN;
    if(typeChar == 'V')
        return ROOK;
    return NONE;
}

FigureColor_t FigureColorCharToType(char typeChar)
{
    if(typeChar == 'b')
        return WHITE;
    if(typeChar == 'c')
        return BLACK;
    return NO_COLOR;
}
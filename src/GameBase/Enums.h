#ifndef __ENUMS_H
#define __ENUMS_H

typedef enum {NONE = 0, KING = 1, QUEEN = 2, ROOK = 3, KNIGHT = 4, BISHOP = 5, PAWN = 6} FigureType_t;
typedef enum {NO_COLOR = 0, WHITE = 1, BLACK = 2} FigureColor_t;

char FigureTypeToChar(FigureType_t figureType);
char FigureColorToChar(FigureColor_t figureType);

FigureType_t FigureTypeCharToType(char typeChar);
FigureColor_t FigureColorCharToType(char typeChar);

#endif
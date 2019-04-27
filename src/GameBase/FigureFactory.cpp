#include "FigureFactory.h"

#include "figures/Bishop.h"
#include "figures/King.h"
#include "figures/Knight.h"
#include "figures/Pawn.h"
#include "figures/Queen.h"
#include "figures/Rook.h"

#include <algorithm>

FigureBase * FigureFactory::CreateFigure(FigureType_t type, FigureColor_t color, Position & initialPosition, Game * game)
{
    FigureBase * newFigure;
    switch (type)
    {
    case KING:
        newFigure = new King(type, color, initialPosition, game);
        break;
    case QUEEN:
        newFigure = new Queen(type, color, initialPosition, game);
        break;
    case ROOK:
        newFigure = new Rook(type, color, initialPosition, game);
        break;
    case KNIGHT:
        newFigure = new Knight(type, color, initialPosition, game);
        break;
    case BISHOP:
        newFigure = new Bishop(type, color, initialPosition, game);
        break;
    case PAWN:
        newFigure = new Pawn(type, color, initialPosition, game);
        break;
    default:
        return NULL;
        break;
    }
    Figures.push_back(newFigure);
    return newFigure;
}
void FigureFactory::DeleteFigure(FigureBase * figure)
{
    Figures.remove(figure);
    delete figure;
}
FigureBase * FigureFactory::GetKing(FigureColor_t color)
{
    for (auto &figure : Figures)
    {
        if(figure->TakenAtTurnNumber == 0 && figure->GetColor() == color && figure->GetType() == KING)
            return figure;
    }
    return NULL;
}


void FigureFactory::TakeFigure(FigureBase * figure, int turnNumber)
{
    figure->TakenAtTurnNumber = turnNumber;
}

void FigureFactory::UnTakeFigure(Position & wasAt, int turnNumber)
{
    for (auto &figure : Figures)
    {
        if(figure->GetPosition() == wasAt && figure->TakenAtTurnNumber == turnNumber)
            figure->TakenAtTurnNumber = 0;
    }
}

FigureBase * FigureFactory::FigureAtPosition(Position & position)
{
    for (auto &figure : Figures)
    {
        if(figure->TakenAtTurnNumber == 0 && figure->GetPosition() == position)
            return figure;
    }
    return NULL;
}

FigureType_t FigureFactory::FigureTypeAtPosition(Position & position)
{
    for (auto &figure : Figures)
    {
        if(figure->TakenAtTurnNumber == 0 && figure->GetPosition() == position)
            return figure->GetType();
    }
    return NONE;
}


FigureColor_t FigureFactory::FigureColorAtPosition(Position & position)
{
    for (auto &figure : Figures)
    {
        if(figure->TakenAtTurnNumber == 0 && position == figure->GetPosition())
            return figure->GetColor();
    }
    return NO_COLOR;
}

FigureBase * FigureFactory::ChangeFigureTo(FigureBase * figure, FigureType_t figureType)
{
    Position figurePosition = Position(figure->GetPosition());
    FigureColor_t figureColor = figure->GetColor();
    Game * game = figure->GetGame();
    DeleteFigure(figure);
    return CreateFigure(figureType, figureColor, figurePosition, game);
}

FigureFactory::~FigureFactory() 
{
    for (auto &figure : Figures)
    {
        delete figure;
    }
}

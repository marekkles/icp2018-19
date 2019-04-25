#include "FigureFactory.h"

#include "figures/Bishop.h"
#include "figures/King.h"
#include "figures/Knight.h"
#include "figures/Pawn.h"
#include "figures/Queen.h"
#include "figures/Rook.h"

void FigureFactory::CreateFigure(FigureType_t type, FigureColor_t color, Position & initialPosition, Game * game)
{
    switch (type)
    {
    case KING:
        this->Figures.push_back(King(type, color, initialPosition, game));
        break;
    case QUEEN:
        this->Figures.push_back(Queen(type, color, initialPosition, game));
        break;
    case ROOK:
        this->Figures.push_back(Rook(type, color, initialPosition, game));
        break;
    case KNIGHT:
        this->Figures.push_back(Knight(type, color, initialPosition, game));
        break;
    case BISHOP:
        this->Figures.push_back(Bishop(type, color, initialPosition, game));
        break;
    case PAWN:
        this->Figures.push_back(Pawn(type, color, initialPosition, game));
        break;
    default:
        break;
    }
}
void FigureFactory::DeleteFigure(FigureBase & figure)
{
    std::vector<FigureBase>::iterator iterator = std::find(this->Figures.begin(), this->Figures.end(), figure);
    this->Figures.erase(iterator);
}
FigureBase & FigureFactory::GetKing(FigureColor_t color)
{
    for (auto &figure : this->Figures)
    {
        if(figure.InGame && figure.GetColor() == color && figure.GetType == KING)
            return figure;
    }
}
FigureBase & FigureFactory::FigureAtPosition(Position & position)
{
    for (auto &figure : this->Figures)
    {
        if(figure.InGame && figure.GetPosition() == position)
            return figure;
    }
    return this->Figures.at(0);
}

FigureType_t FigureFactory::FigureTypeAtPosition(Position & position)
{
    for (auto &figure : this->Figures)
    {
        if(figure.InGame && figure.GetPosition() == position)
            return figure.GetType;
    }
    return NONE;
}


FigureColor_t FigureFactory::FigureColorAtPosition(Position & position)
{
    for (auto &figure : this->Figures)
    {
        if(figure.InGame && figure.GetPosition() == position)
            return figure.GetColor;
    }
    return NO_COLOR;
}

FigureFactory::FigureFactory(Game * game)
{
    this->_game = game;
}
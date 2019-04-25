#include "Game.h"

#include <list>
#include <vector>
#include "Move.h"

void Game::_generateFigures()
{
    int addRow;
    int addCoulumn;
    FigureColor_t colorToCreate;
    Position initialPosition = Position('1','a');
    for (int i = 0; i < 2; i++)
    {
        colorToCreate = (i == 0)?WHITE:BLACK;
        initialPosition.Row = (colorToCreate == WHITE)?2:7;
        initialPosition.Coulumn = 1;
        for (int j = 0; j < 8; j++, initialPosition.Coulumn++)
        {
            _figureFactory.CreateFigure(PAWN, colorToCreate, initialPosition, this);
        }
        initialPosition.Row += (colorToCreate == WHITE)?-1:1;
        initialPosition.Coulumn = 1;
        FigureType_t firstRow[3] = {ROOK, KNIGHT, BISHOP};
        for (int j = 0; j < 3; j++,initialPosition.Coulumn++)
        {
            _figureFactory.CreateFigure(firstRow[j], colorToCreate, initialPosition, this);
            initialPosition.Coulumn = 9 - initialPosition.Coulumn;
            _figureFactory.CreateFigure(firstRow[j], colorToCreate, initialPosition, this);
            initialPosition.Coulumn = 9 - initialPosition.Coulumn;
        }
        initialPosition.Coulumn = (colorToCreate == WHITE)?4:5;
        _figureFactory.CreateFigure(KING, colorToCreate, initialPosition, this);
        initialPosition.Coulumn = (colorToCreate == WHITE)?5:4;
        _figureFactory.CreateFigure(QUEEN, colorToCreate, initialPosition, this);
    }
}
void Game::_loadDoList()
{
    /**
     * TODO
    */
}
bool Game::_isCheck()
{
    FigureColor_t colorToCheck = (PlayerTurn == WHITE)?BLACK:WHITE;
    Move checkMove = Move(NONE, _figureFactory.GetKing(colorToCheck).GetPosition());
    for (auto &figure : _figureFactory.Figures)
    {
        if(PlayerTurn == figure.GetColor() && figure.VerifyMove(checkMove))
            return true;
    }
    return false;
}
bool Game::_checkMove(Move & move)
{
    int numberOfPositives = 0;
    for (auto &figure : _figureFactory.Figures)
    {
        if(PlayerTurn == figure.GetColor() && figure.VerifyMove(move))
            numberOfPositives++;
    }
    return numberOfPositives == 1;
}
bool Game::_tryMove(Move & move)
{
    if(!_checkMove(move))
        return false;
    for (auto &figure : _figureFactory.Figures)
    {
        if(PlayerTurn == figure.GetColor()) 
            figure.TryMove(move);
    }
    return true;
}
void Game::_forceMove(FigureBase & figure,Move & move)
{
    figure.ForceMove(move);
}


FigureColor_t Game::GetFigureColorAt(Position & position)
{
    return _figureFactory.FigureColorAtPosition(position);
}
FigureType_t Game::GetFigureTypeAt(Position & position)
{
    return _figureFactory.FigureTypeAtPosition(position);
}
bool Game::NextMove()
{
    if(DoMoves.empty())
        return false;
    UndoMoves.push_back(DoMoves.back());
    DoMoves.pop_back();
}
void Game::PreviousMove()
{
    if(UndoMoves.empty())
        return;
    DoMoves.push_back(UndoMoves.back());
    UndoMoves.pop_back();
}
bool Game::UserMove(Move & move)
{
    DoMoves.clear();
    DoMoves.push_back(move);
}


Game::Game()
{
    _figureFactory = FigureFactory(this);
    Figures = & _figureFactory.Figures;
    _inputFileName = "";
    PlayerTurn = WHITE;
	Winner = NO_COLOR;
	GameEnd = false;
	Check = false;
    _generateFigures();
}
Game::Game(std::string fileName)
{
    _figureFactory = FigureFactory(this);
    _inputFileName = fileName;
    Figures = & _figureFactory.Figures;
    PlayerTurn = WHITE;
	Winner = NO_COLOR;
	GameEnd = false;
	Check = false;
    _generateFigures();
}



#include "Game.h"

bool Game::_loadLine(std::ifstream & inputFile, int lineNumber)
{
    std::string inputLine;
    std::getline(inputFile, inputLine);
    std::istringstream stringStream(inputLine);
    std::string lineNumberString;
    std::string firstMoveString;
    std::string secondMoveString;
    stringStream >> lineNumber;
    stringStream >> firstMoveString;
    stringStream >> secondMoveString;
}

void Game::BitfieldSet(FigureBase * figure)
{
    figure->LoadValidMoves();
}

void Game::BitfieldSet(Position & position)
{
    BitfieldSet(position.Row, position.Coulumn);
}

void Game::BitfieldSet(int row, int coulumn)
{
    if(row < 1 || row > 8 || coulumn < 1 || coulumn > 8)
        return;
    ValidMovesBitfield[row-1][coulumn-1] = true;
}

bool Game::BitfieldGet(Position & position)
{
    return BitfieldGet(position.Row, position.Coulumn);
}

bool Game::BitfieldGet(int row, int coulumn)
{
    if(row < 1 || row > 8 || coulumn < 1 || coulumn > 8)
        return false;
    return ValidMovesBitfield[row-1][coulumn-1];
}
void Game::BitfieldClear()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            ValidMovesBitfield[i][j] = false;
        }
    }
}

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
            _figureFactory->CreateFigure(PAWN, colorToCreate, initialPosition, this);
        }
        initialPosition.Row += (colorToCreate == WHITE)?-1:1;
        initialPosition.Coulumn = 1;
        FigureType_t firstRow[3] = {ROOK, KNIGHT, BISHOP};
        for (int j = 0; j < 3; j++,initialPosition.Coulumn++)
        {
            _figureFactory->CreateFigure(firstRow[j], colorToCreate, initialPosition, this);
            initialPosition.Coulumn = 9 - initialPosition.Coulumn;
            _figureFactory->CreateFigure(firstRow[j], colorToCreate, initialPosition, this);
            initialPosition.Coulumn = 9 - initialPosition.Coulumn;
        }
        initialPosition.Coulumn = (colorToCreate == WHITE)?4:5;
        _figureFactory->CreateFigure(KING, colorToCreate, initialPosition, this);
        initialPosition.Coulumn = (colorToCreate == WHITE)?5:4;
        _figureFactory->CreateFigure(QUEEN, colorToCreate, initialPosition, this);
    }
}

bool Game::_isCheck()
{
    FigureColor_t colorToCheck = (PlayerTurn == WHITE)?BLACK:WHITE;
    Move checkMove = Move(NONE, _figureFactory->GetKing(colorToCheck)->GetPosition());
    for (auto &figure : _figureFactory->Figures)
    {
        if(PlayerTurn == figure->GetColor() && figure->VerifyMove(checkMove))
            return true;
    }
    return false;
}

void Game::_undoMove(Move & move)
{
    FigureBase * currentFigure = _figureFactory->FigureAtPosition(move.To);
    Move reverseMove = Move(move);
    reverseMove.To = move.From;
    reverseMove.From = move.To;
    reverseMove.Take = move.Take;
    if (reverseMove.Take)
        _figureFactory->FigureAtPosition(reverseMove.From)->InGame = true;
    currentFigure->ForceMove(reverseMove);
    if(move.ChangeTo != NONE)
        _figureFactory->ChangeFigureTo(currentFigure, move.FigureType);
}

bool Game::_checkMove(Move & move)
{
    int numberOfPositives = 0;
    for (auto &figure : _figureFactory->Figures)
    {
        if(PlayerTurn == figure->GetColor() && 
            figure->GetType() == move.FigureType && 
            figure->VerifyMove(move))
            numberOfPositives++;
    }
    return numberOfPositives == 1;
}
bool Game::_tryMove(Move & move)
{
    FigureBase * lastValidFigure = NULL;
    int numberOfPositives = 0;
    for (auto &figure : _figureFactory->Figures)
    {
        if(PlayerTurn == figure->GetColor() && 
            figure->GetType() == move.FigureType &&
            figure->VerifyMove(move))
        {
            numberOfPositives++;
            lastValidFigure = figure;
        }
    }
    if(numberOfPositives != 1)
        return false;
    move.From = Position(lastValidFigure->GetPosition());
    lastValidFigure->TryMove(move);
    if(move.ChangeTo != NONE)
        _figureFactory->ChangeFigureTo(lastValidFigure, move.ChangeTo);
    if(move.Take)
        _figureFactory->FigureAtPosition(move.To)->InGame = false;
    return true;
}

void Game::_forceMove(FigureBase * figure,Move & move)
{
    figure->ForceMove(move);
}

FigureColor_t Game::GetFigureColorAt(Position & position)
{
    return _figureFactory->FigureColorAtPosition(position);
}

FigureType_t Game::GetFigureTypeAt(Position & position)
{
    return _figureFactory->FigureTypeAtPosition(position);
}

FigureBase * Game::GetFigureAt(Position & position)
{
    return _figureFactory->FigureAtPosition(position);
}

bool Game::NextMove()
{
    if(DoMoves.empty())
        return false;
    UndoMoves.push_back(DoMoves.front());
    DoMoves.pop_front();
    return _tryMove(UndoMoves.back());
}

void Game::PreviousMove()
{
    if(UndoMoves.empty())
        return;
    DoMoves.push_back(UndoMoves.back());
    UndoMoves.pop_back();
    _undoMove(DoMoves.back());
}

bool Game::UserMove(Move & move)
{
    DoMoves.clear();
    DoMoves.push_back(move);
    NextMove();
}

bool Game::LoadMoves(std::ifstream & inputFile)
{
    std::string inputLine;
    int number;
    std::string firstMove;
    std::string secondMove;
    int lineCount = 0;
    enum {NUMBER1, NUMBER2, FIRST_MOVE, SECOND_MOVE, ERROR};
    while (!inputFile.eof())
    {
        lineCount++;
        _loadLine(inputFile, lineCount);
    }
    return true;
}

Game::Game()
{
    _figureFactory = new FigureFactory();
    Figures = & _figureFactory->Figures;
    _inputFileName = "";
    PlayerTurn = WHITE;
	Winner = NO_COLOR;
	GameEnd = false;
	Check = false;
    _generateFigures();
}

Game::Game(std::string fileName)
{
    _figureFactory = new FigureFactory();
    _inputFileName = fileName;
    Figures = & _figureFactory->Figures;
    PlayerTurn = WHITE;
	Winner = NO_COLOR;
	GameEnd = false;
	Check = false;
    _generateFigures();
}

Game::~Game()
{
    delete _figureFactory;
}

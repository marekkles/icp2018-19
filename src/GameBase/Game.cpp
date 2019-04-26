#include "Game.h"

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

void Game::_loadDoList()
{
    /**
     * TODO
    */
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

bool Game::_checkMove(Move & move)
{
    int numberOfPositives = 0;
    for (auto &figure : _figureFactory->Figures)
    {
        if(PlayerTurn == figure->GetColor() && figure->VerifyMove(move))
            numberOfPositives++;
    }
    return numberOfPositives == 1;
}
bool Game::_tryMove(Move & move)
{
    if(!_checkMove(move))
        return false;
    for (auto &figure : _figureFactory->Figures)
    {
        if(PlayerTurn == figure->GetColor()) 
            figure->TryMove(move);
    }
    return true;
}

void Game::_forceMove(FigureBase & figure,Move & move)
{
    figure.ForceMove(move);
}

FigureColor_t Game::GetFigureColorAt(Position & position)
{
    return _figureFactory->FigureColorAtPosition(position);
}

FigureType_t Game::GetFigureTypeAt(Position & position)
{
    return _figureFactory->FigureTypeAtPosition(position);
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
    while (std::getline(inputFile, inputLine))
    {
        lineCount++;
        number = 0;
        firstMove.clear();
        secondMove.clear();
        int fsmState = NUMBER1;
        for (int i = 0; i < inputLine.length(); i++)
        {
            char currentChar = inputLine[i];
            switch (fsmState)
            {
            case NUMBER1:
                if (currentChar >= '0' && currentChar <= '9')
                {
                    number = number*10 + (currentChar-'0');
                }
                else if(currentChar == '.')
                {
                    fsmState = NUMBER2;
                }
                else
                {
                    fsmState = ERROR;
                }
                break;
            case NUMBER2:
                if(currentChar == ' ')
                {
                    fsmState = FIRST_MOVE;
                }
                else
                {
                    fsmState = ERROR;
                }
                break;
            case FIRST_MOVE:
                if(currentChar == ' ')
                {
                    fsmState = SECOND_MOVE;
                }
                else
                {
                    firstMove.push_back(currentChar);
                    fsmState = FIRST_MOVE;
                }
                break;
            case SECOND_MOVE:
                secondMove.push_back(currentChar);
                break;
            default:
                break;
            }
        }
        if(fsmState == NUMBER1 || fsmState == NUMBER2 || fsmState == ERROR)
            return false;
        if(fsmState == FIRST_MOVE && inputFile.eof() == false)
            return false;
        if(lineCount != number)
            return false;
        Move move = Move(firstMove);
        if(!move.ValidMove)
            return false;

        DoMoves.push_back(move);
        if(fsmState == FIRST_MOVE)
            return true;

        move = Move(secondMove);
        if(!move.ValidMove)
            return false;
        DoMoves.push_back(move);
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

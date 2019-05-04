#include "Game.h"

bool Game::_loadLine(std::ifstream & inputFile, int lineNumber)
{
    int inputOrder = 0;
    int state = 0;
    std::string inputLine;
    std::string move1;
    std::string move2;
    inputLine.clear();
    move1.clear();
    move2.clear();
    std::getline(inputFile, inputLine);
    for (size_t i = 0; i < inputLine.length(); i++)
    {
        char currentChar = inputLine[i];
        switch (state)
        {
        case 0:
            if(currentChar >= '0' && currentChar >= '0' )
                inputOrder = inputOrder*10 + (currentChar - '0');
            else if(currentChar == '.')
                state++;
            else
                state = -1;
            break;
        case 1:
            if(currentChar == ' ')
                state++;
            else
                state = -1;
            break;
        case 2:
            if(currentChar == ' ')
                state++;
            else
                move1.push_back(currentChar);
            break;
        case 3:
            if(currentChar == ' ')
                state = -1;
            else
                move2.push_back(currentChar);
            break;        
        default:
            break;
        }
    }
    if (inputOrder != lineNumber)
        return false;
    if (state <= 1 || (state <= 2 && !inputFile.eof()))
        return false;
    DoMoves.push_back(Move(move1));
    if(state != 2)
        DoMoves.push_back(Move(move2));
    return true;
}


void Game::_saveLine(std::ostream & outputFile, int lineNumber, Move & move1, Move & move2)
{
    outputFile << lineNumber << ". ";
    move1.SaveMove(outputFile);
    outputFile << " ";
    move2.SaveMove(outputFile);
    outputFile << " \n";
}
void Game::_saveLine(std::ostream & outputFile, int lineNumber, Move & move1)
{
    outputFile << lineNumber << ". ";
    move1.SaveMove(outputFile);
    outputFile << " \n";
}

void Game::BitfieldSet(FigureBase * figure)
{
    figure->LoadValidMoves(true);
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

bool Game::BitfieldGet(const Position & position)
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

void Game::_copyBitfield(bool destination[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            destination[i][j] = ValidMovesBitfield[i][j];
        }
    }
}

void Game::_generateFigures()
{
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

bool Game::_isCheckForAllMovesOfFigure(FigureBase * figure)
{
    Position oldFigurePosition = Position(figure->GetPosition());
    Position newFigurePosition = Position(figure->GetPosition());
    bool bitfield[8][8];
    bool isCheck = true;

    figure->LoadValidMoves(true);
    _copyBitfield(bitfield);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(!bitfield[i][j])
                continue;
            newFigurePosition.Row = i + 1;
            newFigurePosition.Coulumn = j + 1;

            FigureBase * figureToTake = _figureFactory->FigureAtPosition(newFigurePosition);
            
            if(figureToTake != NULL)
                figureToTake->TakenAtTurnNumber = -1;
            
            figure->SetPosition(newFigurePosition);

            isCheck = _isCheck() && isCheck;

            if(figureToTake != NULL)
                figureToTake->TakenAtTurnNumber = 0;
            if(!isCheck)
                break;
        }
    }
    figure->SetPosition(oldFigurePosition);
    return isCheck;
}

bool Game::_isCheckmate()
{
    bool isCheckmate = true;
    for (auto &figure : _figureFactory->Figures)
    {
        if(PlayerTurn == figure->GetOpositeColor() && figure->TakenAtTurnNumber == 0)
        {
            isCheckmate = isCheckmate && _isCheckForAllMovesOfFigure(figure);
        }
    }
    return isCheckmate;
}

bool Game::_isCheck()
{
    FigureColor_t colorToCheck = (PlayerTurn == WHITE)?BLACK:WHITE;
    FigureBase * king = _figureFactory->GetKing(colorToCheck);
    if(king == NULL)
        return true;
    BitfieldClear();
    for (auto &figure : _figureFactory->Figures)
    {
        if(PlayerTurn == figure->GetColor() && figure->TakenAtTurnNumber == 0)
            figure->LoadValidMoves(false);
    }
    if(BitfieldGet(king->GetPosition()))
        return true;
    return false;
}

void Game::_undoMove(Move & move)
{
    FigureBase * figure = _figureFactory->FigureAtPosition(move.To);
    if(move.ChangeTo != NONE)
        figure = _figureFactory->ChangeFigureTo(figure, move.FigureType);
    if(move.Take)
        _figureFactory->UnTakeFigure(move.To, TurnCounter);
    figure->SetPosition(move.From);
}

bool Game::_doMove(Move & move)
{
    if(!move.ValidMove)
        return false;
    FigureBase * figure = _figureThatCanDoMove(move);
    if(figure == NULL)
    {
        move.ValidMove = false;
        return false;
    }
    FigureBase * takenFigure = GetFigureAt(move.To);
    if(takenFigure != NULL)
        _figureFactory->TakeFigure(takenFigure, TurnCounter);
    
    move.From = Position(figure->GetPosition());
    figure->SetPosition(move.To);
    if(move.ChangeTo != NONE)
        figure = _figureFactory->ChangeFigureTo(figure, move.ChangeTo);
    

    bool didTake = takenFigure != NULL;
    bool didCheckmate = _isCheckmate();
    bool didCheck = false;
    if(!didCheckmate)
        didCheck = _isCheck();
    if((move.Take && !didTake) || (move.Check && !didCheck) || (move.Checkmate && !didCheckmate))
    {
        _undoMove(move);
        return false;
    }

    move.Take = didTake;
    move.Checkmate = didCheckmate;
    move.Check = didCheck;

    if(move.Checkmate)
        Check = true;
    if(move.Check)
    {
        GameEnd = true;
        Winner = PlayerTurn;
    }
    return true;
}

FigureBase * Game::_figureThatCanDoMove(Move & move)
{
    FigureBase * returnFigure = NULL;
    for (auto &figure : _figureFactory->Figures)
    {
        if(move.FigureType == figure->GetType() && PlayerTurn == figure->GetColor() && figure->TakenAtTurnNumber == 0 && figure->VerifyMove(move))
        {
            if(returnFigure == NULL)
                returnFigure = figure;
            else
                return NULL;
        }
    }
    return returnFigure;
}

void Game::_changeTurn()
{
    PlayerTurn = (PlayerTurn == WHITE)?BLACK:WHITE;
}

void Game::_updateTurnCounter(bool forward)
{
    TurnCounter += (forward)?1:-1;
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
    if (GameEnd)
        return false;
    if(DoMoves.empty())
        return false;
    UndoMoves.push_back(DoMoves.front());
    
    bool moveResult = _doMove(UndoMoves.back());
    if(moveResult)
    {
        _changeTurn();
        _updateTurnCounter(true);
        DoMoves.pop_front();
    }
    else
    {
        UndoMoves.pop_back();
    }
    return moveResult;
}

void Game::PreviousMove()
{
    if(UndoMoves.empty())
        return;
    DoMoves.push_front(UndoMoves.back());
    UndoMoves.pop_back();
    _updateTurnCounter(false);
    _changeTurn();
    _undoMove(DoMoves.front());
    
    Move & currentMove = UndoMoves.back();
    GameEnd = currentMove.Checkmate;
    Check = currentMove.Check;
    if(GameEnd)
        Winner = PlayerTurn;
    else
        Winner = NO_COLOR;
}

void Game::FirstMove()
{
    while (!UndoMoves.empty())
    {
        PreviousMove();
    }
}

bool Game::UserMove(Move & move)
{
    DoMoves.clear();
    DoMoves.push_back(move);
    return NextMove();
}

bool Game::LoadMoves(std::ifstream & inputFile)
{
    DoMoves.clear();
    std::string inputLine;
    std::string firstMove;
    std::string secondMove;
    int lineCount = 0;
    while (!inputFile.eof())
    {
        lineCount++;
        if(!_loadLine(inputFile, lineCount))
        {
            DoMoves.clear();
            return false;
        }
    }
    return true;
}

void Game::SaveMoves(std::ostream & outputFile)
{
    int moveCounter = 0;
    int turnCounter = 0;
    Move move1;
    for (auto &move : UndoMoves)
    {
        moveCounter++;
        if((moveCounter % 2) == 1)
        {
            turnCounter++;
            move1 = move;
        }
        else
            _saveLine(outputFile, turnCounter, move1, move);
        if((moveCounter & 1 ) == 1 && &move == &UndoMoves.back())
            _saveLine(outputFile, turnCounter, move1);
    }
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
    TurnCounter = 1;
    _generateFigures();
}

Game::~Game()
{
    delete _figureFactory;
}

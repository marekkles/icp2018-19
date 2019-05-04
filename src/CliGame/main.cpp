#include <iostream>
#include <string>
#include <sstream>

#include "../GameBase/Move.h"

char typeToChar(FigureType_t type)
{
    switch (type)
    {
    case BISHOP:
        return 'S';
        break;
    case KING:
        return 'K';
        break;
    case KNIGHT:
        return 'J';
        break;
    case PAWN:
        return 'p';
        break;
    case QUEEN:
        return 'D';
        break;
    case ROOK:
        return 'V';
        break;
    default:
        return ' ';
        break;
    }
}
char colorToChar(FigureColor_t color)
{
    switch (color)
    {
    case WHITE:
        return 'b';
        break;
    case BLACK:
        return 'c';
        break;
    default:
        return ' ';
        break;
    }
}

char rowToChar(int row)
{
    return row - 1 + '1';
}

char coulumnToChar(int coulumn)
{
    return coulumn - 1 + 'a';
}

void printHelp()
{
    std::cout << 
    "Help:\n" <<
    "  ? - help page\n" <<
    "  > - next move\n" <<
    "  < - previous move\n" <<
    "  << - rewind to begining\n" <<
    "  p - print chess board\n" <<
    "  m - print done moves\n" <<
    "  m do - print to do moves\n" <<
    "  ~ POSITION - print hint for figure at position\n" <<
    "  l FILENAME - load from file\n" <<
    "  s FILENAME - save to file\n" <<
    "  [K,D,V,S,J][x][a-h1-8]a-h1-8[D,V,S,J][#,+] - do move\n" <<
    "  q - quit\n";
}

void printValidMoves(Game & game)
{
    Position currentPosition = Position('8','a');
    for (int i = 8; i > 0; i--)
    {
        std::cout << "\n  +--+--+--+--+--+--+--+--+\n"<< i << " |";
        for (int j = 1; j <= 8; j++)
        {
            currentPosition.Row = i;
            currentPosition.Coulumn = j;
            FigureBase * figureAtPosition = game.GetFigureAt(currentPosition);
            if(game.BitfieldGet(currentPosition))
                std::cout << "X";
            else if (figureAtPosition == NULL)
                std::cout << " ";
            else
                std::cout << colorToChar(figureAtPosition->GetColor());
            if(figureAtPosition != NULL)
                std::cout << typeToChar(figureAtPosition->GetType());
            else if(game.BitfieldGet(currentPosition))
                std::cout << "X";
            else
                std::cout << " ";
            std::cout << "|";
        }
    }
    std::cout << "\n  +--+--+--+--+--+--+--+--+\n   A  B  C  D   E  F  G  H\n";
}

void printChessBoard(Game & game)
{
    Position currentPosition = Position('8','a');
    for (int i = 8; i > 0; i--)
    {
        currentPosition.Row = i;
        std::cout << "\n  +--+--+--+--+--+--+--+--+\n"<< i << " |";
        for (int j = 1; j <= 8; j++)
        {
            currentPosition.Coulumn = j;
            if(game.GetFigureColorAt(currentPosition) != NO_COLOR)
                std::cout << 
                colorToChar(game.GetFigureColorAt(currentPosition)) << 
                typeToChar(game.GetFigureTypeAt(currentPosition));
            else
                std::cout << "  ";
            std::cout << "|";
        }
    }
    std::cout << "\n  +--+--+--+--+--+--+--+--+\n   A  B  C  D   E  F  G  H\n";
}

void printDoMoves(Game & game)
{
    int moveCounter = game.UndoMoves.size();
    int turnCounter = (moveCounter+1)/2;
    for (auto &move : game.DoMoves)
    {   
        if(moveCounter % 2 == 0)
        {
            turnCounter++;
            std::cout << "\n" << turnCounter << ". ";
        }
        else if (&game.DoMoves.back() == &move && moveCounter % 2 == 0)
        {
            std::cout << "\n" << turnCounter << ". ";
        }
        else
        {
            std::cout << turnCounter << " ";
        }
        
        moveCounter++;
        move.SaveMove(std::cout);
    }
    std::cout << "\n";
}

int parseInput(std::string & input, Game & game)
{
    if(input == "?")
    {
        printHelp();
    }
    else if(input == ">")
    {
        std::cout << "Turn: " << game.TurnCounter << ". " << ((game.PlayerTurn == WHITE)?"WHITE":"BLACK") << "\n";
        std::cout << "Move: " << ((game.NextMove())?"TRUE":"FALSE") << "\n";
    }
    else if(input == "<")
    {
        game.PreviousMove();
    }
    else if(input == "<<")
    {
        game.FirstMove();
    }
    else if(input == "p")
    {
        printChessBoard(game);
    }
    else if(input[0] == '~' && input.length() == 4)
    {
        if(input[3] > '8' || input[3] < '1' || input[2] > 'h' || input[2] < 'a')
            return 0;
        Position positionToTest = Position(input[3], input[2]);
        FigureBase * figureToTest = game.GetFigureAt(positionToTest);
        if(figureToTest == NULL)
            return 0;
        game.BitfieldSet(figureToTest); 
        printValidMoves(game);
    }
    else if(input == "m do")
    {
        std::cout << "Do moves\n";
        printDoMoves(game);
    }
    else if(input == "m")
    {
        std::cout << "Moves\n";
        game.SaveMoves(std::cout);
    }
    else if(input[0] == 'l')
    {
        std::ifstream inputFile;
        inputFile.open(&input[2]);
        if (inputFile.fail())
        {
            std::cout << "Error opening file: " << &input[2] << "\n";
            return 1;
        }
        std::cout << "Loading from file: " <<  &input[2] << "\n";
        if(!game.LoadMoves(inputFile))
        {
            std::cout << "Error parsing file: " << &input[2] << "\n";
            inputFile.close();
            return 1;
        }
        inputFile.close();
    }
    else if(input[0] == 's')
    {
        std::ofstream outputFile;
        outputFile.open(&input[2]);
        if (outputFile.fail())
        {
            std::cout << "Error opening file: " << &input[2] << "\n";
            return 1;
        }
        std::cout << "Saving to file: " <<  &input[2] << "\n";
        game.SaveMoves(outputFile);
        outputFile.close();
    }
    else if(input == "q")
    {
        std::cout << "Quit\n";
        return -1;
    }
    else
    {
        Move userMove = Move(input);
        std::cout << "Turn: " << game.TurnCounter << ". " << ((game.PlayerTurn == WHITE)?"WHITE":"BLACK") << "\n";
        std::cout << "Move: " << ((game.UserMove(userMove))?"TRUE":"FALSE") << "\n";
    }
    return 0;
}

int main(int argc, char *argv[])
{
    std::cout << "Chess CLI Edition\n";
    std::cout << "\n(C) Marek Vasko\n";
    std::cout << "\nType ? to get help\n";
    Game game = Game();
    for (int i = 0;;i++)
    {
        std::string inputString;
        std::cout << ">> ";
        std::getline(std::cin, inputString);
        if(parseInput(inputString, game) == -1)
            break;
    }
}
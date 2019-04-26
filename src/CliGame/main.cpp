#include <iostream>
#include <string>
#include <sstream>

#include "../GameBase/Move.h"

static bool opMode = false;


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
    "  p - print chess board\n" <<
    "  m - print do moves\n" <<
    "  ~ POSITION - print hint for figure at position\n" <<
    "  l FILENAME - load from file\n" <<
    "  q - quit\n" <<
    "  $ - op (sudo :D ) mode\n" <<
    "  [K,D,V,S,J][x][a-h1-8]a-h1-8[D,V,S,J][#,+] - do move\n";
}
void printOpHelp()
{
    std::cout << 
    "Help:\n" <<
    "  ? - help page\n" <<
    "  > - next move\n" <<
    "  < - previous move\n" <<
    "  p - print chess board\n" <<
    "  m - print do moves\n" <<
    "  ~ POSITION - print hint for figure at position\n" <<
    "  l FILENAME - load from file\n" <<
    "  q - quit\n" <<
    "  $ - op (sudo :D ) mode\n" <<
    "  $n [K,D,V,S,J]a-h1-8 - new figure at position\n" <<
    "  $d a-h1-8 - delete figure at position\n" <<
    "  $p [a-h1-8] - more info on the chess board or figure at position\n" <<
    "  [K,D,V,S,J][x][a-h1-8]a-h1-8[D,V,S,J][#,+] - do move\n";
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
        for (int j = 1; j <= 8; j++, currentPosition.Coulumn)
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

void printMove(Move & move)
{
    std::cout << 
    ((move.FigureType == PAWN)?'\0':typeToChar(move.FigureType)) <<
    ((move.Take)?'x':'\0') <<
    move.To.coulumnToChar() << move.To.rowToChar() <<
    ((move.UseFrom)?move.From.coulumnToChar():'\0')<< ((move.UseFrom)?move.From.rowToChar():'\0') <<
    ((move.ChangeTo != NONE)?typeToChar(move.ChangeTo):'\0') <<
    ((move.Check)?'+':'\0') <<
    ((move.Checkmate)?'#':'\0');
}

void printMoves(Game & game)
{
    int turnCounter = 0;
    bool whitesTurn = true;
    whitesTurn = true;
    for (auto &move : game.UndoMoves)
    {
        if (whitesTurn)
        {
            turnCounter++;
            std::cout  << "\n" << turnCounter << ". ";
        }
        whitesTurn = !whitesTurn;
        printMove(move);
        std::cout << " ";
    }
    std::cout<< "\n";
}

int parseInput(std::string & input, Game & game)
{
    if(input == "?")
    {
        if(opMode == false)
            printHelp();
        else
            printOpHelp();
    }
    else if(input == ">")
    {
        game.NextMove();
    }
    else if(input == "<")
    {
        game.PreviousMove();
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
    else if(input == "m")
    {
        std::cout << "Moves\n";
        printMoves(game);
    }
    else if(input[0] == 'l')
    {
        std::ifstream inputFile;
        inputFile.open(&input[2]);
        if(!game.LoadMoves(inputFile))
        {
            inputFile.close();
            return 1;
        }
        inputFile.close();
    }
    else if(input == "q")
    {
        std::cout << "Quit\n";
        return -1;
    }
    else if(input == "$")
    {
        if(opMode == false)
        {
            opMode = true;
            std::cout << "Now you are in op mode!\n";
        }
    }
    else if (opMode && input == "$n")
    {
        /* code */
    }
    else if (opMode && input == "$d")
    {
        /* code */
    }
    else if (opMode && input == "$p")
    {
        /* code */
    }
    else
    {
        Move userMove = Move(input);
        std::cout << "Move " << ((userMove.ValidMove)?"OK":"BAD") << "\n";
        if(!userMove.ValidMove)
            return 0;
        std::cout <<
         "Figure: " << typeToChar(userMove.FigureType) <<
         "\nTo: " << coulumnToChar(userMove.To.Coulumn) << rowToChar(userMove.To.Row);
        if(userMove.UseFrom)
            std::cout << "\nFrom: " << coulumnToChar(userMove.From.Coulumn) << rowToChar(userMove.From.Row);
        std::cout << ((userMove.Take)?"\nTake":"") <<
        ((userMove.Check)?"\nCheck":"") <<
        ((userMove.Checkmate)?"\nCheckmate":"");
        if(userMove.ChangeTo != NONE)
            std::cout << "\nChange to: " << typeToChar(userMove.ChangeTo);
        std::cout << "\n";
        game.UserMove(userMove);
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
        if(opMode == false)
            std::cout << ">> ";
        else
            std::cout << "$$ ";
        std::getline(std::cin, inputString);
        if(parseInput(inputString, game) == -1)
            break;
    }
}
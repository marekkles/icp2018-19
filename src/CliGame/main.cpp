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
    std::cout << "Help:\n";
    std::cout << "  ? - help page\n";
    std::cout << "  > - next move\n";
    std::cout << "  < - previous move\n";
    std::cout << "  p - print chess board\n";
    std::cout << "  q - quit\n";
    std::cout << "  $ - op (sudo :D ) mode\n";
    std::cout << "  [K,D,V,S,J][x][a-h1-8]a-h1-8[D,V,S,J][#,+] - do move\n";
}
void printOpHelp()
{
    std::cout << "Help:\n";
    std::cout << "  ? - help page\n";
    std::cout << "  > - next move\n";
    std::cout << "  < - previous move\n";
    std::cout << "  p - print chess board\n";
    std::cout << "  $ - op (sudo :D ) mode\n";
    std::cout << "  $n [K,D,V,S,J]a-h1-8 - new figure at position\n";
    std::cout << "  $d a-h1-8 - delete figure at position\n";
    std::cout << "  $p [a-h1-8] - more info on the chess board or figure at position\n";
    std::cout << "  [K,D,V,S,J][x][a-h1-8]a-h1-8[D,V,S,J][#,+] - do move\n";
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
        /* code */
    }
    else if(input == "<")
    {
        /* code */
    }
    else if(input == "p")
    {
        printChessBoard(game);
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
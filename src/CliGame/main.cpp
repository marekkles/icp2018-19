#include "../GameBase/Game.h"
#include "../GameBase/FigureBase.h"
#include <iostream>
#include <string>

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

void printFigure(FigureBase & figure)
{
    char color = (figure.GetColor() == WHITE)?'b':'c';
    switch (figure.GetType)
    {
    case KING:
        std::cout << color << "K";
        break;
    case QUEEN:
        std::cout << color << "D";
        break;    
    case ROOK:
        std::cout << color << "V";
        break;
    case KNIGHT:
        std::cout << color << "J";
        break;
    case BISHOP:
        std::cout << color << "S";
        break;
    case PAWN:
        std::cout << color << "p";
        break;
    default:
        break;
    }
}

void printChessBoard(Game & game)
{
    Position currentPosition = Position('8','a');
    for (int i = 8; i > 0; i--, currentPosition.Row--)
    {
        for (int i = 1; i <= 8; i++, currentPosition.Coulumn++)
        {
            for (auto &figure : (*game.Figures))
            {
                Position figurePosition = figure.GetPosition();
                if(figurePosition == currentPosition)
                {
                    printFigure(figure);
                }
            }
            std::cout << "|";
        }
    }
}

int main(int argc, char *argv[])
{
    std::cout << "Chess CLI Edition\n";
    std::cout << "\n(C) Marek Vasko\n";
    std::cout << "\nType ? to get help\n";
    while (true)
    {
        std::string inputString;
        std::cout << ">> ";
        std::getline(std::cin, inputString);
    }
}
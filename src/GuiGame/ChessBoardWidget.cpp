#include "ChessBoardWidget.h"

ChessBoardWidget::ChessBoardWidget(QWidget *parent) : QWidget(parent)
{
    ChessBoardLayout = new QGridLayout(this);
    ChessBoardLayout->setSpacing(0);

    this->setFixedSize(800, 800);
    _createLayout();
}

void ChessBoardWidget::SetGame(Game * game)
{
    _game = game;
}

void ChessBoardWidget::_createLayout()
{
    for (int i = 0; i < 64; ++i)
    {
        PiecesButtons[i] = new QPushButton(this);
        PiecesButtons[i]->setFixedSize(100, 100);
        ChessBoardLayout->addWidget(PiecesButtons[i], i/8+1, i%8+1);
    }
}

#include "GameTab.h"

GameTab::GameTab(QWidget *parent) : QWidget(parent)
{
    TabName = "untitled.chess";

    _playingGame = false;

    _tabLayout = new QHBoxLayout(this);
    _controlsWidget = new ControlsWidget(this);
    _chessBoardWidget = new ChessBoardWidget(this);

    _game = Game();
    _chessBoardWidget->SetGame(&_game);

    _tabLayout->addWidget(_chessBoardWidget);
    _tabLayout->addWidget(_controlsWidget);
}

void GameTab::PlayButtonClicked()
{
    if(_playingGame)
    {
        _playingGame = false;
    }
    else
    {
        _playingGame = true;
    }
}
void GameTab::NextMoveButtonClicked()
{

}
void GameTab::PreviousMoveButtonClicked()
{

}

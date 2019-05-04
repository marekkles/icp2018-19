#ifndef GAMETAB_H
#define GAMETAB_H

#include <QWidget>
#include <QHBoxLayout>
#include <string>
#include "ControlsWidget.h"
#include "ChessBoardWidget.h"
#include "../GameBase/Game.h"

class GameTab : public QWidget
{
    Q_OBJECT
public:
    explicit GameTab(QWidget *parent = nullptr);
    std::string TabName;

signals:

public slots:
    void PlayButtonClicked();
    void NextMoveButtonClicked();
    void PreviousMoveButtonClicked();
private:
    Game _game;
    bool _playingGame;
    QHBoxLayout * _tabLayout;
    ControlsWidget * _controlsWidget;
    ChessBoardWidget * _chessBoardWidget;
};

#endif // GAMETAB_H

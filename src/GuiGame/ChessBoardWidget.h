#ifndef CHESSBOARDWIDGET_H
#define CHESSBOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include "GameBase/Game.h"


class ChessBoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChessBoardWidget(QWidget *parent = nullptr);
    void SetGame(Game * game);
    QGridLayout * ChessBoardLayout;
    QPushButton * PiecesButtons[64];
private:
    void _createLayout();
    Game * _game;
signals:

public slots:
};

#endif // CHESSBOARDWIDGET_H

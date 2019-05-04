#ifndef CONTROLSWIDGET_H
#define CONTROLSWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QLabel>

class ControlsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ControlsWidget(QWidget *parent = nullptr);
    QGridLayout * ControlsLayout;

    QPlainTextEdit * UndoMovesText;

    QPushButton * BeginningButton;
    QPushButton * PreviousMoveButton;
    QPushButton * NextMoveButton;
    QPushButton * PlayPauseButton;

    QPushButton * LoadGameButton;
    QPushButton * SaveGameButton;
    QPushButton * QuitTabButton;

    QDoubleSpinBox * PlayIntervalInput;
    QLabel * PlayIntervalDescription;
    QLabel * UndoMovesTextDescription;

signals:

public slots:
};

#endif // CONTROLSWIDGET_H

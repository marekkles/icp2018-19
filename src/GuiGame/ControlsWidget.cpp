#include "ControlsWidget.h"

ControlsWidget::ControlsWidget(QWidget *parent) : QWidget(parent)
{
    ControlsLayout = new QGridLayout(this);
    UndoMovesText = new QPlainTextEdit(this);

    SaveGameButton = new QPushButton(this);
    LoadGameButton = new QPushButton(this);
    QuitTabButton = new QPushButton(this);
    BeginningButton = new QPushButton(this);
    PreviousMoveButton = new QPushButton(this);
    NextMoveButton = new QPushButton(this);
    PlayPauseButton = new QPushButton(this);

    UndoMovesTextDescription = new QLabel(this);
    PlayIntervalDescription = new QLabel(this);
    PlayIntervalInput = new QDoubleSpinBox(this);

    ControlsLayout->addWidget(SaveGameButton, 1, 1);
    ControlsLayout->addWidget(LoadGameButton, 1,2);
    ControlsLayout->addWidget(QuitTabButton, 1, 3);
    ControlsLayout->addWidget(UndoMovesTextDescription, 2, 1,1,3);
    ControlsLayout->addWidget(UndoMovesText, 3, 1, 1, 3);
    ControlsLayout->addWidget(BeginningButton, 4,1);
    ControlsLayout->addWidget(PreviousMoveButton, 4, 2);
    ControlsLayout->addWidget(NextMoveButton, 4, 3);
    ControlsLayout->addWidget(PlayIntervalDescription, 5,1);
    ControlsLayout->addWidget(PlayIntervalInput, 5, 2);
    ControlsLayout->addWidget(PlayPauseButton, 5, 3);

    UndoMovesTextDescription->setText("Moves");
    UndoMovesText->setReadOnly(true);
    UndoMovesText->setPlainText("1.abcdefgh\n2.efghijklm");

    PlayIntervalDescription->setText("Interval");
    PlayIntervalInput->setRange(0.1,10.0);
    PlayIntervalInput->setSingleStep(0.1);
    PlayIntervalInput->setDecimals(1);
    PlayIntervalInput->setSuffix(" s");

    SaveGameButton->setText("Save");
    LoadGameButton->setText("Load");
    QuitTabButton->setText("Quit");
    BeginningButton->setText("Beginning");
    NextMoveButton->setText("Next move");
    PreviousMoveButton->setText("Previous move");
    PlayPauseButton->setText("Play");
}

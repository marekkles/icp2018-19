#ifndef __GAME_H

#define __GAME_H

#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream> 

#include "ClassDeclarations.h"
#include "Enums.h"
#include "Move.h"
#include "FigureBase.h"
#include "FigureFactory.h"

class Game
{
private:
	FigureFactory * _figureFactory;
	int _whitesScore;
	int _blacksScore;
	std::string _inputFileName;
	bool _loadLine(std::ifstream & inputFile, int lineNumber);
	void _saveLine(std::ostream & outputFile, int lineNumber, Move & move1, Move & move2);
	void _saveLine(std::ostream & outputFile, int lineNumber, Move & move1);
	
	void _copyBitfield(bool destination[8][8]);
	void _generateFigures();
	bool _isCheckmate();
	bool _isCheck();
	bool _isCheckForAllMovesOfFigure(FigureBase * figure);
	void _undoMove(Move & move);
	bool _doMove(Move & move);
	FigureBase * _figureThatCanDoMove(Move & move);
	void _changeTurn();
	void _updateTurnCounter(bool forward);
public:
	bool ValidMovesBitfield[8][8];
	std::list<Move> DoMoves;
	std::list<Move> UndoMoves;
	const std::list<FigureBase *> * Figures;
	FigureColor_t PlayerTurn;
	FigureColor_t Winner;
	bool GameEnd;
	bool Check;
	int TurnCounter;

	void BitfieldSet(FigureBase * figure);
	void BitfieldSet(Position & position);
	void BitfieldSet(int row, int coulumn);
	bool BitfieldGet(const Position & position);
	bool BitfieldGet(int row, int coulumn);
	void BitfieldClear();
	FigureColor_t GetFigureColorAt(Position & position);
	FigureType_t GetFigureTypeAt(Position & position);
	FigureBase * GetFigureAt(Position & position);
	bool NextMove();
	void PreviousMove();
	void FirstMove();
	bool UserMove(Move & move);
	bool LoadMoves(std::ifstream & inputFile);
	void SaveMoves(std::ostream & outputFile);

	Game();
	~Game();
};

#endif
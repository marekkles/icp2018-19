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
	
	void _generateFigures();
	void _loadDoList();
	bool _isCheck();
	void _undoMove(Move & move);
	bool _checkMove(Move & move);
	bool _tryMove(Move & move);
	void _forceMove(FigureBase * figure,Move & move);
public:
	bool ValidMovesBitfield[8][8];
	std::list<Move> DoMoves;
	std::list<Move> UndoMoves;
	const std::list<FigureBase *> * Figures;
	FigureColor_t PlayerTurn;
	FigureColor_t Winner;
	bool GameEnd;
	bool Check;

	void BitfieldSet(FigureBase * figure);
	void BitfieldSet(Position & position);
	void BitfieldSet(int row, int coulumn);
	bool BitfieldGet(Position & position);
	bool BitfieldGet(int row, int coulumn);
	void BitfieldClear();
	FigureColor_t GetFigureColorAt(Position & position);
	FigureType_t GetFigureTypeAt(Position & position);
	FigureBase * GetFigureAt(Position & position);
	bool NextMove();
	void PreviousMove();
	bool UserMove(Move & move);
	bool LoadMoves(std::ifstream & inputFile);

	Game();
	Game(std::string fileName);
	~Game();
};

#endif
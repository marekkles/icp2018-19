#ifndef __GAME_H

#define __GAME_H

#include <list>
#include <vector>
#include <string>
#include "Move.h"
#include "FigureFactory.h"


class Game
{
private:
	FigureFactory _figureFactory;
	int _whitesScore;
	int _blacksScore;
	std::string _inputFileName;
	void _generateFigures();
	void _loadDoList();
	bool _isCheck();
	bool _checkMove(Move & move);
	bool _tryMove(Move & move);
	void _forceMove(FigureBase & figure,Move & move);
public:
	std::list<Move> DoMoves;
	std::list<Move> UndoMoves;
	std::vector<FigureBase> * Figures;
	FigureColor_t PlayerTurn;
	FigureColor_t Winner;
	bool GameEnd;
	bool Check;

	FigureColor_t GetFigureColorAt(Position & position);
	FigureType_t GetFigureTypeAt(Position & position);
	bool NextMove();
	void PreviousMove();
	bool UserMove(Move & move);

	Game();
	Game(std::string fileName);
	~Game();
};

#endif
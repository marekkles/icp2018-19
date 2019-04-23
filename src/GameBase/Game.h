#ifndef __MOVE_H

#define __MOVE_H
#include <list>
#include <vector>
#include <string>
#include "Move.h"

typedef enum {NOBODY, PLAYER_WHITE, PLAYER_BLACK} GamePlayer_t;

class Game
{
private:
	int _whitesScore;
	int _blacksScore;
	string _inputFileName;
	void GenerateFigures();
	void LoadDoList();
	void TestCheck();
	bool CheckMove(Move * move);
	bool TryMove(Move * move);
	void MakeMove(Move * move);
public:
	std::list<Move *> DoMoves;
	std::list<Move *> UndoMoves;
	std::vector<FigureBase *> Figures;
	GamePlayer_t PlayerTurn;
	GamePlayer_t Winner;
	bool GameEnd;
	bool Check;

	int GetPlayerScore(GamePlayer_t player);
	bool NextMove();
	void PreviousMove();
	bool UserMove(Move * move);

	Game();
	Game(string fileName);
	~Game();
};

#endif
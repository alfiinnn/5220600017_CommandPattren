#pragma once
#include "Header.h"
#include "Invoker.h"
#include "Player.h"

class GameManager
{
private:
	Board* board;
	Player* player;
	Invoker undo;
	Invoker redo;
public:
	GameManager(Board*, Player*);
	void wrong_cell();
	void undo_act();
	void redo_act();
	void set_name();
	void fill_cell(int, int, int);
	void delete_cell(int, int);
	void Play();
};
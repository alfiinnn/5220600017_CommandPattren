#include "GameManager.h"

GameManager::GameManager(Board* board, Player* player)
{
	this->board = board;
	this->player = player;
}

void GameManager::wrong_cell()
{
	struct wrongCell
	{
		int x;
		int y;
		int isi;
	};

	std::vector <wrongCell> Cell;

	for (int p = 0; p < SIZE; ++p) {
		for (int q = 0; q < SIZE; ++q) {
			if (this->board->getCellValue(p, q) != this->board->getCellSolValue(p, q)) {
				Cell.push_back({ p, q, this->board->getCellValue(p,q) });
			}
		}
	}

	std::cout << std::endl
		<< "Semua cell benar, kecuali: " << std::endl;
	for (const auto& arr : Cell)
	{
		std::cout << "Cell "
			<< "[" << arr.x << "]"
			<< "[" << arr.y << "] : ";
		if (arr.isi == 0)
		{
			std::cout << "Masih Kosong";
		}
		else {
			std::cout << arr.isi;
		}
		std::cout << std::endl;
		Cell.pop_back();
	}
}



void GameManager::set_name()
{
	std::string username;
	std::cout << std::endl
		<< "Masukkan Nama Pemain: "; std::cin >> username;
	player->set_name(username);
}

void GameManager::Play()
{
	std::cout << std::endl << "berapa cell yang ingin dihapus ? : ";
	int r = 0; std::cin >> r;
	this->board->difficulty(r);
	board->generate();
}



void GameManager::undo_act()
{
	Command* copy;
	copy = &undo.pop();
	std::cout << copy->get_type();
	redo.push(copy);
	copy->undo();

	std::cout << "Undo on []"
		<< copy->get_query(0) << "]["
		<< copy->get_query(1) << "]" << std::endl;
}

void GameManager::redo_act()
{
	Command* copy;
	copy = &redo.pop();
	undo.push(copy);
	copy->redo();
	std::cout << "Redo on []"
		<< copy->get_query(0) << "]["
		<< copy->get_query(1) << "]" << std::endl;
}

void GameManager::fill_cell(int x, int y, int value)
{
	Fill* copy = new Fill;
	copy->set_board(board);
	if (board->getCellValue(x, y) != 0)
	{
		std::cout << std::endl << "Cell already has value!" << std::endl;
	}
	else
	{
		copy->execute(x, y, value);
	}
	undo.push(copy);
}

void GameManager::delete_cell(int x, int y)
{
	Delete* copy = new Delete;
	copy->set_board(board);
	undo.push(copy);
	copy->execute(x, y);
}
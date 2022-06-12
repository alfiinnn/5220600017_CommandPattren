#pragma once
#include "Header.h"

class Player
{
private:
	std::string name;
	int score;
public:
	Player();
	~Player() = default;
	void set_name(std::string);
	void set_score(int);
	std::string get_name();
	int get_score();
};
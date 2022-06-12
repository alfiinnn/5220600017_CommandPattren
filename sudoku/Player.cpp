#include "Player.h"

Player::Player()
{
	name = "";
	score = 0;
}

void Player::set_name(std::string name)
{
	this->name = name;
}

void Player::set_score(int score)
{
	this->score = score;
}

std::string Player::get_name()
{
	return name;
}

int Player::get_score()
{
	return score;
}
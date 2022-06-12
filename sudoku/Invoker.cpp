#include "Invoker.h"

Invoker::Invoker()
{
	history.clear();
}

void Invoker::push(Command* command)
{
	history.push_back(command);
}

Command& Invoker::pop()
{
	if (history.empty())
	{
		std::cout << std::endl
			<< "salah"
			<< std::endl;
	}
	else
	{
		Command* temp = std::move(history.back());
		Fill* a;

		history.pop_back();

		return *temp;
	}
}

bool Invoker::kosong()
{
	return history.empty();
}

int Invoker::getsize()
{
	return history.size();
}
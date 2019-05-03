#include "Game.h"
#include <ctime>
#include <cstdlib>

Game::Game(int turns, int max)
{
	maxNumber = max;
	numberOfTurnsLeft = turns;
	correctAnswer = generateNumber(max);
}

int Game::generateNumber(int max)
{
	srand(time(NULL));
	return (rand() % max++);
}

bool Game::guessIsCorrect(int guess)
{
	return (guess == correctAnswer);
}

bool Game::outOfTurns()
{
	return (numberOfTurnsLeft == 0);
}

void Game::takeTurn()
{
	numberOfTurnsLeft--;
}

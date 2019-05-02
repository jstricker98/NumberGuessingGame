#include "Game.h"
#include <ctime>
#include <cstdlib>

easyGame::easyGame()
{
	maxNumber = 10;
	numberOfTurnsLeft = 5;
	correctAnswer = generateNumberForEasy();
}

int easyGame::generateNumberForEasy()
{
	srand(time(NULL));
	return ((rand() % 10) + 1);
}

mediumGame::mediumGame()
{
	maxNumber = 50;
	numberOfTurnsLeft = 10;
	correctAnswer = generateNumberForMedium();
}

int mediumGame::generateNumberForMedium()
{
	srand(time(NULL));
	return ((rand() % 50) + 1);
}

hardGame::hardGame()
{
	maxNumber = 100;
	numberOfTurnsLeft = 10;
	correctAnswer = generateNumberForHard();
}

int hardGame::generateNumberForHard()
{
	srand(time(NULL));
	return ((rand() % 100) + 1);
}

insaneGame::insaneGame()
{
	maxNumber = 1000;
	numberOfTurnsLeft = 10;
	correctAnswer = generateNumberForInsane();
}

int insaneGame::generateNumberForInsane()
{
	srand(time(NULL));
	return ((rand() % 1000) + 1);
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
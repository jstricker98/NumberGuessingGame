#include "Game.h"
#include <ctime>
#include <cstdlib>

easyGame::easyGame()
{
	maxNumber = 10;
	numberOfTurnsLeft = 4;
	correctAnswer = generateNumberForEasy();
}

int easyGame::generateNumberForEasy()
{
	srand(time(NULL));
	return (rand() % 11);
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
	return (rand() % 51);
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
	return (rand() % 101);
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
	return (rand() % 1001);
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

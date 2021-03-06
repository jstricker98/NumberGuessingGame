#include <iostream>
#include <algorithm>
#include "Game.h"
#include "NumberGuessingGame.h"

using namespace std;

void printIntroduction()
{
	cout << "Hello and welcome to my guessing game.\n"
		"In this game all you have to do is guess the randomly generated number.\n"
		"But be careful you have a limited number of guesses before you lose\n";
}

void printDifficultyDefinitions()
{
	cout << "\nPlease select which difficulty you would like to play.\n\n"
		"Easy ------- 4 turns to guess a number between 0 and 10\n\n"
		"Medium ------- 10 turns to guess a number between 0 and 50\n\n"
		"Hard ------- 10 turns to guess a number between 0 and 100\n\n"
		"Insane ------- 10 turns to guess a number between 0 and 1000\n\n";
}

Game selectDifficulty()
{
	printDifficultyDefinitions();
	while (true)
	{
		string difficulty;
		cin >> difficulty;
		char difficultyLetter = difficulty[0];
		switch (tolower(difficultyLetter))
		{
		case 'e': return Game(4,10);
			break;
		case 'm': return Game(10,50);
			break;
		case 'h': return Game(10,100);
			break;
		case 'i': return Game(10,1000);
			break;
		default: cout << "Please enter a valid option.\n";
		}
	}
}

bool guessIsValid(int max_number, int guess)
{
	return (guess > 0 && guess < max_number);
}

int getGuess(Game& game)
{
	cout << "Please guess a number.\n";
	int guess;
	while (true)
	{
		cin >> guess;
		cout << endl;
		if (guessIsValid(game.maxNumber, guess))
		{
			return guess;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid number between 0 and " << game.maxNumber << endl;
	}
}

bool guessHandler(Game& game, int guess)
{
	if (game.guessIsCorrect(guess))
	{
		cout << "Congratulations you guessed the correct number!\n";
		return true;
	}
	else if (guess > game.correctAnswer)
	{
		cout << "To high!\n"
			"You have "<<game.numberOfTurnsLeft<<" turn(s) left.\n";
		return false;
	}
	cout << "Too low!\n"
		"You have " << game.numberOfTurnsLeft << " turn(s) left.\n";;
	return false;
}

void takeTurn(Game& game)
{
	while (!game.outOfTurns())
	{
		int guess = getGuess(game);
		game.takeTurn();
		if (guessHandler(game, guess))
		{
			break;
		}
	}
}

void playGame(Game& game)
{
	takeTurn(game);
	if (game.outOfTurns())
	{
		cout << "You ran out of turns!\n"
			"The correct answer was "<< game.correctAnswer<<endl;
	}
}

bool wantsToPlayAgain()
{
	cout << "Would you like to play again?\n\n Yes or No\n";
	while (true)
	{
		string answer;
		cin >> answer;
		char answerLetter = answer[0];
		switch (tolower(answerLetter))
		{
		case 'y': return true;
			break;
		case 'n': return false;
			break;
		default: cout << "Please enter a valid option.\n";
		}
	}
	
}

int main()
{
	bool wantsToPlay = true;
	printIntroduction();
	while (wantsToPlay)
	{
		Game gameToPlay = selectDifficulty();
		playGame(gameToPlay);
		wantsToPlay = wantsToPlayAgain();
	}
	cout << "Thanks for playing!\n";
	return 0;
}

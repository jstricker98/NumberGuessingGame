
class Game
{
public:
	Game(int, int);
	int generateNumber(int);
	bool guessIsCorrect(int);
	bool outOfTurns();
	void takeTurn();
	int maxNumber;
	int numberOfTurnsLeft;
	int correctAnswer; 
};

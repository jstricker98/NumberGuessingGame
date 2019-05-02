
class Game
{
public:
	bool guessIsCorrect(int);
	bool outOfTurns();
	void takeTurn();
	int maxNumber;
	int numberOfTurnsLeft;
	int correctAnswer; 
};

class easyGame : public Game
{
public:
	easyGame();
	int generateNumberForEasy();
};

class mediumGame : public Game
{
public:
	mediumGame();
	int generateNumberForMedium();
};

class hardGame : public Game
{
public:
	hardGame();
	int generateNumberForHard();
};

class insaneGame : public Game
{
public:
	insaneGame();
	int generateNumberForInsane();
};
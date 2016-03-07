#pragma once

class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();

	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	//bool CheckGuessValidity(string);

private:
	int MyCurrentTry;
	int MyMaxTries;

};
#pragma once
#include<iostream>

class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();

	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;

};
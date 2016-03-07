#pragma once
#include<iostream>

class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();

	void Reset();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;

};
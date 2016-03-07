#pragma once
#include<string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();

	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;

};
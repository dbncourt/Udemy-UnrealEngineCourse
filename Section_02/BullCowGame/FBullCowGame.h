#pragma once
#include<string>
#include<map>
#define TMap std::map

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame();
	~FBullCowGame();

	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	int32 GetHiddenWordLength() const;

	FBullCowCount SubmitGuess(FString Guess);

private:
	int32 CurrentTry;
	FString HiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLoweCase(FString) const;
};
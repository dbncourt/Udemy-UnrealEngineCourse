#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	FBullCowGame::Reset();
}

FBullCowGame::~FBullCowGame()
{
}

void FBullCowGame::Reset()
{
	this->MyHiddenWord = "planet";
	this->MyMaxTries = 8;
	this->MyCurrentTry = 0;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
	++this->MyCurrentTry;

	BullCowCount Response;

	return Response;
}

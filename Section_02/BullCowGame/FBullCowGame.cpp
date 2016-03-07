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
	this->HiddenWord = "ant";
	this->MaxTries = 8;
	this->CurrentTry = 0;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return CurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	++this->CurrentTry;

	FBullCowCount Response;

	for (int32 i = 0; i < Guess.length(); ++i)
	{
		for (int32 j = 0; j < this->HiddenWord.length(); ++j)
		{
			if (Guess[i] == this->HiddenWord[j])
			{
				if (i == j)
				{
					++Response.Bulls;
				}
				else
				{
					++Response.Cows;
				}
			}
		}
	}

	return Response;
}

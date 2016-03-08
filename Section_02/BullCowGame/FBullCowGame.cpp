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

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() < FBullCowGame::GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return static_cast<int32>(this->HiddenWord.length());
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

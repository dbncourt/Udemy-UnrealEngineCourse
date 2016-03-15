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
	this->HiddenWord = "planet";
	this->CurrentTry = 0;
	this->bGameIsWon = false;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3, 5}, {4, 5}, {5, 5}, {6, 5} };
	return WordLengthToMaxTries[HiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return CurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return this->bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length() != FBullCowGame::GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsLoweCase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
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

	if (Response.Bulls == this->HiddenWord.length())
	{
		this->bGameIsWon = true;
	}
	return Response;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() < 2) { return true; }
	TMap<char, bool> LettersSeen;

	for (char Letter : Word)
	{
		Letter = tolower(Letter);
		if (LettersSeen[Letter])
		{
			return false;
		}
		LettersSeen[tolower(Letter)] = true;
	}
	return true;
}

bool FBullCowGame::IsLoweCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}

void myFunction(std::string c)
{

}

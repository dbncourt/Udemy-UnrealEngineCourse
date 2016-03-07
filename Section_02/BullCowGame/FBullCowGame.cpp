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
	this->MyMaxTries = 8;
	this->MyCurrentTry = 0;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

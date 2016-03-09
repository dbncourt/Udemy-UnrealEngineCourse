#include<iostream>
#include<string>
#include "FBullCowGame.h"

using FTEXT = std::string;
using int32 = int;

FBullCowGame BCGame = FBullCowGame();
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FTEXT GetValidGuess();

int32 main()
{
	do
	{
		BCGame.Reset();
		system("cls");
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

void PlayGame()
{
	for (int32 i = 0; i < BCGame.GetMaxTries(); ++i)
	{
		FTEXT Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl;
	}
}

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n";
}

FTEXT GetValidGuess()
{
	do
	{
		FTEXT Guess = "";

		std::cout << "Try " << BCGame.GetCurrentTry() + 1 << ". Enter your guess: ";
		getline(std::cin, Guess);
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Length:
				{
					std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
					break;
				}
			case EGuessStatus::Not_Isogram:
				{
					std::cout << "Please enter a word without repeating letters.\n";
					break;
				}
			case EGuessStatus::Not_Lowercase:
				{
					std::cout << "Please enter a all lowercase letters.\n";
					break;
				}
			case EGuessStatus::OK:
				{
					return Guess;
				}
		}
	} while (true);

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?: ";
	FTEXT Response = "";
	getline(std::cin, Response);

	return Response[0] == 'Y' || Response[0] == 'y';
}
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
void PrintGameSummary();

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
	while (!BCGame.IsGameWon() && BCGame.GetMaxTries() > BCGame.GetCurrentTry())
	{
		FTEXT Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << ". Cows = " << BullCowCount.Cows << std::endl;
	}
	PrintGameSummary();
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

		std::cout << "\nTry " << BCGame.GetCurrentTry() + 1 << "/" << BCGame.GetMaxTries() << ". Enter your guess: ";
		getline(std::cin, Guess);
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessStatus::Wrong_Length:
				{
					std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
					break;
				}
			case EGuessStatus::Not_Isogram:
				{
					std::cout << "Please enter a word without repeating letters.\n\n";
					break;
				}
			case EGuessStatus::Not_Lowercase:
				{
					std::cout << "Please enter a all lowercase letters.\n\n";
					break;
				}
			case EGuessStatus::OK:
				{
					return Guess;
				}
		}
	} while (true);

}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "\nWELL DONE - YOU WIN!.";
	}
	else
	{
		std::cout << "\nBetter luck next time!";
	}
}

bool AskToPlayAgain()
{
	std::cout << "\nDo you want to play again?: ";
	FTEXT Response = "";
	getline(std::cin, Response);

	return Response[0] == 'Y' || Response[0] == 'y';
}
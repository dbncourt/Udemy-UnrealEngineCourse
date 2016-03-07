#include<iostream>
#include<string>
#include "FBullCowGame.h"

using FTEXT = std::string;
using int32 = int;

FBullCowGame BCGame = FBullCowGame();
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FTEXT GetGuess();

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
		FTEXT Guess = GetGuess();
		std::cout << "Your guess was " << Guess << std::endl;
	}
}

void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

FTEXT GetGuess()
{
	FTEXT Guess = "";

	std::cout << "Try " << BCGame.GetCurrentTry() + 1 << ". Enter your guess: ";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?: ";
	FTEXT Response = "";
	getline(std::cin, Response);

	return Response[0] == 'Y' || Response[0] == 'y';
}
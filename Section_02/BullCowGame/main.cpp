#include<iostream>
#include<string>
#include "FBullCowGame.h"

FBullCowGame BCGame = FBullCowGame();
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();

int main()
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
	for (int i = 0; i < BCGame.GetMaxTries(); ++i)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was " << Guess << std::endl;
	}
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

std::string GetGuess()
{
	std::string Guess = "";

	std::cout << "Try " << BCGame.GetCurrentTry() + 1 << ". Enter your guess: ";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?: ";
	std::string Response = "";
	getline(std::cin, Response);

	return Response[0] == 'Y' || Response[0] == 'y';
}
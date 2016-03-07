#include<iostream>
#include<string>

void PrintIntro();
void PlayGame(const int &NUMBER_OF_TURNS);
bool AskToPlayAgain();
std::string GetGuess();

int main()
{
	constexpr int NUMBER_OF_TURNS = 5;

	do
	{
		system("cls");
		PrintIntro();
		PlayGame(NUMBER_OF_TURNS);
	} while (AskToPlayAgain());
	
	return 0;
}

void PlayGame(const int &numberOfTurns)
{
	for (int i = 0; i < numberOfTurns; ++i)
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

	std::cout << "Enter your guess: ";
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
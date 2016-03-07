#include<iostream>
#include<string>


using namespace std;

void PrintIntro();
void PlayGame(const int &NUMBER_OF_TURNS);
bool AskToPlayAgain();
string GetGuess();

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
		string Guess = GetGuess();
		cout << "Your guess was " << Guess << endl;
	}
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

string GetGuess()
{
	string Guess = "";

	cout << "Enter your guess: ";
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?: ";
	string Response = "";
	getline(cin, Response);

	return Response[0] == 'Y' || Response[0] == 'y';
}
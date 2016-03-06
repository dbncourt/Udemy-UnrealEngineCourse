#include<iostream>
#include<string>


using namespace std;

void PrintIntro();
void PlayGame(const int &NUMBER_OF_TURNS);
string GetGuess();

int main() 
{
	constexpr int NUMBER_OF_TURNS = 5;
	PrintIntro();
	PlayGame(NUMBER_OF_TURNS);

	return 0;
}

void PlayGame(const int &numberOfTurns)
{
	for (int i = 0; i < numberOfTurns; ++i)
	{
		Print(GetGuess());
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

void Print(string toPrint) 
{
	cout << "Your guess was " << toPrint << endl;
}
#include<iostream>
#include<string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main() 
{
	PrintIntro();
	GetGuessAndPrintBack();

	return 0;
}

void PrintIntro()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

string GetGuessAndPrintBack() 
{
	string Guess = "";
	// get a guess from the player
	cout << "Enter your guess: ";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was " << Guess << endl;
	
	return Guess;
}
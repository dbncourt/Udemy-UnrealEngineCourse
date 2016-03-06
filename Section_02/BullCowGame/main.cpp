#include<iostream>
#include<string>

using namespace std;
int main() 
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";

	// get a guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	// repeat the guess back to them
	cout << "Your guess was " << Guess << endl;

	return 0;
}
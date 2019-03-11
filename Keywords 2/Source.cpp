#include <iostream>		
#include <string>		
#include <stdlib.h>		
#include <ctime>		
#include <random>		

using std::string;
using std::endl;
using std::time;
using std::cin;
using std::cout;						

int main() {
	// sets the size to 10
	const int size = 10;		
	enum fields { WORD, HINT, fields };	
	// This is the word bank that will be used to output scrambled words and hits for those words
	string wordBank[size][fields] = {		
		{"guardian",  "A defender or protector."}, {"time", "Something people wished they had more of."},

		{"money", "You use it to buy things."}, {"program",  "What this game is."},		

		{"student",  "A person who pays to study"},	{"mother",  "A woman who raises a child."},	

		{"pineapple",  "A tropical fruit."}, {"president",   "An elected leader."},		

		{"medicine", "This is used to help sick people."},	{"dragon",  "A large, fire-breathing reptile."}			
	};
	string nameOfPlayer = "";
	// welcomes the player
	cout << " Welcome to Code Breaker 2, \n ";		
	// Has the player enter their name
	cout << "Please Enter Your Name \n\n ";
	// Uses the player's name to tell them the directions for the game
	cin >> nameOfPlayer,
		// describes the directions 
		cout << "\n " << nameOfPlayer << ", this game will challenge you to unscramble coded words, \n ";
	cout << "feel free to type 'hint' to receive a hint if you get stuck!\n The game starts now!\n\n";					
	// pauses so the player can read
	system("pause");

	// asks the user if they would like to play again
	char PlayAgain = 'y';	

	// While play agin isn't no
	while (PlayAgain != 'n') {				
		// Declares the total amount of attempts 
		int totalAttempts = 0;	
		// Declares the total amount of incorrect guesses
		int wrongGuesses = 0;

		for (int i = 0; i < 3; i++) {		
			// Sets the amount of incorrect guesses to 0
			wrongGuesses = 0;
			srand(static_cast<unsigned int>(time(0)));		
			int choice = rand() % size;					
			string Word = wordBank[choice][WORD];	
			string Hint = wordBank[choice][HINT];
			string codedWord = Word;			

			// Tells how many letters there are in a given word
			for (int j = 0; j < codedWord.length(); j++) {		
			
				int index1 = rand() % codedWord.length();		
				int index2 = rand() % codedWord.length();		
				char buffer = codedWord[index1];	
				codedWord[index1] = codedWord[index2];			
				codedWord[index2] = buffer;						
			}
			int letterCount = 0;
			// Declares incorrect guesses
			int count = letterCount + codedWord.length();		
			int totalCount = count + letterCount;
			// Displays the coded word
			cout << "Your jumbled word is: " << codedWord << endl;	
			// declares the players guess
			string playerGuess = "";			
			// While the player's guess isn't the coded word,
			while (playerGuess != Word) {	
				// Offer a hint once the player has guessed incorrectly 3 times
				if ((wrongGuesses % 3 == 0) && (wrongGuesses > 0)) {
					// Displays the option for a hint
					cout << "Enter 'hint' for a hint\n";							
				}
				// Incorrect guesses increases by 1 for each incorrrect guess
				totalAttempts++;		
				// Again asks for the players guess and prompts for an imput
				cout << "Your guess: ";		
				cin >> playerGuess;			
				// If the player enters 'hint'
				if (playerGuess == "hint") {			
					// Set the amount of incorrect guesses to 0
					wrongGuesses = 0;
					// Displays the hint for the coded word
					cout << Hint << endl << endl;	
				}
				// Otherwise if the players guess isn't the coded word, increase the amount of incorrect guesses
				else if (playerGuess != Word) {		
					// incrament the incorrect guesses
					wrongGuesses++;
					// tells the player that they are wrong
					cout << "Incorrect!\n\n";			
				}
			}
			// tells the player they have guessed correctly
			cout << "letter count" << count << "\nCorrect!\n\n";			
		}
		// Tells the player that the game is over
		cout << "COMPLETE!!!\n\n";
		// Displays the total amount of attempts
		cout << nameOfPlayer << " Total Attempts: " << totalAttempts << endl;
		// Asks the player if they would like to play again
		do {      
			cout << "Play again? Y/N: ";		
			cin >> PlayAgain;					
		}
		while (PlayAgain != 'Y' && PlayAgain != 'N');	
	}
	return 0;		
}
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Periodic table data arrays
const int numElements = 5; // Example with a few elements; expand as needed
const string elementNames[numElements] = { "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron" };
const string elementSymbols[numElements] = { "H", "He", "Li", "Be", "B" };
const int atomicNumbers[numElements] = { 1, 2, 3, 4, 5 };

// Function to generate a random question
void generateQuestion(int& index, int& correctAnswerType) {
    index = rand() % numElements;          // Pick a random element index
    correctAnswerType = rand() % 3;        // Randomly choose question type (0=name, 1=symbol, 2=atomic number)
}

// Main game function
void playGame() {
    int score = 0;
    char playAgain;

    do {
        int index, correctAnswerType;
        generateQuestion(index, correctAnswerType);

        string userAnswer;
        int userAtomicAnswer;

        // Ask question based on random choice
        if (correctAnswerType == 0) {
            cout << "What is the symbol for " << elementNames[index] << "? ";
            cin >> userAnswer;
            if (userAnswer == elementSymbols[index]) {
                cout << "Correct!\n";
                score++;
            }
            else {
                cout << "Incorrect. The symbol for " << elementNames[index] << " is " << elementSymbols[index] << ".\n";
            }
        }
        else if (correctAnswerType == 1) {
            cout << "What element has the symbol " << elementSymbols[index] << "? ";
            cin >> userAnswer;
            if (userAnswer == elementNames[index]) {
                cout << "Correct!\n";
                score++;
            }
            else {
                cout << "Incorrect. The element with symbol " << elementSymbols[index] << " is " << elementNames[index] << ".\n";
            }
        }
        else {
            cout << "What is the atomic number of " << elementNames[index] << "? ";
            cin >> userAtomicAnswer;
            if (userAtomicAnswer == atomicNumbers[index]) {
                cout << "Correct!\n";
                score++;
            }
            else {
                cout << "Incorrect. The atomic number of " << elementNames[index] << " is " << atomicNumbers[index] << ".\n";
            }
        }

        // Display current score
        cout << "Your current score is: " << score << endl;

        // Ask if they want to play again
        cout << "Do you want to try another question? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Your final score was: " << score << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator

    cout << "Welcome to the Periodic Table Quiz Game!\n";
    playGame();

    return 0;
}
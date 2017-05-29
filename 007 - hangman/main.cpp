#include "hangmangame.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;

int main()
{
  Hangman game;

  cout << "Welcome to hangman!" << endl;
  std::string input = "";
  int game_state = -1;

  cout << game.getWord() << endl;

  while (game_state != LOSS && game_state != WIN)
  {
    // Print guesses remaining and guess status of current word.
    system("CLS");
    cout << "You have " << game.getLife() << " guesses remaining." << endl;
    game.printCorrectlyGuessed();
    do
    {
      cout << "Please guess a character:" << endl;
      cin >> input;
    } while (input.size() != 1);


    // Pompt user guess and provide feedback.
    game_state = game.guess(input[0]);

    if (game_state == CORRECT)
      cout << "You guessed the right letter!" << endl;
    else if (game_state == INCORRECT)
      cout << "You guessed the wrong letter!" << endl;

    if (game_state == LOSS)
      cout << "You lost the game!" << endl;
    else if (game_state == WIN)
      cout << "You won the game!" << endl;
  }

  std::cout << Correct word : << game.printCorrectlyGuessed() << endl;
  return 0;
}
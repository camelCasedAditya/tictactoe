/*
Aditya Chandrashekaran
9/12/2024
This program allow two players to play tictactoe.
The program checks for wins and ties and keeps track of how many wins each player has.
The program gives the user the option to play again after one game has been completed.
*/

#include <iostream>
#include <cstring>

using namespace std;

// Defining constant variables
const int BLANK = 0;
const int XMOVE = 1;
const int OMOVE = 2;

const int XTURN = 0;
const int OTURN = 1;

bool checkWin (int player, int board[3][3]);
bool checkTie (int board[3][3]);
void printBoard (int board[3][3]);

int main() {
  // initalize variables to keep track of turn and wins
  int xwins = 0;
  int owins = 0;
  int turn = XTURN;

  // variable that stores the input move from the user
  int input = 0;

  // array that stores the moves that have been made
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  // keeps track of whether the user wants to play again or not
  bool playingAgain = true;

  while (playingAgain == true) {
    // display players wins
    cout << "X wins: " << xwins << " | O wins: " << owins << endl;
    while (checkWin(XMOVE, board) == false && checkWin(OMOVE, board) == false && checkTie(board) == false) {
      // tells user whose turn it is
      if (turn == XTURN) {
	cout << "It is X\'s turn" << endl;
      }
      else {
	cout << "It is O\'s turn" << endl;
      }

      // prints board
      printBoard(board);

      // Asks the user to input their move and stores the input
      cout << "Enter the number corresponding to the square where you would like to make your move (1-9): " << endl;
      cin >> input;

      // While the input is invalid ask for a new input
      while (input > 9 || input < 1) {
	cout << "Enter a valid number between 1-9 to select you move: " << endl;
	cin >> input;
      }

      input = input - 1;

      // while the input is an occupied square ask for a new input
      while (board[input/3][input%3] == XMOVE || board[input/3][input%3] == OMOVE) {
	cout << "That square is taken. Please pick a different square (1-9): " << endl;
	cin >> input;
	input = input-1;
      }

      // Store the players move and then change the turn
      if (turn == XTURN) {
	board[input/3][input%3] = XMOVE;
	turn = OTURN;
      }
      else {
	board[input/3][input%3] = OMOVE;
	turn = XTURN;
      }
    }

    // If X wins we update X's win count and notify the players
    if (checkWin(XMOVE, board) == true) {
      printBoard(board);
      xwins += 1;
      cout << "Player X Wins" << endl;
    }
    // If O wins we update O's win cont and notify the players
    else if (checkWin(OMOVE, board) == true) {
      printBoard(board);
      owins+=1;
      cout << "Player O Wins" << endl;
    }

    // if the game is a tie nobody gets point and we notify the players
    else if (checkTie(board) == true) {
      printBoard(board);
      cout << "The Game is a Tie" << endl;
    }

    // Ask the players if they want to play again
    char playAgainInput;
    cout << "Would you like to play again. Type \'y\' or \'n\':" << endl;
    cin >> playAgainInput;

    // if the want to play again we clear the board
    if (playAgainInput == 'y') {
      playingAgain = true;
      for (int i = 0; i < 3; i++) {
	for (int j = 0; j < 3; j++) {
	  board[i][j] = 0;
	}
      }
    }
    // If they dont want to play again we set playingAgain to false which ends the program
    else {
      playingAgain = false;
    }
  }
  return 0;
}


// Function to check if a player has won
// Sees if a player has 3 in a row on every row, column, diagonal
// Returns true if the player is winning
bool checkWin(int player, int board[3][3]) {
  if (board[0][0] == player &&
      board[0][1] == player &&
      board[0][2] == player) {
    return true;
  }
  else if (board[1][0] == player &&
	   board[1][1] == player &&
	   board[1][2] == player) {
    return true;
  }
  else if (board[2][0] == player &&
	   board[2][1] == player &&
	   board[2][2] == player) {
    return true;
  }
  else if (board[0][0] == player &&
	   board[1][0] == player &&
	   board[2][0] == player) {
    return true;
  }
  else if (board[0][1] == player &&
	   board[1][1] == player &&
	   board[2][1] == player) {
    return true;
  }
  else if (board[0][2] == player &&
	   board[1][2] == player &&
	   board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player &&
      board[0][1] == player &&
      board[0][2] == player) {
    return true;
  }
  else if (board[1][0] == player &&
	   board[1][1] == player &&
	   board[1][2] == player) {
    return true;
    }
    else if (board[2][0] == player &&
	     board[2][1] == player &&
	     board[2][2] == player) {
      return true;
    }
    else if (board[0][0] == player &&
	     board[1][0] == player &&
	     board[2][0] == player) {
      return true;
    }
    else if (board[0][1] == player &&
	     board[1][1] == player &&
	     board[2][1] == player) {
      return true;
    }
    else if (board[0][2] == player &&
	     board[1][2] == player &&
	     board[2][2] == player) {
      return true;
    }
    else if (board[0][0] == player &&
	     board[1][1] == player &&
	     board[2][2] == player) {
      return true;
    }
    else if (board[0][2] == player &&
	     board[1][1] == player &&
	     board[2][0] == player) {
      return true;
    }
  return false;
}

// Checks if all the squares are full and nobody has won
// If that condition is true then the game is a tie
bool checkTie(int board[3][3]) {
  for (int row = 0; row<3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	return false;
      }
    }
  }
  return true;
}

// Function to print out board
void printBoard(int board[3][3]) {
  // output char array
  char output[20] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};

  //loops through every row and column
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      int length = strlen(output);
      // adds X or O or \' \' to output array based on if board contains X move or O move or Blank
      if (board[row][column] == BLANK) {
	output[length] = (char)((row*3)+column+49);
      }
      else if (board[row][column] == XMOVE) {
	output[length] = 'X';
      }
      else if (board[row][column] == OMOVE) {
	output[length] = 'O';
      }
    }
    // Adds new line after each row
    output[(row*4)+3] = '\n';
  }
  // Adds null character to end of the output array
  output[strlen(output)] = '\0';
  // Prints out the board
  cout << output << endl;
}

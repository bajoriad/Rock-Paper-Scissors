/**
 * rps.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 2
 * Winter 2021
 *
 * Print a program to play the rock-paper-scissors game between two players
 *
 */

#include <iostream>
#include <string>

const int MAX_ROUNDS = 3;
const int MENU_QUIT = 3;
using namespace std;

//************************************************************************
// The following four functions have already been implemented for you.
// You should use them when writing the other functions, but do not edit
// their implementations.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints a pretty header to introduce the user to the game.
 */
void printInitialHeader();

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints the menu.
 * Prompts:  "1) Play rock, paper, scissors"
 *           "2) Play rock, paper, scissors, lizard, spock"
 *           "3) Quit"
 *           "Choice --> "
 */
void printMenu();

/**
 * Requires: errorNumber be either 1 or 2
 * Modifies: cout
 * Effects:  If errorNumber is 1, prints an error message indicating
 *           an illegal name was entered.
 *           If errorNumber is 2, prints an error message indicating
 *           an illegal move was entered.
 */
void printErrorMessage(int errorNumber);

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints out the final greeting for the program.
 */
void printCloser();

//************************************************************************
// You must implement all of the following functions. Add your 
// implementations below main as indicated.
//************************************************************************

/**
 * Requires: playerNumber is either 1 or 2
 * Modifies: cout, cin
 * Effects:  Prompts the user to enter their name. Names entered may
 *           have spaces within them.
 *               Example: "Kermit the frog"
 *
 *           If an empty name is given, this is invalid input, so print
 *           error message 1, and return a default name.
 *           For player 1, the default name is: Rocky
 *           For player 2, the default name is: Creed
 *              
 *           NOTE: For this function to work correctly on the autograder, you
 *           must print an extra newline before you return from the function.
 * Prompt:   Player [playerNumber], enter your name:
 */
string getName(int playerNumber);


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Prints the menu, and reads the input from the user.
 *           Checks to make sure the input is within range for the menu.
 *           If it is not, prints "Invalid menu choice". Continues to print 
 *           the menu and read in input until a valid choice is entered,
 *           then returns the user's choice of menu options. You can assume
 *           a user will enter an integer, and nothing else, as their choice.
 *
 *           NOTE: For this function to work correctly on the autograder, you
 *           must print an extra newline after every call to cin.
 * Prompt:   Invalid menu choice
 */
int getMenuChoice();


/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character:
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);


/**
 * Requires: playerName is the name of the player being prompted for their
 *           move.
 * Modifies: cout, cin
 * Effects:  Prompts the player for their move and returns it.
 *           This function should accept the first non-whitespace character as
 *           the move. If an illegal character is entered for their move, print
 *           error message 2 and return rock as a default. You can assume a user
 *           will enter a single character, and nothing else, as their move.
 *
 *           NOTE: For this function to work correctly on the autograder, you
 *           must print an extra newline before you return from the function.
 * Prompt:   [playerName], enter your move:
 */
char getMove(string playerName);


/**
 * Requires: move is the move of the player being checked for a win.
 *           opponentMove is the move of the opponent.
 *           both move and opponentMove are valid moves.
 * Modifies: nothing
 * Effects:  Returns true if and only if the player who made move won
 *           according to the rules to rock-paper-scissors. Returns false
 *           otherwise.
 */
bool isRoundWinner(char move, char opponentMove);


/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is empty, prints a message indicating the round
 *           is a draw. Otherwise, prints a congratulatory message to the
 *           winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players
 * Modifies: nothing
 * Effects:  Simulates a complete round of rock-paper-scissors, which
 *           consists of three steps:
 *             1. Get player1 move
 *             2. Get player2 move
 *             3. Return 0 if the round was a draw; 1 if player 1 won;
 *                2 if player 2 won.
 */
int doRound(string p1Name, string p2Name);


/**
 * Requires: winnerName is the name of the player who won the game.
 * Modifies: cout
 * Effects:  If winnerName is blank, prints that the game was a draw.
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   No winner!
 *           ------------- OR -------------
 *           Congratulations [winnerName]!
 *           You won EECS 183 Rock-Paper-Scissors!
 */
void announceWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players,
 *           gameType can be 1 for regular rock-paper-scissors
 *           or 2 for rock-paper-scissors-lizard-spock
 * Modifies: cout
 *
 * Base Project:
 * Effects:  If gameType is 2, prints "Under Construction" to indicate that the
 *           s'more has not been implemented. Returns empty string.
 *           Otherwise, plays exactly three rounds of rock-paper-scissors while
 *           keeping track of the number of round wins for each player.
 *           When a round results in a draw, neither player is the winner,
 *           so neither player is awarded a point.
 *           After each round is played, the round winner (or draw) is
 *           announced. Returns the name of the winner or an empty string if the
 *           game ended in a draw.
 * Prompt:   Under Construction
 *
 * S'more Version:
 * Effects:  Has same functionality as base project, but also handles a
 *           gameType of 2. When game_type is 2, plays exactly three rounds of
 *           rock-paper-scissors-lizard-spock. Keeps track of round wins for
 *           each player and announces round winners in the same fashion as 
 *           described above.
 */
string doGame(string p1Name, string p2Name, int gameType);


// main function calling the other functions to play the game in its entirety
void rps()
{
    printInitialHeader();
    
    // player_1_name stores the name of player 1 by calling getName()
    string player_1_name = getName(1);
    
    // player_2_name stores the name of player 2 by calling getName()
    string player_2_name = getName(2);
    
    /* game_choice stores the menu choice inputted by the user by calling
     getMenuChoice()*/
    int game_choice = getMenuChoice();
    while (game_choice != MENU_QUIT)
    {
        /* game_winner stores the name of the game winner after three rounds of
         rock-paper-scissors has been played by calling doGame() */
        string game_winner = doGame(player_1_name, player_2_name, game_choice);
        announceWinner(game_winner);
        game_choice = getMenuChoice();
    }
    printCloser();
}

//************************************************************************
// Implement the functions below this line.
//************************************************************************


// asks the user to input his name/name of choice
string getName(int playerNumber)
{
    string player_name = "";
    cout << "Player " << playerNumber << ", enter your name: ";
    getline(cin, player_name);
    
    /* ifelse is used to print the default names when the user does not enter
       a valid name */
    if (player_name == "" && playerNumber == 1)
    {
        printErrorMessage(1);
        player_name = "Rocky";
    }
    else if (player_name == "" && playerNumber == 2)
    {
        printErrorMessage(1);
        player_name = "Creed";
    }
    cout << endl;
    return player_name;
}


/* prints the menu and asks the user to enter his menu choice until a valid
   choice is entered */
 int getMenuChoice()
{
    printMenu();
    int menu_choice = 0;
    cin >> menu_choice;
    cout << endl;
    
    /* ifelse ensures a valid menu choice is entered and continues to ask the
       user for a menu choice until a valid one is entered */
    if (menu_choice == 1 || menu_choice == 2 || menu_choice == MENU_QUIT)
    {
        return menu_choice;
    }
    else
    {
        cout << "Invalid menu choice" << endl;
        printMenu();
        cin >> menu_choice;
        cout << endl;
        while (menu_choice < 1 || menu_choice > MENU_QUIT)
        {
            printMenu();
            cin >> menu_choice;
            cout << endl;
        }
        return menu_choice;
    }
}


/* checks if the move played by the user is valid or not in accordance with
 the rules of the game */
bool isMoveGood(char move)
{
     if (move == 'r' || move == 'p' || move == 's' || move == 'R'
         || move == 'P' || move == 'S')
     {
         return true;
     }
     else
     {
         return false;
     }
}


/* asks the user to enter his move and prints the default move if an invalid
   move is entered */
char getMove(string playerName)
{
     char player_move = ' ';
     cout << playerName << ", enter your move: ";
     cin >> player_move;
     cout << endl;
    
    /* ifelse ensures a valid move is entered and prints the default move if an
        invalid move is entered */
     if (isMoveGood(player_move) == true)
     {
         return player_move;
     }
     else
     {
         printErrorMessage(2);
         player_move = 'r';
     }
     cout << endl;
     return player_move;
}


/* checks the winner of a round and ensures the winner has won the round in
   accordance with the rules of the game */
bool isRoundWinner(char move, char opponentMove)
{
     if ((move == 'r' && opponentMove == 's') ||
         (move == 's' && opponentMove == 'p') ||
         (move == 'p' && opponentMove == 'r') ||
         (move == 'R' && opponentMove == 'S') ||
         (move == 'S' && opponentMove == 'P') ||
         (move == 'P' && opponentMove == 'R') ||
         (move == 'R' && opponentMove == 's') ||
         (move == 'r' && opponentMove == 'S') ||
         (move == 'S' && opponentMove == 'p') ||
         (move == 's' && opponentMove == 'P') ||
         (move == 'P' && opponentMove == 'r') ||
         (move == 'p' && opponentMove == 'R'))
          {
              return true;
          }
          else
          {
              return false;
          }
}


/* prints the round winner or the round being a draw based on the value
   of the variable 'winnerName' */
void announceRoundWinner(string winnerName)
{
     if (winnerName == "")
     {
         cout << "This round is a draw!" << endl << endl;
     }
     else
     {
         cout << winnerName << " wins the round!" << endl << endl;
     }
}


/* plays a round of the game by storing the moves of the two players by calling
   getMove() and returns the roundwinner by calling isRoundWinner() */
int doRound(string p1Name, string p2Name)
{
     char player_1_move = getMove(p1Name);
     char player_2_move = getMove(p2Name);
     if (isRoundWinner(player_1_move, player_2_move) == true)
     {
         return 1;
     }
     else if (isRoundWinner(player_2_move, player_1_move) == true)
     {
         return 2;
     }
     else
     {
         return 0;
     }
}
                     

/* prints the game winner or no winner based on the value of the variable
   'winnerName' */
void announceWinner(string winnerName)
{
     if (winnerName == "")
     {
         cout << "No winner!" << endl;
     }
     else
     {
         cout << "Congratulations " << winnerName <<"!" << endl;
         cout << "You won EECS 183 Rock-Paper-Scissors!" << endl;
     }
}


/* plays an entire game i.e. three rounds and returns the game winner or the
   round being a draw based on the number of rounds won by each of the two
   players */
string doGame(string p1Name, string p2Name, int gameType)
{
     int player_1_count = 0;
     int player_2_count = 0;
     string game_winner = "";
     if (gameType == 1)
     {
         // for loop used to play three rounds of the game
         for (int i = 0; i < MAX_ROUNDS; ++i)
         {
             int round = doRound(p1Name, p2Name);
             if (round == 1)
             {
                 announceRoundWinner(p1Name);
                 
                 // player_1_counts stores the number of rounds won by player 1
                 player_1_count++;
            
             }
             else if (round == 2)
             {
                 announceRoundWinner(p2Name);
                 
                 // player_2_counts stores the number of rounds won by player 2
                 player_2_count++;
             }
             else if (round == 0)
             {
                 announceRoundWinner("");
             }
         }
         
         // ifelse used to determine the game winner
         if (player_1_count > player_2_count)
         {
             game_winner = p1Name;
         }
         else if (player_2_count > player_1_count)
         {
             game_winner = p2Name;
         }
         else
         {
             game_winner = "";
         }
     }
     else if (gameType == 2)
     {
         cout << "Under Construction" << endl;
         game_winner = "";
                  
     }
     return game_winner;
}





//***********************************************************************
// DO NOT modify the four functions below.
//***********************************************************************
void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
}

void printMenu() {
    cout << endl <<endl;
    cout << "Menu Options" << endl
    << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    
    cout << "Choice --> ";
}

void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" << endl
        << endl;
    } else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default" << endl;
    } else {
        cout << "This should never print!";
    }
}

void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl
    << "           Thanks for playing            " << endl
    << "          Rock-Paper-Scissors!           " << endl
    << "----------------------------------------" << endl << endl;
}

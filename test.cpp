/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * Divyanga Bajoria
 * bajoriad
 *
 * EECS 183: Project 2
 * Winter 2021
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();
void test_getName();
void test_getMenuChoice();
void test_getMove();
void test_doRound();
void test_doGame();

void startTests() {
    cout << "\nExecuting your test cases\n";

    
    //test_getName();
    //test_getMenuChoice();
    //test_getMove();
    test_isMoveGood();
    test_isRoundWinner();
    test_announceRoundWinner();
    test_announceWinner();
    //test_doRound();
    //test_doGame();
    // TODO: call more test functions here

    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

/*void test_getName() {
    cout << "Now testing function getName()\n";
    cout << "testing good input" << endl;
    cout << getName(1) << endl;
    cout << getName(2) << endl;
     
    cout << "testing bad inout" << endl;
    cout << getName(1) << endl;
    return;
    }*/


void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "testing good input" << endl;
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'R': Expected: 1, Actual: " << isMoveGood('R') << endl;
    cout << "'s': Expected: 1, Actual: " << isMoveGood('s') << endl;
    cout << "'S': Expected: 1, Actual: " << isMoveGood('S') << endl;
    cout << "'P': Expected: 1, Actual: " << isMoveGood('P') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;
    
    cout << "testing bad input" << endl;
    cout << "'2': Expected: 0, Actual: " << isMoveGood('2') << endl;
    cout << "'3': Expected: 0, Actual: " << isMoveGood('3') << endl;
    cout << "'t': Expected: 0, Actual: " << isMoveGood('t') << endl;
    cout << "'Y': Expected: 0, Actual: " << isMoveGood('Y') << endl;
    cout << "'J': Expected: 0, Actual: " << isMoveGood('J') << endl;
    cout << "' ': Expected: 0, Actual: " << isMoveGood(' ') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    return;
}

/*void test_getMove() {
    cout << "Now testing function getMove()\n";
    cout << "testing good input" << endl;
    cout << getMove("Harry");
    cout << getMove("John");
    
    cout << "testing bad input" << endl;
    cout << getMove("Sam");
    cout << getMove("Div");
    return;
}*/

/*void test_getMenuChoice() {
    cout << "Now testing function getMenuChoice()\n";
    cout << "testing good input" << endl;
    cout << getMenuChoice() << endl;
    cout << getMenuChoice() << endl;
    cout << getMenuChoice() << endl;
    
    cout << "testing bad input" << endl;
    cout << getMenuChoice() << endl;
    cout << getMenuChoice() << endl;
    cout << getMenuChoice() << endl;
    return;
    
}*/

void test_isRoundWinner() {
    cout << "Now testing fucntion isRoundWinner()\n";
    cout << "testing good input" << endl;
    cout << " 'r','s': Expected: 1, Actual: " << isRoundWinner('r','s')<< endl;
    cout << " 's','p': Expected: 1, Actual: " << isRoundWinner('s','p')<< endl;
    cout << " 'p','r': Expected: 1, Actual: " << isRoundWinner('p','r')<< endl;
    cout << " 'R','S': Expected: 1, Actual: " << isRoundWinner('R','S')<< endl;
    cout << " 'S','P': Expected: 1, Actual: " << isRoundWinner('S','P')<< endl;
    cout << " 'P','R': Expected: 1, Actual: " << isRoundWinner('P','R')<< endl;
    cout << " 'R','s': Expected: 1, Actual: " << isRoundWinner('R','s')<< endl;
    cout << " 'p','R': Expected: 1, Actual: " << isRoundWinner('p','R')<< endl;
    cout << " 'S','p': Expected: 1, Actual: " << isRoundWinner('S','p')<< endl;
    
    cout << "testing bad input" << endl;
    cout << " 's','s': Expected: 0, Actual: " << isRoundWinner('s','s') << endl;
    cout << " 'r','r': Expected: 0, Actual: " << isRoundWinner('r','r') << endl;
    cout << " 'R','R': Expected: 0, Actual: " << isRoundWinner('R','R') << endl;
    cout << " 'S','S': Expected: 0, Actual: " << isRoundWinner('S','S') << endl;
    cout << " 'S','P': Expected: 0, Actual: " << isRoundWinner('S','S') << endl;
    cout << " 'p','r': Expected: 0, Actual: " << isRoundWinner('S','S') << endl;
    cout << " 'S','R': Expected: 0, Actual: " << isRoundWinner('S','S') << endl;
    return;
}

  void test_announceRoundWinner() {
    cout << "Now testing function announceRoundWinner()\n";
    cout << "testing good input" << endl;
    cout << "'Sam': Expected: Sam wins the round!,Actual: ";
    announceRoundWinner("Sam");
    cout << "'Kelly b': Expected: Kelly b wins the round!,Actual: ";
    announceRoundWinner("Kelly b");
    
    cout << "testing bad input" << endl;
    cout << "'': This round is a draw!,Actual: ";
    announceRoundWinner("");
    cout << "'44': Expected: 44 wins the round!,Actual: ";
    announceRoundWinner("44");
    return;
}

void test_announceWinner() {
    cout << "Now testing function announceWinner()\n";
    cout << "testing good input" << endl;
    cout << "'Sam': Expected: Congratulations Sam!";
    cout << "                 You won EECS 183 Rock-Paper-Scsissors" << endl;
    announceWinner("Sam");
    cout << "'Johnny': Expected: Congratulations Johnny!";
    cout << "                    You won EECS 183 Rock-Paper-Scissors" << endl;
    announceWinner("Johnny");
    
    cout << "testing bad input" << endl;
    cout << "'': Expected: No Winner!" << endl;
    announceWinner("");
    cout <<"'44: Expected: Congratulations 44!";
    cout <<"               You won EECS 183 Rock-Paper-Scissors" << endl;
    announceWinner("44");
    return;
}

/*void test_doRound(){
    cout << "Now testing function doRound()\n";
    cout << doRound("Harry", "Sam");
    cout << doRound("Div", "Avi");
    cout << doRound("Jerry", "Edision");
    cout << doRound("Edison", "Magda");
    return;
}*/

/*void test_doGame(){
    cout << "Now testing function doGame()\n";
    cout << doGame("Harry", "Sam", 1);
    cout << doGame("Div", "Avi", 1);
    cout << doGame("Jerry", "Edision",1);
    cout << doGame("Edison", "Madison",2);
    return;
}*/


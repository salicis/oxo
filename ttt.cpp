#include <iostream>
#include <cstdint>
#include <limits>
#include "Board.h"

using std::cout, std::cin, std::numeric_limits, std::streamsize;

enum Player : char { HUMAN = 'X', MACHINE = 'O' };
static char currentPlayer = HUMAN;
Board board;

void switchPlayer() {
  currentPlayer = (currentPlayer == HUMAN) ? MACHINE : HUMAN;
}

uint8_t get_human_move(){
  int digit;
  while (true) {
    cout << "Enter your move (1 - 9): " << std::flush;
	if ((cin >> digit) && digit > 0 && digit <= 9)
	  break;
    cout << "Oops... must be a single digit between 1 and 9\n";
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
  }
  return static_cast<uint8_t>(digit);
}

void makeHumanMove(){
  uint8_t position;        
  while (true){
    position = get_human_move();
    if (board.placeSymbol(position,HUMAN)) {
      break;
    }
    cout << "Already taken, try again.\n";
  }
}

int main() {
  while (true) {
    if (currentPlayer == HUMAN){
      board.display();
      makeHumanMove();
    }    
    else
      board.placeSymbol(board.getMachineMove(),MACHINE); 
    if (board.win()){
      board.display();
      cout << currentPlayer << " wins\n";
      break;
    } 
    if (board.tie()){
      board.display();
      cout << "It's a tie!\n";
      break;
    }  
    switchPlayer(); 
  }
  return 0;
}
#include "Board.h"

using std::cout;

Board::Board(){
    uint8_t position {1};
    for (uint8_t row = 0; row < dimension; ++row) {
        for (uint8_t col = 0; col < dimension; ++col) {
            board[row][col] = '0'+position;
            availablePositions.insert(position);
            ++position; 
        }
    }
}

void Board::display() const {
    cout << "\n";
    for (uint8_t row = 0; row < dimension; ++row) {
        for (uint8_t col = 0; col < dimension; ++col) {
            cout << " " << board[row][col] ;
            if (col<dimension-1) 
              cout<< " |";
        }
        cout << "\n";
        if (row<dimension-1) 
            cout << "-----------\n";    
    }
    cout << std::flush;
} 
    
void Board::removeAvailablePosition(int position){
    availablePositions.erase(position);
}  

bool Board::placeSymbol(int position, char symbol) {
    uint8_t row = (position-1) / dimension;
    uint8_t col = (position-1) % dimension;
    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }
    board[row][col] = symbol;
    removeAvailablePosition(position);
    return true;
}

bool Board::win() const {
    for (uint8_t n=0; n<dimension; n++) {
    	  //col n
        if (board[n][0] == board[n][1] && board[n][1] == board[n][2]) {
            return true;
        }
        // row n
        if (board[0][n] == board[1][n] && board[1][n] == board[2][n]) {
            return true;
        }
    }
    // diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool Board::tie() const {
    return availablePositions.empty();
}

uint8_t Board::getMachineMove(){
	 // just gets a random move!
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, availablePositions.size() - 1);
    auto it = std::next(availablePositions.begin(), dist(rng));
    uint8_t move = *it;
    removeAvailablePosition(move);
    return move;
}


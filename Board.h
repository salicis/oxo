#include <unordered_set>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdint> 
#include <cstddef> 

class Board {

  private:

    //static constexpr std::size_t dimension = 3;
    static constexpr std::size_t dimension = 3;
	 
    char board[dimension][dimension];

    // set of available positions from which machine generates its next move
    std::unordered_set<uint8_t> availablePositions;

    void removeAvailablePosition(int position);
               	
  public:
    
    Board();
    void display() const;
    bool placeSymbol(int position, char symbol);
    bool tie() const;
    bool win() const;
    uint8_t getMachineMove();
};

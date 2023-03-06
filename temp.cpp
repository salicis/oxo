#include <iostream>

using std::cout;

int main() {
   int position {9};
   cout<< "value stored in position:  " << position<< "\n";
   cout << "address of position: " << &position << "\n";
   int* pointerToPosition = &position;
   cout << "pointer to position:  " << pointerToPosition << "\n";
   cout<< "dereferenced pointer:  " << *pointerToPosition << "\n";
   return 0;
}   
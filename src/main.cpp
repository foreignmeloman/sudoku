#include <iostream>
#include "sudoku.hpp"


int main() {
  Sudoku s;
  s.enterDigits();
  if (s.solve())
    s.print();
  else
    std::cout << "Unsolvable!" << std::endl;
  return 0;
}

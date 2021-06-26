#include <iostream>
#include "sudoku.hpp"

bool Sudoku::next() {
  bool result = true;
  if(++x == limit) {
    x = 0;
    if(++y == limit) {
      return false;
    }
  }
  if (mask[y][x]) {
    result = next();
  }
  return result;
}

bool Sudoku::prev() {
  bool result = true;
  if(--x < 0) {
    x = limit - 1;
    if(--y < 0) {
      return false;
    }
  }
  if (mask[y][x]) {
    result = prev();
  }
  return result;
}

bool Sudoku::check() {
  for (int i = 0; i < limit; i++)
      if (table[y][i] == table[y][x] && i != x)
        return false;

  // check column
  for (int i = 0; i < limit; i++)
    if (table[i][x] == table[y][x] && i != y)
      return false;

  // check square
  int start_x = (x / 3) * 3;
  int start_y = (y / 3) * 3;

  for (int i = start_y; i < start_y + 3; i++)
    for (int j = start_x; j < start_x + 3; j++)
      if (table[i][j] == table[y][x] && i != y && j != x)
        return false;

  return true;
}

bool Sudoku::solve() {
  while (next()) {
      do {
        while (++table[y][x] > 9) {
          table[y][x] = 0;
          if (!prev()) {
            return false;
          }
        }
      } while (!check());
    }
  return true;
}

void Sudoku::enterDigits() {
  std::cout << "Enter Sudoku table digits line by line with 0s as vacant positions" << std::endl;
    for (int i = 0; i < limit; i++)
      for (int j = 0; j < limit; j++) {
        std::cin >> table[i][j];
        if(table[i][j] != 0)
          mask[i][j] = 1;
      }
}

void Sudoku::print() {
  std::cout << std::endl;
    for (int i = 0; i < limit; i++) {
      for (int j = 0; j < limit; j++)
        std::cout << table[i][j] << "  ";
      std::cout << std::endl;
    }
}




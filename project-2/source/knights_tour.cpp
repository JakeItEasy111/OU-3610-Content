#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(
  int row, int col, 
  int row_moves[], int col_moves[], int& num_moves
) {

  //directions for each move type 
  const int dir_col[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
  const int dir_row[8] = { 1, -1, -2, -2, -1, 1, 2, 2 };

  for (int i = 0; i < 8; i++){
    
    //new position
    int move_col = col + dir_col[i]; 
    int move_row = row + dir_row[i];

    if ((move_row >= 0 && move_row < board_size) && (move_col >= 0 && move_col < board_size)){ //valid position

      if(board[move_row][move_col] == 0){ //empty space  

        col_moves[num_moves] = move_col;
        row_moves[num_moves] = move_row; 
        num_moves++; 
        
      }
    }
  }
}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) {

  //fill space 
  ++m; 
  board[row][col] = m; 

  //successful tour, print board and backtrack
  if (m >= board_size*board_size){ 

    num_tours += 1;
    print(); 
    board[row][col] = 0; 
    --m;
    return;

  } 

  //obtain moves 
  int row_moves[8] = {} ;
  int col_moves[8] = {} ;
  int possible_moves = 0; 
  get_moves(row, col, row_moves, col_moves, possible_moves); 

  //no moves found, backtrack 
  if (possible_moves == 0){ 

    board[row][col] = 0; 
    --m;
    return; 
  }
  
  //print all moves 
  for (int i = 0; i < possible_moves; i++){
      move(row_moves[i], col_moves[i], m, num_tours); //recursive call 
  }

  //backtrack after move
  board[row][col] = 0;
  --m;
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}

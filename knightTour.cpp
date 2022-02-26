#include "knightTour.h"


KT::KT(size_t n) : N(n) {
    board.resize(N, std::vector<int>(N, -1));
}


void KT::print() {
    for (int row = 0; row < N; ++row) {
        std::cout << " ";
        for (int col = 0; col < N; ++ col) std::cout << board[row][col] << " ";
        std::cout << " \n";
    }
    std::cout << "\n";
}


bool KT::valid(int row, int col) {
    return (row >= 0 && col >= 0 && row < N && col < N && board[row][col] == -1);
}


bool KT::solve(int move, int row, int col) {
    if (move == N * N) {
        print();
        return true;
    }

    board[row][col] = move;
    print();

    int x[8] = {-2, -2, 2, 2, -1, -1, 1, 1};
    int y[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

    for (int i = 0; i < 8; ++i) {
        int addRow = x[i];
        int addCol = y[i];
        if (valid(row + addRow, col + addCol)) {
            if (solve(move + 1, row + addRow, col + addCol)) return true;
            board[row + addRow][col + addCol] = -1;
        }
    }

    board[row][col] = -1;
    return false;
}
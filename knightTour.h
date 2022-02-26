#ifndef KNIGHTTOUR_KNIGHTTOUR_H
#define KNIGHTTOUR_KNIGHTTOUR_H
#include <vector>
#include <iostream>

class KT {
private:
    size_t N;
    std::vector<std::vector<int>> board;

public:

    KT(size_t n);

    void print();

    bool valid(int row, int col);

    bool solve(int move, int row, int col);
};

#endif //KNIGHTTOUR_KNIGHTTOUR_H
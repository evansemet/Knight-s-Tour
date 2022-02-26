#include <chrono>
#include "knightTour.h"

int main() {
    KT demonstration(8);
    demonstration.print();
    auto start = std::chrono::high_resolution_clock::now();
    if (!demonstration.solve(0, 0, 0)) std::cout << "No solution found!\n";
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "\nSolution found in " << (float) duration.count() / 1000000 << " seconds.\n";
    return 0;
}
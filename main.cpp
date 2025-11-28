#include <iostream>
#include <vector>
#include "MergeSorter.h"

template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    MergeSorter<int> intSorter;
    std::vector<int> intArr = { 38, 27, 43, 3, 9, 82, 10 };

    std::cout << "--- Sortowanie int ---" << std::endl;
    printVector(intArr);
    intSorter.sort(intArr);
    printVector(intArr);

    return 0;
}
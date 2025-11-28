#include <iostream>
#include <vector>
#include "MergeSorter.h"

// Funkcja pomocnicza do wyświetlania wektora
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 1. Instancja dla liczb całkowitych (int)
    MergeSorter<int> intSorter;
    std::vector<int> intArr = { 38, 27, 43, 3, 9, 82, 10 };

    std::cout << "--- Test int ---" << std::endl;
    std::cout << "Przed: ";
    printVector(intArr);
    
    intSorter.sort(intArr);

    std::cout << "Po:    ";
    printVector(intArr);
    std::cout << std::endl;

    // 2. Instancja dla liczb zmiennoprzecinkowych (double)
    MergeSorter<double> doubleSorter;
    std::vector<double> doubleArr = { 3.14, 1.59, 2.65, 3.58, 9.79, 0.01 };

    std::cout << "--- Test double ---" << std::endl;
    std::cout << "Przed: ";
    printVector(doubleArr);

    doubleSorter.sort(doubleArr);

    std::cout << "Po:    ";
    printVector(doubleArr);

    return 0;
}
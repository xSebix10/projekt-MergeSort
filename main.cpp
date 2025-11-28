/**
 * @file main.cpp
 * @brief Główny plik programu demonstrujący działanie algorytmu Merge Sort.
 * * Zawiera funkcję main oraz funkcje pomocnicze do wyświetlania wektorów.
 * Demonstruje sortowanie liczb całkowitych (int) i zmiennoprzecinkowych (double).
 */

#include <iostream>
#include <vector>
#include "MergeSorter.h"

/**
 * @brief Szablonowa funkcja pomocnicza do wypisywania zawartości wektora na konsolę.
 * * @tparam T Typ danych w wektorze.
 * @param vec Wektor do wyświetlenia.
 */
template <typename T>
void printVector(const std::vector<T>& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Główna funkcja programu.
 * * Tworzy instancje wektorów i klasy sortującej, a następnie przeprowadza
 * testowe sortowanie z wypisaniem wyników przed i po operacji.
 * * @return int Kod zakończenia programu (0 oznacza sukces).
 */
int main() {
    // Demo dla int
    MergeSorter<int> intSorter;
    std::vector<int> intArr = { 38, 27, 43, 3, 9, 82, 10 };

    std::cout << "--- Sortowanie int ---" << std::endl;
    std::cout << "Przed: ";
    printVector(intArr);
    
    intSorter.sort(intArr);

    std::cout << "Po:    ";
    printVector(intArr);
    std::cout << std::endl;

    // Demo dla double
    MergeSorter<double> doubleSorter;
    std::vector<double> doubleArr = { 3.14, 1.59, 2.65, 3.58, 9.79, 0.01 };

    std::cout << "--- Sortowanie double ---" << std::endl;
    std::cout << "Przed: ";
    printVector(doubleArr);

    doubleSorter.sort(doubleArr);

    std::cout << "Po:    ";
    printVector(doubleArr);

    return 0;
}
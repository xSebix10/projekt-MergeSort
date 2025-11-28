#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <vector>
#include <iostream>

/**
 * @brief Klasa implementująca algorytm sortowania przez scalanie (Merge Sort).
 * * @tparam T Typ danych przechowywanych w tablicy (np. int, double, float).
 * Typ T musi wspierać operator porównania (<).
 */
template <typename T>
class MergeSorter {
public:
    /**
     * @brief Główna metoda publiczna do sortowania wektora.
     * * @param arr Referencja do wektora, który ma zostać posortowany.
     */
    void sort(std::vector<T>& arr) {
        if (arr.empty()) return;
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }

private:
    /**
     * @brief Rekurencyjna funkcja dzieląca tablicę na podproblemy.
     * * @param arr Referencja do wektora.
     * @param left Indeks początkowy podtablicy.
     * @param right Indeks końcowy podtablicy.
     */
    void mergeSortRecursive(std::vector<T>& arr, int left, int right) {
        if (left >= right) {
            return; // Warunek stopu: tablica ma 0 lub 1 element
        }

        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    /**
     * @brief Funkcja scalająca dwie posortowane podtablice.
     * * @param arr Referencja do wektora.
     * @param left Indeks początkowy lewej podtablicy.
     * @param mid Indeks środkowy (koniec lewej podtablicy).
     * @param right Indeks końcowy prawej podtablicy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Tworzenie tablic tymczasowych
        std::vector<T> L(n1);
        std::vector<T> R(n2);

        // Kopiowanie danych do tablic tymczasowych
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Scalanie tablic tymczasowych z powrotem do arr
        int i = 0; // Indeks początkowy pierwszej podtablicy
        int j = 0; // Indeks początkowy drugiej podtablicy
        int k = left; // Indeks początkowy scalonej podtablicy

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Kopiowanie pozostałych elementów L[], jeśli są
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Kopiowanie pozostałych elementów R[], jeśli są
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

#endif // MERGESORTER_H
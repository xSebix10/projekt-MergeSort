/**
 * @file MergeSorter.h
 * @author Twoje Imie Nazwisko
 * @brief Plik nagłówkowy zawierający szablonową klasę sortowania przez scalanie.
 * @date 2023-10-27
 */

#ifndef MERGESORTER_H
#define MERGESORTER_H

#include <vector>
#include <iostream>

/**
 * @class MergeSorter
 * @brief Klasa implementująca algorytm sortowania przez scalanie (Merge Sort).
 * * Klasa wykorzystuje szablony (templates), dzięki czemu może sortować
 * wektory dowolnego typu danych, który obsługuje operatory porównania (<, <=).
 * * @tparam T Typ danych przechowywanych w wektorze (np. int, double, float).
 */
template <typename T>
class MergeSorter {
public:
    /**
     * @brief Główna metoda publiczna rozpoczynająca proces sortowania.
     * * Metoda sprawdza, czy wektor nie jest pusty, a następnie wywołuje
     * rekurencyjną metodę pomocniczą. Sortowanie odbywa się "w miejscu" (na przekazanej tablicy).
     * * @param arr Referencja do wektora std::vector<T>, który ma zostać posortowany.
     * * @note Złożoność czasowa algorytmu wynosi O(n log n) w każdym przypadku.
     * @note Złożoność pamięciowa wynosi O(n) ze względu na tablice pomocnicze.
     */
    void sort(std::vector<T>& arr) {
        if (arr.empty()) return;
        mergeSortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
    }

private:
    /**
     * @brief Rekurencyjna metoda dzieląca tablicę na podproblemy.
     * * Dzieli zakres tablicy na pół, wywołuje się rekurencyjnie dla lewej
     * i prawej części, a następnie scala posortowane połówki.
     * * @param arr Referencja do sortowanego wektora.
     * @param left Indeks początkowy bieżącego zakresu.
     * @param right Indeks końcowy bieżącego zakresu.
     */
    void mergeSortRecursive(std::vector<T>& arr, int left, int right) {
        if (left >= right) {
            return; // Warunek stopu: 0 lub 1 element
        }

        int mid = left + (right - left) / 2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    /**
     * @brief Metoda scalająca dwie posortowane podtablice w jedną.
     * * Scalane są podtablice arr[left..mid] oraz arr[mid+1..right].
     * Wykorzystuje tablice tymczasowe do przechowania danych.
     * * @param arr Referencja do sortowanego wektora.
     * @param left Indeks początkowy lewej podtablicy.
     * @param mid Indeks końcowy lewej podtablicy.
     * @param right Indeks końcowy prawej podtablicy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Tworzenie tablic tymczasowych
        std::vector<T> L(n1);
        std::vector<T> R(n2);

        // Kopiowanie danych
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        // Scalanie
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

        // Kopiowanie pozostałych elementów
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
};

#endif // MERGESORTER_H
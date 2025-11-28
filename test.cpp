/**
 * @file test.cpp
 * @brief Plik zawierający pełny zestaw testów jednostkowych dla algorytmu Merge Sort.
 * * Testy pokrywają przypadki standardowe, brzegowe oraz wydajnościowe 
 * przy użyciu biblioteki Google Test.
 */

#include "gtest/gtest.h"
#include "MergeSorter.h"
#include <vector>
#include <algorithm> // Do std::is_sorted, std::reverse
#include <random>    // Do generowania losowych danych (opcjonalnie)

/**
 * @class MergeSortTest
 * @brief Fixture testowy (kontekst) dla Google Test.
 * * Pozwala zdefiniować obiekty (instancje sorterów), które będą
 * dostępne w każdym teście, co ogranicza powtarzanie kodu.
 */
class MergeSortTest : public ::testing::Test {
protected:
    MergeSorter<int> sorterInt;       ///< Instancja do testowania int
    MergeSorter<double> sorterDouble; ///< Instancja do testowania double
};

/**
 * @brief Test 1: Zachowuje tablicę niezmienioną, gdy ona jest już posortowana rosnąco.
 */
TEST_F(MergeSortTest, AlreadySorted) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 2: Potrafi posortować tablicę, która jest posortowana w odwrotnej kolejności.
 */
TEST_F(MergeSortTest, ReverseSorted) {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 3: Poprawnie sortuje losową tablicę liczb.
 */
TEST_F(MergeSortTest, RandomArray) {
    std::vector<int> arr = { 10, 2, 8, 5, 1, 9 };
    std::vector<int> expected = { 1, 2, 5, 8, 9, 10 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 4: Poprawnie sortuje tablice tylko z liczbami ujemnymi.
 */
TEST_F(MergeSortTest, OnlyNegative) {
    std::vector<int> arr = { -5, -1, -10, -3 };
    std::vector<int> expected = { -10, -5, -3, -1 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 5: Poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi.
 */
TEST_F(MergeSortTest, MixedNegativeAndPositive) {
    std::vector<int> arr = { -5, 10, 0, -3, 2 };
    std::vector<int> expected = { -5, -3, 0, 2, 10 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 6: Obsługuje pustą tablicę bez rzucania wyjątkiem.
 */
TEST_F(MergeSortTest, EmptyArray) {
    std::vector<int> arr = {};
    // Sprawdzamy czy nie wyrzuca błędu
    EXPECT_NO_THROW(sorterInt.sort(arr));
    // Sprawdzamy czy nadal jest pusta
    EXPECT_TRUE(arr.empty());
}

/**
 * @brief Test 7: Nie zmienia tablicy, która zawiera tylko jeden element.
 */
TEST_F(MergeSortTest, SingleElement) {
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 8: Poprawnie sortuje tablicę z duplikatami liczb (dodatnich).
 */
TEST_F(MergeSortTest, DuplicatesPositive) {
    std::vector<int> arr = { 3, 1, 3, 2, 1 };
    std::vector<int> expected = { 1, 1, 2, 3, 3 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 9: Poprawnie sortuje tablice ujemną z duplikatami.
 */
TEST_F(MergeSortTest, DuplicatesNegative) {
    std::vector<int> arr = { -2, -5, -2, -10 };
    std::vector<int> expected = { -10, -5, -2, -2 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 10: Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami.
 */
TEST_F(MergeSortTest, MixedDuplicates) {
    std::vector<int> arr = { -2, 5, 0, -2, 5, 1 };
    std::vector<int> expected = { -2, -2, 0, 1, 5, 5 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 11: Poprawnie sortuje tablicę zawierającą tylko dwa elementy w kolejności rosnącej.
 */
TEST_F(MergeSortTest, TwoElementsSorted) {
    std::vector<int> arr = { 10, 20 };
    std::vector<int> expected = { 10, 20 };
    sorterInt.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * @brief Test 12: Poprawnie sortuje dużą tablicę zawierającą ponad 100 elementów.
 */
TEST_F(MergeSortTest, LargeArray) {
    std::vector<double> arr;
    // Generowanie 150 malejących liczb
    for (int i = 0; i < 150; ++i) {
        arr.push_back((double)(150 - i));
    }
    
    sorterDouble.sort(arr);

    // std::is_sorted to funkcja z biblioteki <algorithm>
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr.size(), 150);
}

/**
 * @brief Test 13: Poprawnie sortuje dużą tablicę (>100 elementów) z liczbami ujemnymi, 
 * dodatnimi oraz duplikatami.
 */
TEST_F(MergeSortTest, LargeArrayMixedDuplicates) {
    std::vector<int> arr;
    // Generujemy 200 liczb. 
    // (i % 20) daje liczby 0..19. 
    // Odejmując 10, mamy zakres od -10 do 9.
    // Dzięki modulo powstaną liczne duplikaty.
    for (int i = 0; i < 200; ++i) {
        arr.push_back((i % 20) - 10); 
    }

    sorterInt.sort(arr);

    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr.size(), 200);
    // Sprawdzenie czy min i max są w oczekiwanym zakresie
    EXPECT_EQ(arr.front(), -10);
    EXPECT_EQ(arr.back(), 9);
}
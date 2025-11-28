# projekt-MergeSort

Projekt implementujący algorytm sortowania przez scalanie (**Merge Sort**) w języku C++ z wykorzystaniem **szablonów klas**. Projekt zawiera kompleksowe testy jednostkowe oparte na bibliotece **Google Test** oraz konfigurację budowania **CMake**.

## 📋 Funkcjonalności

Projekt realizuje następujące wymagania:
- [x] Implementacja algorytmu Merge Sort w klasie.
- [x] Wykorzystanie **szablonów (templates)** – obsługa typów `int`, `double` i innych.
- [x] Demonstracja działania w `main.cpp` (dwie instancje: `int` i `double`).
- [x] Automatyczne pobieranie i konfiguracja biblioteki **Google Test**.
- [x] Dokumentacja kodu w standardzie **Doxygen**.
- [x] Skrypty `.bat` do łatwego uruchamiania na Windows.

## ✅ Testy Jednostkowe

Zaimplementowano 13 scenariuszy testowych (zgodnie z wymaganiami):
1. Tablica posortowana rosnąco.
2. Tablica posortowana odwrotnie.
3. Losowa tablica.
4. Liczby tylko ujemne.
5. Liczby mieszane (dodatnie/ujemne).
6. Pusta tablica.
7. Jeden element.
8. Duplikaty (liczby dodatnie).
9. Duplikaty (liczby ujemne).
10. Mieszane duplikaty i znaki.
11. Dwa elementy posortowane.
12. Duża tablica (>100 elementów).
13. Duża tablica mieszana z duplikatami.

## 🚀 Jak uruchomić (Windows)

### Wymagania wstępne
* Kompilator C++ (np. MinGW / GCC).
* Narzędzie CMake (wersja 3.14 lub nowsza).

### Sposób 1: Automatyczne skrypty (Zalecane)
W folderze głównym znajdują się pliki `.bat`:
* `run_tests.bat` - Buduje i uruchamia testy jednostkowe.
* `run_app.bat` - Buduje i uruchamia główny program demonstracyjny.

### Sposób 2: Visual Studio Code
1. Otwórz folder projektu w VS Code.
2. Poczekaj na konfigurację CMake (wybierz zestaw narzędzi GCC/MinGW).
3. Kliknij **Build** na dolnym pasku.
4. Uruchom testy z zakładki **Testing** (ikona kolby).
#include "Menu.h"
#include "DataGenerator.h"
#include "SortingAlgorithms.h"

// menu jesli zostana wybrane dane typu int
void Menu::displayMenuInt() {
    vector<int> data;
    SortingAlgorithms<int> sorter;
    int choice = 0;

    while(choice != -1) {
        cout << "Menu:\n";
        cout << "1. Wczytaj tablicę z pliku o zadanej nazwie\n";
        cout << "2. Wygeneruj losową tablicę o zadanym rozmiarze\n";
        cout << "3. Wyświetl ostatnio utworzoną tablicę\n";
        cout << "4. Uruchom wybrany algorytm na ostatnio utworzonej tablicy\n";
        cout << "5. Wyświetl posortowaną tablicę\n";
        cout << "-1. Cofnij do poprzedniego\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                string name;
                cout<<"Podaj nazwę pliku, z którego chcesz wczytać tablicę: ";
                cin >> name;
                data = DataGenerator<int>::generateDataFromGivenFile(name);
                cout << "Pomyślnie wczytano tablicę z pliku.\n";
                break;
            }
            case 2: {
                int size;
                cout << "Podaj rozmiar tablicy, którą chcesz wygenerować: ";
                cin >> size;
                data = DataGenerator<int>::generateIntData(size);
                break;
            }
            case 3: {
                sorter.allocateArray(data);
                sorter.display();
                break;
            }
            case 4: {
                int alg;
                cout << "Który algorytm chcesz uruchomić:\n";
                cout << "1. Quick Sort\n";
                cout << "2. Insertion Sort\n";
                cout << "3. Binary Insertion Sort\n";
                cout << "4. Heap Sort\n";
                cin >> alg;
                if(alg == 1) {
                    sorter.allocateArray(data);
                    sorter.quickSort(0, sorter.size-1, "MenuQuickSort");
                } else if(alg == 2) {
                    sorter.allocateArray(data);
                    sorter.insertionSort("MenuInsertionSort");
                } else if(alg == 3) {
                    sorter.allocateArray(data);
                    sorter.binaryInsertionSort("MenuBinaryInsertionSort");
                } else if(alg == 4) {
                    sorter.allocateArray(data);
                    sorter.heapSort("MenuHeapSort");
                } else {
                    cout << "Nie ma takiej opcji!" << endl;
                }
                break;
            }
            case 5: {
                sorter.allocateArray(data);
                sorter.quickSort(0, sorter.size-1);
                sorter.display();
                break;
            }
            case -1:
                choice = -1;
                break;
            default: {
                cerr << "Nie ma możliwości takiego wyboru!" << endl;
                break;
            }
        }
    }
}

// menu jesli zostana wybrane dane typu float
void Menu::displayMenuFloat() {
    vector<float> data;
    SortingAlgorithms<float> sorter;
    int choice = 0;

    while(choice != -1) {
        cout << "Menu:\n";
        cout << "1. Wczytaj tablicę z pliku o zadanej nazwie\n";
        cout << "2. Wygeneruj losową tablicę o zadanym rozmiarze\n";
        cout << "3. Wyświetl ostatnio utworzoną tablicę\n";
        cout << "4. Uruchom wybrany algorytm na ostatnio utworzonej tablicy\n";
        cout << "5. Wyświetl posortowaną tablicę\n";
        cout << "-1. Cofnij do poprzedniego\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                string name;
                cout<<"Podaj nazwę pliku, z którego chcesz wczytać tablicę: ";
                cin >> name;
                data = DataGenerator<float>::generateDataFromGivenFile(name);
                cout << "Pomyślnie wczytano tablicę z pliku.\n";
                break;
            }
            case 2: {
                int size;
                cout << "Podaj rozmiar tablicy, którą chcesz wygenerować: ";
                cin >> size;
                data = DataGenerator<float>::generateFloatData(size);
                break;
            }
            case 3: {
                sorter.allocateArray(data);
                sorter.display();
                break;
            }
            case 4: {
                int alg;
                cout << "Który algorytm chcesz uruchomić:\n";
                cout << "1. Quick Sort\n";
                cout << "2. Insertion Sort\n";
                cout << "3. Binary Insertion Sort\n";
                cout << "4. Heap Sort\n";
                cin >> alg;
                if(alg == 1) {
                    sorter.allocateArray(data);
                    sorter.quickSort(0, sorter.size-1, "MenuQuickSort");
                } else if(alg == 2) {
                    sorter.allocateArray(data);
                    sorter.insertionSort("MenuInsertionSort");
                } else if(alg == 3) {
                    sorter.allocateArray(data);
                    sorter.binaryInsertionSort("MenuBinaryInsertionSort");
                } else if(alg == 4) {
                    sorter.allocateArray(data);
                    sorter.heapSort("MenuHeapSort");
                } else {
                    cout << "Nie ma takiej opcji!" << endl;
                }
                break;
            }
            case 5: {
                char sort;
                if(sorter.isSorted()) {
                    sorter.display();
                    break;
                } else {
                    cout << "Tablica nie jest jeszcze posortowana! Chcesz ja posortowac? (t/n) ";
                    cin >> sort;
                }
                if(sort != 't'){
                    break;
                } else {
                    sorter.quickSort(0, sorter.size-1);
                    sorter.display();
                }
                break;
            }
            case -1:
                choice = -1;
                break;
            default: {
                cerr << "Nie ma możliwości takiego wyboru!" << endl;
                break;
            }
        }
    }
}

// menu jesli zostana wybrane dane typu double
void Menu::displayMenuDouble() {
    vector<double> data;
    SortingAlgorithms<double> sorter;
    int choice = 0;

    while(choice != -1) {
        cout << "Menu:\n";
        cout << "1. Wczytaj tablicę z pliku o zadanej nazwie\n";
        cout << "2. Wygeneruj losową tablicę o zadanym rozmiarze\n";
        cout << "3. Wyświetl ostatnio utworzoną tablicę\n";
        cout << "4. Uruchom wybrany algorytm na ostatnio utworzonej tablicy\n";
        cout << "5. Wyświetl posortowaną tablicę\n";
        cout << "-1. Cofnij do poprzedniego\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                string name;
                cout<<"Podaj nazwę pliku, z którego chcesz wczytać tablicę: ";
                cin >> name;
                data = DataGenerator<double>::generateDataFromGivenFile(name);
                cout << "Pomyślnie wczytano tablicę z pliku.\n";
                break;
            }
            case 2: {
                int size;
                cout << "Podaj rozmiar tablicy, którą chcesz wygenerować: ";
                cin >> size;
                data = DataGenerator<double>::generateDoubleData(size);
                break;
            }
            case 3: {
                sorter.allocateArray(data);
                sorter.display();
                break;
            }
            case 4: {
                int alg;
                cout << "Który algorytm chcesz uruchomić:\n";
                cout << "1. Quick Sort\n";
                cout << "2. Insertion Sort\n";
                cout << "3. Binary Insertion Sort\n";
                cout << "4. Heap Sort\n";
                cin >> alg;
                if(alg == 1) {
                    sorter.allocateArray(data);
                    sorter.quickSort(0, sorter.size-1, "MenuQuickSort");
                } else if(alg == 2) {
                    sorter.allocateArray(data);
                    sorter.insertionSort("MenuInsertionSort");
                } else if(alg == 3) {
                    sorter.allocateArray(data);
                    sorter.binaryInsertionSort("MenuBinaryInsertionSort");
                } else if(alg == 4) {
                    sorter.allocateArray(data);
                    sorter.heapSort("MenuHeapSort");
                } else {
                    cout << "Nie ma takiej opcji!" << endl;
                }
                break;
            }
            case 5: {
                char sort;
                if(sorter.isSorted()) {
                    sorter.display();
                    break;
                } else {
                    cout << "Tablica nie jest jeszcze posortowana! Chcesz ja posortowac? (t/n) ";
                    cin >> sort;
                }
                if(sort != 't'){
                    break;
                } else {
                    sorter.quickSort(0, sorter.size-1);
                    sorter.display();
                }
                break;
            }
            case -1:
                choice = -1;
                break;
            default: {
                cerr << "Nie ma możliwości takiego wyboru!" << endl;
                break;
            }
        }
    }
}

// menu jesli zostana wybrane dane typu char
void Menu::displayMenuChar() {
    vector<char> data;
    SortingAlgorithms<char> sorter;
    int choice = 0;

    while(choice != -1) {
        cout << "Menu:\n";
        cout << "1. Wczytaj tablicę z pliku o zadanej nazwie\n";
        cout << "2. Wygeneruj losową tablicę o zadanym rozmiarze\n";
        cout << "3. Wyświetl ostatnio utworzoną tablicę\n";
        cout << "4. Uruchom wybrany algorytm na ostatnio utworzonej tablicy\n";
        cout << "5. Wyświetl posortowaną tablicę\n";
        cout << "-1. Cofnij do poprzedniego\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                string name;
                cout<<"Podaj nazwę pliku, z którego chcesz wczytać tablicę: ";
                cin >> name;
                data = DataGenerator<char>::generateDataFromGivenFile(name);
                cout << "Pomyślnie wczytano tablicę z pliku.\n";
                break;
            }
            case 2: {
                int size;
                cout << "Podaj rozmiar tablicy, którą chcesz wygenerować: ";
                cin >> size;
                data = DataGenerator<char>::generateCharData(size);
                break;
            }
            case 3: {
                sorter.allocateArray(data);
                sorter.display();
                break;
            }
            case 4: {
                int alg;
                cout << "Który algorytm chcesz uruchomić:\n";
                cout << "1. Quick Sort\n";
                cout << "2. Insertion Sort\n";
                cout << "3. Binary Insertion Sort\n";
                cout << "4. Heap Sort\n";
                cin >> alg;
                if(alg == 1) {
                    sorter.allocateArray(data);
                    sorter.quickSort(0, sorter.size-1, "MenuQuickSort");
                } else if(alg == 2) {
                    sorter.allocateArray(data);
                    sorter.insertionSort("MenuInsertionSort");
                } else if(alg == 3) {
                    sorter.allocateArray(data);
                    sorter.binaryInsertionSort("MenuBinaryInsertionSort");
                } else if(alg == 4) {
                    sorter.allocateArray(data);
                    sorter.heapSort("MenuHeapSort");
                } else {
                    cout << "Nie ma takiej opcji!" << endl;
                }
                break;
            }
            case 5: {
                char sort;
                if(sorter.isSorted()) {
                    sorter.display();
                    break;
                } else {
                    cout << "Tablica nie jest jeszcze posortowana! Chcesz ja posortowac? (t/n) ";
                    cin >> sort;
                }
                if(sort != 't'){
                    break;
                } else {
                    sorter.quickSort(0, sorter.size-1);
                    sorter.display();
                }
                break;
            }
            case -1:
                choice = -1;
                break;
            default: {
                cerr << "Nie ma możliwości takiego wyboru!" << endl;
                break;
            }
        }
    }
}

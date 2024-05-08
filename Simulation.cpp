#include "Simulation.h"
#include "SortingAlgorithms.h"
#include "DataGenerator.h"

void Simulation::simulate() {
    vector<int> lengths = {15000, 20000, 30000, 40000, 50000, 65000, 80000};

    vector<int> intData;
    SortingAlgorithms<int> intSorter;

    vector<float> floatData;
    SortingAlgorithms<float> floatSorter;

    vector<double> doubleData;
    SortingAlgorithms<double> doubleSorter;

    vector<char> charData;
    SortingAlgorithms<char> charSorter;
    // dla kazdego ustalonego rozmiaru tablicy 100 razy wykonywane jest sortowanie kazdym z algorytmow
    // dane sa zapisywane do plikow w folderze results, wykoanane na tablicach losowych i typach int, float, double i char
    for(int length : lengths) {
        for(int i = 0; i < 100; i++) {
            cout << "Int_" + to_string(length) + ": " << i+1 << endl;
            intData = DataGenerator<int>::generateIntData(length);
            intSorter.allocateArray(intData);
            intSorter.quickSort(0, intSorter.size-1, ("IntQuickSort_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntInsertionSort_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntBinaryInsertionSort_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.heapSort(("IntHeapSort_"+ to_string(length)));

            cout << "Float_" + to_string(length) + ": " << i+1 << endl;
            floatData = DataGenerator<float>::generateFloatData(length);
            floatSorter.allocateArray(floatData);
            floatSorter.quickSort(0, floatSorter.size-1, ("FloatQuickSort_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatInsertionSort_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatBinaryInsertionSort_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.heapSort(("FloatHeapSort_"+ to_string(length)));

            cout << "Double_" + to_string(length) + ": " << i+1 << endl;
            doubleData = DataGenerator<double>::generateDoubleData(length);
            doubleSorter.allocateArray(doubleData);
            doubleSorter.quickSort(0, doubleSorter.size-1, ("DoubleQuickSort_"+ to_string(length)));
            doubleSorter.allocateArray(doubleData);
            doubleSorter.insertionSort(("DoubleInsertionSort_"+ to_string(length)));
            doubleSorter.allocateArray(doubleData);
            doubleSorter.insertionSort(("DoubleBinaryInsertionSort_"+ to_string(length)));
            doubleSorter.allocateArray(doubleData);
            doubleSorter.heapSort(("DoubleHeapSort_"+ to_string(length)));

            cout << "Char_" + to_string(length) + ": " << i+1 << endl;
            charData = DataGenerator<char>::generateCharData(length);
            charSorter.allocateArray(charData);
            charSorter.quickSort(0, charSorter.size-1, ("CharQuickSort_"+ to_string(length)));
            charSorter.allocateArray(charData);
            charSorter.insertionSort(("CharInsertionSort_"+ to_string(length)));
            charSorter.allocateArray(charData);
            charSorter.insertionSort(("CharBinaryInsertionSort_"+ to_string(length)));
            charSorter.allocateArray(charData);
            charSorter.heapSort(("CharHeapSort_"+ to_string(length)));
        }
    }

    // dla kazdego ustalonego rozmiaru tablicy 25 razy wykonywane jest sortowanie kazdym z algorytmow
    // dane sa zapisywane do plikow w folderze results, wykoanane na tablicach specjalnych:
    // czyli calkowicie posortowanych, odwrotnie posortowanych i czesciowo posortowanych na typach int, float
    for(int length : lengths) {
        for(int i = 0; i < 25; i++) {
            cout << "Int_" + to_string(length) + ": " << i+1 << endl;
            intData = DataGenerator<int>::generateIntAscending(length);
            intSorter.allocateArray(intData);
            intSorter.quickSort(0, intSorter.size-1, ("IntQuickSortAscending_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntInsertionSortAscending_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntBinaryInsertionSortAscending_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.heapSort(("IntHeapSortAscending_"+ to_string(length)));

            cout << "Float_" + to_string(length) + ": " << i+1 << endl;
            floatData = DataGenerator<float>::generateFloatAscending(length);
            floatSorter.allocateArray(floatData);
            floatSorter.quickSort(0, floatSorter.size-1, ("FloatQuickSortAscending_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatInsertionSortAscending_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatBinaryInsertionSortAscending_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.heapSort(("FloatHeapSortAscending_"+ to_string(length)));

            cout << "Int_" + to_string(length) + ": " << i+1 << endl;
            intData = DataGenerator<int>::generateIntDescending(length);
            intSorter.allocateArray(intData);
            intSorter.quickSort(0, intSorter.size-1, ("IntQuickSortDescending_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntInsertionSortDescending_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntBinaryInsertionSortDescending_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.heapSort(("IntHeapSortDescending_"+ to_string(length)));

            cout << "Float_" + to_string(length) + ": " << i+1 << endl;
            floatData = DataGenerator<float>::generateFloatDescending(length);
            floatSorter.allocateArray(floatData);
            floatSorter.quickSort(0, floatSorter.size-1, ("FloatQuickSortDescending_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatInsertionSortDescending_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatBinaryInsertionSortDescending_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.heapSort(("FloatHeapSortDescending_"+ to_string(length)));

            cout << "Int_" + to_string(length) + ": " << i+1 << endl;
            intData = DataGenerator<int>::generateInt33(length);
            intSorter.allocateArray(intData);
            intSorter.quickSort(0, intSorter.size-1, ("IntQuickSort33_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntInsertionSort33_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntBinaryInsertionSort33_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.heapSort(("IntHeapSort33_"+ to_string(length)));

            cout << "Float_" + to_string(length) + ": " << i+1 << endl;
            floatData = DataGenerator<float>::generateFloat33(length);
            floatSorter.allocateArray(floatData);
            floatSorter.quickSort(0, floatSorter.size-1, ("FloatQuickSort33_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatInsertionSort33_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatBinaryInsertionSort33_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.heapSort(("FloatHeapSort33_"+ to_string(length)));

            cout << "Int_" + to_string(length) + ": " << i+1 << endl;
            intData = DataGenerator<int>::generateInt66(length);
            intSorter.allocateArray(intData);
            intSorter.quickSort(0, intSorter.size-1, ("IntQuickSort66_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntInsertionSort66_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.insertionSort(("IntBinaryInsertionSort66_"+ to_string(length)));
            intSorter.allocateArray(intData);
            intSorter.heapSort(("IntHeapSort66_"+ to_string(length)));

            cout << "Float_" + to_string(length) + ": " << i+1 << endl;
            floatData = DataGenerator<float>::generateFloat66(length);
            floatSorter.allocateArray(floatData);
            floatSorter.quickSort(0, floatSorter.size-1, ("FloatQuickSort66_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatInsertionSort66_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.insertionSort(("FloatBinaryInsertionSort66_"+ to_string(length)));
            floatSorter.allocateArray(floatData);
            floatSorter.heapSort(("FloatHeapSort66_"+ to_string(length)));

        }
    }
}
#ifndef SORTOWANIA_SORTINGALGORITHMS_H
#define SORTOWANIA_SORTINGALGORITHMS_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T>
class SortingAlgorithms {
public:
    T* arr;
    int size;
    SortingAlgorithms();
    ~SortingAlgorithms();
    void allocateArray(const vector<T>& data);
    void quickSort(int left, int right, const string& fileName);
    void quickSort(int left, int right);
    void insertionSort(const string& fileName);
    void binaryInsertionSort(const string& fileName);
    void heapSort(const string& fileName);
    bool isSorted();
    void display();
};

#endif //SORTOWANIA_SORTINGALGORITHMS_H

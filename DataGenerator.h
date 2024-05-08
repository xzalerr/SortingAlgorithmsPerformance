#ifndef SORTOWANIA_DATAGENERATOR_H
#define SORTOWANIA_DATAGENERATOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <random>
#include <limits>

using namespace std;

template<typename T>
class DataGenerator {
public:
    static vector<T> generateDataFromLastFile();
    static vector<T> generateDataFromGivenFile(string name);
    static vector<int> generateIntData(int size);
    static vector<float> generateFloatData(int size);
    static vector<double> generateDoubleData(int size);
    static vector<char> generateCharData(int size);
    static vector<int> generateIntAscending(int size);
    static vector<float> generateFloatAscending(int size);
    static vector<int> generateIntDescending(int size);
    static vector<float> generateFloatDescending(int size);
    static vector<int> generateInt33(int size);
    static vector<float> generateFloat33(int size);
    static vector<int> generateInt66(int size);
    static vector<float> generateFloat66(int size);
};


#endif //SORTOWANIA_DATAGENERATOR_H

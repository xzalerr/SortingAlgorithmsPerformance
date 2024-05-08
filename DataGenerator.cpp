#include "DataGenerator.h"

// funkcja generuje i zwraca wektor na podstawie danych zapisanych w pliku last.txt w folderze data
// dane w tym plku sa zapisane tak, ze pierwsza linia to rozmiar wektora a kolejne linijki to dane
template <typename T>
vector<T> DataGenerator<T>::generateDataFromLastFile() {
    vector<T> data;
    int size;
    ifstream inFile("data/last.txt");
    inFile >> size;
    data.reserve(size);
    T next;
    while(inFile >> next) {
        data.push_back(next);
    }
    inFile.close();
    return data;
}

// funkcja generuje i zwraca wektor na podstawie danych zapisanych w pliku o zadanej nazwie
// dane w tym plku sa zapisane tak, ze pierwsza linia to rozmiar wektora a kolejne linijki to dane
template <typename T>
vector<T> DataGenerator<T>::generateDataFromGivenFile(string name) {
    vector<T> data;

    ifstream inFile(name);
    if(!inFile.is_open()) {
        cerr << "Couldn't find given file!"<< endl;
        return data;
    }
    ofstream outFile("data/last.txt");
    if(!outFile.is_open()) {
        cerr << "File with last array opening error!"<< endl;
        inFile.close();
        return data;
    }
    int size;
    inFile >> size;
    data.reserve(size);
    T next;
    while(inFile >> next) {
        data.push_back(next);
        outFile << next << endl;
    }
    inFile.close();
    outFile.close();
    return data;
}

// funkcja generuje i zwraca wektor o zadanym rozmiarze wypelniony losowymi liczbami z przedzialu min i max dla typu int
// dane losowane sa za pomoca obiektu random_device
template <typename T>
vector<int> DataGenerator<T>::generateIntData(int size) {
    vector<int> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());
    for(int i = 0; i < size; i++) {
        int random = dist(gen);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// funkcja generuje i zwraca wektor o zadanym rozmiarze wypelniony losowymi liczbami z przedzialu min i max dla typu float
// dane losowane sa za pomoca obiektu random_device
template <typename T>
vector<float> DataGenerator<T>::generateFloatData(int size) {
    vector<float> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(numeric_limits<float>::min(), numeric_limits<float>::max());
    for(int i = 0; i < size; i++) {
        float random = dist(gen);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// funkcja generuje i zwraca wektor o zadanym rozmiarze wypelniony losowymi liczbami z przedzialu min i max dla typu double
// dane losowane sa za pomoca obiektu random_device
template <typename T>
vector<double> DataGenerator<T>::generateDoubleData(int size) {
    vector<double> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(numeric_limits<double>::min(), numeric_limits<double>::max());
    for(int i = 0; i < size; i++) {
        double random = dist(gen);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// funkcja generuje i zwraca wektor o zadanym rozmiarze wypelniony losowymi liczbami z przedzialu min i max dla typu char
// dane losowane sa za pomoca obiektu random_device
template <typename T>
vector<char> DataGenerator<T>::generateCharData(int size) {
    vector<char> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(32, 126);
    for(int i = 0; i < size; i++) {
        char random = static_cast<char>(dist(gen));
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// funkcja generuje i zwarca wektor z kolejno ulozonymi liczbami typu int od 0 do wartosci rownej dlugosci wektora -1
template <typename T>
vector<int> DataGenerator<T>::generateIntAscending(int size) {
    vector<int> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    for(int i = 0; i < size; i++) {
        data.push_back(i);
        outFile << i << endl;
    }
    outFile.close();

    return data;
}

// funkcja generuje i zwarca wektor z kolejno ulozonymi liczbami typu float od
// generowane sa wartości od 0 do dlugosci tablicy -1
// nastepnie losowo dodawana jest czesc po przecinku wylosowana przy uzyciu random_device
template <typename T>
vector<float> DataGenerator<T>::generateFloatAscending(int size) {
    vector<float> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0, 1);
    for(int i = 0; i < size; i++) {
        float random = dist(gen);
        random += i;
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// funkcja generuje i zwarca wektor z kolejno ulozonymi liczbami typu int od wartosci rownej dlugosci wektora do 1
template <typename T>
vector<int> DataGenerator<T>::generateIntDescending(int size) {
    vector<int> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    for(int i = 0; i < size; i++) {
        data.push_back(size-i);
        outFile << (size-i) << endl;
    }
    outFile.close();

    return data;
}

// funkcja generuje i zwarca wektor z kolejno ulozonymi liczbami typu float od
// generowane sa wartości od dlugosci tablicy do 1
// nastepnie losowo dodawana jest czesc po przecinku wylosowana przy uzyciu random_device
template <typename T>
vector<float> DataGenerator<T>::generateFloatDescending(int size) {
    vector<float> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0, 1);
    for(int i = 0; i < size; i++) {
        float random = dist(gen);
        random += (size-i);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// pierwsza 1/3 tablicy zapelniana jest kolejnymi wartosciami od 0
// kolejne 2/3 zapalniane sa losowymi wartosciami z zakresu [r, max]
// gdzie r to wartosc o jedna wieksza od najwiekzsej z czesci wypelnionej posortowanymi wartosciami
template <typename T>
vector<int> DataGenerator<T>::generateInt33(int size) {
    vector<int> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    int space = size / 3;

    for(int i = 0; i < space; i++) {
        data.push_back(i);
        outFile << (i) << endl;
    }
    outFile.close();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(space, numeric_limits<int>::max());
    for(int i = space; i < size; i++) {
        int random = dist(gen);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// pierwsza 1/3 tablicy zapelniana jest kolejnymi wartosciami od 0 i losowa czescia po przecinku
// kolejne 2/3 zapalniane sa losowymi wartosciami z zakresu [r, max]
// gdzie r to wartosc  wieksza od najwiekzsej z czesci wypelnionej posortowanymi wartosciami
template <typename T>
vector<float> DataGenerator<T>::generateFloat33(int size) {
    vector<float> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    int space = size / 3;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0, 1);
    for(int i = 0; i < space; i++) {
        float random = dist(gen);
        random += i;
        data.push_back(random);
        outFile << random << endl;
    }
    uniform_real_distribution<float> dist1(space, numeric_limits<float>::max());
    for(int i = 0; i < size; i++) {
        float random = dist1(gen);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// pierwsza 2/3 tablicy zapelniana jest kolejnymi wartosciami od 0
// kolejne 1/3 zapalniane sa losowymi wartosciami z zakresu [r, max]
// gdzie r to wartosc o jedna wieksza od najwiekzsej z czesci wypelnionej posortowanymi wartosciami
template <typename T>
vector<int> DataGenerator<T>::generateInt66(int size) {
    vector<int> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    int space = (2 * size) / 3;

    for(int i = 0; i < space; i++) {
        data.push_back(i);
        outFile << (i) << endl;
    }
    outFile.close();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(space, numeric_limits<int>::max());
    for(int i = space; i < size; i++) {
        int random = dist(gen);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

// pierwsza 2/3 tablicy zapelniana jest kolejnymi wartosciami od 0 i losowa czescia po przecinku
// kolejne 1/3 zapalniane sa losowymi wartosciami z zakresu [r, max]
// gdzie r to wartosc  wieksza od najwiekzsej z czesci wypelnionej posortowanymi wartosciami
template <typename T>
vector<float> DataGenerator<T>::generateFloat66(int size) {
    vector<float> data;
    data.reserve(size);

    ofstream outFile("data/last.txt");
    if (!outFile.is_open()) {
        cerr << "File not opened!" << endl;
        return data;
    }
    outFile << size << endl;
    int space = (2 * size) / 3;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(0, 1);
    for(int i = 0; i < space; i++) {
        float random = dist(gen);
        random += i;
        data.push_back(random);
        outFile << random << endl;
    }
    uniform_real_distribution<float> dist1(space, numeric_limits<float>::max());
    for(int i = 0; i < size; i++) {
        float random = dist1(gen);
        data.push_back(random);
        outFile << random << endl;
    }
    outFile.close();

    return data;
}

template class DataGenerator<int>;
template class DataGenerator<float>;
template class DataGenerator<double>;
template class DataGenerator<char>;

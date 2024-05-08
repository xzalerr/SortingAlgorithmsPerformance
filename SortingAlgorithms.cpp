#include "SortingAlgorithms.h"

// konstruktor obiektu tworzacy pusty wskaznik, ktory bedzie pozniej uzywany jako wskaznik na tablice
// deklaruje poczatkowy rozmiar tablicy na 0
template <typename T>
SortingAlgorithms<T>::SortingAlgorithms() {
    arr = nullptr;
    size = 0;
}

// dekonstruktor obiektu usuwajacy tablice jesli wskaznik nie jest pusty
template <typename T>
SortingAlgorithms<T>::~SortingAlgorithms() {
   if(arr!= nullptr) {
       delete[] arr;
   }
}

// funkcja alokujaca tablice, najpierw sprawdza czy obiekt ma juz utworzona tablice
// jesli tak to ja usuwa, nastepnie tworzy nowa tablice kopiujac wektor zadany jako parametr
template <typename T>
void SortingAlgorithms<T>::allocateArray(const vector<T> &data) {
    if(arr!= nullptr) {
        delete[] arr;
    }
    size = data.size();
    arr = new T[size];
    copy(data.begin(), data.end(), arr);
}

// funkcja sortowania szybkiego w implementacji pivota jako ostatni element tbalicy
// przyjmuje rowniez nazwe pliku, do ktorego nastepnie zapisuje czas trwania algorytmu
// czas trwania algorytmu mierzony za pomoca biblioteki chrono
template <typename T>
void SortingAlgorithms<T>::quickSort(int left, int right, const string& fileName) {
    auto start = chrono::high_resolution_clock::now();
    int i, j;
    T pivot;
    pivot = arr[right];
    j = left;
    for(i = left; i < right; i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[j], arr[right]);
    if(left < j-1) quickSort(left, j-1);
    if(j+1 < right) quickSort(j+1, right);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double time_taken = duration.count();
    if(!isSorted()) cerr << "Sorting Error in Quick Sort!" << endl;
    ofstream outFile("results/" + fileName + ".txt", ios::app);
    if(outFile.is_open()) {
        outFile << time_taken << endl;
        outFile.close();
    } else {
        cerr << "Couldn't save quick sort time!" << endl;
    }
}

// funkcja sortowania szybkiego, jednak nie mierzy czasu trwania i go nie zapisuje, wykorzystywana zeby wywolywac ja rekurencyjnie
// wywolania rekurencyjne nie maja byc mierzone pod wzgledem czasu trwania
template <typename T>
void SortingAlgorithms<T>::quickSort(int left, int right) {
    int i, j;
    T pivot;
    pivot = arr[right];
    j = left;
    for(i = left; i < right; i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[j], arr[right]);
    if(left < j-1) quickSort(left, j-1);
    if(j+1 < right) quickSort(j+1, right);
}

// funkjca sortowania przez wstawianie, mierzy czas trwania za pomocna chrono i zapisuje go do pliku
// zadanego jako parametr
template <typename T>
void SortingAlgorithms<T>::insertionSort(const string& fileName) {
    auto start = chrono::high_resolution_clock::now();
    int i, j;
    T key;
    for(i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double time_taken = duration.count();
    if(!isSorted()) cerr << "Sorting Error in Insertion Sort!" << endl;
    ofstream outFile("results/" + fileName + ".txt", ios::app);
    if(outFile.is_open()) {
        outFile << time_taken << endl;
        outFile.close();
    } else {
        cerr << "Couldn't save insertion sort time!" << endl;
    }
}

// funkjca sortowania przez wstawianie binarne, mierzy czas trwania za pomocna chrono i zapisuje go do pliku
// zadanego jako parametr
template <typename T>
void SortingAlgorithms<T>::binaryInsertionSort(const string& fileName) {
    auto starting = chrono::high_resolution_clock::now();
    int i, j, start, end, insert;
    T key;
    for(i = 1; i < size; i++) {
        key = arr[i];
        start = 0;
        end = i - 1;
        while(start<=end) {
            j = (start+end) / 2;
            if(arr[j] >= key) end = j - 1;
            else start = j + 1;
        }
        insert = start;
        j = i - 1;
        while(j>=insert) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    auto ending = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = ending - starting;
    double time_taken = duration.count();
    if(!isSorted()) cerr << "Sorting Error in Binary Insertion Sort!" << endl;
    ofstream outFile("results/" + fileName + ".txt", ios::app);
    if(outFile.is_open()) {
        outFile << time_taken << endl;
        outFile.close();
    } else {
        cerr << "Couldn't save binary insertion sort time!" << endl;
    }
}

// funkjca sortowania przez kopcowanie, mierzy czas trwania za pomocna chrono i zapisuje go do pliku
// zadanego jako parametr, pierwsza petla uzywana do budowy kopca poprawnie ukladajac elementy w tablicy
// tak aby zachowywaly wlasnosc kopca maksymalnego
// druga petla rozbierajaca kopiec wykonujac w ten sposob sortowanie poprzez zamiane korzenia z ostatnim elementem
// a nastepnie zmniejszajac rozmiar kopca o jeden
template <typename T>
void SortingAlgorithms<T>::heapSort(const string& fileName) {
    auto start = chrono::high_resolution_clock::now();
    int child, parent;
    T key;
    //budowa kopca
    for(int i = 1; i < size; i++) {
        key = arr[i];
        child = i;
        parent = (i - 1) / 2;
        while(child > 0 && arr[parent] < key) {
            arr[child] = arr[parent];
            child = parent;
            parent = (child - 1) / 2;
        }
        arr[child] = key;
    }
    //rozbiór kopca
    for(int i = size-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        child = 1;
        parent = 0;
        while(child<i) {
            if((child+1) < i && arr[child+1] > arr[child]) child += 1;
            if(arr[child] <= arr[parent]) break;
            swap(arr[child], arr[parent]);
            parent = child;
            child = 2 * parent + 1;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double time_taken = duration.count();
    if(!isSorted()) cerr << "Sorting Error in Heap Sort!" << endl;
    ofstream outFile("results/" + fileName + ".txt", ios::app);
    if(outFile.is_open()) {
        outFile << time_taken << endl;
        outFile.close();
    } else {
        cerr << "Couldn't save quick sort time!" << endl;
    }
}

// funkcja sprawdzajaca czy tablica bedaca polem obiektu jest posortowana
template <typename T>
bool SortingAlgorithms<T>::isSorted() {
    for(int i = 0; i < size-1; i++) {
        if(arr[i] > arr[i+1]) {
            std::cout<<"The array is not sorted."<<"\n";
            return 0;
        }
    }
    std::cout<<"The array is sorted."<<"\n";
    return 1;
}

// funkcja wyswietlajaca tablice bedaca polem obiektu
template <typename T>
void SortingAlgorithms<T>::display() {
    for(int i = 0; i < size; i++) {
        cout<< arr[i] << " ";
    }
    cout<<"\n";
}

template class SortingAlgorithms<int>;
template class SortingAlgorithms<float>;
template class SortingAlgorithms<double>;
template class SortingAlgorithms<char>;
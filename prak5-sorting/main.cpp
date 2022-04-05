#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

namespace Sorting {

int data[10], data2[10];
int n;
int tukar(int a, int b)
{
    int t;
    t = data[b];
    data[b] = data[a];
    data[a] = t;
    return 0;
}
void refill()
{
    for (int i = 0; i < n; i++) {
        data[i] = data2[i];
    }
}
int input()
{
    cout << "Masukan Jumlah Data = ";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "Masukan Data Ke-" << i + 1 << " = ";
        cin >> data[i];

        data2[i]
            = data[i];
    }
    cout << endl;
    return 0;
}
int tampil()
{
    for (int i = 0; i < n; i++) {
        cout << "[" << data[i] << "] ";
    }
    cout << endl;
    return 0;
}
int bubbleSort()
{
    auto start = high_resolution_clock::now();
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (data[j] < data[j - 1]) {
                tukar(j, j - 1);
            }
        }
        tampil();
    }
    cout << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration: " << duration.count() << "ms" << endl;
    return 0;
}
int selectionSort()
{
    auto start = high_resolution_clock::now();

    int i, j, posisi, tukar;
    for (i = 0; i < (n - 1); i++) {
        posisi = i;
        for (int j = i + 1; j < n; j++) {
            if (data[posisi] > data[j]) {
                posisi = j;
            }
        }
        if (posisi != i) {
            tukar = data[i];
            data[i] = data[posisi];
            data[posisi] = tukar;
        }
        tampil();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration: " << duration.count() << "ms" << endl;

    return 0;
}
void insertionSort()
{
    auto start = high_resolution_clock::now();

    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = data[i];
        j = i - 1;
        while (data[j] > temp && j >= 0) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = temp;
        tampil();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Duration: " << duration.count() << "ms" << endl;
}
}
int main()
{
    cout << "\n\nALGORITMA BUBBLE SORT" << endl;
    cout << "----------------------" << endl;
    Sorting::input();
    cout << "Proses Bubble Sort" << endl;
    Sorting::bubbleSort();

    cout << "\n\nALGORITMA Selection SORT" << endl;
    cout << "----------------------" << endl;
    Sorting::refill();
    cout << "Proses Selection Sort" << endl;
    Sorting::selectionSort();

    cout << "\n\nALGORITMA Insertion SORT" << endl;
    cout << "----------------------" << endl;
    Sorting::refill();
    cout << "Proses Insertion Sort" << endl;
    Sorting::insertionSort();

    return 0;
}

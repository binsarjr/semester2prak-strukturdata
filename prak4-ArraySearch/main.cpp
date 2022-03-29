/**

Program: Array search dengan algoritma sequential search dan binary search
Nama: Binsar Dwi Jasuma
NIM: 21.11.4002

*/

#include <iostream>

using namespace std;

namespace Search {
void Sequential(int x = 7)
{
    int arr[] { 5, 9, 2, 7, 8, 1, 6 };

    bool found { false };
    for (int i = 0; i < 7; ++i) {
        if (x == arr[i]) {
            found = true;
            cout << "Data ditemukan di indeks ke-" << i << endl;
            break;
        }
    }
    if (!found) {
        cout << "Data tidak ditemukan\n";
    }
}
void Binary(int x = 5)
{
    int m;
    int arr[] { 1, 2, 5, 7, 8, 9, 9, 11, 15, 16, 20 };
    int l { 0 };
    int r { 10 };
    bool found { false };

    while (l <= r && !found) {
        m = l + (r - l) / 2;
        if (x == arr[m]) {
            found = true;
            break;
        } else if (x < arr[m])
            r = m - 1;
        else if (x > arr[m])
            l = m + 1;
    }

    if (found) {
        cout << "Data ditemukan pada index ke-" << m << endl;
    } else {
        cout << "Data tidak ditemukan\n";
    }
}

bool BinaryRecursif(int n[], int x, int l, int r)
{
    int m = l + (r - l) / 2;
    if (x == n[m]) {
        cout << "Data ditemukan pada index ke-" << m << endl;
        return true;
    };
    if (x < n[m])
        return BinaryRecursif(n, x, l, m - 1);
    if (x > n[m])
        return BinaryRecursif(n, x, m + 1, r);
    if (l > r)
        return false;
}

void BinaryRecursifSolution()
{
    int x = 9;
    int arr[] { 1, 2, 5, 7, 8, 9, 9, 11, 15, 16, 20 };
    int l { 0 };
    int r { 10 };
    if (!BinaryRecursif(arr, x, l, r)) {
        cout << "Data tidak ditemukan\n";
    }
}

//	void MultipleSequential() {
//		const int MAX_SIZE {
//			20
//		};
//		int data[MAX_SIZE]; // array data
//		int idx[MAX_SIZE]; // array untuk menyimpan index elemen yang ditemukan
//		int count {0}; // counter, menghitung ada berapa banyak data yang ditemukan
//
//
//		int n;
//		cout << "jumlah data: ";
//		cin << n;
//		for(auto i = 0; i < n; ++i) {
//			cout << "data ke-"<< i ;
//			cin >> data[i];
//		}
//		int x;
//		cout << "cari: ";
//		cin >> x;
//
//		for(int i = 0; i < n; ++i) {
//			// jika x ditemukan pada data[i]
//
//			if(x == data[i]) {
//				// simpan index i ke array x
//				idx[count++] = i;
//			}
//		}
//
//
//		// jika counter > 0, berarti ada data yang ditemukan
//		if(count > 0) {
//			cout << "ditemukan pada index: ";
//			for(auto i = 0; i < count; ++i) {
//				cout << idx[i] << ", ";
//			}
//		} else {
//			cout << "data tidak ditemukan\n";
//		}
//	}
}

int main()
{
    cout << "Sequential Search\n";
    Search::Sequential(10);
    cout << "Binary Search\n";
    Search::Binary();
    cout << "Binary Recursif Search\n";
    Search::BinaryRecursifSolution();
    return 0;
}
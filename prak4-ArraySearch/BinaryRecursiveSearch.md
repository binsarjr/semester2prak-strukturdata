# Binary Recursive Search Algorithm

Proses pencarian dengan metode Binary Search selain menggukan Looping
dapat pula dibuat dengan rekursi. Berikut ini contoh penggunaan rekursi untuk
pencarian dengan binary search

### Percobaan
```cpp
bool binsearch(int n[], int x, int l, int r)
{
    int m = l + (r - l) / 2;
    if(x == n[m])
        return true;
    if(x < n[m])
        return binsearch(x, l, m - 1);
    if(x > n[m])
        return binsearch(x, m + 1, r);
    if(l > r)
        return false;

}
```

### Latihan
Cobalah dengan data yang `ada` dan data yang `tidak ada` di dalam
array serta munculkanlah keterangan di outputnya Data ditemukan atau tidak.
Jika data ditemukan maka tunjukkan data tersebut berada di indeks keberapa !



### Jawaban
Cukup dengan menambahkan cout data ditemukan pada kondisi yang mengembalikkan nilai `true`
dan cout data tidak ditemukan pada kondisi yang mengembalikkan nilai `false`
```cpp
#include <iostream>

using namespace std;

bool binsearch(int n[], int x, int l, int r)
{
    int m = l + (r - l) / 2;
    if(x == n[m]) {
        cout << "Data ditemukan pada index ke-"<<m<<endl;
        return true;
    }
    if(x < n[m])
        return binsearch(x, l, m - 1);
    if(x > n[m])
        return binsearch(x, m + 1, r);
    if(l > r) {
        cout << "Data tidak ditemukan"<<endl;
        return false;
    }

}

int main() {
    int x = 9;
    int arr[] { 1, 2, 5, 7, 8, 9, 9, 11, 15, 16, 20 };
    int l { 0 };
    int r { 10 };
    BinaryRecursif(arr, x, l, r);

    return 0;
}
```

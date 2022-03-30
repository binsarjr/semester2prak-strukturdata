# Multiple Sequential Search
Sama dengan sequential search bedanya disini kita akan mengecek lebih dari 1 data


### Soal
Terdapat sebuah array dengan ukuran maksimal 20. Elemen array diisi
dengan input oleh pengguna saat program berjalan. Program harus bisa
melakukan pencarian terhadap elemen array dan bila ketemu maka harus

menampilkan semua posisi index-nya bila terdapat lebih dari satu elemen yang
sama nilainya.

```cpp
/**
 * program sequential search
 * dapat menampilkan semua index data yang ditemukan
 *
 */
#include <iostream>
using namespace std;
const int MAX_SIZE { 20 }
int data[MAX_SIZE]; // array data
int idx[MAX_SIZE];  // array untuk menyimpan index elemen yang ditemukan
int count { 0 };    // counter, menghitung ada berapa banyak data yang ditemukan

void search(int x);
int main(void)
{
    int n;
    cout << "jumlah data: ";
    cin << n;
    for (auto i = 0; i < n; ++i) {
        cout << "data ke-" << i;
        cin >> data[i];
    }
    int x;
    cout << "cari: ";
    cin >> x;
    search(x);
    // jika counter > 0, berarti ada data yang ditemukan
    if (count > 0) {
        cout << "ditemukan pada index: ";
        for (auto i = 0; i < count; ++i) {
            cout << idx[i] << ", ";
        }
    } else {
        Cout << "data tidak ditemukan\n";
    }
    return 0;
}
void search(int x)
{
    for (auto i = 0; i < n; ++i) {
        // jika x ditemukan pada data[i]
        if (x == data[i]) {
            // simpan index i ke array idx
            idx[count++] = i;
        }
    }
}
```
### Jawaban
```cpp
#include <iostream>

using namespace std;

/** fungsi search saya ubah namanya sesuai dengan yang saya inginkan
* Kemudian parameternya saya tambahkan n, array data dan idx serta referensi count
*/
void MultipleSequentialSearch(int x, int n, int data[], int idx[], int& count)
{
    for (int i = 0; i < n; ++i) {
        // jika x ditemukan pada data[i]
        if (x == data[i]) {
            // simpan index i ke array idx
            idx[count++] = i;
        }
    }
}

void MultipleSequential()
{
    // Semua deklarasi variabel saya masukkan kedalam fungsi saja karena compiler saya memberikan pesan error ketika inisialisasi tersebut dilakukan
    const int MAX_SIZE { 20 };
    int data[MAX_SIZE]; // array data
    int idx[MAX_SIZE];  // array untuk menyimpan index elemen yang ditemukan
    int count { 0 };    // counter, menghitung ada berapa banyak data yang ditemukan

    int n;
    cout << "jumlah data: ";
    cin >> n; // yang awalnya << saya ubah ke >>
    for (int i = 0; i < n; ++i) {
        cout << "data ke-" << i << " ";
        cin >> data[i];
    }
    int x;
    cout << "cari: ";
    cin >> x;
    // pemanggilan fungsi search
    MultipleSequentialSearch(x, n, data, idx, count);
    // jika counter > 0, berarti ada data yang ditemukan
    if (count > 0) {
        cout << "ditemukan pada index: ";
        for (int i = 0; i < count; ++i) {
            cout << idx[i] << ", ";
        }
    } else {
        cout << "data tidak ditemukan\n";
    }
}
```

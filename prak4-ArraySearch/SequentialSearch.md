# Sequential Search Algorithm

Metode Sequential Search dapat digunakan untuk melakukan pencarian data
baik pada array yang **sudah terurut** maupun yang **belum terurut**. Proses yang
terjadi pada metode pencarian ini adalah sebagai berikut:

- Menentukan data yang dicari.
- Data yang dicari akan dibandingkan dengan data dalam array satu persatu mulai dari data ke-0 sampai index terakhir, tetapi
- Jika perbandingan antara data yang dicari dengan data dalam array cocok maka proses dihentikan.

### Percobaan
Sebagai ilustrasi ada sebuah array berukuran 7 bertipe `int`
dengan nama `arr` berisi data `{5, 9,2, 7, 8, 1, 6}`. Data yang akan
dicari adalah 7 yang dinyatakan sebagai x. Berikut ini adalah contoh
proses pencarian yang bisa digunakan.

### Inisialisasi
```cpp
int x=7;
int arr[]{5,9,2,7,8,1,6};
```

### Proses pencarian secara linier
```cpp
bool found{false};
for(auto i = 0; i < 7; ++i)
{
    if(x == arr[i])
    {
        found = true;
        cout << "Data ditemukan di indeks ke-"<< i;
        break;
    }
}
```

Pada potongan kode di atas terdapat variabel `x` sebagai penampung
data yang di cari yaitu `7` dan variabel `found` sebagai penanda apakah
data yang dicari ketemu.
Sebagai nilai awal variable `found` adalah `false` sebagai penanda
bahwa data belum ditemukan.

Pada saat proses perulangan ke-i nilai x akan selalu dibandingkan
dengan nilai `arr[i]`. Jika perbandingan sesuai maka nilai `found`
akan diset menjadi `true` dan perulangan dihentikan.
Akhir proses dari contoh di atas akan didapatkan nilai 3, sehingga pencarian dikatakan berhasil yaitu data ketemu pada index yang ke-3.

### Latihan
      Cobalah dengan data yang tidak ada di dalam array dan
      munculkanlah Data tidak ditemukan


### Jawaban
      ```cpp
#include <iostream>

      using namespace std;

void Sequential(int x = 7)
{
    int arr[] { 5, 9, 2, 7, 8, 1, 6 };

    bool found { false };
    for (int i = 0; i < 7; ++i) {
        if (x == arr[i]) {
            found = true;
            // Menampilkan pesan ditemukan ketika found bernilai true
            cout << "Data ditemukan di indeks ke-" << i << endl;
            break; // langsung break saja karena kita hanya butuh 1 data
        }
    }
    // Apabila found bernilai false. Maka, tampilkan data tidak ditemukan
    if (!found) {
        cout << "Data tidak ditemukan\n";
    }
}

int main() {
    Sequential(7);
    Sequential(10);
    return 0;
}

```

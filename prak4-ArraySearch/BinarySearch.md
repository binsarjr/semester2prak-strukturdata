# Binary Search Algorithm
Metode Binary Search hanya digunakan untuk pencarian data yang sudah
terurut. Proses yang terjadi pada pencarian dengan metode ini adalah sebagai
berikut:

- Menentukan data yang akan dicari.
- Menentukan elemen tengah dari array.
- Jika nilai elemen tengah sama dengan data yang dicari maka pencarian selesai, tetapi
- Jika nilai elemen tengah tidak sama dengan data yang dicari maka:
    - Jika nilai elemen tengah lebih besar daripada data yang dicari maka pencarian dilakukan pada setengah array pertama, tetapi
    - Jika nilai elemen tengah lebih kecil daripada data yang dicari maka pencarian dilakukan pada setengah array berikutnya.



### Percobaan
Sebagai ilustrasi terdapat array berukuran `11` bertipe `int`
dengan nama `arr` berisi data terurut naik `{1, 2, 5, 7, 8, 9, 9, 11, 15, 16, 20}`.
Sebagai contoh data yang akan dicari adalah 5, dinyatakakan sebagai x dan penanda bila data ketemu adalah found. Proses pencarian dapat dilakukan seperti berikut.

### Inisialisasi
```cpp
int m,x=5;
int arr[]{1, 2, 5, 7, 8, 9, 9, 11, 15, 16, 20};
int l{0};
int r{10};
```
### Proses pencarian dengan binary search
```cpp
bool found{false};
while(l <= r && !found)
{
    m = l + (r - l) / 2;
    if(x == arr[m])
        found = true;
    else if(x < arr[m])
        r = m - 1;
    else if(x > arr[m])
        l = m + 1;
}
```

Pengaksesan dapat dilakukan satu persatu langsung merujuk pada indeks atau
serentak. Contoh pengaksesan secara serentak pada array 2 dimensi


### Latihan
Cobalah dengan data yang `ada` dan data yang `tidak ada` di dalam
array serta munculkanlah keterangan di outputnya Data ditemukan atau tidak.
Jika data ditemukan maka tunjukkan data tersebut berada di indeks keberapa !

### Jawaban
```cpp
#include <iostream>

using namespace std;

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
    
    /**
    * Dengan kode dibawah ini kita bisa mengecek apakah data suatu data berhasil
    * ditemukan atau tidak dengan mengecek nilai dari variabel found
    */
    if (found) {
        cout << "Data ditemukan pada index ke-" << m << endl;
    } else {
        cout << "Data tidak ditemukan\n";
    }
}


int main() {
    Binary(5);
    Binary(10);
    return 0;
}

```


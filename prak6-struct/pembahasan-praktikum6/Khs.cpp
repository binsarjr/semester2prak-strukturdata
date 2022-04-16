#include "iomanip"
#include "iostream"
#include "limits"

using namespace std;

struct MataKuliah {
  string kode;
  string nama;
  float bobot;
  string nilai;
};

struct Mahasiswa {
  string nim;
  string nama;
  MataKuliah matkul[30];
  int jumlahMatkul;
};

int hitungIpk(float bobotSks, string nilai) {
  int nilaiAngka = 0;

  if (nilai == "A" || nilai == "a") {
    nilaiAngka = 4;
  } else if (nilai == "B" || nilai == "b") {
    nilaiAngka = 3;
  } else if (nilai == "C" || nilai == "c") {
    nilaiAngka = 2;
  } else if (nilai == "D" || nilai == "d") {
    nilaiAngka = 1;
  } else if (nilai == "E" || nilai == "e") {
    nilaiAngka = 0;
  }
  return nilaiAngka * bobotSks;
}

int main() {
  system("clear");
  int jumlahMhs;
  cout << "Program KHS Mahasiswa\n";
  cout << "Jumlah mahasiswa : ";
  cin >> jumlahMhs;

  Mahasiswa mhs[jumlahMhs];

  // ambil data mahasiswa
  for (int i = 0; i < jumlahMhs; i++) {
    cin.ignore();
    cout << "---------------------------------\n";
    cout << i + 1 << ". NIM : ";
    getline(cin, mhs[i].nim);
    cout << "Nama : ";
    getline(cin, mhs[i].nama);

    cout << "Jumlah mata kuliah diambil: ";
    cin >> mhs[i].jumlahMatkul;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // ambil data MataKuliah
    for (int j = 0; j < mhs[i].jumlahMatkul; j++) {
      cout << "---------------------------------\n";
      cout << j + 1 << ". Kode : ";
      getline(cin, mhs[i].matkul[j].kode);
      cout << "Nama: ";

      getline(cin, mhs[i].matkul[j].nama);
      cout << "Bobot SKS: ";
      cin >> mhs[i].matkul[j].bobot;
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Nilai: ";
      getline(cin, mhs[i].matkul[j].nilai);
    }

    // hitung khs
    cout << "+---------------------------------------------------------+\n";
    cout << "| Kartu Hasil Studi |\n";
    cout << "+---------------------------------------------------------+\n";
    cout << "| NIM : " << mhs[i].nim << " |\n";
    cout << "| Nama : " << mhs[i].nama << " |\n";

    cout << "+---------------------------------------------------------+\n";
    cout << "| KDMK Mata Kuliah SKS Nilai Bobot |\n";
    cout << "+---------------------------------------------------------+\n";

    int jumlahSks = 0;
    int jumlahIpk = 0;
    for (int j = 0; j < mhs[i].jumlahMatkul; j++) {
      jumlahSks += mhs[i].matkul[j].bobot;
      int ipk = hitungIpk(mhs[i].matkul[j].bobot, mhs[i].matkul[j].nilai);
      jumlahIpk += ipk;
      cout << "| ";
      cout << mhs[i].matkul[j].kode << " ";
      cout << mhs[i].matkul[j].nama << " ";
      cout << mhs[i].matkul[j].bobot << " ";
      cout << mhs[i].matkul[j].nilai << " ";
      cout << ipk << " |\n";
    }

    float ipk = float(jumlahIpk) / float(jumlahSks);

    cout << "+---------------------------------------------------------+\n";
    cout << "| Jumlah SKS Total " << jumlahSks << " |\n";
    cout << "| Indeks Prestasi Kumulatif " << fixed << setprecision(1) << ipk
         << " |\n";
    cout << "+---------------------------------------------------------+\n";
  }
}

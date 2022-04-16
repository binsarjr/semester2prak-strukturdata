/*
 * program buku alamat sederhana
 * menyimpan data alamat: nama, alamat, nomor telepon
 */

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
struct PhoneBook {
  string name;
  string address;
  string number;
};
// ukuran array
const int SIZE = 100;
// counter, menghitung jumlah data yang tersimpan
int counter = 0;
// array untuk menyimpan data
PhoneBook pb[SIZE];

void add_contact();
void show_contact(PhoneBook *pb, int counter);
void search_contact();
void edit_contact();

void pause();
char get_menu();
int main() {
  while (true) {
    char select = get_menu();
    if (select == '1')
      add_contact();
    else if (select == '2')
      show_contact(pb, counter);
    else if (select == '3')
      search_contact();
    else if (select=='4')
      edit_contact();
    else if (select == '5')
      break;
  }
  return 0;
}

void pause() { system("read -p 'Press Enter to continue...' var"); }

void edit_contact() {
  system("clear");
  int index;

  cout << "Menu Edit\n";
  show_contact(pb, counter);
  cout << "Silakan pilih data ke-# akan diedit\n";
  cout << "Pilih : ";
  cin>>index;

  
  system("clear");
  cout << "Data yang akan diedit adalah sebagai berikut:\n";
  cout << "- Name     : "<<pb[index-1].name<<endl;
  cout << "- Address  : "<<pb[index-1].address<<endl;
  cout << "- Phone    : "<<pb[index-1].number<<endl<<endl;

  cout << "Edit Contact To\n";
  cin.ignore();
  cout << "- Name : ";
  getline(cin, pb[index-1].name);
  cout << "- Address: ";
  getline(cin, pb[index-1].address);
  cout << "- Phone : ";
  getline(cin, pb[index-1].number);
 
}

void search_contact() {
  int counterSearched = 0;
  PhoneBook pbSearch[counter];
  string kataKunci;
  system("clear");
  cout << "Masukkan kata kunci : ";
  getline(cin, kataKunci);

  for (int i = 0; i < counter; i++) {
    bool found{false};

    if (pb[i].name.find(kataKunci) != string::npos) {
      found = true;
    }

    if (pb[i].address.find(kataKunci) != string::npos) {
      found = true;
    }
    if (pb[i].number.find(kataKunci) != string::npos) {
      found = true;
    }

    if (found) {
      pbSearch[counterSearched++] = pb[i];
    }
  }
  show_contact(pbSearch, counterSearched);
}

void add_contact() {
  system("clear");
  cout << "Add New Contact\n";
  cout << "- Name : ";
  getline(cin, pb[counter].name);
  cout << "- Address: ";
  getline(cin, pb[counter].address);
  cout << "- Phone : ";
  getline(cin, pb[counter].number);
  ++counter;
}
void show_contact(PhoneBook *pb, int counter) {
  system("clear");
  cout << "Show Contact\n";
  cout << "--------------------------------------------------------------\n";
  cout << setw(4) << "#";
  cout << setw(15) << "Name";
  cout << setw(30) << "Address";
  cout << setw(13) << "Number";
  cout << endl;
  cout << "--------------------------------------------------------------\n";
  for (int i = 0; i < counter; ++i) {
    cout << setw(4) << i + 1;
    cout << setw(15) << pb[i].name;
    cout << setw(30) << pb[i].address;
    cout << setw(13) << pb[i].number;
    cout << endl;
  }
  cout << "--------------------------------------------------------------\n";
  pause();
}
char get_menu() {
  system("clear");
  cout << "Phone Book\n";
  cout << " [1] Add Contact\n";
  cout << " [2] Show Contact\n";
  cout << " [3] Search Contact\n";
  cout << " [4] Edit Contact\n";
  cout << " [5] Exit\n";
  cout << "Select: ";
  string sel;
  getline(cin, sel);
  return sel[0]; // hanya mengambil karakter ke-0
}

#include <iostream>

using namespace std;

struct UserCredential {
  string username;
  string password;
};
typedef UserCredential Credential;

struct User {
  string username, password;
};

void menuLabel() {
  cout << "======  Pilihan barang ======" << endl;
  cout << "=== A. Baju   - Rp.15.000 ===" << endl;
  cout << "=== B. Sepatu - Rp.30.000 ===" << endl;
  cout << "=== C. Sandal - Rp.25.000 ===" << endl;
  cout << "=============================" << endl << endl;
}

void categoryLabel() {
  cout << "======  Category ======" << endl;
  cout << "=== A. Aparel   " << endl;
  cout << "=== B. Sepatu " << endl;
  cout << "=== C. Bola " << endl;
  cout << "=== D. Aksesoris " << endl;
  cout << "=============================" << endl << endl;
}

int main(){
  const Credential credential = {"admin", "password123"};
  User user;
  
  char category;
  int product;

  cout << "Masukan username: "; cin >> user.username;
  cout << "Masukan password: "; cin >> user.password;

  if (user.username != credential.username || user.password != credential.password) {
    cout << "Tidak valid";
    return 0;
  }
  

  categoryLabel();
  cout << "Masukkan kategori barang (A/B/C/D): "; cin >> category;
  
  menuLabel();
  cout << "Masukkan kategori Product (A/B/C/D): "; cin >> category;
  

  return 0;
}

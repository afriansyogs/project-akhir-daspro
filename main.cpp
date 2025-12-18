#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

struct RegisteredPasien {
  string nama;
  string nik;
  int umur;
  string penyakit;
  string categoryPenyakit;
  double biaya;
}; 
typedef RegisteredPasien Pasien;

const int maxPasien = 100; 
Pasien daftarPasien[maxPasien]; 
int jumlahPasien = 0;

void tampilkanMenu(); 
double hitungBiaya(string jenisPenyakit, int umur); 
void tambahPasien();
void lihatDataPasien();

int main() {
  int pilihan;
  char kembali;

  do {
    // system("cls"); 
    tampilkanMenu();
    
    cout << "Pilih menu (1-3): ";
    cin >> pilihan;
    cin.ignore(); 

    if (pilihan == 1) {
      tambahPasien();
    } else if (pilihan == 2) {
      lihatDataPasien();
    } else if (pilihan == 3) {
      cout << "Terima kasih telah menggunakan sistem EMR." << endl;
      break; 
    } else {
      cout << "Pilihan tidak valid!" << endl;
    }

    cout << "\nKembali ke menu utama? (y/n): ";
    cin >> kembali;

  } while (kembali == 'y' || kembali == 'Y');

  return 0;
}


void tampilkanMenu() {
  cout << "======================================" << endl;
  cout << "   EMR KLINIK SEHAT (TERMINAL)        " << endl;
  cout << "======================================" << endl;
  cout << "1. Registrasi Pasien Baru" << endl;
  cout << "2. Lihat Daftar Pasien (Sorted)" << endl;
  cout << "3. Keluar" << endl;
  cout << "======================================" << endl;
}

void dataPasien(Pasien pasien) {
  cout << "Nama pasien: " << pasien.nama << endl;
  cout << "NIK: " << pasien.nik << endl;
  cout << "Umur: " << pasien.umur << endl;
  cout << "Penyakit: " << pasien.penyakit << endl;
  cout << "Kategori penyakit: " << pasien.categoryPenyakit << endl;
  cout << "Biaya pengobatan: Rp " << pasien.biaya << endl;
}


double hitungBiaya(string jenisPenyakit, int umur) {
  double biayaDasar = 0;

  if (jenisPenyakit == "berat") {
    biayaDasar = 500000;
    if (umur > 60) {
      cout << ">> Info: Pasien Lansia (Diskon Subsidi 20%)" << endl;
      return biayaDasar * 0.8; 
      }
  } else if (jenisPenyakit == "sedang") {
    biayaDasar = 250000;
    if (umur < 12) {
        cout << ">> Info: Pasien Anak (Diskon Anak 10%)" << endl;
        return biayaDasar * 0.9;
      }
  } else {
    biayaDasar = 100000;
  }
  
  return biayaDasar;
}

void tambahPasien() {
  if (jumlahPasien >= maxPasien) {
    cout << "Kapasitas penuh!" << endl;
    return;
  }

  cout << "\n--- FORM REGISTRASI ---" << endl;
  cout << "Nama Pasien: ";
  getline(cin, daftarPasien[jumlahPasien].nama);

  do {
    cout << "NIK: ";
    cin >> daftarPasien[jumlahPasien].nik;
    cin.ignore();

    if (daftarPasien[jumlahPasien].nik.length() != 16) {
      cout << "NIK harus 16 digit\n";
    }
  } while (daftarPasien[jumlahPasien].nik.length() != 16);

  cout << "Umur: ";
  cin >> daftarPasien[jumlahPasien].umur;
  cin.ignore();
  cout << "Masukan nama penyakit: ";
  getline(cin, daftarPasien[jumlahPasien].penyakit);
  cout << "Tingkat Penyakit (ringan/sedang/berat): ";
  cin >> daftarPasien[jumlahPasien].categoryPenyakit;

  daftarPasien[jumlahPasien].biaya = hitungBiaya(daftarPasien[jumlahPasien].categoryPenyakit, daftarPasien[jumlahPasien].umur);

  cout << "\n--- RINCIAN ---" << endl;
  dataPasien(daftarPasien[jumlahPasien]);

  jumlahPasien++;
  cout << "Data berhasil disimpan!" << endl;
}

void lihatDataPasien() {
  int pilihanData;
  string searchPasienByNik;

  if (jumlahPasien == 0) {
    cout << "Belum ada data pasien." << endl;
    return;
  }
  cout << "\n--- MENU LIHAT DATA PASIEN ---" << endl;
  cout << "1. Cari Pasien" << endl;
  cout << "2. Lihat Semua Pasien" << endl;
  cout << "Pilih opsi (1-2): "; cin >> pilihanData;

  if (pilihanData == 1) {
    cout << "Masukkan NIK pasien yang ingin dicari: "; cin >> searchPasienByNik;
    for (int i = 0; i < jumlahPasien; i++) {
      if (daftarPasien[i].nik == searchPasienByNik) {
        cout << "\n--- DATA PASIEN DITEMUKAN ---" << endl;
        dataPasien(daftarPasien[i]);
        break;
      } else {
        cout << "Pasien dengan NIK " << searchPasienByNik << " tidak ditemukan." << endl;
      }
    }
  } else if(pilihanData == 2) {
    for (int i = 0; i < jumlahPasien - 1; i++) { 
      for (int j = 0; j < jumlahPasien - i - 1; j++) { 
        if (daftarPasien[j].umur > daftarPasien[j + 1].umur) { 
          Pasien temp = daftarPasien[j];
          daftarPasien[j] = daftarPasien[j + 1];
          daftarPasien[j + 1] = temp;
        }
      }
    }

    cout << "\n--- DAFTAR PASIEN (Diurutkan berdasarkan Umur) ---" << endl;
    cout << left << setw(20) << "Nama" << setw(10) << "Umur" << setw(15) << "Penyakit" << setw(15) << "Biaya (Rp)" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < jumlahPasien; i++) {
      cout << left << setw(20) << daftarPasien[i].nama 
        << setw(10) << daftarPasien[i].umur 
        << setw(15) << daftarPasien[i].penyakit 
        << setw(15) << daftarPasien[i].categoryPenyakit 
        << setw(15) << daftarPasien[i].biaya << endl;
    }
  } else {
    cout << "Opsi tidak valid!" << endl;
    return;
  }
}
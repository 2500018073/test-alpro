#include <iostream>
using namespace std;

int main() {
    string nama;
    int pilihan;
    float berat, hargaPerKg = 0, totalHarga = 0;

    cout << "=== PROGRAM LAUNDRY ===" << endl;
    cout << "Masukkan nama pelanggan: ";
    cin >> nama;

    cout << " \npilih jenis layanan : ";
    cout << "\n1. Cuci saja (Rp 5000    /kg)" << endl;
    cout << "2. Cuci dan setrika (Rp 10000/kg)" << endl;
    cout << "3. Setrika saja (Rp 4000/kg)" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihan;

    cout << "Masukkan berat pakaian (kg): ";
    cin >> berat;

    // Menentukan harga per kg berdasarkan pilihan layanan
    if (pilihan == 1) {
        hargaPerKg = 5000;
    } else if (pilihan == 2) {
        hargaPerKg = 10000;
    } else if (pilihan == 3) {
        hargaPerKg = 4000;
    } else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    totalHarga = berat * hargaPerKg;

    cout << "\n===STRUKTUR LAUNDRY===" << endl;
    cout << "Nama Pelanggan: " << nama << endl;
    cout << "Berat pakaian : " << berat << endl;
    cout << "Total Harga: Rp " << totalHarga << endl;

    cout << "\nTerima kasih telah menggunakan layanan kami!" << endl;

    return 0;
}
#include <iostream>
using namespace std;

class Laundry {
private:
    string nama;
    int pilihan;
    int berat;
    int harga;
    int total;

public:
    void input() {
        cout << "\n=== SISTEM LAUNDRY ===" << endl;
        cout << "Masukkan nama pelanggan: ";
        cin >> nama;

        cout << "\nPilih jenis layanan:" << endl;
        cout << "1. Cuci Kering (Rp5000/kg)" << endl;
        cout << "2. Cuci Setrika (Rp7000/kg)" << endl;
        cout << "3. Setrika Saja (Rp4000/kg)" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        cout << "Masukkan berat (kg): ";
        cin >> berat;
    }

    // KONDISIONAL
    void proses() {
        switch (pilihan) {
            case 1:
                harga = 5000;
                break;
            case 2:
                harga = 7000;
                break;
            case 3:
                harga = 4000;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                harga = 0;
        }

        // IF ELSE
        if (berat > 0 && harga > 0) {
            total = hitungIteratif();
        } else {
            total = 0;
        }
    }

    // PERULANGAN ITERATIF
    int hitungIteratif() {
        int hasil = 0;

        for (int i = 1; i <= berat; i++) {
            hasil = hasil + harga;
        }

        return hasil;
    }

    // REKURSI
    int hitungRekursif(int n) {
        if (n == 0) {
            return 0;
        } else {
            return harga + hitungRekursif(n - 1);
        }
    }

    void output() {
        cout << "\n=== STRUK LAUNDRY ===" << endl;
        cout << "Nama pelanggan : " << nama << endl;
        cout << "Berat          : " << berat << " kg" << endl;

        // KONDISIONAL IF ELSE
        if (pilihan == 1) {
            cout << "Layanan        : Cuci Kering" << endl;
        } else if (pilihan == 2) {
            cout << "Layanan        : Cuci Setrika" << endl;
        } else if (pilihan == 3) {
            cout << "Layanan        : Setrika Saja" << endl;
        } else {
            cout << "Layanan        : Tidak valid" << endl;
        }

        cout << "Total Iteratif : Rp" << total << endl;

        // PEMANGGILAN REKURSI
        cout << "Total Rekursif : Rp" 
             << hitungRekursif(berat) << endl;
    }
};

int main() {
    char ulang;

    // PERULANGAN DO WHILE
    do {
        Laundry l;

        l.input();
        l.proses();
        l.output();

        cout << "\nIngin input lagi? (y/t): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nProgram selesai." << endl;

    return 0;
}

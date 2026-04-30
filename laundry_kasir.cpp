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
        cout << "=== SISTEM LAUNDRY ===" << endl;
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

        // if-else untuk validasi
        if (berat > 0 && harga > 0) {
            total = berat * harga;
        } else {
            total = 0;
        }
    }

    void output() {
        cout << "\n=== STRUK LAUNDRY ===" << endl;
        cout << "Nama pelanggan : " << nama << endl;
        cout << "Berat          : " << berat << " kg" << endl;

        if (pilihan == 1) {
            cout << "Layanan        : Cuci Kering" << endl;
        } else if (pilihan == 2) {
            cout << "Layanan        : Cuci Setrika" << endl;
        } else if (pilihan == 3) {
            cout << "Layanan        : Setrika Saja" << endl;
        } else {
            cout << "Layanan        : Tidak valid" << endl;
        }

        cout << "Total bayar    : Rp" << total << endl;
    }
};

int main() {
    Laundry l;
    l.input();
    l.proses();
    l.output();

    return 0;
}

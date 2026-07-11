#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_TRANSAKSI = 100;

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

        if (berat > 0 && harga > 0) {
            total = hitungIteratif();
        } else {
            total = 0;
        }
    }


    int hitungIteratif() {
        int hasil = 0;
        for (int i = 1; i <= berat; i++) {
            hasil = hasil + harga;
        }
        return hasil;
    }


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
        cout << "Total Rekursif : Rp" << hitungRekursif(berat) << endl;
    }

    int getPilihan() const { return pilihan; }
    int getBerat() const { return berat; }
    int getTotal() const { return total; }
};


void simpanTransaksi(int riwayat[][3], int *ptrTotal, int &jumlah, int pilihan, int berat, int total) {
    if (jumlah < MAX_TRANSAKSI) {
        
        riwayat[jumlah][0] = pilihan;
        riwayat[jumlah][1] = berat;
        riwayat[jumlah][2] = total;
        
        
        *(ptrTotal + jumlah) = total; 
        jumlah++;
    }
}


void sortingTotal(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}


int searchingTotal(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == key) {
            return i; 
        }
    }
    return -1; 
}


void tampilkanRiwayat(int riwayat[][3], int *ptrTotal, int n) {
    cout << "\n=== RIWAYAT TRANSAKSI ===" << endl;
    cout << "No | Layanan       | Berat | Total" << endl;
    for (int i = 0; i < n; i++) {
        string layanan = "";
        if (riwayat[i][0] == 1) layanan = "Cuci Kering";
        else if (riwayat[i][0] == 2) layanan = "Cuci Setrika";
        else if (riwayat[i][0] == 3) layanan = "Setrika Saja";
        else layanan = "Invalid";
        
        cout << i + 1 << "  | " << left << setw(13) << layanan 
             << "| " << left << setw(5) << riwayat[i][1] 
             << "| Rp" << *(ptrTotal + i) << endl;
    }
}

int main() {
    char ulang;
    int jumlahTransaksi = 0;
    
   
    int daftarTotal[MAX_TRANSAKSI]; 
    
    
    int riwayatTransaksi[MAX_TRANSAKSI][3]; 
    
    
    int *ptrTotal = daftarTotal; 

    
    do {
        Laundry l;
        l.input();
        l.proses();
        l.output();
        
        
        simpanTransaksi(riwayatTransaksi, ptrTotal, jumlahTransaksi, l.getPilihan(), l.getBerat(), l.getTotal());

        cout << "\nIngin input lagi? (y/t): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    tampilkanRiwayat(riwayatTransaksi, ptrTotal, jumlahTransaksi);


    cout << "\n--- Melakukan Sorting Total Transaksi ---" << endl;
    sortingTotal(ptrTotal, jumlahTransaksi);
    
    cout << "Daftar Total setelah di-sorting: " << endl;
    for(int i = 0; i < jumlahTransaksi; i++) {
        cout << "Rp" << *(ptrTotal + i) << " ";
    }
    cout << endl;

    int cari;
    cout << "\n--- Searching Total Transaksi ---" << endl;
    cout << "Masukkan nominal total yang ingin dicari: Rp";
    cin >> cari;
    
    int hasilSearch = searchingTotal(ptrTotal, jumlahTransaksi, cari);
    if (hasilSearch != -1) {
        cout << "Ditemukan! Nominal Rp" << cari << " ada di urutan ke-" << hasilSearch + 1 << " setelah sorting." << endl;
    } else {
        cout << "Tidak ditemukan nominal Rp" << cari << " dalam riwayat." << endl;
    }

    cout << "\nProgram selesai." << endl;
    return 0;
}
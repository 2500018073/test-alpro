#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


struct Mahasiswa {
    string nim;
    string nama;
    double tugas;
    double uts;
    double uas;
    double nilaiAkhir;
};


double hitungNilaiAkhirRekursif(double komponen[], int index) {
 
    if (index == 3) {
        return 0;
    }

    return komponen[index] + hitungNilaiAkhirRekursif(komponen, index + 1);
}


int cariMahasiswaByNIM(Mahasiswa arr[], int n, string targetNIM) {
    for (int i = 0; i < n; i++) {
        if (arr[i].nim == targetNIM) {
            return i; 
        }
    }
    return -1;
}


int cariNilaiTerendah(Mahasiswa arr[], int n) {
    if (n <= 0) return -1;
    
    int indeksTerendah = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].nilaiAkhir < arr[indeksTerendah].nilaiAkhir) {
            indeksTerendah = i;
        }
    }
    return indeksTerendah;
}


double hitungRataRata(Mahasiswa arr[], int n) {
    if (n == 0) return 0;
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i].nilaiAkhir;
    }
    return total / n;
}

int main() {
    const int MAX_MAHASISWA = 100;
    
    Mahasiswa daftarMhs[MAX_MAHASISWA];
    int jumlahMhs = 0;


    ifstream fileInput("mahasiswa.txt");
    if (!fileInput) {
        cout << "Error: File 'mahasiswa.txt' tidak ditemukan!\n";
        return 1;
    }

    while (fileInput >> daftarMhs[jumlahMhs].nim >> daftarMhs[jumlahMhs].nama 
                     >> daftarMhs[jumlahMhs].tugas >> daftarMhs[jumlahMhs].uts 
                     >> daftarMhs[jumlahMhs].uas) {
        
      
        double komponen[3] = {
            0.30 * daftarMhs[jumlahMhs].tugas,
            0.30 * daftarMhs[jumlahMhs].uts,
            0.40 * daftarMhs[jumlahMhs].uas
        };

       
        daftarMhs[jumlahMhs].nilaiAkhir = hitungNilaiAkhirRekursif(komponen, 0);
        
        jumlahMhs++;
        if (jumlahMhs >= MAX_MAHASISWA) break;
    }
    fileInput.close();

    cout << "=== Berhasil memuat " << jumlahMhs << " data mahasiswa ===\n\n";

    
    double rataRata = hitungRataRata(daftarMhs, jumlahMhs);
    int indeksTerendah = cariNilaiTerendah(daftarMhs, jumlahMhs);

    
    ofstream fileOutput("hasil_analisis_nilai.txt");
    fileOutput << "=========================================================================\n";
    fileOutput << "                       HASIL ANALISIS NILAI MAHASISWA                    \n";
    fileOutput << "=========================================================================\n";
    fileOutput << left << setw(12) << "NIM" << setw(18) << "Nama" 
               << setw(10) << "Tugas" << setw(10) << "UTS" << setw(10) << "UAS" 
               << "Nilai Akhir\n";
    fileOutput << "=========================================================================\n";

    for (int i = 0; i < jumlahMhs; i++) {
        fileOutput << left << setw(12) << daftarMhs[i].nim 
                   << setw(18) << daftarMhs[i].nama 
                   << setw(10) << fixed << setprecision(1) << daftarMhs[i].tugas 
                   << setw(10) << daftarMhs[i].uts 
                   << setw(10) << daftarMhs[i].uas 
                   << fixed << setprecision(2) << daftarMhs[i].nilaiAkhir << "\n";
    }
    
    fileOutput << "=========================================================================\n";
    fileOutput << "Rata-rata Nilai Akhir Kelas : " << fixed << setprecision(2) << rataRata << "\n";
    if (indeksTerendah != -1) {
        fileOutput << "Nilai Akhir Terendah        : " << daftarMhs[indeksTerendah].nilaiAkhir 
                   << " (An. " << daftarMhs[indeksTerendah].nama << " - " << daftarMhs[indeksTerendah].nim << ")\n";
    }
    fileOutput << "=========================================================================\n";
    fileOutput.close();

    cout << "-> Laporan analisis telah disimpan di 'hasil_analisis_nilai.txt'\n\n";

    
    int pilihan;
    do {
        cout << "--- MENU NAVIGASI DATA ---\n";
        cout << "1. Cari Mahasiswa berdasarkan NIM\n";
        cout << "2. Tampilkan Mahasiswa dengan Nilai Terendah\n";
        cout << "3. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string targetNIM;
            cout << "Masukkan NIM yang dicari: ";
            cin >> targetNIM;
            
            int idx = cariMahasiswaByNIM(daftarMhs, jumlahMhs, targetNIM);
            if (idx != -1) {
                cout << "\n[Data Ditemukan]\n";
                cout << "Nama        : " << daftarMhs[idx].nama << "\n";
                cout << "Nilai Tugas : " << daftarMhs[idx].tugas << "\n";
                cout << "Nilai UTS   : " << daftarMhs[idx].uts << "\n";
                cout << "Nilai UAS   : " << daftarMhs[idx].uas << "\n";
                cout << "Nilai Akhir : " << daftarMhs[idx].nilaiAkhir << "\n\n";
            } else {
                cout << "\n[Pemberitahuan] Mahasiswa dengan NIM " << targetNIM << " tidak ditemukan.\n\n";
            }
        } 
        else if (pilihan == 2) {
            if (indeksTerendah != -1) {
                cout << "\n[Mahasiswa Nilai Terendah]\n";
                cout << "NIM         : " << daftarMhs[indeksTerendah].nim << "\n";
                cout << "Nama        : " << daftarMhs[indeksTerendah].nama << "\n";
                cout << "Nilai Akhir : " << daftarMhs[indeksTerendah].nilaiAkhir << "\n\n";
            } else {
                cout << "\nBelum ada data mahasiswa.\n\n";
            }
        }
    } while (pilihan != 3);

    cout << "\nProgram selesai. Sampai jumpa!\n";
    return 0;
}

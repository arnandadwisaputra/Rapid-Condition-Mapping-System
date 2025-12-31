#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

// Array data lokasi
string namaLokasi[MAX];
int jumlahKorban[MAX];
int lukaBerat[MAX];
int air[MAX];
int makanan[MAX];
int medis[MAX];
int jalan[MAX];
string statusLokasi[MAX];

// Fungsi input data
void inputData(int& n) {
    cout << "Masukkan jumlah lokasi yang diasesmen: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "\nLokasi ke-" << i + 1 << endl;
        cout << "Nama lokasi: ";
        getline(cin, namaLokasi[i]);

        cout << "Jumlah korban terlihat: ";
        cin >> jumlahKorban[i];

        cout << "Ada luka berat? (1=Ya, 0=Tidak): ";
        cin >> lukaBerat[i];

        cout << "Akses air bersih tersedia? (1=Ya, 0=Tidak): ";
        cin >> air[i];

        cout << "Akses makanan tersedia? (1=Ya, 0=Tidak): ";
        cin >> makanan[i];

        cout << "Akses medis tersedia? (1=Ya, 0=Tidak): ";
        cin >> medis[i];

        cout << "Akses jalan terbuka? (1=Ya, 0=Tidak): ";
        cin >> jalan[i];

        cin.ignore();
    }
}

// Fungsi evaluasi status
void evaluasiStatus(int n) {
    for (int i = 0; i < n; i++) {
        if ((lukaBerat[i] == 1 && medis[i] == 0) ||
            (jumlahKorban[i] > 20 && jalan[i] == 0)) {
            statusLokasi[i] = "MERAH (Darurat Tinggi)";
        }
        else if (air[i] == 0 || makanan[i] == 0) {
            statusLokasi[i] = "KUNING (Butuh Logistik)";
        }
        else {
            statusLokasi[i] = "HIJAU (Terkendali)";
        }
    }
}

// Fungsi output hasil
void tampilkanHasil(int n) {
    cout << "\n=== HASIL PEMETAAN KONDISI LAPANGAN ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nLokasi: " << namaLokasi[i];
        cout << "\nStatus: " << statusLokasi[i] << endl;
    }
}

int main() {
    int jumlahLokasi;

    inputData(jumlahLokasi);
    evaluasiStatus(jumlahLokasi);
    system("cls");
    tampilkanHasil(jumlahLokasi);

    return 0;
}

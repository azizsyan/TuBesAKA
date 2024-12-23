#include <iostream>
#include <string>
#include <chrono> // Untuk mengukur waktu eksekusi

using namespace std;

const int TREES_PER_DAY = 60;

// Fungsi rekursif untuk menanam pohon
void tanamPohonRekursif(int JumSawit, int SawitDitanam) {
    // Base case: Jika sudah mencapai atau melebihi jumlah pohon yang ditanam
    if (SawitDitanam >= JumSawit) {
        cout << "Semua pohon sawit telah ditanam (Rekursif)!" << endl;
        return; // Kembali jika selesai
    }

    // Menanam pohon dan menampilkan progress
    SawitDitanam += TREES_PER_DAY;
    cout << "Pohon sawit yang telah ditanam (Rekursif): " << SawitDitanam << endl;

    // Memanggil fungsi rekursif untuk menanam lebih banyak pohon
    tanamPohonRekursif(JumSawit, SawitDitanam);
}

int main() {
    int hektar, JumSawit, SawitDitanam = 0;

    // Menanyakan input dari pengguna
    cout << "Berapa hektar tanah yang ingin ditanami: ";
    cin >> hektar;

    // Menghitung jumlah pohon yang akan ditanam
    JumSawit = hektar * 150;

    // Menampilkan total pohon yang akan ditanam
    cout << "Total pohon sawit yang akan ditanam: " << JumSawit << endl;

    // Mengukur waktu eksekusi dengan chrono untuk iteratif
    auto startIteratif = chrono::high_resolution_clock::now(); // Mulai mengukur waktu iteratif

    // Pendekatan iteratif untuk menanam pohon
    while (SawitDitanam < JumSawit) {
        SawitDitanam += TREES_PER_DAY;
        cout << "Pohon sawit yang telah ditanam (Iteratif): " << SawitDitanam << endl;
    }

    // Menghitung waktu yang telah berlalu untuk iteratif
    auto endIteratif = chrono::high_resolution_clock::now(); // Waktu akhir iteratif
    chrono::duration<double> durationIteratif = endIteratif - startIteratif; // Durasi waktu eksekusi iteratif
    cout << "Waktu eksekusi (Iteratif): " << durationIteratif.count() << " detik" << endl;

    // Mengukur waktu eksekusi dengan chrono untuk rekursif
    auto startRekursif = chrono::high_resolution_clock::now(); // Mulai mengukur waktu rekursif

    // Pendekatan rekursif untuk menanam pohon
    tanamPohonRekursif(JumSawit, 0); // Mulai rekursif dengan 0 pohon yang telah ditanam

    // Menghitung waktu yang telah berlalu untuk rekursif
    auto endRekursif = chrono::high_resolution_clock::now(); // Waktu akhir rekursif
    chrono::duration<double> durationRekursif = endRekursif - startRekursif; // Durasi waktu eksekusi rekursif
    cout << "Waktu eksekusi (Rekursif): " << durationRekursif.count() << " detik" << endl;

    return 0;
}

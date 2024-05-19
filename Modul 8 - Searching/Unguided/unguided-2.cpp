/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal
bool CheckHuruf(char c) {
    // Konversi karakter ke huruf kecil
    c = tolower(c);
    // Mengecek apakah karakter adalah salah satu huruf vokal
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    string kalimat;
    int jumlahVokal = 0;
    cout << "\n˚₊‧꒰ა PROGRAM MENCARI HURUF VOKAL ໒꒱ ‧₊˚" << endl;
    // Input kalimat
    cout << "✎ INPUT SEBUAH KATA / KALIMAT : ";
    getline(cin, kalimat);

    // Menampilkan indeks dan huruf vokal yang ditemukan
    cout << "⊹ • INDEKS HURUF VOKAL : ";
    for (int i = 0; i < kalimat.length(); ++i) {
        if (CheckHuruf(kalimat[i])) {
            jumlahVokal++;
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "⊹ • HURUF YANG DITEMUKAN : ";
    for (int i = 0; i < kalimat.length(); ++i) {
        if (CheckHuruf(kalimat[i])) {
            cout << kalimat[i] << " ";
        }
    }
    cout << endl;

    // Menampilkan hasil perhitungan
    cout << "⊹ • JUMLAH HURUF VOKAL : " << jumlahVokal << endl;

    return 0;
}

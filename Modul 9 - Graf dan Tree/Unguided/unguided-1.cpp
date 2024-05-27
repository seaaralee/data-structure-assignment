/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <iomanip>

using namespace std;

// max jumlah kota
const int max_182_ara = 100;

// MENAMPILKAN GRAF
void showGraf(const string node[], const int jarak[][max_182_ara], int jumlahKota) {

    // CETAK BARIS HEADER
    cout << setw(10) << " ";
    for (int i = 0; i < jumlahKota; ++i) {
        cout << setw(10) << node[i];
    }
    cout << endl;

    // CETAK ISI BARIS
    // cetak nama kota
    for (int i = 0; i < jumlahKota; ++i) {
        cout << setw(10) << node[i];
        // cetak jarak
        for (int j = 0; j < jumlahKota; ++j) {
            cout << setw(10) << jarak[i][j];
        }
        cout << endl;
    }
}

// MAIN PROGRAM
int main() {

    int jumlahKota;
    cout << "\n˚₊‧꒰ა PROGRAM JARAK SUATU KOTA ໒꒱ ‧₊˚" << endl;
    cout << "✎ INPUT JUMLAH KOTA : ";
    cin >> jumlahKota;
    cin.ignore();

    // cek jumlah kota
    if (jumlahKota > max_182_ara) {
        cout << "⊹ • MELEBIHI JUMLAH MAX ( " << max_182_ara << " ) ⊹ •" << endl;
        return 1;
    }

    // input nama kota
    string node[max_182_ara];
    for (int i = 0; i < jumlahKota; i++) {
        cout << "↳ INPUT NAMA KOTA " << i + 1 << ": ";
        getline(cin, node[i]);
    }

    // matriks simpan jarak
    int jarak[max_182_ara][max_182_ara] = {0};
    for (int i = 0; i < jumlahKota; i++) {
        for (int j = 0; j < jumlahKota; j++) {
            if (i != j) {
                cout << "↳ INPUT JARAK DARI " << node[i] << " → " << node[j] << " : ";
                cin >> jarak[i][j];
            }
        }
    }

    // tampilkan hasil tabel
    cout << "\n˚₊‧꒰ TABEL GRAF JARAK SUATU KOTA ꒱ ‧₊˚" << endl;
    showGraf(node, jarak, jumlahKota);

    return 0;
}

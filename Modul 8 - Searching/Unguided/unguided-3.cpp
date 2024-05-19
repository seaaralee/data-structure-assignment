/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>

using namespace std;

int main() {
    // Inisialisasi variable dan tipedata
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int dataSize = sizeof(data) / sizeof(data[0]);
    int target = 4;
    int jumlahKemunculan = 0;

    cout << "\n˚₊‧꒰ა PROGRAM MENCARI KEMUNCULAN ANGKA ໒꒱ ‧₊˚" << endl;
    // Searching kemunculan angka 4
    cout << "ʚ DATA : [ ";
    for (int i = 0; i < dataSize; ++i) {
        cout << data[i] << ", ";
    }
    cout << "] ɞ";
    cout << endl;

    // Menampilkan indeks kemunculan angka 4
    cout << "⊹ • INDEKS ANGKA " << target << " DALAM DATA : ";
    for (int i = 0; i < dataSize; ++i) {
        if (data[i] == target) {
            cout << i << " ";
            jumlahKemunculan++;
        }
    }
    cout << endl;

    // Menampilkan jumlah kemunculan 
    cout << "⊹ • JUMLAH KEMUNCULAN ANGKA " << target << " DALAM DATA : " << jumlahKemunculan << endl;

    return 0;
}

/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengurutkan string secara manual (selection sort)
void selectionSort(string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(str[i], str[minIndex]);
        }
    }
}

// Binary Search untuk menemukan semua kemunculan
void binarySearch(const string& str, char target) {
    bool found = false;
    cout << "⊹ • INDEKS KEMUNCULAN HURUF '" << target << "' : ";
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == target) {
            cout << i << ", ";
            found = true;
        }
    }
    if (!found) {
        cout << "⊹ • TIDAK DITEMUKAN !";
    }
    cout << endl;
}

int main() {
    string kalimat;
    char huruf;

    cout << "\n˚₊‧꒰ა PROGRAM MENCARI HURUF DENGAN BINARY SEARCH ໒꒱ ‧₊˚" << endl;
    // Input kalimat
    cout << "✎ INPUT SEBUAH KATA / KALIMAT : ";
    getline(cin, kalimat);

    // Input huruf yang ingin dicari
    cout << "✎ MASUKAN HURUF YANG DICARI : ";
    cin >> huruf;

    // Mengurutkan kalimat secara manual dengan selection sort
    selectionSort(kalimat);

    // Menampilkan kalimat yang sudah diurutkan
    cout << "↳ KATA / KALIMAT YANG DIURUTKAN : " << kalimat << endl;

    // Mencari semua kemunculan huruf menggunakan binary search
    binarySearch(kalimat, huruf);

    return 0;
}

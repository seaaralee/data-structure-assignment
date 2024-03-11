// Program Menggunakan Tipe Data Primitif

#include <iostream>
using namespace std;

// Inisialisasi Tipe Data dan Variable
int s;

// Fungsi Keliling
int hitung_keliling(int s)
{
    return 4 * s;
}

// Fungsi Luas
int hitung_luas(int s)
{
    return s * s;
}

// Main Program
int main()
{
    // Input Output
    cout << "Masukan Panjang Sisi : ";
    cin >> s;

    // Panggil Fungsi Keliling dan Luas
    cout << "Keliling : " << hitung_keliling(s) << endl;
    cout << "Luas : " << hitung_luas(s) << endl;

    return 0;
}
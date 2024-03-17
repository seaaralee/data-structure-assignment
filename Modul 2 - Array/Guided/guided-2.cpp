#include <iostream>
using namespace std;

// Main Program
int main()
{
    int maks, a, i = 1, lokasi;

    // Input Panjang Data Array
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";

    // Perulangan Input Data Array
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }

    // Inisialisasi Variable Maksimum
    maks = array[0];

    // Perulangan mencari nilai maks dan lokasinya
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }

    // Output Nilai Maksimum Array dan Lokasinya
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
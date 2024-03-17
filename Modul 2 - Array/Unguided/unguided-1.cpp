#include <iostream>

using namespace std;

// Main Program
int main()
{
    int n;
    // Input Jumlah Elemen Data Array
    cout << "Masukkan jumlah elemen array : ";
    cin >> n;

    int array[n];
    int arrayGenap[n], arrayGanjil[n];
    // Inisialisasi awal indeks array ganjil dan genap
    int genap = 0, ganjil = 0;

    // Input Elemen Data Array
    cout << "Masukkan elemen array! " << endl;
    for (int i = 0; i < n; i++)
    {
        // Input Data Array
        cout << "Masukkan Data ke-" << i + 1 << " : ";
        cin >> array[i];
        // Mengecek Data Array
        if (array[i] % 2 == 0)
        {
            // Jika genap, simpan di arrayGenap dan increment indeksnya
            arrayGenap[genap++] = array[i];
        }
        else
        {
            // Jika ganjil, simpan di arrayGanjil dan increment indeksnya
            arrayGanjil[ganjil++] = array[i];
        }
    }

    cout << "--------------------" << endl;
    // Menampilkan data array yang dimasukan
    cout << "Data Array : ";
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << ", ";
    }
    cout << endl;

    // Menampilkan bilangan genap dengan array genap
    cout << "Bilangan Genap : ";
    for (int i = 0; i < genap; ++i)
    {
        cout << arrayGenap[i] << ", ";
    }
    cout << endl;

    // Menampilkan bilangan genap dengan array ganjil
    cout << "Bilangan Ganjil : ";
    for (int i = 0; i < ganjil; ++i)
    {
        cout << arrayGanjil[i] << ", ";
    }
    cout << endl;

    return 0;
}

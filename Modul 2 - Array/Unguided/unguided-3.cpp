#include <iostream>
#include <iomanip>
using namespace std;

// Fungsi mencari nilai maksimum
int findMax(const int arr[], int size, int &lokasiMax)
{
    int maxVal = arr[0];
    lokasiMax = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
            lokasiMax = i;
        }
    }
    return maxVal;
}

// Fungsi mencari nilai minimum
int findMin(const int arr[], int size, int &lokasiMin)
{
    int minVal = arr[0];
    lokasiMin = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
            lokasiMin = i;
        }
    }
    return minVal;
}

// Fungsi mencari nilai rata-rata
int findSum(const int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum / size;
}

// Main Program
int main()
{
    int a;
    // Meminta Pengguna Input Data Array
    cout << "Masukkan panjang array : ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka!\n";
    for (int i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << " : ";
        cin >> array[i];
    }

    // Pilihan Menu
    int pilihan;
    cout << "\n-- Pilih Menu --\n";
    cout << "1. Nilai Maksimum\n";
    cout << "2. Nilai Minimum\n";
    cout << "3. Nilai Rata-rata\n";
    cout << "Pilih Operasi : ";
    cin >> pilihan;

    switch (pilihan)
    {

    // Pilihan Nilai Maksimum
    case 1:
    {
        int maksimum, lokasiMax;
        maksimum = findMax(array, a, lokasiMax);
        cout << "Nilai maksimum adalah " << maksimum << " berada di Array ke-" << lokasiMax << endl;
        break;
    }
    
    // Pilihan Nilai Minimum
    case 2:
    {
        int minimum, lokasiMin;
        minimum = findMin(array, a, lokasiMin);
        cout << "Nilai minimum adalah " << minimum << " berada di Array ke-" << lokasiMin << endl;
        break;
    }

    // Pilihan Nilai Rata Rata
    case 3:
    {
        double rata_rata = findSum(array, a);
        cout << "Nilai rata-rata adalah " << fixed << setprecision(2) << rata_rata << endl;
        break;
    }

    // Pilihan Menu Tidak Valid
    default:
        cout << "Tidak ada pilihan Menu " << pilihan << "!";
    }

    return 0;
}

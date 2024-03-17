# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

Array merupakan struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang serupa, tersusun secara berurutan dalam memori komputer. Semua elemen dalam array memiliki tipe yang sama, menjadikannya cocok untuk mengorganisir data homogen dengan ukuran atau jumlah elemen yang telah ditentukan sebelumnya. Array dapat dibagi menjadi beberapa jenis:

Array Satu Dimensi:
Merupakan kumpulan elemen identik yang tersusun dalam satu baris, namun isi dari elemen tersebut dapat bervariasi. Setiap elemen memiliki indeks yang digunakan untuk mengaksesnya, dimulai dari 0 hingga jumlah elemen dikurangi satu.

Array Dua Dimensi:
Terdiri dari kumpulan array satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom. Setiap elemen memiliki dua indeks, yaitu indeks baris dan indeks kolom, menunjukkan posisinya dalam matriks. Pendeklarasiannya hampir sama dengan array satu dimensi, hanya dengan tambahan dua jumlah elemen array.

Array Multidimensi:
Mirip dengan array satu dan dua dimensi namun dengan kapasitas memori yang lebih besar. Digunakan untuk merepresentasikan array dengan dimensi lebih dari dua, seperti array tiga dimensi, empat dimensi, lima dimensi, dan seterusnya. Meskipun jarang digunakan, prinsipnya sama dengan array sebelumnya hanya dengan jumlah dimensi yang lebih banyak.

## Guided

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z <<

                    "] = ";

                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z <<

                    "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/fa85284c-250f-4518-b667-d0f948bb3892)

Penjelasan Program : Program ini adalah sebuah program yang meminta pengguna untuk memasukkan nilai ke dalam sebuah array tiga dimensi dengan ukuran 2x3x3. Setelah nilai-nilai dimasukkan, program akan menampilkan kembali nilai-nilai tersebut sesuai dengan indeksnya dalam array. Program ini juga mencetak tampilan array secara berurutan dalam tiga dimensi untuk memberikan visualisasi lengkap dari struktur array yang telah diisi.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
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
    cout << "Nilai maksimum adalah " << maks << " berada di Array
        ke " << lokasi << endl;
}
```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/9e34edfb-7e6d-4ff9-b678-a6c46f761357)

Penjelasan Program : Program ini merupakan program untuk mencari nilai maksimum dalam sebuah array yang diisi oleh pengguna. Pertama, program meminta pengguna untuk memasukkan panjang array dan nilai-nilai array tersebut. Kemudian, program melakukan perulangan untuk mencari nilai maksimumnya dan juga menentukan lokasinya dalam array. Setelah nilai maksimum ditemukan, program mencetak nilai maksimum beserta lokasinya dalam array

## Unguided

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
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

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/66c7b4c0-057a-4dce-b19c-fe08df280d9e)

Penjelasan Program : Program ini merupakan program yang meminta pengguna untuk memasukkan sejumlah elemen dalam sebuah array. Setelah pengguna memasukkan elemen-elemen tersebut, program akan memisahkan bilangan genap dan ganjil ke dalam dua array terpisah, yaitu arrayGenap dan arrayGanjil. Selanjutnya, program akan menampilkan kembali elemen-elemen array yang dimasukkan oleh pengguna, serta menampilkan bilangan genap dan ganjil yang terpisah dalam array masing-masing

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

// Main Program
int main()
{
    int x, y, z;

    // Meminta User Menginputkan Jumlah Elemen Array
    cout << "Masukkan jumlah elemen array untuk dimensi pertama : ";
    cin >> x;
    cout << "Masukkan jumlah elemen array untuk dimensi kedua : ";
    cin >> y;
    cout << "Masukkan jumlah elemen array untuk dimensi ketiga : ";
    cin >> z;

    // Deklarasi Array dari Inputan User
    int arr[x][y][z];

    // Input elemen array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Input Array [ " << i << " ][ " << j << " ][ " << k << " ] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }


    // Output elemen array
    cout << "Data Array :" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Array [ " << i << " ][ " << j << " ][ " << k << " ] = " << arr[i][j][k] << endl;
            }
        }
        cout << endl;
    }

    // Output Array Terbuat
    cout << "Array " << x << " x " << y << " x " << z << " telah dibuat!" << endl;


    // Tampilan array
    cout << "-- Tampilan Array --" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "Array Dimensi ke-" << i + 1 << " :" << endl;
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/5e5aaa3c-fcee-467e-bdfb-a7fc663919cd)

Penjelasan Program : Program ini merupakan program yang meminta pengguna untuk membuat array tiga dimensi dengan ukuran yang ditentukan oleh pengguna. Pertama, pengguna diminta untuk memasukkan jumlah elemen untuk masing-masing dimensi array. Setelah itu, program akan membuat array dengan ukuran yang sesuai dengan input pengguna. Pengguna kemudian diminta untuk memasukkan nilai-nilai elemen array tersebut. Setelah nilai-nilai dimasukkan, program akan menampilkan kembali nilai-nilai array sesuai dengan indeksnya dalam array. Terakhir, program akan menampilkan tampilan lengkap array tiga dimensi yang telah dibuat.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
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

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/8604f000-cf4b-44d4-84a8-d04ddf4ce316)
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/6646674d-bb0b-4b6b-9bf0-2d3e2ba11bec)
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/1fabfddb-208a-4e06-83c4-1bbd92a42adb)

Penjelasan Program : Program ini adalah program yang dapat melakukan beberapa operasi pada array yang telah dimasukkan. Setelah pengguna memasukkan sejumlah angka ke dalam array, program menawarkan pilihan menu untuk menemukan nilai maksimum, nilai minimum, atau nilai rata-rata dari angka-angka tersebut. Program menggunakan fungsi-fungsi terpisah untuk mencari nilai maksimum, nilai minimum, dan nilai rata-rata dari array yang dimasukkan. Hasil operasi dipresentasikan sesuai dengan pilihan pengguna. Jika pengguna memilih pilihan menu yang tidak valid, program akan memberikan pesan kesalahan.

## Kesimpulan

Array merupakan struktur penyimpanan data yang terdiri dari elemen-elemen dengan tipe data yang sama, diatur secara berurutan di dalam memori komputer. Terdapat beberapa jenis array, seperti array satu dimensi, array dua dimensi, dan array multidimensi. Array satu dimensi berisi elemen-elemen yang disusun dalam satu baris, dengan setiap elemen memiliki indeks yang dimulai dari 0. Array dua dimensi terdiri dari kumpulan array satu dimensi yang disusun dalam baris dan kolom, di mana setiap elemen memiliki dua indeks untuk menunjukkan posisinya dalam matriks. Sementara itu, array multidimensi digunakan untuk mewakili array dengan lebih dari dua dimensi, meskipun jarang digunakan, namun prinsipnya sama dengan array sebelumnya dengan jumlah dimensi yang lebih banyak.

## Referensi

[1] Pratama, Muhammad A. 2020. “STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.” OSF Preprints. March 29. doi:10.31219/osf.io/vyech.

[2] Anita Sindar. 2018. "STRUKTUR DATA DAN ALGORITMA DENGAN C++". Serang, Banten : CV. AA. RIZKY.


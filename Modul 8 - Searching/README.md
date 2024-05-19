# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/7d07e8d1-106a-4f74-aed2-a453ee64e723)

Pencarian (Searching) yaitu proses menemukan suatu nilai tertentu pada kumpulan
data. Hasil pencarian adalah salah satu dari tiga keadaan ini: data ditemukan, data
ditemukan lebih dari satu, atau data tidak ditemukan. Searching juga dapat dianggap
sebagai proses pencarian suatu data di dalam sebuah array dengan cara mengecek satu
persatu pada setiap index baris atau setiap index kolomnya dengan menggunakan teknik
perulangan untuk melakukan pencarian data. Terdapat 2 metode pada algoritma
Searching, yaitu: [2]

#### 1. Pencarian Berurutan (Sequential Search)
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/82351025-bdc9-4f47-810b-9af0bee8a158)

Pencarian berurutan sering disebut pencarian linear merupakan metode pencarian yang paling sederhana. Pencarian berurutan menggunakan prinsip sebagai berikut : data yang ada dibandingkan satu per satu secara berurutan dengan yang dicari sampai data tersebut ditemukan atau tidak ditemukan.

Pada dasarnya, pencarian ini hanya melakukan pengulangan dari 1 sampai dengan jumlah data. Pada setiap pengulangan, dibandingkan data ke-i dengan yang dicari. Apabila sama, berarti data telah ditemukan. Sebaliknya apabila sampai akhir pengulangan tidak ada data yang sama, berarti data tidak ada. Pada kasus yang paling buruk, untuk N elemen data harus dilakukan pencarian sebanyak N kali pula. [1]

Konsep Sequential Search :

● Membandingkan setiap elemen pada array satu per satu secara berurut.

● Proses pencarian dimulai dari indeks pertama hingga indeks terakhir.

● Proses pencarian akan berhenti apabila data ditemukan. Jika hingga akhir array data masih juga tidak ditemukan, maka proses pencarian tetap akan dihentikan.

● Proses perulangan pada pencarian akan terjadi sebanyak jumlah N elemen pada array. [2]

#### 2. Pencarian Biner (Binary Search)
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/41bbe4b2-9844-4013-8c5d-3b671bf36be7)

Salah satu syarat agar pencarian biner dapat dilakukan adalah data sudah dalam keadaan urut. Dengan kata lain, apabila data belum dalam keadaan urut, pencarian biner tidak dapat dilakukan. Dalam kehidupan sehari-hari, sebenarnya kita juga sering menggunakan pencarian biner. Misalnya saat ingin mencari suatu kata dalam kamus

Prinsip dari pencarian biner dapat dijelaskan sebagai berikut : mula-mula diambil posisi awal 0 dan posisi akhir = N - 1, kemudian dicari posisi data tengah dengan rumus (posisi awal + posisi akhir) / 2. Kemudian data yang dicari dibandingkan dengan data tengah. Jika lebih kecil, proses dilakukan kembali tetapi posisi akhir dianggap sama dengan posisi tengah –1. Jika lebih besar, porses dilakukan kembali tetapi posisi awal dianggap sama dengan posisi tengah + 1. Demikian seterusnya sampai data tengah sama dengan yang dicari. [1]

Konsep Binary Search : 

● Data diambil dari posisi 1 sampai posisi akhir N.

● Kemudian data akan dibagi menjadi dua untuk mendapatkan posisi data tengah.

● Selanjutnya data yang dicari akan dibandingkan dengan data yang berada di posisi tengah, apakah lebih besar atau lebih kecil.

● Apabila data yang dicari lebih besar dari data tengah, maka dapat dipastikan bahwa data yang dicari kemungkinan berada di sebelah kanan dari data tengah. Proses pencarian selanjutnya akan dilakukan pembagian data menjadi dua bagian pada bagian kanan dengan acuan posisi data tengah akan menjadi posisi awal untuk pembagian tersebut.

● Apabila data yang dicari lebih kecil dari data tengah, maka dapat dipastikan bahwa data yang dicari kemungkinan berada di sebelah kiri dari data tengah. Proses pencarian selanjutnya akan dilakukan pembagian data menjadi dua bagian pada bagian kiri. Dengan acuan posisi data tengah akan menjadi posisi akhir untuk pembagian selanjutnya.

● Apabila data belum ditemukan, maka pencarian akan dilanjutkan dengan kembali membagi data menjadi dua.

● Namun apabila data bernilai sama, maka data yang dicari langsung ditemukan dan pencarian dihentikan.

## Guided

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>
using namespace std;
int main()
{
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;
    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }
    cout << "Program Sequential Search Sederhana " << endl;
    cout << "Data : {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    if (ketemu)
    {
        cout << "Angka " << cari << " ditemukan pada indeks ke -" << i << endl;
    }
    else
    {
        cout << cari << " Tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/8ab8d639-ed3c-4d12-a63c-906d3ab4b1e4)

Penjelasan Program :
Program ini adalah contoh sederhana dari Sequential Search. Dimulai dengan array data yang berisi beberapa angka. Program kemudian mencari angka tertentu di dalam array tersebut, dalam hal ini angka 10. Proses pencarian dilakukan dengan cara membandingkan setiap elemen array satu per satu dengan angka yang dicari. Jika angka yang dicari ditemukan, program akan menghentikan pencarian dan memberi tahu pengguna bahwa angka tersebut ditemukan beserta indeksnya dalam array. Jika tidak ditemukan, program akan memberi tahu pengguna bahwa angka tersebut tidak ditemukan dalam data.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++
#include <iostream>
#include <iomanip>
using namespace std;
// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort(int arr[], int n)
{
    int temp, min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void binary_search(int arr[], int n, int target)
{
    int awal = 0, akhir = n - 1, tengah, b_flag = 0;
    while (b_flag == 0 && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target)
        {
            b_flag = 1;
            break;
        }
        else if (arr[tengah] < target)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag == 1)
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\nData tidak ditemukan\n";
}
int main()
{
    cout << "BINARY SEARCH" << endl;
    cout << "\nData awal : ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari : ";
    cin >> cari;
    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan : ";
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;
    // Lakukan binary search
    binary_search(arrayData, 7, cari);
    return 0;
}
```
 
#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/9f3439bd-120d-4841-b902-79fd070cb063)

Penjelasan Program :
Program di atas merupakan contoh implementasi algoritma pencarian Binary Search. Pada program ini, terdapat sebuah array yang berisi data yang belum terurut. Program akan meminta pengguna untuk memasukkan angka yang ingin dicari. Setelah itu, program akan mengurutkan data menggunakan algoritma Selection Sort agar data tersusun secara terurut. Setelah data diurutkan, proses pencarian menggunakan algoritma Binary Search akan dilakukan. Algoritma ini membagi rentang pencarian menjadi dua bagian dan memeriksa elemen tengah. Jika elemen tengah sama dengan angka yang dicari, program akan memberitahu pengguna di mana posisi angka tersebut dalam array. Jika tidak, program akan terus membagi rentang pencarian hingga menemukan angka yang dicari atau menentukan bahwa angka tersebut tidak ada dalam array. Hasil pencarian akan ditampilkan kepada pengguna.

## Unguided

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
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

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/2a7afe4c-fcd5-4258-9b93-d03d6857a1ec)

Penjelasan Program :
Program di atas adalah sebuah program sederhana yang menggunakan algoritma Binary Search untuk mencari semua kemunculan dari sebuah huruf dalam sebuah kata atau kalimat yang dimasukkan oleh pengguna. Pertama, pengguna diminta untuk memasukkan sebuah kata atau kalimat, serta huruf yang ingin dicari di dalamnya. Kemudian, program akan mengurutkan huruf-huruf dalam kata atau kalimat tersebut secara alfabetis menggunakan algoritma Selection Sort. Setelah itu, program akan menggunakan algoritma Binary Search untuk mencari semua kemunculan dari huruf yang dicari dalam kata atau kalimat yang sudah diurutkan tadi. Hasil pencarian akan ditampilkan kepada pengguna, termasuk indeks-indeks di mana huruf tersebut muncul dalam kata atau kalimat tersebut. Jika huruf yang dicari tidak ditemukan, program akan memberitahu pengguna bahwa huruf tersebut tidak ditemukan dalam kata atau kalimat yang dimasukkan.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
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

```
 
#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/4b601aab-37cd-42cf-bf56-2b7c38351ecd)

Penjelasan Program :
Program di atas adalah sebuah program sederhana yang bertujuan untuk mencari huruf vokal dalam sebuah kata atau kalimat yang dimasukkan oleh pengguna. Pertama, pengguna diminta untuk memasukkan sebuah kata atau kalimat. Kemudian, program akan mengecek setiap karakter dalam kata atau kalimat tersebut apakah merupakan huruf vokal atau bukan, dengan menggunakan fungsi CheckHuruf. Setiap kali program menemukan huruf vokal, program akan mencatat indeksnya dan menampilkan huruf vokal tersebut. Selain itu, program juga akan menghitung jumlah huruf vokal yang ditemukan. Hasil pencarian dan jumlah huruf vokal kemudian ditampilkan kepada pengguna.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
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

```
 
#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/53ea9624-6242-4f2d-be6d-6d67737859a1)

Penjelasan Program :
Program di atas adalah sebuah program sederhana yang bertujuan untuk mencari kemunculan suatu angka dalam sebuah array data. Array data tersebut sudah diinisialisasi dengan beberapa angka. Angka yang ingin dicari kemunculannya sudah ditentukan terlebih dahulu. Program akan mencari kemunculan angka tersebut dalam array data dan menampilkan indeks-indeks di mana angka tersebut muncul. Selain itu, program juga akan menghitung jumlah kemunculan angka tersebut dalam array data. Hasil pencarian dan jumlah kemunculan angka kemudian ditampilkan kepada pengguna.

## Kesimpulan

Sequential Search adalah metode pencarian yang sederhana, di mana data dibandingkan satu per satu secara berurutan dengan data yang dicari sampai data tersebut ditemukan atau tidak ditemukan. Metode ini melibatkan pengulangan dari 1 sampai dengan jumlah data, dengan setiap iterasi membandingkan data ke-i dengan data yang dicari. Pencarian berurutan memerlukan waktu yang linier tergantung pada jumlah data, di mana pada kasus terburuk, pencarian harus dilakukan sebanyak jumlah elemen data.

Binary Search adalah metode pencarian yang memerlukan data untuk diurutkan terlebih dahulu. Metode ini bekerja dengan membagi data menjadi dua bagian secara terus-menerus dan memeriksa apakah data yang dicari berada di bagian kiri atau kanan dari titik tengah. Proses ini terus berlanjut dengan mengurangi setengah dari rentang pencarian pada setiap iterasi. Pencarian biner lebih efisien daripada pencarian berurutan karena waktu yang dibutuhkan berbanding logaritmik dengan jumlah data.

Dengan demikian, pemilihan metode pencarian tergantung pada sifat data yang akan dicari dan kebutuhan kinerja. Jika data tidak diurutkan atau hanya sedikit data yang akan dicari, pencarian berurutan mungkin menjadi pilihan yang lebih sederhana. Namun, jika data sudah diurutkan dan jumlah data cukup besar, pencarian biner akan menjadi lebih efisien.

## Referensi

#### [1] Pencarian (Searching) (2016) yuliana.lecturer.pens.ac.id, 2016.
#### [2] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.
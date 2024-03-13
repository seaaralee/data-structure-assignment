# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

Tipe data adalah suatu memori atau media pada komputer yang digunakan untuk menampung informasi atau data sementara. Tipe data berfungsi untuk mempresentasikan jenis dari sebuah nilai yang terdapat dalam program. Berikut ini merupakan macam-macam tipe data serta penjelasannya yang terdapat pada C++:

1. Tipe Data Primitif
Tipe data primitif adalah tipe data yang sudah ditentukan oleh sistem dan disediakan oleh banyak bahasa pemrograman. Tipe data ini terdiri dari nilai yang paling banyak bentuk dasar dan tidak dapat diuraikan menjadi bagian bagian yang lebih kecil. Contoh tipe data primitif:

- Int (Bilangan bulat)
- Float (Bilangan desimal)
- Char (Huruf)
- Boolean (True/False)

2. Tipe Data Abstrak
Tipe data abstrak atau yang biasa disebut Abstrak Data Type merupakan tipe data yang dibentuk oleh programmer itu sendiri. Tipe data abstrak adalah tipe untuk objek yang perilakunya
ditentukan oleh satu set nilai dan satu set operasi. Pada tipe data abstrak bisa berisi banyak tipe data, jadi nilainya bisa lebih dari satu dan beragam tipe data

3. Tipe Data Koleksi
Tipe data koleksi (Collection Data Type) adalah tipe data yang digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Tipe data koleksi memungkinkan Anda menyimpan, mengelola, dan mengakses sejumlah besar data dengan cara yang terstruktur. 

## Guided

### 1. Tipe Data Primitif

```C++

#include <iostream>
using namespace std;
// Main program
int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}
```
#### Output :
![guided1](https://github.com/seaaralee/data-structure-assignment/assets/87632337/2d04c6f5-2c61-439a-b9b2-d42a20b3d152)

Penjelasan Program : Program di atas adalah sebuah kalkulator sederhana yang meminta pengguna memasukkan operator (+, -, *, /) diikuti oleh dua bilangan. Selanjutnya, program menggunakan sebuah switch statement untuk melakukan operasi aritmatika sesuai dengan operator yang dimasukkan. Hasil operasi kemudian dicetak, dan jika operator yang dimasukkan tidak valid, program akan memberikan pesan kesalahan. Setelah mencetak hasilnya, program berakhir.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>
#include <iostream>
using namespace std;
// Struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};
int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
#### Output :
![guided2](https://github.com/seaaralee/data-structure-assignment/assets/87632337/e285354b-ed1a-40e3-a69f-71b23bb02ca5)

Penjelasan Program : Program di atas menggunakan struct untuk merepresentasikan informasi mahasiswa. Dua variabel bertipe struct Mahasiswa, mhs1 dan mhs2, digunakan untuk menyimpan informasi dua mahasiswa. Setiap variabel diisi dengan nama, alamat, dan umur mahasiswa. Kemudian, informasi dari kedua variabel tersebut dicetak menggunakan printf dengan format yang telah ditentukan.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    // mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
#### Output :
![guided3](https://github.com/seaaralee/data-structure-assignment/assets/87632337/e106df22-be52-45d4-b702-41822b65458a)

Penjelasan Program : Program di atas adalah sebuah contoh penggunaan array dalam C++. Pada program ini, sebuah array bernama "nilai" dengan ukuran 5 elemen. Kemudian, setiap elemen dari array tersebut dicetak satu per satu. Hasilnya adalah mencetak isi masing-masing elemen array "nilai".

## Unguided

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
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
```
#### Output :
![un1](https://github.com/seaaralee/data-structure-assignment/assets/87632337/8f9838b7-dc8a-40d5-9ed1-a7cc31c81749)

Penjelasan Program : Program di atas adalah sebuah contoh penggunaan tipe data primitif. Di dalam fungsi main(), pengguna diminta untuk memasukkan panjang sisi persegi melalui input, dan kemudian hasil keliling dan luasnya dicetak. Program ini menggunakan tipe data primitif, karena bilangan bulat termasuk dalam tipe data yang sudah ditentukan oleh sistem atau bahasa pemrograman itu sendiri. 

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

```C++
#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan informasi
struct StudentInfo {
    string name;
    int age;
};

// Class untuk merepresentasikan informasi
class Student {
public:
    StudentInfo studentInfo; // Objek dari struct StudentInfo

    // Inisialisasi objek
    Student(string n, int a) {
        studentInfo.name = n;
        studentInfo.age = a;
    }

    // Method untuk menampilkan informasi
    void displayInfo() {
        cout << "-- Data Added! --" << endl;
        cout << "Student Name : " << studentInfo.name << endl;
        cout << "Age : " << studentInfo.age << endl;
    }
};

// Main Program
int main() {
    string name;
    int age;

    // Input dari pengguna untuk informasi
    cout << "-- Add Student Member --" << endl;
    cout << "Enter student name : ";
    getline(cin, name);
    cout << "Enter student age : ";
    cin >> age;

    // Membuat instance dari class Student dengan nama student1
    Student student1(name, age);

    // Menampilkan informasi menggunakan method displayInfo
    student1.displayInfo();

    return 0;
}

```
#### Output :
![un2](https://github.com/seaaralee/data-structure-assignment/assets/87632337/3602fda7-5a27-48f7-8218-97085a262ee1)

Penjelasan Program : Program di atas merupakan contoh sederhana penggunaan class dan struct. Program meminta pengguna untuk memasukkan nama dan usia mahasiswa, kemudian membuat objek mahasiswa menggunakan data yang dimasukkan. Informasi mahasiswa tersebut kemudian ditampilkan ke layar. Program ini memberikan gambaran tentang bagaimana class dan struct digunakan untuk mengatur dan merepresentasikan data dalam program.

Struct digunakan untuk mengelompokkan beberapa tipe data yang berbeda menjadi satu yang berguna untuk merepresentasikan objek atau konsep dalam program dan memudahkan dalam mengorganisasi data, sementara class memberikan lebih banyak fitur seperti encapsulation, inheritance, dan polymorphism. Dengan class, kita dapat menggabungkan data dan fungsi yang beroperasi pada data tersebut ke dalam satu kesatuan yang disebut objek.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

// Main Program
int main() {
    // Map dengan memuat tipe data string dan int
    map<string, int> studentAge;

    // Menambahkan data ke dalam map
    studentAge["Ara"] = 19;
    studentAge["Bintang"] = 22;
    studentAge["Choco"] = 20;

    // Input data yang akan dicari
    string nameToSearch;
    cout << "Enter student name to search: ";
    getline(cin, nameToSearch);

    // Mengakses data dari data yang dicari
    if (studentAge.find(nameToSearch) != studentAge.end()) {
        cout << "Student Name : " << nameToSearch << endl;
        cout << "Age : " << studentAge[nameToSearch] << endl;
    } else {
        cout << "Student with name " << nameToSearch << " not found." << endl;
    }

    return 0;
}

```
#### Output :
![un3](https://github.com/seaaralee/data-structure-assignment/assets/87632337/259b74c9-0392-4222-ab68-2b043c2744e3)

Penjelasan Program : Program di atas adalah contoh penggunaan map. Dalam program ini, map digunakan untuk memetakan nama dan usia siswa. Pengguna diminta untuk memasukkan nama siswa yang ingin dicari, dan program mencari nama tersebut dalam data map. Jika nama tersebut ditemukan, program mencetak nama dan usia siswa yang sesuai. Jika tidak ditemukan, program mencetak pesan bahwa nama siswa tidak ditemukan.

Perbedaan array dan map terdapat pada penggunaan indeks, ukuran memori, ukuran dinamis dan kompleksitas. Setiap elemen dalam array diakses menggunakan indeks numerik, array memiliki ukuran yang tetap dan menghabiskan jumlah memori karena jumlah elemen yang sudah ditentukan di awal. Sedangkan map menyimpan dan mengakses data menggunakan kunci (key), map dapat berupa tipe data yang berbeda, map memiliki ukuran yang dinamis, sehingga hanya menggunakan memori sesuai dengan jumlah elemen yang sebenarnya disimpan di dalamnya. Selain itu, operasi pencarian dalam map cenderung lebih cepat daripada dalam array, terutama untuk jumlah data yang besar

## Kesimpulan

Tipe data merupakan memori atau media pada komputer yang digunakan untuk menampung informasi atau data sementara. Tipe data berfungsi untuk mempresentasikan jenis dari sebuah nilai yang terdapat dalam program. Ada tiga jenis tipe data yang umum digunakan dalam bahasa pemrograman C++, yaitu Tipe data primitif, abstrak dan koleksi. Dari tipe data yang sudah diketahui kita dapat memilih tipe data yang sesuai untuk memenuhi kebutuhan aplikasi yang sedang dibangun dan mengoptimalkan kinerja program agar lebih efektif.

## Referensi

#### [1] Meidyan Permata Putri, et al., Algoritma dan Struktur Data. Bandung: Widina Bhakti Persada Bandung, 2022.
#### [2] Zein Afrizal & Eriana Emi Sita, Algoritma dan Struktur Data. Tangerang Selatan: Unpam Press, 2022.



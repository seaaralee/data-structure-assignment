# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan LinkedList). Dalam tumpukan, urutan kedatangan data adalah penting. [3] Stack adalah kumpulan elemen yang hanya dapat ditambah dan atau dihapus dari satu ujung (gerbang) yang sama, seolah-olah bertumpuk. Stack mempunyai sifat LIFO (Last In First Out) yang berarti elemen terakhir masuk akan pertama keluar yang direpresentasikan menggunakan Linked List dan array yang disajikan Single Stack atau Double Stack (Suyanto, 2021). [1]

### Operasi Pada Stack [2]
• Push : digunakan untuk menambah item pada stack pada
tumpukan paling atas
• Pop : digunakan untuk mengambil item pada stack pada
tumpukan paling atas
• Clear : digunakan untuk mengosongkan stack
• IsEmpty : fungsi yang digunakan untuk mengecek
apakah stack sudah kosong
• IsFull : fungsi yang digunakan untuk mengecek apakah
stack sudah penuh


## Guided

### 1. 

```C++
#include <iostream>
using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull()
{
    return (top == maksimal);
}
bool isEmpty()
{
    return (top == 0);
}
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
int countStack()
{
    return top;
}
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}
int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");
    cetakArrayBuku();
    cout << "\n";
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;
    peekArrayBuku(2);
    popArrayBuku();
    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}
```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/3ea18856-5e2f-409b-b18f-14b4b5877028)

Penjelasan Program :
Program diatas adalah implementasi sederhana dari struktur data stack, dimana data yang terakhir dimasukkan akan menjadi yang pertama dikeluarkan. Program ini memungkinkan pengguna untuk menambahkan data ke dalam stack, menghapus data dari stack, melihat data pada posisi tertentu dalam stack, serta melakukan operasi lainnya seperti memeriksa apakah stack penuh atau kosong, menghitung jumlah data dalam stack, mengubah data pada posisi tertentu dan menghapus semua data dari stack. 


## Unguided

### 1. program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak.

```C++
/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// KONVERSI KE HURUF KECIL
string convertChar(string word)
{
    string result;

    // looping untuk setiap char
    for (char a : word)
    {
        if (isalpha(a))
        {
            result += tolower(a);
        }
    }

    // mengembalikan nilai yang sudah di convert
    return result;
}

// PENGECEKAN KATA ATAU KALIMAT
bool isPalindrom(string word)
{

    // memanggil fungsi convert, kemudian disimpan di variable word
    word = convertChar(word);

    // membuat variable reversed
    string reversed = word;

    // library c++ untuk membalikan kata
    reverse(reversed.begin(), reversed.end());
    return word == reversed;
}

// MAIN PROGRAM
int main()
{
    string input;
    cout << "✎ MASUKAN KATA ATAU KALIMAT : ";
    getline(cin, input);

    if (isPalindrom(input))
    {
        cout << " • "<< input << " • " << " ADALAH PALINDROM" << endl;
    }
    else
    {
        cout << " • "<< input << " • " << " BUKAN PALINDROM" << endl;
    }

    return 0;
}

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/40a69127-f94a-4cd8-b9c2-ca5f71009bab)

Penjelasan Program : 
Program diatas adalah program untuk mengecek sebuah kata atau kalimat adalah kalimat palindrom atau bukan. Fungsi 'convertChar' yang mengubah karakter menjadi huruf kecil, dalam fungsi tersebut menggunakan looping untuk mengubah setiap karakter dari inputan user. Hasil konversi tersebut kemudian disimpan di variable result. Fungsi 'isPalindrom' menggunakan tipe data bool untuk pengecekan kata atau kalimat yang dimasukan. Dalam fungsi tersebut kita mengubah inputan menjadi huruf kecil menggunakan fungsi sebelumnya, kemudian disalin ke dalam variable reversed. Terdapat fungsi 'reverse' yang merupakan library C++ yang fungsinya yaitu membalikan. Jika inputan dan hasil balikan sama, maka mengembalikan nilai true dan sebaliknya. Pada main program kita menggunakan fungsi 'isPalindrom' untuk mengecek kata yang dimasukan, kemudian kata yang diinputkan akan dicetak dan menunjukan kata tersebut palindrom atau bukan.

### 2. program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata.

```C++
/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// MEMBALIKAN KALIMAT
string reverseSentence(string word)
{
    // membuat variable reversed
    string reversed = word;

    // library c++ untuk membalikan kata
    reverse(reversed.begin(), reversed.end());

    return reversed;
}

// MAIN PROGRAM
int main()
{
    string input;
    cout << "✎ MASUKAN KATA ATAU KALIMAT : ";
    getline(cin, input); // Menggunakan getline() untuk mengambil seluruh baris input

    string reversed = reverseSentence(input);

    cout << "↳ HASIL ( SETELAH DIBALIK ): " << reversed << endl;

    return 0;
}

```
 
#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/f6de372e-9c0a-488b-bcf9-e2de7f729df8)

Penjelasan Program : Program diatas adalah program untuk membalikan sebuah kata atau kalimat. Fungsi 'reverseSentence' untuk membalikan kata atau kalimat yang diinputkan. Terdapat fungsi 'reverse' yang merupakan library C++ yang fungsinya yaitu membalikan. Kemudian hasil pembalikan itu akan menjadi output dari fungsi tersebut. Pada main program kita menggunakan fungsi 'getline' untuk menerima input yang mengandung spasi. Fungsi 'reverseSentence' kemudian digunakan untuk membalikan dan akan dicetak sebagai hasil dari pembalikan kata yang diinputkan.

## Kesimpulan
Stack adalah struktur data sederhana yang digunakan untuk menyimpan data dengan prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Stack dapat direpresentasikan menggunakan Linked List atau array. Beberapa operasi yang umum dilakukan pada stack meliputi push (menambahkan item pada stack), pop (mengambil item pada stack), clear (mengosongkan stack), isEmpty (mengecek apakah stack kosong), dan isFull (mengecek apakah stack penuh). Dengan menggunakan operasi-operasi tersebut, stack dapat digunakan dalam berbagai aplikasi seperti pengolahan ekspresi matematika, evaluasi ekspresi, dan manajemen memori.

## Referensi

#### [1] Moh. Erkamim, Iim Abdurrohim. BUKU AJAR ALGORITMA DAN STRUKTUR DATA. Jambi : PT. Sonpedia Publishing Indonesia, 2024.
#### [2] Anita Sindar RMS. Struktur Data dan Algoritma C++. Banten: CV. AA. Rizky, 2019.
#### [3] Joseph Teguh Santoso. Struktur Data dan Algoritma (Bagian 1). Semarang: Yayasan Prima Agus Teknik, 2021.
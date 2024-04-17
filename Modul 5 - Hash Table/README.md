# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

Hash table atau tabel hash digunakan untuk mengindeks sekumpulan array untuk memudahkan proses pencarian. Hash function adalah fungsi yang digunakan untuk mengubah nilai kunci menjadi nilai yang disebut alamat hash. Alamat hash ini mewakili indeks posisi dalam array.[2] Hash merupakan modul (function) dalam algoritma. Teknik yang memungkinkan lokasi suatu record dapat diperoleh dengan mudah dan cepat dikenal dengan fungsi hashing. Untuk menyimpan data dalam hashing diantaranya menggunakan array yang dikenal dengan istilah tabel hashing. [1]

Fungsi hash membuat pemetaan antara kunci dan nilai, hal ini dilakukan
melalui penggunaan rumus matematika yang dikenal sebagai fungsi hash. Hasil dari fungsi hash disebut sebagai nilai hash atau hash. Nilai hash adalah representasi dari string karakter asli tetapi biasanya lebih kecil dari aslinya. [3]

Operasi Hash Table
1. Insertion:
Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash
untuk menentukan posisi bucket yang tepat, dan kemudian menambahkan
data ke bucket tersebut.
2. Deletion:
Menghapus data dari hash table dengan mencari data menggunakan fungsi
hash, dan kemudian menghapusnya dari bucket yang sesuai.
3. Searching:
Mencari data dalam hash table dengan memasukkan input kunci ke fungsi
hash untuk menentukan posisi bucket, dan kemudian mencari data di dalam
bucket yang sesuai.
4. Update:
Memperbarui data dalam hash table dengan mencari data menggunakan
fungsi hash, dan kemudian memperbarui data yang ditemukan.
5. Traversal:
Melalui seluruh hash table untuk memproses semua data yang ada dalam
tabel. [3]

## Guided

### 1.
```C++
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable
{
private:
    Node **table;

public:
    // Konstruktor
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }

    // Destruktor
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Penyisipan data
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }

        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Pencarian data
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Penghapusan data
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traverse atau traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;

    // Penyisipan data
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Pencarian data
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Penghapusan data
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}

```
#### Output
![guideda](https://github.com/seaaralee/data-structure-assignment/assets/87632337/8be8d163-29da-4869-bf54-4a1b0439b5c1)

Penjelasan Program :
Program di atas adalah implementasi dari struktur data tabel hash. Tabel hash digunakan untuk menyimpan pasangan kunci-nilai yang memungkinkan pencarian, penyisipan, dan penghapusan data secara efisien. Program ini menggunakan teknik hashing sederhana yang menggunakan modulo sebagai fungsi hash untuk menentukan indeks array berdasarkan kunci yang diberikan. Struktur dasar tabel hash ini terdiri dari array pointer ke Node, di mana setiap Node menyimpan kunci (key), nilai (value), dan pointer ke Node berikutnya

### 2.
```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

class HashNode
{
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    // Fungsi hash untuk menghitung indeks dalam tabel
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Menyisipkan data ke dalam tabel hash
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Menghapus data dari tabel hash berdasarkan nama
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Mencari nomor telepon berdasarkan nama
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    // Menampilkan isi dari tabel hash
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "] ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;

    // Menambahkan data ke dalam tabel hash
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    // Mencari nomor telepon berdasarkan nama
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Nomer Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    // Menghapus data dari tabel hash
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl
         << endl;

    // Menampilkan isi dari tabel hash
    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}

```

#### Output

![guidedb](https://github.com/seaaralee/data-structure-assignment/assets/87632337/9e9a9a7d-564b-4434-8e2b-390026dbc237)

Penjelasan Program :
Program diatas adalah implementasi dari hash map yang mengelola informasi karyawan berupa nama dan nomor telepon. Menggunakan kelas HashNode untuk menyimpan data individu dan kelas HashMap untuk mengatur kumpulan HashNode. Fungsi hash mengonversi nama ke indeks array melalui operasi matematika sederhana, dan hash map memungkinkan penyisipan, pencarian, dan penghapusan data.

## Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru,menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.
```C++
/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// STRUCT MAHASISWA
struct Mahasiswa
{
    string nim;
    int nilai;
    string nama;
};

// CREATE HASH
class HashTable
{
private:
    static const int tableSize = 10;
    list<Mahasiswa> table[tableSize];

    // FUNGSI HASH
    int hashFunction(string nim)
    {
        int sum = 0;
        for (char ch : nim) {
            sum += ch;
        }
        return sum % tableSize;

    }

public:
    // TAMBAH DATA
    void addData(string nim, int nilai, string nama)
    {
        int index = hashFunction(nim);
        Mahasiswa mahasiswa = {nim, nilai, nama};
        table[index].push_back(mahasiswa);
    }

    // HAPUS DATA BY NIM
    void deleteData(string nim)
    {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->nim == nim)
            {
                table[index].erase(it);
                break;
            }
        }
    }

    // SEARCH DATA
    Mahasiswa *searchByNIM(string nim)
    {
        int index = hashFunction(nim);
        for (auto &mahasiswa : table[index])
        {
            if (mahasiswa.nim == nim)
            {
                return &mahasiswa;
            }
        }
        return nullptr;
    }

    // SEARCH DATA BY NILAI
    vector<Mahasiswa> searchByNilai(int min, int max)
    {
        vector<Mahasiswa> hasil;
        for (int i = 0; i < tableSize; ++i)
        {
            for (auto &mahasiswa : table[i])
            {
                if (mahasiswa.nilai >= min && mahasiswa.nilai <= max)
                {
                    hasil.push_back(mahasiswa);
                }
            }
        }
        return hasil;
    }
};

int main()
{
    HashTable hashTable;
    int pilihan;
    string nim;
    int nilai;
    string nama;

    do
    {
        cout << "\n˚₊‧꒰ა PROGRAM HASHTABLE MAHASISWA TELKOM UNIVERSITY ໒꒱ ‧₊˚" << endl;
        cout << "ʚ 1 ɞ ⁺˖ TAMBAH DATA ⸝⸝" << endl;
        cout << "ʚ 2 ɞ ⁺˖ HAPUS DATA ⸝⸝" << endl;
        cout << "ʚ 3 ɞ ⁺˖ CARI DATA BERRDASAKAN NIM ⸝⸝" << endl;
        cout << "ʚ 4 ɞ ⁺˖ CARI DATA BERRDASAKAN NIAI ( 80 - 90 ) ⸝⸝" << endl;
        cout << "ʚ 5 ɞ ⁺˖ KELUAR ⸝⸝" << endl;
        cout << "↳ PILIH MENU : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "\n˚₊‧꒰ TAMBAH DATA ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NAMA : ";
            cin.ignore();
            getline(cin, nama);
            cout << "✎ INPUT NIM : ";
            cin >> nim;
            cout << "✎ INPUT NILAI : ";
            cin >> nilai;
            hashTable.addData(nim, nilai, nama);
            cout << "⊹ • DATA DENGAN NAMA " << nama << " [ " << nim << " ] DENGAN NILAI " << nilai << " DITAMBAHKAN ! • ⊹" << endl;
            break;
        case 2:
            cout << "\n˚₊‧꒰ HAPUS DATA ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NIM : ";
            cin >> nim;
            if (Mahasiswa *mahasiswa = hashTable.searchByNIM(nim))
            {
                cout << "⊹ • DATA DENGAN NAMA " << mahasiswa->nama << " [" << mahasiswa->nim << "] DENGAN NILAI " << mahasiswa->nilai << " DIHAPUS ! • ⊹" << endl;
                hashTable.deleteData(nim);
            }
            else
            {
                cout << "⊹ • TIDAK DITEMUKAN ! • ⊹" << endl;
            }
            break;
        case 3:
            cout << "\n˚₊‧꒰ CARI DATA BERRDASAKAN NIM ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NIM : ";
            cin >> nim;
            if (Mahasiswa *mahasiswa = hashTable.searchByNIM(nim))
            {
                cout << "⊹ • DATA DENGAN NIM " << mahasiswa->nim << " ATAS NAMA " << mahasiswa->nama <<" DITEMUKAN DENGAN NILAI " << mahasiswa->nilai << endl;
            }
            else
            {
                cout << "⊹ • TIDAK DITEMUKAN ! • ⊹" << endl;
            }
            break;
        case 4:
            cout << "\n˚₊‧꒰ CARI DATA BERRDASAKAN NIAI ( 80 - 90 ) ꒱ ‧₊˚" << endl;
            {
                vector<Mahasiswa> mahasiswas = hashTable.searchByNilai(80, 90);
                for (const auto &mahasiswa : mahasiswas)
                {
                    cout << "NAMA : " << mahasiswa.nama << ", NIM : " << mahasiswa.nim << ", NILAI: " << mahasiswa.nilai << endl;
                }
            }
            break;
        case 5:
            cout << "\n⊹ • THANK YOU FOR USING THIS PROGRAM ! • ⊹" << endl;
            break;
        default:
            cout << "\n⊹ • INVALID CHOICE ! • ⊹" << endl;
            break;
        }
    } while (pilihan != 5);

    return 0;
}

```
#### Output

#### Tambah Data 
![1](https://github.com/seaaralee/data-structure-assignment/assets/87632337/f81aaf05-fdfd-494c-91e8-0298dd411cd9)
![2](https://github.com/seaaralee/data-structure-assignment/assets/87632337/f2defaea-a93f-4319-97ea-20aa167fdca2)

#### Hapus Data
![hpus](https://github.com/seaaralee/data-structure-assignment/assets/87632337/0e6dcdca-0dfd-407a-84a9-c215320f041e)

#### Cari Data berdasarkan NIM
![bynim](https://github.com/seaaralee/data-structure-assignment/assets/87632337/bcb8f6d7-173d-4cca-a52c-2769bffa1f72)

#### Cari Data berdasarkan Nilai
![bynilai](https://github.com/seaaralee/data-structure-assignment/assets/87632337/7e14e92e-40a9-4ebd-8103-7570cc38418b)

Penjelasan Program :
Program diatas adalah implementasi hash tabel yang mengelola data mahasiswa Telkom University, yang memungkinkan penambahan, penghapusan, dan pencarian data mahasiswa. Struktur data yang digunakan adalah array dari linked list, dimana setiap mahasiswa, yang memiliki NIM, nama, dan nilai, diindeks berdasarkan fungsi hash dari NIM mereka. Program ini menyediakan menu untuk memasukkan atau menghapus data mahasiswa, serta mencari berdasarkan NIM atau rentang nilai. Melalui menu ini, pengguna dapat interaksi secara mudah dengan sistem untuk mengelola informasi mahasiswa secara efisien.

## Kesimpulan
Hash table adalah struktur data yang memakai array untuk memudahkan pencarian informasi. Di dalam hash table, kita menggunakan sesuatu yang disebut fungsi hash untuk mengubah kunci atau identifier dari data menjadi sebuah indeks dalam array yang disebut alamat hash. Ini membantu kita menemukan, menyimpan, atau menghapus informasi dengan cepat. Ada beberapa operasi dasar yang bisa dilakukan dengan hash table, seperti memasukkan data baru, menghapus data, mencari data tertentu, memperbarui data yang sudah ada, dan menelusuri seluruh data di tabel untuk memprosesnya. Penggunaan hash table sangat membantu dalam membuat aplikasi yang memerlukan akses cepat ke data, karena meminimalkan waktu yang dibutuhkan untuk mencari dan mengelola informasi.

## Referensi

#### [1] Supriatna, A, "PENERAPAN ALGORITMA HASH PADA APLIKASI PERPUSTAKAAN KAMPUS UNTUK PENATAAN BUKU-BUKU DALAM RAK", J. Teknologi Informasi dan Komunikasi. 2, Okt. 2016.
#### [2] Bahit, M, ALGORITMA PEMROGRAMAN TERSTRUKTUR . Cetakan Pertama. Banjarmasin:Poliban Press,2024.
#### [3] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.

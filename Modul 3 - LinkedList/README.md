# <h1 align="center">Laporan Praktikum Modul LinkedList</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

Linked List (Senarai Berantai) adalah jenis struktur data yang berisi kumpulan data yang disusun secara linear dengan setiap data disimpan dalam sebuah simpul dan antara satu simpul dengan simpul lain dihubungkan melalui pointer.[1] Linked List memiliki properti berikut:
- Elemen yang berurutan dihubungkan oleh pointer
- Elemen terakhir menunjuk ke NULL
- Dapat tumbuh atau menyusut dalam ukuran selama eksekusi program
- Dapat dibuat selama diperlukan (sampai memori sistem habis)
- Tidak membuang-buang ruang memori (tetapi membutuhkan memori ekstra untuk pointer). Ini mengalokasikan memori saat daftar bertambah. [2]

#### Single Linked List
Single linked list atau biasa disebut linked list terdiri dari elemen-elemen individu, dimana masing masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointer next. Elemen pada awal suatu list disebut head, dan elemen terakhir dari suatu list disebut tail. Dengan single linke list, list dapat dilintasi hanya satu arah dari head ke tail karena masing-masing elemen tidak terdapat link dengan elemen sebelumnya.[1]

#### Double Linked List
Double linked list dibentuk dengan menyusun sejumlah elemen sehingga pointer next menunjuk ke elemen yang mengikutinya dan pointer prev menunjuk ke elemen yang mendahuluinya. Untuk menunjukkan head dari double linked list, maka pointer prev dari elemen pertama menunjuk NULL. Untuk menunjukkan tail dari double linked list tersebut, maka pointer next dari elemen terakhir menunjuk NULL. [1] Keuntungan dari Double Linked List (juga disebut daftar tertaut dua arah) adalah bahwa dengan adanya simpul dalam daftar, kita dapat menavigasi ke dua arah[2]


## Guided

### 1. Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```

Penjelasan Program : Program di atas adalah implementasi dari struktur data Single Linked List Program ini menyediakan fungsi-fungsi dasar seperti insertDepan, insertBelakang, hapusDepan, hapusBelakang, insertTengah, hapusTengah, ubahDepan, ubahBelakang, ubahTengah, clearList, dan tampil untuk mengelola dan memanipulasi elemen dalam linked list. Pada main() program, terdapat contoh penggunaan fungsi-fungsi tersebut untuk menambah, menghapus, dan mengubah data dalam linked list.

### 2. Double Linked List

```C++
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    void pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData, newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
        {
            list.deleteAll();
            break;
        }
        case 5:
        {
            list.display();
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```

Penjelasan Program : Program di atas adalah implementasi dari struktur data Double Linked List. Program menyediakan beberapa fungsi dasar seperti push (menambahkan elemen di awal), pop (menghapus elemen di awal), update (mengubah data), deleteAll (menghapus semua elemen), dan display (menampilkan semua elemen). Pada main(), terdapat menu interaktif untuk memilih operasi yang ingin dilakukan, seperti menambah, menghapus, mengubah, dan menampilkan data.

## Unguided

### 1. Single Linked List

```C++
/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <iomanip>
using namespace std;

// STRUCT NODE
struct Node
{
    string dataNama;
    int dataUmur;
    Node *next;
};

// DEKLARASI POINTER
Node *head;
Node *tail;

// INISIALISASI
void init()
{
    head = NULL;
    tail = NULL;
}

// CEK LIST
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// CEK JUMLAH
int jumlah()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// HAPUS LIST
void clear()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "LIST TERHAPUS!" << endl;
}

// SHOW LIST
void show()
{
    cout << "\n[ Nama ]           [ Umur ]" << endl;

    Node *bantu = head;
    
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << left << setw(15) << bantu->dataNama << right << setw(8) << bantu->dataUmur << endl;
            bantu = bantu->next;
        }
    }
    else
    {
        cout << "LIST KOSONG!" << endl;
    }
}


// TAMBAH DEPAN
void addDepan(string nama, int umur)
{
    Node *baru = new Node;
    baru->dataNama = nama;
    baru->dataUmur = umur;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// TAMBAH TENGAH
void addTengah(string nama, int umur, int posisi)
{
    if (posisi < 1 || posisi > jumlah())
    {
        cout << "JUMLAH LIST KURANG!" << endl;
    }
    else if (posisi == 1)
    {
        cout << "POSISI BUKAN DITENGAH!" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->dataNama = nama;
        baru->dataUmur = umur;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// TAMBAH BELAKANG
void addBelakang(string nama, int umur)
{
    Node *baru = new Node;
    baru->dataNama = nama;
    baru->dataUmur = umur;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// UPDATE DEPAN
void updateDepan(string nama, int umur)
{
    if (isEmpty() == false)
    {
        head->dataNama = nama;
        head->dataUmur = umur;
    }
    else
    {
        cout << "LIST KOSONG!" << endl;
    }
}

// UPDATE TENGAH
void updateTengah(string nama, int umur, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > jumlah())
        {
            cout << "JUMLAH LIST KURANG!" << endl;
        }
        else if (posisi == 1)
        {
            cout << "POSISI BUKAN DITENGAH!" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->dataNama = nama;
            bantu->dataUmur = umur;
        }
    }
    else
    {
        cout << "LIST KOSONG!" << endl;
    }
}

// UPDATE BELAKANG
void updateBelakang(string nama, int umur)
{
    if (isEmpty() == false)
    {
        tail->dataNama = nama;
        tail->dataUmur = umur;
    }
    else
    {
        cout << "LIST KOSONG!" << endl;
    }
}

// HAPUS DEPAN
void deleteDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "LIST KOSONG!" << endl;
    }
}

// HAPUS TENGAH
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > jumlah())
    {
        cout << "JUMLAH LIST KURANG!" << endl;
    }
    else if (posisi == 1)
    {
        cout << "POSISI BUKAN DITENGAH!" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

// HAPUS BELAKANG
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "LIST KOSONG!" << endl;
    }
}

// MAIN PROGRAM
int main()
{
    init();
    int pilihan, umur, posisi;
    string nama;

    do
    {
        // MENU DATA MAHASISWA
        cout << "\n>>> MENU DATA MAHASISWA <<<" << endl;
        cout << "1. ADD" << endl;
        cout << "2. UPDATE" << endl;
        cout << "3. DELETE" << endl;
        cout << "4. SHOW" << endl;
        cout << "5. CLEAR" << endl;
        cout << "6. EXIT" << endl;
        cout << "PILIH MENU : ";
        cin >> pilihan;

        switch (pilihan)
        {
            // MENU ADD
            case 1:
                cout << "\n- MENU ADD -" << endl;
                cout << "1. DEPAN" << endl;
                cout << "2. TENGAH" << endl;
                cout << "3. BELAKANG" << endl;
                cout << "PILIH MENU : ";
                cin >> pilihan;

                cout << "MASUKAN NAMA : ";
                cin.ignore();
                getline(cin, nama);
                cout << "MASUKAN UMUR : ";
                cin >> umur;

                switch (pilihan)
                {
                    case 1:
                        addDepan(nama, umur);
                        break;
                    case 2:
                        cout << "POSISI ( Add ) : ";
                        cin >> posisi;
                        addTengah(nama, umur, posisi);
                        break;
                    case 3:
                        addBelakang(nama, umur);
                        break;
                    default:
                        cout << "TIDAK VALID!" << endl;
                        break;
                }
                break;

            // MENU UPDATE
            case 2:
                cout << "\n- MENU UPDATE -" << endl;
                cout << "1. DEPAN" << endl;
                cout << "2. TENGAH" << endl;
                cout << "3. BELAKANG" << endl;
                cout << "PILIH MENU : ";
                cin >> pilihan;

                cout << "MASUKAN NAMA : ";
                cin.ignore();
                getline(cin, nama);
                cout << "MASUKAN UMUR : ";
                cin >> umur;

                switch (pilihan)
                {
                    case 1:
                        updateDepan(nama, umur);
                        break;
                    case 2:
                        cout << "POSISI ( Update ): ";
                        cin >> posisi;
                        updateTengah(nama, umur, posisi);
                        break;
                    case 3:
                        updateBelakang(nama, umur);
                        break;
                    default:
                        cout << "TIDAK VALID!" << endl;
                        break;
                }
                break;

            // MENU DELETE
            case 3:
                cout << "\n- MENU DELETE -" << endl;
                cout << "1. DEPAN" << endl;
                cout << "2. TENGAH" << endl;
                cout << "3. BELAKANG" << endl;
                cout << "PILIH MENU : ";
                cin >> pilihan;

                switch (pilihan)
                {
                    case 1:
                        deleteDepan();
                        break;
                    case 2:
                        cout << "POSISI ( Delete ): ";
                        cin >> posisi;
                        hapusTengah(posisi);
                        break;
                    case 3:
                        hapusBelakang();
                        break;
                    default:
                        cout << "TIDAK VALID!" << endl;
                        break;
                }
                break;

            // SHOW LIST
            case 4:
                show();
                break;

            // CLEAR LIST
            case 5:
                clear();
                break;

            case 6:
                cout << "THANK YOU FOR USING THIS PROGRAM!" << endl;
                break;

            default:
                cout << "TIDAK VALID!" << endl;
                break;
        }
    } while (pilihan != 6);

    return 0;
}


```

Penjelasan Program : Program C++ ini merupakan implementasi dari single linked list untuk mengelola daftar mahasiswa berdasarkan nama dan umur. Program menyajikan antarmuka menu yang memungkinkan pengguna untuk menambahkan, memperbarui, dan menghapus data mahasiswa, serta menampilkan seluruh daftar dan menghapus seluruh entri dalam daftar.

#### Case 1 : Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

- Tambah Data 1
- ![a1](https://github.com/seaaralee/data-structure-assignment/assets/87632337/1bcef792-a25a-4a3d-98dc-8aae76dbd4cd)
  
- Tambah Data 2
- ![a2](https://github.com/seaaralee/data-structure-assignment/assets/87632337/6111d0ea-b2d9-46d1-907c-8fea38df8e8f)

- Tambah Data 3
- ![a3](https://github.com/seaaralee/data-structure-assignment/assets/87632337/b7e5a140-0672-47ab-8a88-20697d324881)

- Tambah Data 4
- ![a4](https://github.com/seaaralee/data-structure-assignment/assets/87632337/f3472def-6a62-441b-9e32-aed0577baad4)

- Tambah Data 5
- ![a5](https://github.com/seaaralee/data-structure-assignment/assets/87632337/d93b6c04-840c-4fa2-9f93-da46c985d0b1)

- Tambah Data 6
- ![a6](https://github.com/seaaralee/data-structure-assignment/assets/87632337/fde8408c-02a1-4b86-a909-df3ce36295a4)

- Tambah Data 7
- ![a7](https://github.com/seaaralee/data-structure-assignment/assets/87632337/f9bde502-4084-4104-849b-5baf2bc67161)

- Tambah Data Nama dan Usia Anda
- ![a](https://github.com/seaaralee/data-structure-assignment/assets/87632337/63b0c296-e5c4-409d-9252-7fe5f21c0bf7)

#### Case 2 : Hapus data Akechi
![b](https://github.com/seaaralee/data-structure-assignment/assets/87632337/136a70f5-2aab-41ba-a380-e0ef3403f355)

#### Case 3 : Tambahkan data berikut diantara John dan Jane : Futaba 18
![c](https://github.com/seaaralee/data-structure-assignment/assets/87632337/6096fe48-accf-47b3-9174-53a6b44fed74)

#### Case 4 : Tambahkan data berikut diawal : Igor 20
![d](https://github.com/seaaralee/data-structure-assignment/assets/87632337/df629859-0514-41ef-8673-987db7d1e2a3)

#### Case 5 : Ubah data Michael menjadi : Reyn 18
![e](https://github.com/seaaralee/data-structure-assignment/assets/87632337/79f6cecc-abda-4835-b355-377d864831c6)

#### Case 6 : Tampilkan seluruh data
![f](https://github.com/seaaralee/data-structure-assignment/assets/87632337/eebc40af-f45e-4e92-a596-fa48e03fd413)


### 2. Double Linked List

```C++
/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <iomanip>
using namespace std;

// CLASS NODE
class Node
{
public:
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

// CLASS LINKEDLIST
class DoublyLinkedList
{
public:

    // DEKLARASI POINTER
    Node *head;
    Node *tail;

    // INISIALISASI AWAL
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // SHOW LIST
    void show()
    {
        Node *current = head;
        cout << left << setw(20) << "[ NAMA PRODUK ]" << right << setw(4) << "[ HARGA ]" << endl;
        while (current != nullptr)
        {
            cout << left << setw(20) << current->namaProduk << right << setw(6) << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }

    // TAMBAH DEPAN
    void addDepan(string namaProduk, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }

        head = newNode;
    }

    // TAMBAH DI POSISI TERTENTU
    void addAtPosition(string namaProduk, int harga, int position)
    {
        if (position == 1)
        {
            addDepan(namaProduk, harga);
            return;
        }

        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        Node *current = head;
        for (int i = 1; i < position - 1 && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "POSISI TIDAK ADA!" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    // UPDATE
    bool update(string oldNama, string newNama, int newHarga)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == oldNama)
            {
                current->namaProduk = newNama;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // HAPUS DEPAN
    void hapusDepan()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }

        delete temp;
    }

    // HAPUS DI POSISI TERTENTU
    void hapusAtPosition(int position)
    {
        if (head == nullptr || position <= 0)
        {
            return;
        }

        Node *current = head;
        for (int i = 1; i < position && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "POSISI TIDAK ADA!" << endl;
            return;
        }

        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }
        else
        {
            head = current->next;
        }

        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }
        else
        {
            tail = current->prev;
        }

        delete current;
    }

    // HAPUS LIST
    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

};

int main()
{
    // Buat List
    DoublyLinkedList list;

    // Masukan Data
    list.addDepan("Hanasui", 30000);
    list.addDepan("Wardah", 50000);
    list.addDepan("Skintific", 100000);
    list.addDepan("Somethinc", 150000);
    list.addDepan("Originote", 60000);
    cout << endl;
    list.show();

    while (true)
    {
        // Menu 
        cout << "\n>> Toko Skincare Purwokerto by ARA <<" << endl;
        cout << "1. TAMBAH DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. UPDATE DATA" << endl;
        cout << "4. TAMBAH DATA ( AT POSITION )" << endl;
        cout << "5. HAPUS DATA ( AT POSITION )" << endl;
        cout << "6. CLEAR" << endl;
        cout << "7. SHOW" << endl;
        cout << "8. EXIT" << endl;

        int choice;
        cout << "PILIH MENU : ";
        cin >> choice;

        switch (choice)
        {
        
        // PILIHAN 1 
        case 1:
        {
            string nama;
            int harga;
            cout << "NAMA PRODUK : ";
            cin.ignore();
            getline(cin, nama);
            cout << "HARGA : ";
            cin >> harga;
            list.addDepan(nama, harga);
            cout << nama <<" BERHASIL DITAMBAHKAN!" << endl;
            break;
        }

        // PILIHAN 2
        case 2:
        {
            list.hapusDepan();
            cout << "PRODUK PALING ATAS DIHAPUS!" << endl;
            break;
        }

        // PILIHAN 3
        case 3:
        {
            string oldNama, newNama;
            int newHarga;
            cout << "PRODUK YANG AKAN DIUPDATE : ";
            cin.ignore();
            getline(cin, oldNama);
            cout << "NAMA PRODUK BARU: ";
            getline(cin, newNama);
            cout << "HARGA BARU : ";
            cin >> newHarga;
            bool updated = list.update(oldNama, newNama, newHarga);
            if (!updated)
            {
                cout << "TIDAK DITEMUKAN!" << endl;
            } else {
                cout << "PRODUK " << oldNama << " DI UPDATE MENJADI " << newNama << " DENGAN HARGA " << newHarga<< endl;
            }
            break;
        }

        // PILIHAN 4
        case 4:
        {
            string nama;
            int harga, position;
            cout << "NAMA PRODUK : ";
            cin.ignore();
            getline(cin, nama);
            cout << "HARGA : ";
            cin >> harga;
            cout << "POSISI : ";
            cin >> position;
            list.addAtPosition(nama, harga, position);
            cout << "PRODUK DITAMBAHKAN DI POSISI " << position << " !" << endl;
            break;
        }

        // PILIHAN 5
        case 5:
        {
            int position;
            cout << "POSISI : ";
            cin >> position;
            list.hapusAtPosition(position);
            cout << "PRODUK DI POSISI " << position << " DIHAPUS!" << endl;
            break;
        }

        // PILIHAN 6
        case 6:
        {
            list.clear();
            cout << "LIST CLEARED!" << endl;
            break;
        }

        // PILIHAN 7
        case 7:
        {
            cout << "\n- DATA PRODUK SKINCARE -" << endl;
            list.show();
            break;
        }

        // PILIHAN 8
        case 8:
        {
            return 0;
        }

        // PILIHAN SALAH
        default:
        {
            cout << "TIDAK VALID!" << endl;
            break;
        }
        }
    }
    return 0;
}

```
 
#### Output

Penjelasan Program : Program yang Anda berikan merupakan implementasi dari Double Linked List untuk mengelola data produk skincare. Program ini memiliki fungsi untuk menampilkan semua produk, menambahkan produk baru di bagian depan atau pada posisi tertentu, memperbarui informasi produk, serta menghapus produk baik dari bagian depan maupun pada posisi tertentu. Selain itu, program juga memiliki menu interaktif, sehingga pengguna dapat dengan mudah mengelola daftar produk skincare sesuai kebutuhan.

#### Case 1 : Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
![a](https://github.com/seaaralee/data-structure-assignment/assets/87632337/4c384295-ef04-4b8d-b1b3-6594d5ccfce0)

#### Case 2 : Hapus produk wardah
![b](https://github.com/seaaralee/data-structure-assignment/assets/87632337/047a2700-69ca-4586-a299-43462535986b)

#### Case 3 : Update produk Hanasui menjadi Cleora dengan harga 55.000
![c](https://github.com/seaaralee/data-structure-assignment/assets/87632337/94b83f44-00ca-4f16-822d-de640e1d125c)

#### Case 4 : Tampilkan menu dan tampilan akhirnya
![d](https://github.com/seaaralee/data-structure-assignment/assets/87632337/616de348-63d8-49e4-9df7-6f2faf8d0742)


## Kesimpulan

Linked List adalah struktur data yang menyimpan kumpulan elemen secara berurutan, dihubungkan oleh pointer. Ada dua jenis Linked List: Single Linked List, di mana setiap elemen terhubung dengan pointer ke elemen berikutnya dan hanya bisa dilintasi satu arah dari head ke tail, serta Double Linked List, yang memungkinkan lintasan dua arah dengan pointer next dan prev. Meskipun memerlukan memori ekstra untuk pointer, Linked List efisien dalam penggunaan ruang memori dan dapat tumbuh sesuai kebutuhan.

## Referensi

#### [1] Anita Sindar RMS, Struktur Data dan Algoritma C++, Banten: CV. AA. Rizky, 2019.

#### [2] Joseph Teguh Santoso, Struktur Data dan Algoritma (Bagian 1). Semarang: Yayasan Prima Agus Teknik, 2021.

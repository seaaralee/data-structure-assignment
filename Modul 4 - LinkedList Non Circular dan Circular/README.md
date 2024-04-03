# <h1 align="center">Laporan Praktikum Modul Linked List Circular dan Non Circular</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

Linked List (Senarai Berantai) adalah jenis struktur data yang berisi kumpulan data yang disusun secara linear dengan setiap data disimpan dalam sebuah simpul dan antara satu simpul dengan simpul lain dihubungkan melalui pointer.[1] Linked List memiliki properti berikut:

- Elemen yang berurutan dihubungkan oleh pointer
- Elemen terakhir menunjuk ke NULL
- Dapat tumbuh atau menyusut dalam ukuran selama eksekusi program
- Dapat dibuat selama diperlukan (sampai memori sistem habis)
- Tidak membuang-buang ruang memori (tetapi membutuhkan memori ekstra untuk pointer). Ini mengalokasikan memori saat daftar bertambah. [2]

#### Non-Circular Linked List
Linked list non circular merupakan linked list dengan node pertama (head) dan node terakhir (tail) yang tidak saling terhubung. Pointer terakhir (tail) pada Linked List ini selalu bernilai NULL sebagai pertanda data terakhir dalam list-nya. Non-Circular Linked List terdiri dari 2 jenis yaitu :

- Single Linked List
Single linked list atau biasa disebut linked list terdiri dari elemen-elemen individu, dimana masing masing dihubungkan dengan pointer tunggal. Masing-masing elemen terdiri dari dua bagian, yaitu sebuah data dan sebuah pointer yang disebut dengan pointer next. [1]

- Double Linked List
Double linked list dibentuk dengan menyusun sejumlah elemen sehingga pointer next menunjuk ke elemen yang mengikutinya dan pointer prev menunjuk ke elemen yang mendahuluinya. Untuk menunjukkan head dari double linked list, maka pointer prev dari elemen pertama menunjuk NULL. Untuk menunjukkan tail dari double linked list tersebut, maka pointer next dari elemen terakhir menunjuk NULL. [1]

#### Circular Linked List
Circular list adalah bentuk lain dari linked list yang memberikan fleksibilitas. Pada circular list, pointer next dari elemen terakhir menunjuk ke elemen pertama. [1] Circular Linked List terdiri dari 2 jenis yaitu :

- Single Linked List Circular
Single Linked List Circular adalah linked list unidirectional yang hanya dapat dilintasi dalam satu arah saja. Jenis linked list ini memiliki simpul terakhir yang menunjuk ke simpul kepala. [3]

- Double Linked List Circular
Circular doubly linked list adalah gabungan dari Double Linked List dan Single Circular Linked List. Seperti Doubly linked list, linked list ini memiliki pointer tambahan yang disebut previous pointer, dan mirip dengan Circular linked list, simpul terakhirnya menunjuk pada simpul kepala. Jenis linked list ini adalah bidirectional. Jadi, double linked list circular ini bisa dilintasi secara dua arah. [3]

## Guided

### 1. Linked List Non Circular

```C++

#include <iostream>

using namespace std;

// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

// Deklarasi struct node
struct Node
{
    int data;
    Node *next;
};

Node *head; // Deklarasi head
Node *tail; // Deklarasi tail

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekkan apakah linked list kosong
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    // Tambah depan
    void insertDepan(int nilai)
    {

        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            baru->next = head;
            head = baru;
        }
    }

    // Tambah belakang
    void insertBelakang(int nilai)
    {
        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
    }

    // Hitung jumlah list
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

    // Tambah tengah
    void insertTengah(int data, int posisi)
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

    // Hapus depan
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
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus belakang
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
            cout << "Linked list masih kosong" << endl;
        }
    }
    // Hapus tengah
    void hapusTengah(int posisi)
    {
        Node *hapus, *bantu, *sebelum;
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
                    sebelum = bantu;
                }
                if (nomor == posisi)
                {
                    hapus = bantu;
                }
                bantu = bantu->next;
                nomor++;
            }
            sebelum->next = bantu;
            delete hapus;
        }
    }

    // ubah depan
    void ubahDepan(int data)
    {
        if (isEmpty() == 0)
        {
            head->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah tengah
    void ubahTengah(int data, int posisi)
    {
        Node *bantu;
        if (isEmpty() == 0)
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
                int nomor = 1;
                bantu = head;
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
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah belakang
    void ubahBelakang(int data)
    {
        if (isEmpty() == 0)
        {
            tail->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus list
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

    // Tampilkan list
    void tampil()
    {
        Node *bantu;
        bantu = head;
        if (isEmpty() == false)
        {
            while (bantu != NULL)
            {
                cout << bantu->data << " ";
                bantu = bantu->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
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

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/72ad9c2c-5074-4279-8a1b-f4b219a8ccbc)

Penjelasan Program : Program di atas merupakan implementasi dari struktur data linked list non-circular dengan berbagai fungsi dasar. Dalam program ini, terdapat fungsi-fungsi dasar seperti pengecekan list kosong (isEmpty), menambah node (insertDepan, insertTengah, insertBelakang), penghapusan node(hapusDepan, hapusTengah, hapusBelakang), mengubah data(ubahDepan, ubahTengah, ubahBelakang) dan untuk menghapus seluruh list (clearList) serta menampilkan isi list (tampil). Dalam main, program menunjukkan contoh penggunaan fungsi-fungsi tersebut dengan operasi tambah, hapus, ubah, dan tampilkan.

### 2. Linked List Circular

```C++
#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

int isEmpty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

// Buat Node Baru
void createNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void addFront(string data)
{
    // Buat Node
    createNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void addBack(string data)
{
    // Buat Node
    createNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
}

// Tambah Tengah
void addMiddle(string data, int posisi)
{

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        int nomor = 1;
        bantu = head;
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
void deleteFront()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

// Hapus Belakang
void deleteBack()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

// Hapus Tengah
void deleteMiddle(int posisi)
{
    if (isEmpty() == 0)
    {
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

// Clear List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List terhapus" << endl;
}

// Show List
void show()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << endl;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

int main()
{
    init();
    addFront("Ayam");
    show();
    addFront("Bebek");
    show();
    addBack("Cicak");
    show();
    addBack("Domba");
    show();
    deleteBack();
    show();
    deleteFront();
    show();
    addMiddle("Sapi", 2);
    show();
    deleteMiddle(2);
    show();

    return 0;
}
```
 
#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/40b5cdc5-3b4f-407e-ae79-0d0135099858)

Penjelasan Program : Program di atas merupakan implementasi LinkedList Circular dengan fungsi dasar seperti menambah (addFront, addBack, addMiddle) dan menghapus (deleteFront, deleteBack, deleteMiddle) node, serta fungsi lainnya seperti pengecekan list kosong (isEmpty), dan menampilkan isi list (show). List diawali dengan head dan tail yang kosong, dan fungsi-fungsi tersebut digunakan untuk memanipulasi isi list. Dalam fungsi main, program menunjukkan contoh penggunaan fungsi-fungsi tersebut dengan operasi tambah dan hapus.

## Unguided

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa.

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
    string dataNIM;
    Node *next;
};

// DEKLARASI POINTER
Node *head, *tail, *baru, *bantu, *hapus;

// INISIALISASI HEAD DAN TAIL
void init()
{
    head = NULL;
    tail = NULL;
}

// PENGECEKAN LIST
bool isEmpty()
{
    return head == NULL;
}

// MENGHITUNG JUMLAH LIST
int jumlah()
{
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
        if (hitung == head) break;
    }
    return jumlah;
}

// MENGHAPUS SELURUH LIST
void clear()
{
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
        if (bantu == head) break;
    }
    head = tail = NULL;
}

// MENAMPILKAN LIST
void show()
{
    bantu = head;

    if (!isEmpty())
    {
        cout << "\n꒰ NAMA ꒱        ꒰ NIM ꒱" << endl;
        do
        {
            cout << left << setw(15) << bantu->dataNama << right << setw(8) << bantu->dataNIM << endl;
            bantu = bantu->next;
        } while (bantu != head);
    }
    else
    {
        cout << "⊹ • LIST EMPTY ! • ⊹" << endl;
    }
}

// MEMBUAT NODE BARU
void buatNode(string nama, string nim)
{
    baru = new Node;
    baru->dataNama = nama;
    baru->dataNIM = nim;
    baru->next = NULL;
}

// TAMBAH DEPAN
void addDepan(string nama, string nim)
{
    buatNode(nama, nim);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// TAMBAH TENGAH
void addTengah(string nama, string nim, int posisi)
{
    if (posisi < 1 || posisi > jumlah())
    {
        cout << "⊹ • POSITION OUT OF RANGE ! • ⊹" << endl;
    }
    else
    {
        baru = new Node();
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->dataNama = nama;
        baru->dataNIM = nim;
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// TAMBAH BELAKANG
void addBelakang(string nama, string nim)
{
    buatNode(nama, nim);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
}

// UPDATE DEPAN
void updateDepan(string nama, string nim)
{
    if (!isEmpty())
    {
        head->dataNama = nama;
        head->dataNIM = nim;
    }
    else
    {
        cout << "⊹ • LIST EMPTY ! • ⊹" << endl;
    }
}

// UPDATE TENGAH
void updateTengah(string nama, string nim, int posisi)
{
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > jumlah())
        {
            cout << "⊹ • POSITION OUT OF RANGE ! • ⊹" << endl;
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
            bantu->dataNIM = nim;
        }
    }
    else
    {
        cout << "⊹ • LIST EMPTY ! • ⊹" << endl;
    }
}

// UPDATE BELAKANG
void updateBelakang(string nama, string nim)
{
    if (!isEmpty())
    {
        tail->dataNama = nama;
        tail->dataNIM = nim;
    }
    else
    {
        cout << "⊹ • LIST EMPTY ! • ⊹" << endl;
    }
}

// DELETE DEPAN
void deleteDepan()
{
    if (!isEmpty())
    {
        hapus = head;
        if (head->next != head)
        {
            head = head->next;
            tail->next = head;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "⊹ • LIST EMPTY ! • ⊹" << endl;
    }
}

// DELETE TENGAH
void deleteTengah(int posisi)
{
    if (!isEmpty())
    {
        if (posisi < 1 || posisi > jumlah())
        {
            cout << "⊹ • POSITION OUT OF RANGE ! • ⊹" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }
            hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        }
    }
    else
    {
        cout << "⊹ • LIST EMPTY ! • ⊹" << endl;
    }
}

// DELETE BELAKANG
void deleteBelakang()
{
    if (!isEmpty())
    {
        if (head != tail)
        {
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            hapus = tail;
            tail = bantu;
            tail->next = head;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "⊹ • LIST EMPTY ! • ⊹" << endl;
    }
}

// MAIN PROGRAM
int main()
{
    init();
    int pilihan, posisi;
    string nama, nim;

    do
    {
        // MENU DATABASE
        cout << "\n˚₊‧꒰ა MENU DATABASE TELKOM UNIVERSITY STUDENT ໒꒱ ‧₊˚" << endl;
        cout << "ʚ 1 ɞ ⁺˖ ADD DEPAN ⸝⸝" << endl;
        cout << "ʚ 2 ɞ ⁺˖ ADD BELAKANG ⸝⸝" << endl;
        cout << "ʚ 3 ɞ ⁺˖ ADD TENGAH ⸝⸝" << endl;
        cout << "ʚ 4 ɞ ⁺˖ UPDATE DEPAN ⸝⸝" << endl;
        cout << "ʚ 5 ɞ ⁺˖ UPDATE BELAKANG ⸝⸝" << endl;
        cout << "ʚ 6 ɞ ⁺˖ UPDATE TENGAH ⸝⸝" << endl;
        cout << "ʚ 7 ɞ ⁺˖ DELETE DEPAN ⸝⸝" << endl;
        cout << "ʚ 8 ɞ ⁺˖ DELETE BELAKANG ⸝⸝" << endl;
        cout << "ʚ 9 ɞ ⁺˖ DELETE TENGAH ⸝⸝" << endl;
        cout << "ʚ 10 ɞ ⁺˖ CLEAR ⸝⸝" << endl;
        cout << "ʚ 11 ɞ ⁺˖ SHOW ⸝⸝" << endl;
        cout << "ʚ 0 ɞ ⁺˖ EXIT ⸝⸝" << endl;
        cout << "↳ CHOOSE YOUR OPERATION : ";
        cin >> pilihan;

        switch (pilihan)
        {
        // CASE TAMBAH DEPAN
        case 1:
            cout << "\n˚₊‧꒰ ADD DEPAN ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NAMA : ";
            cin.ignore();
            getline(cin, nama);
            cout << "✎ INPUT NIM : ";
            cin >> nim;
            addDepan(nama, nim);
            cout << "⊹ • DATA " << nama << " WITH NIM " << nim << " ADDED AT TOP ! • ⊹" << endl;
            break;
        
        // CASE TAMBAH BELAKANG
        case 2:
            cout << "\n˚₊‧꒰ ADD BELAKANG ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NAMA : ";
            cin.ignore();
            getline(cin, nama);
            cout << "✎ INPUT NIM : ";
            cin >> nim;
            addBelakang(nama, nim);
            cout << "⊹ • DATA " << nama << " WITH NIM " << nim << " ADDED AT BOTTOM ! • ⊹" << endl;
            break;

        // CASE TAMBAH TENGAH
        case 3:
            cout << "\n˚₊‧꒰ ADD TENGAH ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NAMA : ";
            cin.ignore();
            getline(cin, nama);
            cout << "✎ INPUT NIM : ";
            cin >> nim;
            cout << "✎ POSITION ( ADD ) : ";
            cin >> posisi;
            addTengah(nama, nim, posisi);
            cout << "⊹ • DATA " << nama << " WITH NIM " << nim << " ADDED AT POSITION " << posisi << " ! • ⊹" << endl;
            break;

        // CASE UPDATE DEPAN
        case 4:
            cout << "\n˚₊‧꒰ UPDATE DEPAN ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NEW NAMA : ";
            cin.ignore();
            getline(cin, nama);
            cout << "✎ INPUT NEW NIM : ";
            cin >> nim;
            updateDepan(nama, nim);
            cout << "⊹ • TOP DATA UPDATED, WITH NEW NAME " << nama << " AND NEW NIM " << nim << " ! • ⊹" << endl;
            break;

        // CASE UPDATE BELAKANG
        case 5:
            cout << "\n˚₊‧꒰ UPDATE BELAKANG ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NEW NAMA : ";
            cin.ignore();
            getline(cin, nama);
            cout << "✎ INPUT NEW NIM : ";
            cin >> nim;
            updateBelakang(nama, nim);
            cout << "⊹ • BOTTOM DATA UPDATED, WITH NEW NAME " << nama << " AND NEW NIM " << nim << " ! • ⊹" << endl;
            break;

        // CASE UPDATE TENGAH
        case 6:
            cout << "\n˚₊‧꒰ UPDATE TENGAH ꒱ ‧₊˚" << endl;
            cout << "✎ INPUT NEW NAMA : ";
            cin.ignore();
            getline(cin, nama);
            cout << "✎ INPUT NEW NIM : ";
            cin >> nim;
            cout << "✎ POSITION ( UPDATE ) : ";
            cin >> posisi;
            updateTengah(nama, nim, posisi);
            cout << "⊹ • DATA AT POSITION " << posisi << " UPDATED, WITH NEW NAME " << nama << " AND NEW NIM " << nim << " ! • ⊹" << endl;
            break;

        // CASE DELETE DEPAN
        case 7:
            deleteDepan();
            cout << "⊹ • TOP DATA DELETED ! • ⊹" << endl;
            break;

        // CASE DELETE BELAKANG
        case 8:
            deleteBelakang();
            cout << "⊹ • BOTTOM DATA DELETED ! • ⊹" << endl;
            break;

        // CASE DELETE TENGAH
        case 9:
            cout << "\n˚₊‧꒰ DELETE TENGAH ꒱ ‧₊˚" << endl;
            cout << "✎ POSITION ( DELETE ) : ";
            cin >> posisi;
            deleteTengah(posisi);
            cout << "⊹ • DATA AT POSITION " << posisi << " DELETED ! • ⊹" << endl;
            break;

        // CASE HAPUS LIST
        case 10:
            clear();
            cout << "⊹ • ALL DATA DELETED ! • ⊹" << endl;
            break;

        // CASE TAMPIL LIST
        case 11:
            cout << "\n˚₊‧꒰ DATABASE TELKOM UNIVERSITY STUDENT ꒱ ‧₊˚" << endl;
            show();
            break;

        // CASE EXIT
        case 0:
            cout << "\n⊹ • THANK YOU FOR USING THIS PROGRAM ! • ⊹" << endl;
            break;

        // PILIHAN TIDAK VALID
        default:
            cout << "\n⊹ • INVALID CHOICE ! • ⊹" << endl;
            break;
        }
    } while (pilihan != 0);

    return 0;
}

```

Penjelasan Program : Program diatas merupakan implementasi dari struktur data LinkedList Circular yaitu Database Mahasiswa Telkom University. Program ini memiliki beberapa fungsi dasar seperti menambah, mengubah, menghapus dan menampilkan data. Detail dari setiap fungsi yang ada didalam program diatas adalah sebagai berikut :

- Fungsi isEmpty() -> Untuk mengembalikan nilai true jika head bernilai NULL dan sebaliknya
- Fungsi jumlah() -> Untuk menghitung jumlah list
- Fungsi clear() -> Untuk menghapus seluruh list
- Fungsi show() -> Untuk menampilkan list
- Fungsi buatNode() -> Untuk membuat node baru yang berisikan nama dan nim
- Fungsi addDepan(), addTengah(), addBelakang() -> Untuk menambakan node baru didepan, ditengah ataupun dibelakang
- Fungsi updateDepan(), updateTengah(), updateBelakang() -> Untuk mengubah node baru didepan, ditengah ataupun dibelakang
- Fungsi deleteDepan(), deleteTengah(), deleteBelakang() -> Untuk menghapus node baru didepan, ditengah ataupun dibelakang
- Fungsi main() -> Fungsi main atau main program ini menampilkan menu yang bisa dilakukan oleh pengguna. Pengguna dapat memilih untuk melakukan operasi yang disediakan pada program tersebut, seperti menambah data, mengubah data, menghapus data dan menampilkan data.

#### Output

#### Tampilan Menu
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/688aba08-a9e8-4e4f-9502-c5d6da73a10f)

#### Tampilan Operasi Tambah
![ADD TENGAH](https://github.com/seaaralee/data-structure-assignment/assets/87632337/d63eb366-32db-4fdc-aaa5-57389d4f5c63)

![ADD DEPAN](https://github.com/seaaralee/data-structure-assignment/assets/87632337/9c0e554b-b1cf-4bc0-83d7-de702230a483)

![ADD BELAKANG](https://github.com/seaaralee/data-structure-assignment/assets/87632337/5d3a0d44-4cb0-4159-a40e-a4218160bf87)

#### Tampilan Operasi Ubah
![UPDATE BELAKANG](https://github.com/seaaralee/data-structure-assignment/assets/87632337/12023774-5e81-4f24-bd27-ef98cbc62a79)

![UPDATE DEPAN](https://github.com/seaaralee/data-structure-assignment/assets/87632337/b7aaaa0b-2d46-4b94-90ef-edb07ddf392e)

![UPDATE TENGAH](https://github.com/seaaralee/data-structure-assignment/assets/87632337/1c913efc-b5bf-4a50-9fd3-c4f0d51b6823)

#### Tampilan Operasi Hapus
![HAPUS DEPAN](https://github.com/seaaralee/data-structure-assignment/assets/87632337/54a8f992-e3ba-4a68-8f38-a3b3908367fc)

![HAPUS BELAKANG](https://github.com/seaaralee/data-structure-assignment/assets/87632337/6d76b8ee-a7e3-45f1-a03f-70c9f35faf43)

![HAPUS TENGAH](https://github.com/seaaralee/data-structure-assignment/assets/87632337/a2a6a8f5-7f1d-4577-b0eb-3e2ea0dc8846)

#### Tampilan Operasi Tampil Data
![SHOW](https://github.com/seaaralee/data-structure-assignment/assets/87632337/fed7f831-995c-415a-9da3-5964f8e53bc9)

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan.

#### Tampilan Data
![11](https://github.com/seaaralee/data-structure-assignment/assets/87632337/f2d49a5b-67e9-441f-acc9-0e6872afe3f2)

#### Tambah Data
![1](https://github.com/seaaralee/data-structure-assignment/assets/87632337/efdc9d76-e9e8-417a-be17-f40436494af3)

![2](https://github.com/seaaralee/data-structure-assignment/assets/87632337/6a1cfa13-62a7-4f23-8011-2fc9a6c720c8)

![3](https://github.com/seaaralee/data-structure-assignment/assets/87632337/a0132e4f-efc8-434d-8562-71f442fe531f)

![4](https://github.com/seaaralee/data-structure-assignment/assets/87632337/c26d54d6-f967-4894-b62e-87f1fef85632)

![5](https://github.com/seaaralee/data-structure-assignment/assets/87632337/a1647063-0e5e-40a7-b327-d24000e34e7d)

![6](https://github.com/seaaralee/data-structure-assignment/assets/87632337/21519946-974b-4a3f-abcb-62587174ce54)

![7](https://github.com/seaaralee/data-structure-assignment/assets/87632337/2b18e924-aae9-4514-bd45-4edeb3a5250a)

![8](https://github.com/seaaralee/data-structure-assignment/assets/87632337/e44a79f3-a7b0-4b9b-93d0-344171d4e6c2)

![9](https://github.com/seaaralee/data-structure-assignment/assets/87632337/c53c3f0c-ac3f-4de2-bba8-6b93cc4a79ac)

![10](https://github.com/seaaralee/data-structure-assignment/assets/87632337/5fa7e889-f571-47fb-bc33-90834581b109)


### 3. Lakukan perintah berikut

#### Case 1 : Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004
![1](https://github.com/seaaralee/data-structure-assignment/assets/87632337/ec93fa82-0976-4787-9bc0-1cbfcf460158)

#### Case 2 : Hapus data Denis
![2](https://github.com/seaaralee/data-structure-assignment/assets/87632337/813ba43a-e11e-495f-95e1-5c3cda04598f)

#### Case 3 : Tambahkan data berikut di awal: Owi 2330000
![3](https://github.com/seaaralee/data-structure-assignment/assets/87632337/677b936d-fd44-469a-bf0f-dab06008e915)

#### Case 4 : Tambahkan data berikut di akhir: David 23300100
![4](https://github.com/seaaralee/data-structure-assignment/assets/87632337/8c36ab0f-2c5b-4242-be9f-12d674333e28)

#### Case 5 : Ubah data Udin menjadi data berikut: Idin 23300045
![5](https://github.com/seaaralee/data-structure-assignment/assets/87632337/ff2fafb3-c604-46de-9a63-a6b66a2d398f)

#### Case 6 : Ubah data terkahir menjadi berikut: Lucy 23300101
![6](https://github.com/seaaralee/data-structure-assignment/assets/87632337/cd6168f9-859a-4316-a1ff-2e547742a86c)

#### Case 7 : Hapus data awal
![7](https://github.com/seaaralee/data-structure-assignment/assets/87632337/4a38aa7e-1274-42dd-945f-c8c651399ce7)

#### Case 8 : Ubah data awal menjadi berikut: Bagas 2330002
![8](https://github.com/seaaralee/data-structure-assignment/assets/87632337/b482e6a9-5034-45a3-90dc-973be53746a5)

#### Case 9 : Hapus data akhir
![9](https://github.com/seaaralee/data-structure-assignment/assets/87632337/94bcc539-af90-400f-8b8b-d26a3406b96b)

#### Case 10 : Tampilkan seluruh data
![10](https://github.com/seaaralee/data-structure-assignment/assets/87632337/80d98170-c845-485e-9e95-55dfd17a409e)


## Kesimpulan

Linked List adalah struktur data linear yang menghubungkan setiap elemen datanya melalui pointer. Elemen-elemen ini tersusun berurutan dengan elemen terakhir menunjuk ke NULL. Linked List memiliki kemampuan untuk tumbuh atau menyusut selama eksekusi program dan dapat dibuat sesuai kebutuhan, meskipun memerlukan alokasi memori tambahan untuk pointer. Terdapat dua jenis Linked List utama: Non-Circular Linked List dan Circular Linked List.

- Non-Circular Linked List terdiri dari Single Linked List, di mana setiap elemen terhubung dengan pointer tunggal, dan Double Linked List, di mana setiap elemen memiliki pointer next dan pointer prev yang menghubungkannya dengan elemen sebelum dan sesudahnya. 

- Circular Linked List memiliki sifat unik di mana elemen terakhirnya menunjuk kembali ke elemen pertama. Circular Linked List juga terdiri dari dua jenis: Single Linked List Circular yang hanya dapat dilintasi dalam satu arah dan Double Linked List Circular yang memungkinkan lintasan dua arah karena memiliki pointer next dan pointer prev.

## Referensi

#### [1] Anita Sindar RMS. Struktur Data dan Algoritma C++. Banten: CV. AA. Rizky, 2019.
#### [2] Joseph Teguh Santoso. Struktur Data dan Algoritma (Bagian 1). Semarang: Yayasan Prima Agus Teknik, 2021.
#### [3] Moh. Erkamim, Iim Abdurrohim. BUKU AJAR ALGORITMA DAN STRUKTUR DATA. Jambi : PT. Sonpedia Publishing Indonesia, 2024.
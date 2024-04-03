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

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


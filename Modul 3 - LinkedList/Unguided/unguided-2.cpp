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

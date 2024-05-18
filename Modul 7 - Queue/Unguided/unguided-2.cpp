/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
using namespace std;

// Buat struct Node
struct Node
{
    string nama; // Nama Mahasiswa
    string nim;  // NIM Mahasiswa
    Node *next;  // Pointer ke node berikutnya
};

class Queue
{
private:
    Node *front; // Pointer ke elemen depan
    Node *back;  // Pointer ke elemen belakang

public:
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }

    // Cek antrian full
    bool isFull()
    {
        return false;
    }

    // Cek antrian kosong
    bool isEmpty()
    {
        return (front == nullptr);
    }

    // Menambah antrian
    void enqueueAntrian(string nama, string nim)
    {
        Node *newNode = new Node(); // Buat node baru
        newNode->nama = nama;       // Isi nama mahasiswa
        newNode->nim = nim;         // Isi NIM mahasiswa
        newNode->next = nullptr;    // Isi next

        if (isEmpty())
        {
            front = newNode;
            back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
    }

    // Menghapus antrian
    void dequeueAntrian()
    {
        if (isEmpty())
        { // Cek antrian kosong
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *temp = front;  // Simpan node paling depan di temp
            front = front->next; // Ubah node setelah front menjadi paling depan
            delete temp;         // Hapus temp
            if (front == nullptr)
            {
                back = nullptr; // Jika antrian menjadi kosong, set back ke nullptr
            }
        }
    }

    // Menghitung antrian
    int countQueue()
    {
        int count = 0;
        Node *current = front;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // Menghapus semua antrian
    void clearQueue()
    {
        while (!isEmpty())
        {
            dequeueAntrian();
        }
    }

    // Menampilkan antrian
    void viewQueue()
    {
        cout << "• Data Antrian Teller •" << endl;
        Node *current = front;
        int position = 1;
        while (current != nullptr)
        {
            cout << position << ". ʚ Nama : " << current->nama << " ɞ • ʚ NIM: " << current->nim << " ɞ" << endl;
            current = current->next;
            position++;
        }
        if (position == 1)
        {
            cout << "ʚ ( kosong ) ɞ" << endl;
        }
    }
};

// Main Program
int main()
{
    Queue que;
    cout << "˚₊‧꒰ა ANTRIAN TELLER ໒꒱ ‧₊˚" << endl;
    cout << "\n˚₊‧꒰ Tambah Data Antrian ꒱‧₊˚" << endl;
    que.enqueueAntrian("Mutia", "1311102182");
    que.enqueueAntrian("Rani", "2311102182");
    que.enqueueAntrian("Meilani", "3311102182");
    que.viewQueue();
    cout << "↳ Jumlah antrian : " << que.countQueue() << endl;
    cout << "\n˚₊‧꒰ Hapus Data Antrian ꒱‧₊˚" << endl;
    que.dequeueAntrian();
    que.viewQueue();
    cout << "↳ Jumlah antrian : " << que.countQueue() << endl;
    cout << "\n˚₊‧꒰ Hapus Semua Data Antrian ꒱‧₊˚" << endl;
    que.clearQueue();
    que.viewQueue();
    cout << "↳ Jumlah antrian :  " << que.countQueue() << endl;
    return 0;
}

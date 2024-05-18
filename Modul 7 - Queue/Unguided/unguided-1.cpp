/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>

using namespace std;

// Buat struct Node
struct Node
{
    string data;
    Node *next;
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
    void enqueueAntrian(string data)
    {
        Node *newNode = new Node(); // buat node baru
        newNode->data = data;       // isi data
        newNode->next = nullptr;    // isi next

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
        { // cek antrian
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *temp = front;  // node paling depan disimpan di temp
            front = front->next; // ubah node setelah front menjadi paling depan
            delete temp;         // hapus temp
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
            cout << position << ". " << current->data << endl;
            current = current->next;
            position++;
        }
        if (position == 1)
        {
            cout << "ʚ ( kosong ) ɞ" << endl;
        }
    }
};

// Main program
int main()
{
    Queue que;
    cout << "˚₊‧꒰ა ANTRIAN TELLER ໒꒱ ‧₊˚" << endl;
    cout << "\n˚₊‧꒰ Tambah Data Antrian ꒱‧₊˚" << endl;
    que.enqueueAntrian("Andi");
    que.enqueueAntrian("Maya");
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

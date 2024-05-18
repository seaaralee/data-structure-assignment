# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/c82c96a2-2b20-49c3-980d-849eaba2e957)

Queue atau antrian adalah suatu kumpulan data yang penambahan elemennya hanya bisa dilakukan pada suatu ujung (disebut dengan sisi belakang atau rear), dan penghapusan atau pengambilan elemen dilakukan lewat ujung yang lain (disebut dengan sisi depan atau front). Kalau tumpukan dikenal dengan menggunakan prinsip LIFO (Last In First Out), maka pada antrian prinsip yang digunakan adalah FIFO (First In First Out). [1]

Pada Queue, operasi tersebut dilakukan ditempat berbeda (melalui salah satu ujung) karena perubahan data selalu mengacu pada Head, maka hanya ada 1 jenis insert maupun delete. Prosedur ini sering disebut Enqueue dan Dequeue pada kasus Queue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup "geser"kan Head menjadi elemen selanjutnya.[2]

Berikut ini operasi-operasi standar pada queue :

a. Inisialisasi, merupakan prosedur untuk membuat queue pada kondisi awal, yaitu queue yang masih kosong (belum mempunyai elemen).

b. InQueue, Insert Queue merupakan prosedur untuk memasukkan sebuah elemen baru pada queue. Jumlah elemen Queue akan bertambah satu dan elemen tersebut merupakan elemen belakang.

c. DeQueue, Delete Queue merupakan prosedur untuk menghapus/mengambil sebuah elemen dari queue. Elemen yang diambil adalah elemen depan dan jumlah elemen queue akan berkurang satu [1]

## Guided

### 1. 

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan

bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] <<

                endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/62b268cf-49e1-4e99-b821-f76aecf81362)

Penjelasan Program :
Program ini mengimplementasikan antrian (queue) sederhana menggunakan array dengan panjang maksimal lima elemen. Program memiliki beberapa fungsi untuk mengelola antrian :
 
isFull: Mengecek apakah antrian sudah penuh.
isEmpty: Mengecek apakah antrian kosong.
enqueueAntrian: Menambahkan data ke antrian jika belum penuh.
dequeueAntrian: Mengeluarkan data dari antrian jika tidak kosong.
countQueue: Menghitung jumlah elemen dalam antrian.
clearQueue: Mengosongkan semua elemen dalam antrian.
viewQueue: Menampilkan elemen-elemen dalam antrian.

Pada main program ditambahkan dua nama ("Andi" dan "Maya") ke dalam antrian, menampilkan isi antrian beserta jumlahnya, mengeluarkan satu elemen dari antrian, dan menampilkan kembali isi dan jumlah antrian setelah pengeluaran elemen. Kemudian, program mengosongkan antrian dan menampilkan kondisi antrian setelah dikosongkan.

## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
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

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/ca6bc5af-4799-4378-940b-844629cceaf4)

Penjelasan Program :
Program ini adalah aplikasi sederhana untuk mengelola antrian (queue) menggunakan linked list. Antrian ini menyimpan data dalam bentuk string. Terdapat beberapa fungsi yang digunakan, seperti enqueueAntrian untuk menambahkan data ke dalam antrian, dequeueAntrian untuk menghapus data dari antrian, countQueue untuk menghitung jumlah data dalam antrian, clearQueue untuk mengosongkan seluruh data dalam antrian, dan viewQueue untuk menampilkan seluruh data dalam antrian.

Pada program utama, beberapa data ditambahkan ke dalam antrian, kemudian program menampilkan isi antrian dan jumlah datanya. Salah satu data kemudian dihapus dari antrian, dan program menampilkan kembali isi antrian dan jumlah datanya setelah penghapusan. Terakhir, program mengosongkan seluruh data dari antrian dan menampilkan kembali jumlah data dalam antrian yang telah kosong.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
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

```
 
#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/9b8ba542-7581-419e-ad42-4b55b85325e6)


Penjelasan Program :
Program ini adalah aplikasi sederhana untuk mengelola antrian (queue) dengan menggunakan linked list. Antrian ini menyimpan nama dan NIM mahasiswa. Fungsi enqueueAntrian menambahkan mahasiswa baru ke akhir antrian, dequeueAntrian mengeluarkan mahasiswa dari depan antrian jika tidak kosong, countQueue menghitung jumlah mahasiswa dalam antrian, dan clearQueue mengosongkan seluruh antrian. Program utama menambahkan tiga mahasiswa ke antrian, menampilkan isi dan jumlah antrian, menghapus satu mahasiswa, lalu menampilkan kembali kondisi antrian. Akhirnya, semua mahasiswa dihapus dari antrian dan kondisi antrian ditampilkan kembali.

## Kesimpulan

Queue adalah struktur data yang mengorganisir elemen-elemennya sesuai dengan prinsip FIFO (First In First Out), yang berarti elemen yang pertama masuk akan menjadi yang pertama keluar. Dalam Queue, penambahan elemen dilakukan di ujung belakang, sedangkan penghapusan elemen dilakukan di ujung depan. Operasi utama dalam Queue adalah Enqueue, yang menambahkan elemen baru di belakang Queue, dan Dequeue, yang menghapus elemen di depan Queue. Proses Enqueue meningkatkan jumlah elemen dalam Queue, sementara Dequeue menguranginya. Operasi standar lainnya meliputi inisialisasi, yang membuat Queue dalam keadaan kosong, serta penghapusan dan penambahan elemen. Dengan demikian, Queue memberikan mekanisme untuk mengelola urutan elemen dengan mematuhi prinsip "siapa yang datang pertama, akan dilayani pertama".

## Referensi

#### [1] Anita Sindar RMS. Struktur Data dan Algoritma C++. Banten: CV. AA. Rizky, 2019.
#### [2] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.

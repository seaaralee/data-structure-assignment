# <h1 align="center">Laporan Praktikum Modul Graf dan Tree</h1>

<p align="center">Mutia Rani Zahra Meilani | 2311102182</p>

## Dasar Teori

### Tree

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/379e1d66-575f-435b-979c-a3deb9747131)

Binary tree adalah tree syaratnya setiap node hanya boleh memiliki paling banyak dua subtree, dan kedua subtree tersebut harus dipisahkan. Dengan definisi ini, setiap node di binary tree hanya dapat memiliki paling banyak dua child.[2] 

#### Binary Tree
Binary tree adalah pohon biner yang pada setiap node menyimpan data atau kunci yang lebih besar dari semua node pada sub tree kirinya yang lebih kecil dari semua node pada sub tree kanannya. [2] Karakteristik utama bahwa setiap node maksimal memiliki dua anak, yaitu anak kiri dan anak kanan. Pohon Biner Lengkap ditandai dengan semua node, kecuali daun, memiliki nol atau dua anak. Dalam pohon ini, subpohon pada Heap Tree dapat memiliki panjang jalur yang berbeda. Pohon Biner Miring adalah pohon di mana semua node, kecuali daun, hanya memiliki satu anak. Sedangkan Pohon Biner Penuh adalah pohon di mana semua node, kecuali daun, memiliki dua anak dan semua subpohon harus memiliki panjang jalur yang sama. [1]

- Tranversal Binary Tree [1] [2]
Operasi penelusuran node-node dalam binary tree, Traversal dibagi 3, yaitu :
a. Preorder, urutan kunjungan dari node mengunjungi node utama, kemudian mengunjungi node di sebelah kiri, dan terakhir mengunjungi node di sebelah kanan
b. Inorder, dimana node yang dikunjungi mempunyai urutan dikunjungi node di sebelah kiri, kemudian mengunjungi node asli dan terakhir kunjungi node di sebelah kanan
c. Postorder, kunjungan dimana node yang berkunjung diperintahkan untuk mengunjungi node (L) di subtree kiri, kemudian mengunjungi node di sebelah kanan (R), dan terakhir mengunjungi node itu sendiri (V).

- Istilah dalam Tree : [2]

Root (atau akar) Node dengan hirarki tertinggi dinamakan root.
Leaf (atau daun) Node yang tidak memiliki cabang.
Internal node (atau node dalam) Node yang bukan merupakan leaf.
Edge (atau sisi atau cabang) Menyatakan hubungan hirarkis antara kedua node yang terhubungkan, biasanya digambarkan berarah (berupa panah) untuk menunjukkan node asal edge lebih tinggi dari node tujuan dari edge.
Level (atau tingkat) suatu node (Kadang dimulai level 0 atau 1)
Bilangan yang menunjukan hirarki dari suatu node, root memiliki level 1, node cabang dari root memiliki level 2, node cabang berikutnya dari node adalah level 3, dan seterusnya.
Height (atau tinggi) suatu tree, sama dengan level dengan angka terbesar (hirarki terendah) suatu node yang ada dalam tree atau bisa juga didefinisikan sebagai jumlah sisi terbanyak dari root hingga suatu leaf yang ada di tree.
Depth (atau kedalaman) suatu node : jumlah sisi dari root hingga node ybs.
Subtree (atau subpohon), sebagian dari tree mulai dari suatu node N melingkupi node-node yang berada dibawah hirarkinya sehingga dapat dipandang sebagai suatu tree juga yang mana N sebagai root dari tree ini.
Tree kosong : suatu tree yang tidak memiliki satu node pun
Predesesor merupakan node yang berada di atas node tertentu.
Successor merupakan node yang berada dibawah node tertentu.
Ancestor merupakan seluruh node yang terletak sebelum node tertentu dan terletak pada jalur yang sama.
Descendant merupakan seluruh node yang terletak sesudah node tertentu dan terletak pada jalur yang sama.
Parent merupakan predesesor satu level di atas satu node.
Child merupakan successor satu level di bawah suatu node.
Sibling merupakan node-node yang memiliki parent yang sama dengan suatu node.

### Graph

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/ead786cc-b1da-458f-a334-fcbbbf3e7f97)

Graph merupakan struktur data yang berbentuk network/jaringan, hubungan antar elemen adalah many-to-many. Graph terdiri dari himpunan verteks (node) dan himpunan sisi (edge, arc). Verteks menyatakan entitasentitas data dan sisi menyatakan keterhubungan antara verteks. Graf merupakan suatu cabang ilmu yang memiliki
banyak terapan. Struktur dan permasalahan yang dapat direpresentasikan dengan graf, misalkan jaringan jalan raya dimodelkan graf dengan kota sebagai simpul (vertex/node) dan jalan yang menghubungkan setiap kotanya sebagai sisi (edge) yang bobotnya (weight) adalah panjang dari jalan tersebut.[1]

#### Jenis Graph

- Graf Berarah (Digraph)


![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/792d92b7-b3a2-44a9-bd43-07d46ca0c4d2)
adalah jenis graf di mana setiap sisi memiliki arah tertentu. Misalnya, sisi {x,y} menunjukkan arah dari x ke y, bukan sebaliknya; x disebut sebagai asal (origin) dan y disebut sebagai tujuan (terminus). Sisi pada digraph biasanya ditulis dalam bentuk vektor (x, y). Contoh Digraph G terdiri dari himpunan V (vertices) dan E (edges): V = {A, B, C, D, E, F, G, H, I, J, K, L, M} dan E = {(A,B), (A,C), (A,D), (A,F), (B,C), (B,H), (C,E), (C,G), (C,H), (C,I), (D,E), (D,F), (D,G), (D,K), (D,L), (E,F), (G,I), (G,K), (H,I), (I,J), (I,M), (J,K), (J,M), (L,K), (L,M)}.

- Graf Tak Berarah (undirected graph atau undigraph)


![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/fc1bd5d5-06aa-4a6f-9499-629e4b23a378)
graf di mana setiap sisi {x, y} berlaku dua arah, artinya hubungan antara x dan y sama-sama berlaku baik dari x ke y maupun dari y ke x. Sisi pada undigraph tidak memiliki tanda panah dan secara notasi ditulis dengan kurung kurawal. Contoh Undigraph G terdiri dari himpunan V (vertices) dan E (edges): V = {A, B, C, D, E, F, G, H, I, J, K, L, M} dan E = {{A,B}, {A,C}, {A,D}, {A,F}, {B,C}, {B,H}, {C,E}, {C,G}, {C,H}, {C,I}, {D,E}, {D,F}, {D,G}, {D,K}, {D,L}, {E,F}, {G,I}, {G,K}, {H,I}, {I,J}, {I,M}, {J,K}, {J,M}, {L,K}, {L,M}}.

- Graf Berbobot (Weighted Graph)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/b8e8770d-0f1b-43c1-93fe-10bd399bf204)

graf di mana setiap sisi memiliki bobot atau biaya tertentu. Biaya ini bisa mewakili berbagai aspek seperti biaya ekonomi suatu aktivitas, jarak geografis atau tempuh, waktu tempuh, tingkat kesulitan, dan lain sebagainya. Contohnya adalah graf tak berarah berbobot, di mana misalnya verteks A memiliki derajat 4 dan verteks B memiliki derajat 3, dan daftar ketetanggaan (adjacency list) dari D adalah {A, E, F, G, K, L}.

- Representasi Graf
Matriks Keterhubungan Langsung (Adjacency Matrix) digunakan untuk mencatat hubungan adjacency setiap vertex. Baris pada matriks berisi vertex asal, sementara kolom berisi vertex tujuan. Jika sebuah sisi pada graf tidak memiliki bobot, maka entri [x, y] dalam matriks akan disimbolkan dengan 1 untuk menunjukkan adanya hubungan dan 0 jika tidak ada hubungan. Jika sisi pada graf memiliki bobot, maka entri [x, y] akan disimbolkan dengan bobot dari sisi tersebut, dan ¥ jika tidak ada hubungan. [1]


## Guided

### 1. Program Graf

```C++
#include <iostream>
#include <iomanip>
using namespace std;
string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"};
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};
void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15)
             << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom]

                     << ")";
            }
        }
        cout << endl;
    }
}
int main()
{
    tampilGraph();
    return 0;
}
```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/a9effc39-03d0-45ed-a4a1-794c0c7d63dc)

Penjelasan Program :
Program di atas adalah implementasi dari struktur data graf yang fungsinya untuk menampilkan hubungan antara tujuh kota beserta jaraknya. Nama-nama kota disimpan dalam array "simpul", sedangkan jarak antara kota-kota disimpan dalam matriks "busur". Fungsi tampilGraph() digunakan untuk mencetak nama setiap kota, dan menampilkan kota-kota yang terhubung dengannya beserta jaraknya. Jika ada jarak (nilai tidak nol), fungsi ini akan menampilkan kota tujuan dan jaraknya. Program dimulai dari fungsi main() yang memanggil tampilGraph(), sehingga menghasilkan output berupa daftar hubungan dan jarak antara kota-kota tersebut.

### 2. Program Tree

```C++

#include <iostream>
using namespace std;
// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};
// pointer global
Pohon *root;
// Inisialisasi
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"

                 << endl;

            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
                return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " <<

                data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&

                node->parent->right == node)

                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node

                     && node->parent->left == node)

                cout << "Sibling : " << node->parent->right->data <<

                    endl;

            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" <<

                    endl;

            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}
int main()
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
}
```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/14b3ecc1-c41a-429e-8645-92e682374239)

Penjelasan Program :
Program di atas adalah implementasi dari struktur data Tree yang fungsinya untuk menyimpan dan mengelola data dalam bentuk hierarki. Program ini mencakup beberapa fungsi utama untuk menginisialisasi pohon, menambah node ke kiri dan kanan, memperbarui nilai node, mengambil dan mencari informasi node, serta melakukan traversal (penelusuran) pohon dalam urutan pre-order, in-order, dan post-order. Program ini juga mencakup fungsi untuk menghapus node, menghitung ukuran dan tinggi pohon, serta menampilkan karakteristik pohon seperti ukuran, tinggi, dan rata-rata node per level.

## Unguided

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <iomanip>

using namespace std;

// max jumlah kota
const int max_182_ara = 100;

// MENAMPILKAN GRAF
void showGraf(const string node[], const int jarak[][max_182_ara], int jumlahKota) {

    // CETAK BARIS HEADER
    cout << setw(10) << " ";
    for (int i = 0; i < jumlahKota; ++i) {
        cout << setw(10) << node[i];
    }
    cout << endl;

    // CETAK ISI BARIS
    // cetak nama kota
    for (int i = 0; i < jumlahKota; ++i) {
        cout << setw(10) << node[i];
        // cetak jarak
        for (int j = 0; j < jumlahKota; ++j) {
            cout << setw(10) << jarak[i][j];
        }
        cout << endl;
    }
}

// MAIN PROGRAM
int main() {

    int jumlahKota;
    cout << "\n˚₊‧꒰ა PROGRAM JARAK SUATU KOTA ໒꒱ ‧₊˚" << endl;
    cout << "✎ INPUT JUMLAH KOTA : ";
    cin >> jumlahKota;
    cin.ignore();

    // cek jumlah kota
    if (jumlahKota > max_182_ara) {
        cout << "⊹ • MELEBIHI JUMLAH MAX ( " << max_182_ara << " ) ⊹ •" << endl;
        return 1;
    }

    // input nama kota
    string node[max_182_ara];
    for (int i = 0; i < jumlahKota; i++) {
        cout << "↳ INPUT NAMA KOTA " << i + 1 << ": ";
        getline(cin, node[i]);
    }

    // matriks simpan jarak
    int jarak[max_182_ara][max_182_ara] = {0};
    for (int i = 0; i < jumlahKota; i++) {
        for (int j = 0; j < jumlahKota; j++) {
            if (i != j) {
                cout << "↳ INPUT JARAK DARI " << node[i] << " → " << node[j] << " : ";
                cin >> jarak[i][j];
            }
        }
    }

    // tampilkan hasil tabel
    cout << "\n˚₊‧꒰ TABEL GRAF JARAK SUATU KOTA ꒱ ‧₊˚" << endl;
    showGraf(node, jarak, jumlahKota);

    return 0;
}

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/2be2d338-7d32-447a-bd82-96019c7507f1)

Penjelasan Program :
Program di atas adalah implementasi sederhana dari graf yang merepresentasikan jarak antara beberapa kota. Program ini meminta pengguna untuk memasukkan jumlah kota, nama-nama kota, dan jarak antara masing-masing kota, kemudian menampilkan data tersebut dalam bentuk tabel. Program ini dimulai dengan menampilkan judul, kemudian meminta input jumlah kota dan nama-nama kota. Setelah itu, pengguna diminta untuk memasukkan jarak antara setiap pasangan kota. Terakhir, program menampilkan tabel yang menunjukkan jarak antara kota-kota yang telah dimasukkan.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
using namespace std;

// DEKLARASI POHON
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// POINTER GLOBAL
Pohon *root;

// INIT
void init_182_ara()
{
    root = NULL;
}

// CEK POHON
bool isEmpty()
{
    return root == NULL;
}

// NODE POHON
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// FUNGSI BUAT NODE
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "⊹ • NODE '" << data << "' DIBUAT MENJADI ROOT • ⊹" << endl;
    }
    else
    {
        cout << "⊹ • SUDAH ADA POHON • ⊹" << endl;
    }
}

// FUNGSI INSERT KIRI
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "⊹ • NODE '" << node->data << "' SUDAH ADA DI CHILD KIRI • ⊹" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "⊹ • NODE '" << data << "' DITAMBAHKAN KE CHILD KIRI " << node->data << " • ⊹" << endl;
            return baru;
        }
    }
}

// FUNGSI INSERT KANAN
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "⊹ • NODE '" << node->data << "' SUDAH ADA DI CHILD KANAN • ⊹" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "⊹ • NODE '" << data << "' DITAMBAHKAN KE CHILD KANAN " << node->data << " • ⊹" << endl;
            return baru;
        }
    }
}

// FUNGSI UPDATE NODE
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "⊹ • NODE '" << temp << "' DIUBAH MENJADI " << data << " • ⊹" << endl;
        }
    }
}

// FUNGSI RETRIEVE
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        }
        else
        {
            cout << "⊹ • DATA NODE : " << node->data << endl;
        }
    }
}

// FUNGSI FIND NODE
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        }
        else
        {
            cout << "⊹ • DATA NODE : " << node->data << endl;
            cout << "↳ ROOT : " << root->data << endl;
            if (!node->parent)
                cout << "↳ PARENT : ✖" << endl;
            else
                cout << "↳ PARENT : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "↳ SIBLING : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "↳ SIBLING : " << node->parent->right->data << endl;
            else
                cout << "↳ SIBLING : ✖" << endl;
            if (!node->left)
                cout << "↳ CHILD KIRI : ✖" << endl;
            else
                cout << "↳ CHILD KIRI : " << node->left->data << endl;
            if (!node->right)
                cout << "↳ CHILD KANAN : ✖" << endl;
            else
                cout << "↳ CHILD KANAN : " << node->right->data << endl;
        }
    }
}

// FUNGSI SHOW CHILD
void showChildren(Pohon *node)
{
    if (node == NULL)
    {
        cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        return;
    }
    if (node->left == NULL && node->right == NULL)
    {
        cout << "⊹ • NODE '" << node->data << "' TIDAK PUNYA CHILD • ⊹" << endl;
        return;
    }
    cout << "⊹ • CHILD NODE " << node->data << " : ";
    if (node->left != NULL)
        cout << "\n↳ KIRI : " << node->left->data << " ";
    if (node->right != NULL)
        cout << "\n↳ KANAN : " << node->right->data << " ";
    cout << endl;
}

// FUNGSI SHOW DESCENDANT
void showDescendants(Pohon *node)
{
    if (node == NULL)
    {
        cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        return;
    }
    cout << "⊹ • DESCENDANTS NODE " << node->data << " :" << endl;
    if (node->left != NULL)
    {
        cout << node->left->data << " ";
        showDescendants(node->left);
    }
    if (node->right != NULL)
    {
        cout << node->right->data << " ";
        showDescendants(node->right);
    }
    cout << endl;
}

// FUNGSI PREORDER
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// FUNGSI INORDER
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// FUNGSI POSTORDER
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// FUNGSI HAPUS NODE TREE
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// HAPUS TREE
void clear()
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        deleteTree(root);
        cout << "⊹ • POHON DIHAPUS • ⊹" << endl;
    }
}

// FUNGSI HAPUS SUBTREE
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "⊹ • NODE SUBTREE '" << node->data << "' DIHAPUS • ⊹" << endl;
    }
}

// CEK SIZE TREE
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// CEK HEIGHT
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// FUNGSI KARAKTERISTIK
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "↳ SIZE : " << s << endl;
    cout << "↳ HEIGHT: " << h << endl;
    if (h != 0)
        cout << "↳ AVERAGE NODE : " << s / h << endl;
    else
        cout << "↳ AVERAGE NODE : 0" << endl;
}

// FIND NODE
Pohon *findNode(Pohon *node, char data)
{

    if (node == NULL)
        return NULL;

    if (node->data == data)
        return node;

    Pohon *leftResult = findNode(node->left, data);

    if (leftResult != NULL)
        return leftResult;

    return findNode(node->right, data);
}

// MENU
void menu()
{
    char choice, data, parentData;
    Pohon *node = NULL;
    do
    {
        cout << "\n˚₊‧꒰ა PROGRAM MEMBUAT TREE ໒꒱ ‧₊˚" << endl;
        cout << "ʚ 1 ɞ ⁺˖ BUAT ROOT ⸝⸝" << endl;
        cout << "ʚ 2 ɞ ⁺˖ TAMBAH NODE ⸝⸝" << endl;
        cout << "ʚ 3 ɞ ⁺˖ UBAH NODE ⸝⸝" << endl;
        cout << "ʚ 4 ɞ ⁺˖ SHOW NODE ( DATA, INFO, CHILD, DESCENDANT ) ⸝⸝" << endl;
        cout << "ʚ 5 ɞ ⁺˖ SHOW NODE TRANVERSAL ( PREORDER, INORDER, POSTORDER ) ⸝⸝" << endl;
        cout << "ʚ 6 ɞ ⁺˖ HAPUS SUBTREE ⸝⸝" << endl;
        cout << "ʚ 7 ɞ ⁺˖ HAPUS TREE ⸝⸝" << endl;
        cout << "ʚ 8 ɞ ⁺˖ KARAKTERISTIK TREE ⸝⸝" << endl;
        cout << "ʚ 0 ɞ ⁺˖ KELUAR ⸝⸝" << endl;
        cout << "✎ PILIH MENU : ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "\n˚₊‧꒰ BUAT ROOT ꒱ ‧₊˚" << endl;
            cout << "↳ INPUT DATA ROOT : ";
            cin >> data;
            buatNode(data);
            break;

        case '2':
            cout << "\n˚₊‧꒰ TAMBAH NODE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN DATA PARENT : ";
            cin >> parentData;
            node = findNode(root, parentData);
            if (node != NULL)
            {
                int childChoice;
                cout << "\n˚₊‧꒰ PILIH LOKASI TAMBAH NODE ꒱ ‧₊˚" << endl;
                cout << "ʚ 1 NODE KIRI ⸝⸝" << endl;
                cout << "ʚ 2 NODE KANAN ⸝⸝" << endl;
                cout << "✎ PILIH LOKASI : ";
                cin >> childChoice;
                if (childChoice == 1)
                {
                    cout << "↳ MASUKAN DATA NODE KIRI :";
                    cin >> data;
                    insertLeft(data, node);
                }
                else if (childChoice == 2)
                {
                    cout << "↳ MASUKAN DATA NODE KANAN :";
                    cin >> data;
                    insertRight(data, node);
                }
                else
                {
                    cout << "⊹ • PILIHAN TIDAK VALID • ⊹" << endl;
                }
            }
            break;

        case '3':
        cout << "\n˚₊‧꒰ UBAH NODE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN DATA NODE YANG INGIN DIUBAH : ";
            cin >> data;
            node = findNode(root, data);
            if (node != NULL)
            {
                cout << "↳ MASUKAN DATA BARU : ";
                cin >> data;
                update(data, node);
            }
            break;

        case '4':
        cout << "\n˚₊‧꒰ SHOW NODE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN DATA NODE YANG INGIN DITAMPILKAN : ";
            cin >> data;
            node = findNode(root, data);
            if (node != NULL)
            {
                char infoChoice;
                cout << "\n˚₊‧꒰ PILIH TAMPILAN NODE ꒱ ‧₊˚" << endl;
                cout << "ʚ 1 DATA NODE ⸝⸝" << endl;
                cout << "ʚ 2 INFO NODE ⸝⸝" << endl;
                cout << "ʚ 3 NODE CHILD ⸝⸝" << endl;
                cout << "ʚ 4 NODE DESCENDANT ⸝⸝" << endl;
                cout << "✎ PILIH INFORMASI : " << endl;
                cin >> infoChoice;
                switch (infoChoice)
                {
                case '1':
                    retrieve(node);
                    break;
                case '2':
                    find(node);
                    break;
                case '3':
                    showChildren(node);
                    break;
                case '4':
                    showDescendants(node);
                    break;
                default:
                    cout << "⊹ • PILIHAN TIDAK VALID • ⊹" << endl;
                    break;
                }
            }
            break;

        case '5':
        cout << "\n˚₊‧꒰ NODE TRANVERSAL ꒱ ‧₊˚" << endl;
            cout << "↳ PREORDER : " << endl;
            preOrder(root);
            cout << endl;
            cout << "↳ INORDER : " << endl;
            inOrder(root);
            cout << endl;
            cout << "↳ POSTORDER : " << endl;
            postOrder(root);
            cout << endl;
            break;

        case '6':
        cout << "\n˚₊‧꒰ HAPUS SUBTREE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN NODE SUBTREE YANG INGIN DIHAPUS : ";
            cin >> data;
            node = findNode(root, data);
            deleteSub(node);
            break;
        case '7':
            clear();
            break;
        case '8':
        cout << "\n˚₊‧꒰ KARAKTERISTIK ꒱ ‧₊˚" << endl;
            characteristic();
            break;
        case '0':
            break;
        default:
            cout << "⊹ • PILIHAN TIDAK VALID • ⊹" << endl;
            break;
        }
    } while (choice != '0');
}

// MAIN PROGRAM
int main()
{
    init_182_ara();
    menu();
    return 0;
}

```

#### Output
![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/a1ce53fa-fba8-4106-8f3b-bd09b3eeba60)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/9f982500-1e7f-45ec-9d23-c6b76e69dbbf)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/b1331d75-73ee-4bcd-abd5-0a6e51eaae5b)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/a3f3fbd9-2ee7-4034-9898-d8c1c9f9fabb)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/07ba375e-3af3-4a78-adf9-7151dcd8e295)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/14f75f76-d825-409e-a995-569b0637e954)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/3d67165b-c2a7-44dd-ae3f-814199333429)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/b8e405e3-fc8f-4610-afea-8f35b31ad7fe)

![image](https://github.com/seaaralee/data-structure-assignment/assets/87632337/ef07e283-2870-46e9-835a-496fa2d8291e)

Penjelasan Program :
Berikut adalah penjelasan tentang program yang mengimplementasikan struktur data pohon biner beserta berbagai operasinya, termasuk membuat, menambahkan, mengubah, menghapus node, dan menampilkan informasi tentang pohon.

- Fungsi newPohon : membuat node baru dengan data tertentu.
- Fungsi buatNode : membuat node root jika pohon kosong.
- Fungsi insertLeft dan insertRight : menambahkan node sebagai anak kiri atau kanan dari node tertentu.
- update : mengubah data pada node tertentu.
- retrieve : menampilkan data node.
- find : mencari dan menampilkan informasi detail tentang node.
- showChildren : menampilkan anak-anak dari node tertentu.
- showDescendants : menampilkan semua keturunan dari node tertentu.
- preOrder, inOrder, postOrder : untuk traversal preorder, inorder, dan postorder.
- deleteTree : menghapus semua node dari pohon.
- clear : menghapus seluruh pohon.
- deleteSub : menghapus subtree dari node tertentu.
- size : menghitung jumlah node dalam pohon.
- height : menghitung tinggi pohon.
- characteristic : menampilkan ukuran, tinggi, dan rata-rata node pohon.
- findNode : mencari node dengan data tertentu dalam pohon.

## Kesimpulan

#### Tree
Tree adalah struktur data yang terdiri dari simpul-simpul yang saling terhubung dan tidak memiliki siklus. Binary tree adalah salah satu jenis tree yang memiliki setiap simpul (node) dengan paling banyak dua anak. Karakteristik utama binary tree adalah bahwa setiap node memiliki maksimal dua anak: anak kiri dan anak kanan. Binary tree dapat dibagi menjadi beberapa jenis, seperti:

- Pohon Biner Lengkap: Setiap node, kecuali daun, memiliki nol atau dua anak.
- Pohon Biner Miring: Setiap node, kecuali daun, hanya memiliki satu anak.
- Pohon Biner Penuh: Setiap node, kecuali daun, memiliki dua anak, dan semua subpohon memiliki panjang jalur yang sama.

Operasi penelusuran (traversal) dalam binary tree dibagi menjadi tiga jenis:

- Preorder: Mengunjungi node utama, kemudian node kiri, dan terakhir node kanan.
- Inorder: Mengunjungi node kiri, kemudian node utama, dan terakhir node kanan.
- Postorder: Mengunjungi node kiri, kemudian node kanan, dan terakhir node utama.

Beberapa istilah yang terkait dengan tree termasuk Root (akar), Leaf (daun), Internal node (node dalam), Edge (sisi), Level (tingkat), Height (tinggi), Depth (kedalaman), Subtree (subpohon), dan lainnya.

#### Graph
Graph adalah struktur data yang berbentuk jaringan yang terdiri dari simpul-simpul (node) dan sisi-sisi (edge) yang menghubungkan simpul-simpul tersebut. Terdapat beberapa jenis graph, di antaranya:

- Graf Berarah (Digraph): Setiap sisi memiliki arah tertentu.
- Graf Tak Berarah (Undirected Graph): Setiap sisi berlaku dua arah.
- Graf Berbobot (Weighted Graph): Setiap sisi memiliki bobot atau biaya tertentu.
- Graph dapat direpresentasikan menggunakan Matriks Keterhubungan Langsung (Adjacency Matrix), yang mencatat hubungan adjacency setiap vertex.

## Referensi

#### [1] Sindar, A, STRUKTUR DATA DAN ALGORITMADENGAN C++. Cetakan Pertama. Serang : CV.AA.RIZKY, 2018

#### [2] Bahit, M, ALGORITMA PEMROGRAMAN TERSTRUKTUR. Cetakan Pertama. Banjarmasin : Poliban Press, 2024.

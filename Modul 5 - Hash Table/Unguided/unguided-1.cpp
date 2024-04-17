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

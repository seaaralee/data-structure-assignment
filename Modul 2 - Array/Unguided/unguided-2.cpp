#include <iostream>
using namespace std;

// Main Program
int main()
{
    int x, y, z;

    // Meminta User Menginputkan Jumlah Elemen Array
    cout << "Masukkan jumlah elemen array untuk dimensi pertama : ";
    cin >> x;
    cout << "Masukkan jumlah elemen array untuk dimensi kedua : ";
    cin >> y;
    cout << "Masukkan jumlah elemen array untuk dimensi ketiga : ";
    cin >> z;

    // Deklarasi Array dari Inputan User
    int arr[x][y][z];

    // Input elemen array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Input Array [ " << i << " ][ " << j << " ][ " << k << " ] = ";
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }


    // Output elemen array
    cout << "Data Array :" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Array [ " << i << " ][ " << j << " ][ " << k << " ] = " << arr[i][j][k] << endl;
            }
        }
        cout << endl;
    }

    // Output Array Terbuat
    cout << "Array " << x << " x " << y << " x " << z << " telah dibuat!" << endl;


    // Tampilan array
    cout << "-- Tampilan Array --" << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "Array Dimensi ke-" << i + 1 << " :" << endl;
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

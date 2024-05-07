/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// MEMBALIKAN KALIMAT
string reverseSentence(string word)
{
    // membuat variable reversed
    string reversed = word;

    // library c++ untuk membalikan kata
    reverse(reversed.begin(), reversed.end());

    return reversed;
}

// MAIN PROGRAM
int main()
{
    string input;
    cout << "✎ MASUKAN KATA ATAU KALIMAT : ";
    getline(cin, input); // Menggunakan getline() untuk mengambil seluruh baris input

    string reversed = reverseSentence(input);

    cout << "↳ HASIL ( SETELAH DIBALIK ): " << reversed << endl;

    return 0;
}

/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// KONVERSI KE HURUF KECIL
string convertChar(string word)
{
    string result;

    // looping untuk setiap char
    for (char a : word)
    {
        if (isalpha(a))
        {
            result += tolower(a);
        }
    }

    // mengembalikan nilai yang sudah di convert
    return result;
}

// PENGECEKAN KATA ATAU KALIMAT
bool isPalindrom(string word)
{

    // memanggil fungsi convert, kemudian disimpan di variable word
    word = convertChar(word);

    // membuat variable reversed
    string reversed = word;

    // library c++ untuk membalikan kata
    reverse(reversed.begin(), reversed.end());
    return word == reversed;
}

// MAIN PROGRAM
int main()
{
    string input;
    cout << "✎ MASUKAN KATA ATAU KALIMAT : ";
    getline(cin, input);

    if (isPalindrom(input))
    {
        cout << " • "<< input << " • " << " ADALAH PALINDROM" << endl;
    }
    else
    {
        cout << " • "<< input << " • " << " BUKAN PALINDROM" << endl;
    }

    return 0;
}

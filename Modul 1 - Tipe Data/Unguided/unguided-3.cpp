#include <iostream>
#include <map>
#include <string>
using namespace std;

// Main Program
int main() {
    // Map dengan memuat tipe data string dan int
    map<string, int> studentAge;

    // Menambahkan data ke dalam map
    studentAge["Ara"] = 19;
    studentAge["Bintang"] = 22;
    studentAge["Choco"] = 20;

    // Input data yang akan dicari
    string nameToSearch;
    cout << "Enter student name to search: ";
    getline(cin, nameToSearch);

    // Mengakses data dari data yang dicari
    if (studentAge.find(nameToSearch) != studentAge.end()) {
        cout << "Student Name : " << nameToSearch << endl;
        cout << "Age : " << studentAge[nameToSearch] << endl;
    } else {
        cout << "Student with name " << nameToSearch << " not found." << endl;
    }

    return 0;
}

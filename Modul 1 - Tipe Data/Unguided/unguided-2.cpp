#include <iostream>
#include <string>
using namespace std;

// Struct untuk menyimpan informasi
struct StudentInfo {
    string name;
    int age;
};

// Class untuk merepresentasikan informasi
class Student {
public:
    StudentInfo studentInfo; // Objek dari struct StudentInfo

    // Inisialisasi objek
    Student(string n, int a) {
        studentInfo.name = n;
        studentInfo.age = a;
    }

    // Method untuk menampilkan informasi
    void displayInfo() {
        cout << "-- Data Added! --" << endl;
        cout << "Student Name : " << studentInfo.name << endl;
        cout << "Age : " << studentInfo.age << endl;
    }
};

// Main Program
int main() {
    string name;
    int age;

    // Input dari pengguna untuk informasi
    cout << "-- Add Student Member --" << endl;
    cout << "Enter student name : ";
    getline(cin, name);
    cout << "Enter student age : ";
    cin >> age;

    // Membuat instance dari class Student dengan nama student1
    Student student1(name, age);

    // Menampilkan informasi menggunakan method displayInfo
    student1.displayInfo();

    return 0;
}

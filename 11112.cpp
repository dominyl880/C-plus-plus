#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // เปิดไฟล์สำหรับอ่านและเขียน
    ifstream inputFile("example.txt");
    ofstream outputFile("temp.txt");

    if (!inputFile || !outputFile) {
        cerr << "ไม่สามารถเปิดไฟล์ได้" << endl;
        return 1;
    }

    // ค้นหาและแทนที่ข้อมูล
    string search = "P";
    string replace = "Q";
    string line;

    while (getline(inputFile, line)) {
        replace(line.begin(), line.end(), search.begin(), search.end(), replace.begin());
        outputFile << line << endl;
    }

    // ปิดไฟล์
    inputFile.close();
    outputFile.close();

    // ลบไฟล์เดิม
    remove("example.txt");

    // เปลี่ยนชื่อไฟล์
    rename("temp.txt", "example.txt");

    cout << "แก้ไขข้อมูลเรียบร้อย" << endl;

    return 0;
}

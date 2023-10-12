#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // เปิดไฟล์เพื่อเขียน (โดยใช้ mode append)
    ofstream outputFile("example.dat", ios::app);

    // ตรวจสอบว่าไฟล์ถูกเปิดหรือไม่
    if (outputFile.is_open()) {
        // เพิ่มข้อมูลต่อจาก record เดิม
        outputFile << "New Data\n";
        outputFile << 123 << '\n';

        // ปิดไฟล์
        outputFile.close();
        cout << "Data has been added to the file.\n";
    } else {
        cerr << "Unable to open the file.\n";
    }

    return 0;
}

//#include <iostream>
//#include <iomanip>
//#include <vector>

// ฟังก์ชันที่ใช้ในการตกแต่งและสร้างตาราง
void printTable(const std::vector<std::vector<std::string>>& data, char borderChar, char paddingChar) {
    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout<<borderChar << std::setw(cell.length() + 2) << std::left << cell << borderChar;
        }
        std::cout<<std::endl;

        for (const auto& cell : row) {
            std::cout << borderChar << std::setw(cell.length() + 2) << std::setfill(paddingChar) << borderChar;
        }
        std::cout<<std::endl;
    }
}
/*int main() {
    // ตัวอย่างข้อมูลสำหรับตาราง
    std::vector<std::vector<std::string>> tableData = {
        {"Header 1", "Header 2", "Header 3"},
        {"Data 1-1", "Data 1-2", "Data 1-3"},
        {"Data 2-1", "Data 2-2", "Data 2-3"}
    };

    // ให้ | เป็นอักขระขอบ, - เป็นอักขระเส้นแบ่งแถว
    printTable(tableData, '|', '-');

    return 0;
}*/

/*#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

// ฟังก์ชันที่ใช้ในการตกแต่งและสร้างตาราง
void printTableToFile(const std::vector<std::vector<std::string>>& data, std::ofstream& outputFile, char borderChar, char paddingChar) {
    for (const auto& row : data) {
        for (const auto& cell : row) {
            outputFile << borderChar << std::setw(cell.length() + 2) << std::left << cell << borderChar;
        }
        outputFile << std::endl;

        for (const auto& cell : row) {
            outputFile << borderChar << std::setw(cell.length() + 2) << std::setfill(paddingChar) << borderChar;
        }
        outputFile << std::endl;
    }
}

int main() {
    // ตัวอย่างข้อมูลสำหรับตาราง
    std::vector<std::vector<std::string>> tableData = {
        {"Header 1", "Header 2", "Header 3"},
        {"Data 1-1", "Data 1-2", "Data 1-3"},
        {"Data 2-1", "Data 2-2", "Data 2-3"}
    };

    // เปิดไฟล์เพื่อเขียนข้อมูล
    std::ofstream outputFile("output.txt");

    if (outputFile.is_open()) {
        // ให้ | เป็นอักขระขอบ, - เป็นอักขระเส้นแบ่งแถว
        printTableToFile(tableData, outputFile, '|', '-');

        // ปิดไฟล์
        outputFile.close();
        std::cout << "Data written to output file." << std::endl;
    } else {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    return 0;
}
*/
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// // ฟังก์ชันที่ใช้ในการตกแต่งและสร้างตาราง
// void printTable(const std::vector<std::vector<std::string>>& data, char borderChar, char paddingChar) {
//     // โค้ดฟังก์ชัน printTable ที่แก้ไขแล้ว

// }

// int main() {
//     // ตัวอย่างข้อมูลสำหรับตาราง
//     std::vector<std::vector<std::string>> tableData = {
//         {"Header 1", "Header 2", "Header 3"},
//         {"Data 1-1", "Data 1-2", "Data 1-3"},
//         {"Data 2-1", "Data 2-2", "Data 2-3"}
//     };

//     // ให้ | เป็นอักขระขอบ, - เป็นอักขระเส้นแบ่งแถว
//     printTable(tableData, '|', '-');

//     // ตัวแปร PId และ Pname ถูกประกาศและให้ค่าไว้ก่อนในที่นี้
//     int PId = 123;
//     string Pname = "John Doe";

//     // ใช้ตัวแปร PId และ Pname ในที่นี้
//     cout << "Here : " << PId << " " << Pname << " ";

//     return 0;
// }

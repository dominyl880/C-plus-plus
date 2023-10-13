#include <iostream>
#include <fstream>
#include <sstream>  // เพิ่มบรรทัดนี้
#include <string>

using namespace std;

void editProductLine(const string& fileName, const string& targetProductId, const string& newProductData) {
    ifstream inFile(fileName);

    if (!inFile) {
        cerr << "Unable to open the file: " << fileName << endl;
        return;
    }

    ofstream outFile("temp.txt");

    string line;
    bool edited = false;

    while (getline(inFile, line)) {
        // แยกข้อมูลในบรรทัดเดิม
        string currentProductId, productName, typeId;
        int price, amount;
        istringstream iss(line);
        iss >> currentProductId >> productName >> typeId >> price >> amount;

        // เปรียบเทียบกับ ID ที่ต้องการแก้ไข
        if (currentProductId == targetProductId) {
            outFile << newProductData << endl;
            edited = true;
        } else {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

// ลบไฟล์เดิมและเปลี่ยนชื่อไฟล์ชั่วคราวเป็นชื่อไฟล์หลัก
    if (remove(fileName.c_str()) != 0) {
        cerr << "Unable to remove the original file: " << fileName << endl;
        return;
    }

    if (rename("temp.txt", fileName.c_str()) != 0) {
        cerr << "Unable to rename the temporary file." << endl;
    }

    if (edited) {
        cout << "Product information updated successfully." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

int main() {
    // ตัวอย่างการใช้งาน
    string targetProductId = "P1";
    string newProductData = "P1 Pen T1 7 3";
    editProductLine("product.txt", targetProductId, "P1 yanisa T1 5 5");

    return 0;
}

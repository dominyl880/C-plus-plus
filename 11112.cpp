#include <iostream>
#include <fstream>

using namespace std;

void deleteProductLine(const string& fileName, const string& targetProductId);

int main() {
    deleteProductLine("product.txt", "P1");
    return 0;
}

void deleteProductLine(const string& fileName, const string& targetProductId) {
    ifstream inFile(fileName);
    ofstream outFile("temp.txt");

    string line;
    bool deleted = false;

    while (getline(inFile, line)) {
        if (line.find(targetProductId) == string::npos) {
            outFile << line << endl;
        } else {
            deleted = true;
        }
    }

    inFile.close();
    outFile.close();

    if (remove(fileName.c_str()) != 0 || rename("temp.txt", fileName.c_str()) != 0) {
        cerr << "Unable to perform file operations." << endl;
        return;
    }

    cout << (deleted ? "Product deleted successfully." : "Product not found.") << endl;
}

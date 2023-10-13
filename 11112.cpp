#include <iostream>

int main() {
    std::string input = "P10";

    // ดึง string ออกมา
    std::string prefix = input.substr(0, 1);

    // แปลง string เป็น int
    int number = std::stoi(input.substr(1));

    std::cout << "Prefix: " << prefix << std::endl;
    std::cout << "Number: " << number << std::endl;

    return 0;
}

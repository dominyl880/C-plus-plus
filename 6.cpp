#include <iostream>
#include <cmath>

using namespace std;

// 1. ฟังก์ชันบวก (Addition)
float add(float a, float b) {
    return a + b;
}

// 2. ฟังก์ชันลบ (Subtraction)
float subtract(float a, float b) {
    return a - b;
}

// 3. ฟังก์ชันคูณ (Multiplication)
float multiply(float a, float b) {
    return a * b;
}

// 4. ฟังก์ชันหาร (Division)
float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

// 5. ฟังก์ชันยกกำลัง (Power)
float power(float base, float exponent) {
    return pow(base, exponent);
}

// 6. ฟังก์ชันรากที่สอง (Square Root)
float squareRoot(float num) {
    if (num >= 0) {
        return sqrt(num);
    } else {
        cout << "Error: Cannot calculate square root of a negative number!" << endl;
        return 0;
    }
}

// 7. ฟังก์ชันทางซ้าย (Left Shift)
int leftShift(int num, int shift) {
    return num << shift;
}

// 8. ฟังก์ชันทางขวา (Right Shift)
int rightShift(int num, int shift) {
    return num >> shift;
}

// 9. ฟังก์ชัน Modulo
int modulo(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        cout << "Error: Modulo by zero!" << endl;
        return 0;
    }
}

// 10. ฟังก์ชันค่าสัมบูรณ์ (Absolute Value)
float absoluteValue(float num) {
    return abs(num);
}

int main() {
    // ทดสอบการใช้งานฟังก์ชัน
    cout << "1 + 2 = " << add(1, 2) << endl;
    cout << "5 - 3 = " << subtract(5, 3) << endl;
    cout << "4 * 6 = " << multiply(4, 6) << endl;
    cout << "8 / 2 = " << divide(8, 2) << endl;
    cout << "2^3 = " << power(2, 3) << endl;
    cout << "Square root of 9 = " << squareRoot(9) << endl;
    cout << "5 left-shifted by 2 = " << leftShift(5, 2) << endl;
    cout << "8 right-shifted by 1 = " << rightShift(8, 1) << endl;
    cout << "10 modulo 3 = " << modulo(10, 3) << endl;
    cout << "Absolute value of -7.5 = " << absoluteValue(-7.5) << endl;

    return 0;
}

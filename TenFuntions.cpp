#include<iostream>
using namespace std;

// 1. ฟังก์ชันบวก
float add(float a, float b) {
    return a + b;
}
// 2. ฟังก์ชันลบ
float sub(float a, float b) {
    return a - b;
}
// 3. ฟังก์ชันคูณ
float multiply(float a, float b) {
    return a * b;
}
// 4. ฟังก์ชันหาร
float divide(float a, float b) {
    return a / b;
}
// 5. ฟังก์ชันหารเอาเศษ
int modulo(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        cout << "Error: Modulo by zero!" << endl;
        return 0;
    }
}
// 6. ฟังก์ชันยกกำลัง (Power)
float power(float a, float b) {
    float result = 1;
    for (int i = 0; i < b; ++i) {
        result *= a;
    }
    return result;
}
// 7. ฟังก์ชันรากที่สอง (Square Root)
float squareroot(float a) {
    if (a >= 0) {
        float guess = a / 2;  // ใช้วิธีทางทฤษฎี Newton-Raphson
        for (int i = 0; i < 10; ++i) {
            guess = 0.5 * (guess + a / guess);
        }
        return guess;
    } else {
        cout << "Error: Cannot calculate square root of a negative number!" << endl;
        return 0;
    }
}
// 8. ฟังก์ชันค่าสัมบูรณ์ (Absolute Value)
float absolutevalue(float a) {
    return (a < 0) ? -a : a;
}
// 9. ฟังก์ชันการสลับค่า (Swap)
void swapvalues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
// 10. ฟังก์ชันคำนวณเลขยกกำลังสาม (Cube)
float cube(float a) {
    return a * a * a;
}

int main(){
    int select;
    do{
        cout<<"-----------Cal Program-----------"<<endl;
        cout<<"-----------Select Menu-----------"<<endl;
        cout<<" 1 Add"<<endl;
        cout<<" 2 Subtract"<<endl;
        cout<<" 3 Multiply"<<endl;
        cout<<" 4 Divide"<<endl;
        cout<<" 5 Modulo"<<endl;
        cout<<" 6 Power"<<endl;
        cout<<" 7 SquareRoot"<<endl;
        cout<<" 8 Absolute Value"<<endl;
        cout<<" 9 Swap Values"<<endl;
        cout<<"10 Cube"<<endl;
        cout<<" 0 Exit"<<endl;
        cout<<"Enter Select Menu : "; cin>>select;
        if(select==1){ 
            int a,b;
            cout<<"---------Add(+)---------"<<endl;
            cout<<"Enter first number : ";
            cin>>a;
            cout<<"Enter secon number : ";
            cin>>b;
            cout<<"Output = "<<add(a,b)<<endl;
        }else if(select==2){
            int a,b;
            cout<<"---------Subtract(-)---------"<<endl;
            cout<<"Enter first number : ";
            cin>>a;
            cout<<"Enter secon number : ";
            cin>>b;
            cout<<"Output = "<<sub(a,b)<<endl;
        }else if(select==3){
            int a,b;
            cout<<"---------Multiply(*)---------"<<endl;
            cout<<"Enter first number : ";
            cin>>a;
            cout<<"Enter secon number : ";
            cin>>b;
            cout<<"Output = "<<multiply(a,b)<<endl;
        }else if(select==4){
            int a,b;
            cout<<"---------Divide(/)---------"<<endl;
            cout<<"Enter first number : ";
            cin>>a;
            cout<<"Enter secon number : ";
            cin>>b;
            cout<<"Output = "<<divide(a,b)<<endl;
        }else if(select==5){
            int a,b;
            cout<<"---------Modulo(%)---------"<<endl;
            cout<<"Enter first number : ";
            cin>>a;
            cout<<"Enter secon number : ";
            cin>>b;
            cout<<"Output = "<<modulo(a,b)<<endl;
        }else if(select==6){
            int a,b;
            cout<<"---------Power------------"<<endl;
            cout<<"Enter first number : ";
            cin>>a;
            cout<<"Enter secon number : ";
            cin>>b;
            cout<<"Output = "<<power(a,b)<<endl; 
        }else if(select==7){
            int a;
            cout<<"---------SquareRoot--------"<<endl;
            cout<<"Enter SquareRoot : ";
            cin>>a;
            cout<<"Output = "<<squareroot(a)<<endl; 
        }else if(select==8){
            float a;
            cout<<"---------Absolute Value--------"<<endl;
            cout<<"Enter Absolute value : ";
            cin>>a;
            cout<<"Output = "<<absolutevalue(a)<<endl; 
        }else if(select==9){
            int a,b;
            cout<<"---------Swap Values------------"<<endl;
            cout<<"Enter first number : ";
            cin>>a;
            cout<<"Enter secon number : ";
            cin>>b;
            cout<<"Before = "<<a<<"  "<<b<<endl; 
            swapvalues(a,b); 
            cout<<"After  = "<<a<<"  "<<b<<endl; 
        }else if(select==10){
            int a;
            cout<<"---------Cube------------"<<endl;
            cout<<"Enter cube number : ";
            cin>>a;
            cout<<"Output = "<<cube(a)<<endl; 
        }
    }while(select!=0);
    return(0);
}
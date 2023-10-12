#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


void ReadProduct();

void addProduct();


int main(){
   

    char sell;
    do{
        cout<<"Enter choice -> "; cin>>sell;
        if(sell=='l'){
            ReadProduct();
        }else if(sell=='a'){
            addProduct();
        }
    }while(sell!='x');
    
    return(0);
}

// อ่าน product
void ReadProduct(){

    string FileProduct="product",FileType="type";
    ifstream InFile,InFileType;
    ofstream OutFile;
    
    string PId2,TId2,PId,Pname,TId,type_id,type_name;
    int Price,Pamount,t2,t3;
    long round=1000000000;

    // หาจำนวนข้อมูลทั้งหมดที่มี
    InFile.open(FileProduct.c_str());
        for(int n = 1 ; n <= round ; n++) {
            InFile>>PId>>Pname>>TId>>Price>>Pamount;
            if(PId==PId2){
                t2=n-1;
                break;
            }
            PId=PId2;
        }
    InFile.close();

    // แสดงผล
    InFile.open(FileProduct.c_str());
        for(int i=1;i<=t2;i++){
            InFile>>PId>>Pname>>TId>>Price>>Pamount;
            cout<<"Here :  "<<PId<<" "<<Pname<<" ";

                InFileType.open(FileType.c_str());
                    for(int n = 1 ; n <= round ; n++) {
                        InFileType>>type_id>>type_name;
                            if(type_id==TId2){
                                t3=n-1;
                                break;
                            }
                            TId2=type_id;
                    }
                InFileType.close();

                InFileType.open(FileType.c_str());
                    for(int i2=1;i2<=t3;i2++){
                        InFileType>>type_id>>type_name;
                        if(type_id==TId){
                            cout<<type_name<<"  ";
                        }
                    }
                InFileType.close();
        
            cout<<Price<<"   "<<Pamount<<endl;
        }
    InFile.close();
    


}

// เพิ่มข้อมูล product
void addProduct(){
    
        string name,Pid,type_id;
        int price,amount,numpro;

        ofstream OutFile("product", ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
        cout<<"Enter number of product : "; cin>>numpro;

        // ตรวจสอบว่าไฟล์ถูกเปิดหรือไม่
        if (OutFile.is_open()){
            // เพิ่มข้อมูลต่อจาก record เดิม
            for(int i=1;i<=numpro;i++){
                cout<<endl;

                cout<<"order = "<<i<<endl; 
                cout<<"Enter Pid : "; cin>>Pid;
                cout<<"Enter name : "; cin>>name;
                cout<<"Enter type_id : "; cin>>type_id;
                cout<<"Enter price : "; cin>>price;
                cout<<"Enter amount : "; cin>>amount;

                OutFile << Pid << " " << name << " "<<type_id<<" ";
                OutFile << price << " " << amount << endl;
            }

            // ปิดไฟล์
            OutFile.close();
            cout << "Data has been added to the file.\n";
        } else {
            cerr << "Unable to open the file.\n";
        }


}
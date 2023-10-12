#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void lastrowproduct(int &t);

void ReadProduct();

void addProduct();

    string FileProduct="product",FileType="type";
    ifstream InFile,InFileType;
    ofstream OutFile;

    string PId2,TId2,PId,Pname,TId,type_id,type_name;
    int Price,Pamount,t2,t3;
    long round=1000000000;

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

void lastrowproduct(int &t){
    // หาจำนวนข้อมูลทั้งหมดที่มี
    int n=1;
    InFile.open(FileProduct.c_str());
        while(n>0){
            InFile>>PId>>Pname>>TId>>Price>>Pamount;
            // cout<<endl;
            // cout<<PId<<"   "<<PId2;
            // cout<<endl;
                if(PId2==PId){
                    t2=n-1;
                    break;
                }
            PId2=PId;
            n++;
        } 
    InFile.close();
}

// อ่าน product
void ReadProduct(){
    // string PId2,TId2,PId,Pname,TId,type_id,type_name;
    // int Price,Pamount,t2,t3;
    // long round=1000;

    // หาจำนวนข้อมูลทั้งหมดที่มี
    // t2=0;
    lastrowproduct(t2);
    cout<<"list = "<<t2<<endl;
    // t2=5;
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
    
        string name,type_id;
        int price,amount,numpro;

        ofstream OutFile("product", ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
        cout<<"Enter number of product : "; cin>>numpro;
        lastrowproduct(t2);
        // ตรวจสอบว่าไฟล์ถูกเปิดหรือไม่
        if (OutFile.is_open()){
            // เพิ่มข้อมูลต่อจาก record เดิม
            for(int i=1;i<=numpro;i++){
                cout<<endl;

                string Rid;
                stringstream ss;
                ss << (t2+1);
                Rid="P"+ss.str();

                cout<<"order = "<<i<<endl; 
                cout<<"Enter Pid : "<<Rid<<endl;
                cout<<"Enter name : "; cin>>name;
                cout<<"Enter type_id : "; cin>>type_id;
                cout<<"Enter price : "; cin>>price;
                cout<<"Enter amount : "; cin>>amount;

                OutFile << Rid << " " << name << " "<<type_id<<" ";
                OutFile << price << " " << amount << endl;
            }

            // ปิดไฟล์
            OutFile.close();
            cout << "Data has been added to the file.\n";
        } else {
            cerr << "Unable to open the file.\n";
        }


}
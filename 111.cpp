#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void lastrowproduct(int &p);
void lastrowtype(int &t);


void ReadProduct();
void addProduct();

void ReadType();
void addType();


    string FileProduct="product",FileType="type";
    ifstream InFile,InFileType;
    ofstream OutFile;

    string PId2,PId,Pname,TId2,TId,Tname;
    int Price,Pamount,t2,t3;
    // long round=1000000000;

int main(){
   

    string sell;
    do{

        cout<<"pass lp to show list product."<<endl;
        cout<<"pass lt to show list type."<<endl;
        cout<<"pass ap to add product."<<endl;
        cout<<"pass at to add type."<<endl;

        cout<<"Enter choice -> "; cin>>sell;
        cout<<endl;
        if(sell=="lp"){
            ReadProduct();
        }else if(sell=="ap"){
            addProduct();
        }else if(sell=="lt"){
            ReadType();
        }else if(sell=="at"){
            addType();
        }
        
        cout<<endl;

    }while(sell!="x");
    
    return(0);
}

// หาล่าสุดของสินค้า
void lastrowproduct(int &p){
    // หาจำนวนข้อมูลทั้งหมดที่มี-สินค้า
    int n=1;
    InFile.open(FileProduct.c_str());
        while(n>0){
            InFile>>PId>>Pname>>TId>>Price>>Pamount;
                if(PId2==PId){
                    t2=n-1;
                    break;
                }
            PId2=PId;
            n++;
        } 
    InFile.close();
}

// หาล่าสุดของประเภท
void lastrowtype(int &t){
    // หาจำนวนข้อมูลทั้งหมดที่มี-สินค้า
    int n=1;
    InFileType.open(FileType.c_str());
        while(n>0){
            InFileType>>TId>>Tname;
                if(TId2==TId){
                    t3=n-1;
                    break;
                }
            TId2=TId;
            n++;
        } 
    InFileType.close();
}

// อ่าน product
void ReadProduct(){
    // หาจำนวนข้อมูลทั้งหมดที่มี
    // t2=0;
    lastrowproduct(t2);
    // cout<<"list = "<<t2<<endl;
    lastrowtype(t3);
    // cout<<"list type = "<<t3<<endl;

    // t2=5;
    // แสดงผล
    InFile.open(FileProduct.c_str());
        for(int i=1;i<=t2;i++){
            InFile>>PId>>Pname>>TId>>Price>>Pamount;
            cout<<"Here :  "<<PId<<" "<<Pname<<" ";

                InFileType.open(FileType.c_str());
                    for(int i2=1;i2<=t3;i2++){
                        InFileType>>TId2>>Tname;
                        if(TId2==TId){
                            // cout<<Tname<<"  ";
                            break;
                        }
                        TId2=TId;
                    }
                InFileType.close();

            cout<<Price<<"   "<<Pamount<<endl;
        }
    InFile.close();
    


}

// เพิ่มข้อมูล product
void addProduct(){
        string name,type_id,Rid,Rid2,Rid3;
        int price,amount,numpro;
        bool tc=false;

        ofstream OutFile(FileProduct, ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
        cout<<"Enter number of product : "; cin>>numpro; // เลือกจำนวนที่จะเพิ่มรายการสินค้า
        lastrowproduct(t2);
        lastrowtype(t3);

         // ตรวจสอบว่าไฟล์ถูกเปิดหรือไม่
        if (OutFile.is_open()){
            // เพิ่มข้อมูลต่อจาก record เดิม
            for(int i=1;i<=numpro;i++){
                cout<<endl;

                InFile.open(FileProduct,ios::app);
                    for(int p=1;p<=t2;p++){
                        InFile>>Rid>>Pname>>TId>>Price>>Pamount;
                    }
                InFile.close();
                
                if(Rid==""){
                    Rid="P0";
                }

                // ดึง string ออกมา
                string prefix = Rid.substr(0, 1);
                // แปลง string เป็น int
                int number = stoi(Rid.substr(1));
                
                stringstream ss;
                ss << (number+1);
                Rid=prefix+ss.str();

                cout<<"order = "<<i<<endl; 
                cout<<"Enter PId : "<<Rid<<endl;
                cout<<"Enter name : "; cin>>name;

                // type_id
                        do{
                            cout<<"Enter type_id : "; cin>>type_id;
                                InFileType.open(FileType, ios::app);
                                for(int i2=1;i2<=t3;i2++){
                                    InFileType>>TId2>>Tname;
                                    cout<<TId2<<"  ";
                                    if(TId2==type_id){
                                        cout<<" = "<<type_id<<endl;
                                        tc=true;
                                    }
                                }
                                InFileType.close();
                                if(tc==false){ cout<<"Try again."<<endl; }
                        }while(tc!=true);
                        tc=false;
                
                cout<<"Enter price : "; cin>>price;
                cout<<"Enter amount : "; cin>>amount;

                OutFile << Rid << " " << name << " "<<type_id<<" ";
                OutFile << price << " " << amount << endl;

                cout<<"Complete!"<<endl;
                t2++;
            }

            // ปิดไฟล์
            OutFile.close();
        } else {
            cerr << "Unable to open the file.\n";
        }


}




// อ่าน product
void ReadType(){
    lastrowtype(t3);
    cout<<"list type = "<<t3<<endl;

    InFileType.open(FileType.c_str());
        for(int i2=1;i2<=t3;i2++){
            InFileType>>TId>>Tname;
            cout<<"Here :  "<<TId<<" "<<Tname<<" "<<endl;
        }
    InFileType.close();

}

// เพิ่มข้อมูล product
void addType(){
        string name,Rid,Rid2;
        int numpro;

        ofstream OutFileType(FileType, ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
        cout<<"Enter number of type : "; cin>>numpro; // เลือกจำนวนที่จะเพิ่มรายการสินค้า
        lastrowtype(t3);
        // cout<<"t3 = "<<t3<<endl;

         // ตรวจสอบว่าไฟล์ถูกเปิดหรือไม่
        if (OutFileType.is_open()){
            // เพิ่มข้อมูลต่อจาก record เดิม
            for(int i=1;i<=numpro;i++){
                cout<<endl;
                // cout<<"i = "<<i<<endl;
                InFileType.open(FileType,ios::app);
                    for(int p=1;p<=t3;p++){
                        InFileType>>Rid>>Tname;
                    }
                InFileType.close();

                cout<<endl;

                if(Rid==""){
                    Rid="T0";
                }
                
                cout<<Rid<<endl;
         
                // ดึง string ออกมา
                string prefix = Rid.substr(0, 1);
                // แปลง string เป็น int
                int number = stoi(Rid.substr(1));
                
                stringstream ss;
                ss << (number+1);
                Rid=prefix+ss.str();

                cout<<"order = "<<i<<endl; 
                cout<<"Enter TId : "<<Rid<<endl;
                cout<<"Enter name : "; cin>>name;
  

                OutFileType << Rid << " " << name<<endl;

                cout<<"Complete!"<<endl;
                t3++;

            }

            // ปิดไฟล์
            OutFileType.close();
        } else {
            cerr << "Unable to open the file.\n";
        }


}


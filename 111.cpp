#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


void ReadProduct();

int main(){
    ReadProduct();
    return(0);
}

void ReadProduct(){
    string FileProduct,FileType;
    ifstream InFile,InFileType;
    ofstream OutFile;
    
    FileProduct="product"; 
    FileType="type"; 



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

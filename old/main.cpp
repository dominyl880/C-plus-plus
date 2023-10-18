#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
//#include "table.cpp"
using namespace std;


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

void ReadProduct();

int main(){
    ReadProduct();
    return(0);
}

void ReadProduct(std::vector<std::vector<std::string>>& tableData){
    string FileProduct,FileType;
    ifstream InFile,InFileType;
    ofstream OutFile;
    
    FileProduct="product"; 
    FileType="type"; 



    string PId2,TId2,PId,Pname,TId,type_id,type_name;
    int Price,Pamount,t2,t3;
    long round=1000000000;
    const int columnWidth = 10;


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
            std::vector<std::vector<std::string>> products = {
                {"Here : ", PId, Pname}
            };
            printTable(tableData, '|', '-');
            //cout<<"Here :  "<<PId<<" "<<Pname<<" ";

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
            // ให้ | เป็นอักขระขอบ, - เป็นอักขระเส้นแบ่งแถว
            //printTable(tableData, '|', '-');
        }
    InFile.close();
    


}




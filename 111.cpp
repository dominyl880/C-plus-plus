#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

void lastrowproduct(int &p);
void lastrowtype(int &t);


void ReadProduct();
void addProduct();
void editproduct();


void ReadType();
void addType();
void edittype();

    string FileProduct="product.txt",FileType="type";
    ifstream InFile,InFileType;
    ofstream OutFile;

    string PId2,PId,Pname,TId2,TId,Tname;
    int Price,Pamount,t2,t3;

int main(){
   

    string sell;
    do{

        cout<<"pass lp to show list product."<<endl;
        cout<<"pass lt to show list type."<<endl;
        cout<<"pass ap to add product."<<endl;
        cout<<"pass at to add type."<<endl;
        cout<<"pass ep to edit type."<<endl;
        cout<<"pass et to edit type."<<endl;


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
        }else if(sell=="ep"){
            editproduct();
        }else if(sell=="et"){
            edittype();
        }
        
        cout<<endl;

    }while(sell!="x");
    
    return(0);
}

// หาล่าสุดของประเภท
void lastrowtype(int &t){
    int n=1;
    InFileType.open(FileType.c_str());
        while(n>0){
            InFileType>>TId>>Tname;
                if(TId==TId2){
                    t3=n-1;
                    break;
                }
            TId2=TId;
            n++;
        } 
    InFileType.close();
}

// หาล่าสุดของสินค้า
void lastrowproduct(int &p){
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



// อ่าน product
void ReadProduct(){
    // หาจำนวนข้อมูลทั้งหมดที่มี
    lastrowproduct(t2); 
    lastrowtype(t3);  

    // แสดงผล
    InFile.open(FileProduct,ios::app);
        for(int i=1;i<=t2;i++){
            InFile>>PId>>Pname>>TId>>Price>>Pamount;
            cout<<"Here :  "<<PId<<" "<<Pname<<" ";

                InFileType.open(FileType,ios::app);
                    for(int i2=1;i2<=t3;i2++){
                        InFileType>>TId2>>Tname;
                        if(TId==TId2){
                            cout<<Tname<<" ";
                            break;
                        }
                    }
                InFileType.close();

            cout<<Price<<"   "<<Pamount<<endl;
        }
    InFile.close();


    // return(0);
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
                                    if(TId2==type_id){ 
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

void editproduct() {
    bool ep = false, tc = false;
    char anw;
    string row;
    
    lastrowproduct(t2);
    lastrowtype(t3);

    do {
        
        cout << "Enter PId : ";
        cin >> PId;
        InFile.open(FileProduct.c_str());

        for (int i = 1; i <= t2; i++) {
            InFile >> PId2 >> Pname >> TId >> Price >> Pamount;

            if (PId == PId2) {
                cout << PId2 << "  " << Pname << "  " << TId << Price << "  " << Pamount;
                cout << endl;
                cout << "==New data==" << endl;

                do {
                    cout << "Do you want to edit Name? (Y/N) : ";
                    cin >> anw;
                    if (anw == 'Y') {
                        cout << "New Name : ";
                        cin >> Pname;
                        cout << "Completed." << endl;
                        anw = 'N';
                    }
                    else if (anw == 'N') {
                        cout << "You have skipped." << endl;
                    }
                    else {
                        cout << "Try again." << endl;
                    }
                } while (anw != 'N');

                do {
                    cout << "Do you want to edit Type? (Y/N) : ";
                    cin >> anw;
                    if (anw == 'Y') {
                        // type_id
                        do {
                            cout << "New Type : ";
                            cin >> TId;
                            InFileType.open(FileType);
                                for (int i2 = 1; i2 <= t3; i2++) {
                                    InFileType >> TId2 >> Tname;
                                    cout<<TId<<" "<<Tname<<endl;
                                    if (TId2 == TId) {
                                        tc = true;
                                    }
                                }
                            InFileType.close();
                            if (tc == false) { cout << "Try again." << endl; }
                        } while (tc != true);
                        tc = false;
                        cout << "Completed." << endl;
                        anw = 'N';
                    }
                    else if (anw == 'N') {
                        cout << "You have skipped." << endl;
                    }
                } while (anw != 'N');

                do {
                    cout << "Do you want to edit Price? (Y/N) : ";
                    cin >> anw;
                    if (anw == 'Y') {
                        cout << "New Price : ";
                        cin >> Price;
                        cout << "Completed." << endl;
                        anw = 'N';
                    }
                    else if (anw == 'N') {
                        cout << "You have skipped." << endl;
                    }
                    else {
                        cout << "Try again." << endl;
                    }
                } while (anw != 'N');

                do {
                    cout << "Do you want to edit Amount? (Y/N) : ";
                    cin >> anw;
                    if (anw == 'Y') {
                        cout << "New Amount : ";
                        cin >> Pamount;
                        cout << "Completed." << endl;
                        anw = 'N';
                    }
                    else if (anw == 'N') {
                        cout << "You have skipped." << endl;
                    }
                    else {
                        cout << "Try again." << endl;
                    }
                } while (anw != 'N');
                cout << endl;
                

                // -------------------------------------------------------
                stringstream price_in,amount_in;
                price_in <<(Price);
                amount_in <<(Pamount);

                // ss << (c+1);
                row=PId+" "+Pname+" "+TId+" "+price_in.str()+" "+amount_in.str();
                cout<<row<<endl;

                editProductLine("product.txt", PId, row);
                
                // -------------------------------------------------
            }
        }
        InFile.close();
        ep = true;
    } while (ep != true);
}


// อ่าน product
void ReadType(){
    cout<<"list type = "<<t3<<endl;
    InFileType.open("type.txt",ios::app);
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

         // ตรวจสอบว่าไฟล์ถูกเปิดหรือไม่
        if (OutFileType.is_open()){
            // เพิ่มข้อมูลต่อจาก record เดิม
            for(int i=1;i<=numpro;i++){
                cout<<endl;

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

void edittype(){
    
}



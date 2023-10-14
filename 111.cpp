#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include <sstream>  // เพิ่มบรรทัดนี้


using namespace std;

void deleteProductLine(const string& fileName, const string& targetProductId);


void editProductLine(const string& fileName2, const string& targetProductId, const string& newProductData);
void editTypeLine(const string& fileName2, const string& targetProductId, const string& newProductData);

void lastrowproduct(int &p);
void lastrowtype(int &t);
void lastrowsale(int &sa);



void ReadProduct();
void addProduct();
void editproduct();
void delproduct();



void ReadType();
void addType();
void edittype();
void deltype();

void readsale();
void addsale();



    string FileProduct="product.txt",FileType="type.txt",FileSale="sale.txt";
    ifstream InFile,InFileType,InFileSale;
    ofstream OutFile;


    string PId2,PId,Pname,TId2,TId,Tname,SId2,SId;
    int Price,Pamount,Samount,t2,t3,t4;
    float Total=0;
int main(){
    string sell;
    do{
        cout<<"pass lp to show list product."<<endl;
        cout<<"pass lt to show list type."<<endl;
        cout<<"pass ap to add product."<<endl;
        cout<<"pass at to add type."<<endl;
        cout<<"pass ep to edit product."<<endl;
        cout<<"pass et to edit type."<<endl;
        cout<<"pass dp to delete product."<<endl;
        cout<<"pass dt to delete type."<<endl;
        cout<<"pass ls to show list sale."<<endl;
        cout<<"pass as to add sale."<<endl;


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
        }else if(sell=="dp"){
            delproduct();
        }else if(sell=="dt"){
            deltype();
        }else if(sell=="ls"){
            readsale();
        }else if(sell=="as"){
            addsale();
        }
        
        cout<<endl;

    }while(sell!="x");
    
    return(0);
}

//delete product
void deleteProductLine(const string& fileNameD, const string& targetProduct) {
    ifstream inFileP(fileNameD);
    ofstream outFileP("temp.txt");

    string line;
    bool deleted = false;

    while (getline(inFileP, line)) {
        if (line.find(targetProduct) == string::npos) {
            outFileP << line << endl;
        } else {
            deleted = true;
        }
    }

    inFileP.close();
    outFileP.close();

    if (remove(fileNameD.c_str()) != 0 || rename("temp.txt", fileNameD.c_str()) != 0) {
        cerr << "Unable to perform file operations." << endl;
        return;
    }

    // cout << (deleted ? "Product deleted successfully." : "Product not found.") << endl;
}





// update product
void editProductLine(const string& fileName2, const string& targetProductId, const string& newProductData) {
    ifstream inFile2(fileName2);

    if (!inFile2) {
        cerr << "Unable to open the file: " << fileName2 << endl;
        return;
    }

    ofstream outFile2("temp.txt");

    string line;
    bool edited = false;

    while (getline(inFile2, line)) {
        // แยกข้อมูลในบรรทัดเดิม
        string currentProductId, productName, typeId;
        int price, amount;
        istringstream iss(line);
        iss >> currentProductId >> productName >> typeId >> price >> amount;

        // เปรียบเทียบกับ ID ที่ต้องการแก้ไข
        if (currentProductId == targetProductId) {
            outFile2 << newProductData << endl;
            edited = true;
        } else {
            outFile2 << line << endl;
        }
    }

    inFile2.close();
    outFile2.close();

// ลบไฟล์เดิมและเปลี่ยนชื่อไฟล์ชั่วคราวเป็นชื่อไฟล์หลัก
    if (remove(fileName2.c_str()) != 0) {
        cerr << "Unable to remove the original file: " << fileName2 << endl;
        return;
    }

    if (rename("temp.txt", fileName2.c_str()) != 0) {
        cerr << "Unable to rename the temporary file." << endl;
    }

    if (edited) {
        // cout << "Completed." << endl;
    } else {
        cout << "Product not found." << endl;
    }
}

// update type
void editTypeLine(const string& fileName2, const string& targetTypeId, const string& newTypeData) {
    ifstream inFile2(fileName2);

    if (!inFile2) {
        cerr << "Unable to open the file: " << fileName2 << endl;
        return;
    }

    ofstream outFile2("temp.txt");

    string line;
    bool edited = false;

    while (getline(inFile2, line)) {
        // แยกข้อมูลในบรรทัดเดิม
        string currentTypeId, TypeName;
        istringstream iss(line);
        iss >> currentTypeId >> TypeName;

        // เปรียบเทียบกับ ID ที่ต้องการแก้ไข
        if (currentTypeId == targetTypeId) {
            outFile2 << newTypeData << endl;
            edited = true;
        } else {
            outFile2 << line << endl;
        }
    }

    inFile2.close();
    outFile2.close();

// ลบไฟล์เดิมและเปลี่ยนชื่อไฟล์ชั่วคราวเป็นชื่อไฟล์หลัก
    if (remove(fileName2.c_str()) != 0) {
        cerr << "Unable to remove the original file: " << fileName2 << endl;
        return;
    }

    if (rename("temp.txt", fileName2.c_str()) != 0) {
        cerr << "Unable to rename the temporary file." << endl;
    }

    if (edited) {
        // cout << "Completed." << endl;
    } else {
        cout << "Type not found." << endl;
    }
}

// หาล่าสุดของสินค้า
void lastrowproduct(int &p){
    int n=1;
    string a,b,c,a2;
    int d,e;
    InFile.open(FileProduct.c_str());
        while(n>0){
            InFile>>a>>b>>c>>d>>e;
            // cout<<a<<endl;
                if(a2==a){
                    t2=n-1;
                    break;
                }
            a2=a;
            n++;
        } 
    InFile.close();
}

// หาล่าสุดของประเภท
void lastrowtype(int &t){
    int n=1;
    string f,f2,z;

    InFileType.open(FileType.c_str());
        while(n>0){
            InFileType>>f>>z;
                if(f==f2){
                    t3=n-1;
                    break;
                }
            f2=f;
            n++;
        } 
    InFileType.close();
}

// หาล่าสุดของประเภท
void lastrowsale(int &sa){
    int n=1;
    string sa1,sa2,m;
    int sm;
    float to;

    InFileSale.open(FileSale.c_str());
        while(n>0){
            InFileSale>>sa1>>m>>sm>>to;
                if(sa1==sa2){
                    t4=n-1;
                    break;
                }
            sa2=sa1;
            n++;
        } 
    InFileSale.close();
}

// ------------------------------------------------------
// อ่าน product
void ReadProduct(){
    // หาจำนวนข้อมูลทั้งหมดที่มี
    lastrowproduct(t2);
    lastrowtype(t3);  
    cout<<"list product = "<<t2<<endl;
    // cout<<"list type = "<<t3<<endl;


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
                        }
                    }
                InFileType.close();

            cout<<Price<<" "<<Pamount<<endl;
        }
    InFile.close();
}

// เพิ่มข้อมูล product
void addProduct(){
        string name,type_id,Rid,Rid2,Rid3;
        int price,amount,numpro;
        bool tc=false;

        ofstream OutFile(FileProduct, ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
        do{
            cout<<"Enter 0 to exit."<<endl;
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

        }while(numpro!=0);
        


}

// แก้ไขสินค้า
void editproduct() {
    bool ep = false, tc = false;
    string targetProductId;
    string row; 
    char anw;
    
    lastrowproduct(t2);
    lastrowtype(t3);

    do { 
        cout<<"Enter X to exit."<<endl;

        cout << "Enter PId : ";
        cin >> PId;
        InFile.open(FileProduct.c_str());

        for (int i = 1; i <= t2; i++) {
            InFile >> PId2 >> Pname >> TId >> Price >> Pamount;

            if (PId == PId2) {
                cout << PId2 << " " << Pname << " " << TId <<" "<< Price << " " << Pamount;
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
                                    cout<<TId<<endl;
                                    if (TId2 == TId) {
                                        // cout<<TId<<endl;

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
                
                row=PId+" "+Pname+" "+TId+" "+price_in.str()+" "+amount_in.str();
                targetProductId=PId;
                // -------------------------------------------------               
            }
        }
        InFile.close();
                
        editProductLine(FileProduct, targetProductId, row);
        if(PId=="X"){
            ep = true;
        }
    } while (ep != true);
}

void delproduct(){
    char anw;
    bool del=false;
    do{
        cout<<"Enter X to exit."<<endl;
        lastrowproduct(t2);
        cout<<"Enter PId : "; cin>>PId;
        InFile.open(FileProduct.c_str());
            for (int i = 1; i <= t2; i++) {
                InFile >> PId2 >> Pname >> TId >> Price >> Pamount;
                // cout<<PId2<<endl;
                if(PId == PId2) {
                    cout << PId2 << " " << Pname << " " << TId <<" "<< Price << " " << Pamount<<endl;
                    cout << "==Delete data==" << endl;
                    do {
                        cout << "Do you want to delete "<<Pname<<" ? (Y/N) : ";
                        cin >> anw;
                        if (anw == 'Y') {
                            cout<<"Completed."<<endl;
                            anw='N';
                            del=true;
                        }
                        else if (anw == 'N') {
                            cout << "You have skipped." << endl;
                        }
                        else {
                            cout << "Try again." << endl;
                        }
                    }while (anw != 'N');
                    cout << endl;
                }
            }
       
        InFile.close();
        if(del==true){
            // -------------------------------------------------------
                deleteProductLine(FileProduct, PId);
            // -------------------------------------------------------
        }   
    }while(PId!="X");
}

// -----------------------------------------------------

// อ่าน product
void ReadType(){
    lastrowtype(t3); 
    cout<<"list type = "<<t3<<endl;
    InFileType.open(FileType,ios::app);
        for(int i=1;i<=t3;i++){
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
        do{
            cout<<"Enter 0 to exit."<<endl;
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
                    
                    // cout<<Rid<<endl;
            
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
        }while(numpro!=0);



}

// แก้ไขประเภท
void edittype(){
    bool ep = false, tc = false;
    char anw;
    string targetProductId;
    string row; 
    
    lastrowtype(t3);

    do {
        cout<<"Enter X to exit."<<endl;

        cout << "Enter TId : ";
        cin >> TId;
        InFile.open(FileType.c_str());

        for (int i = 1; i <= t3; i++) {
            InFile >> TId2 >> Pname ;

            if (TId == TId2) {
                cout << TId2 << "  " << Pname;
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
                cout << endl;
                
                // -------------------------------------------------------
                row=TId+" "+Pname;
                targetProductId=TId;
                // -------------------------------------------------
               
            }
        }
        InFile.close();
                
        editTypeLine("type.txt", targetProductId, row);
        if(PId=="X"){
            ep = true;
        }
    } while (ep != true);

}

void deltype(){
    char anw;
    bool del=false;
    do{
        cout<<"Enter X to exit."<<endl;
        lastrowtype(t3);
        cout<<"Enter TId : "; cin>>TId;
        InFileType.open(FileType.c_str());
            for (int i = 1; i <= t3; i++) {
                InFileType >> TId2 >> Tname;
                // cout<<TId2<<endl;
                if(TId == TId2) {
                    cout << TId2 << " " << Tname<<endl;
                    cout << "==Delete data==" << endl;
                    do {
                        cout << "Do you want to delete "<<Tname<<" ? (Y/N) : ";
                        cin >> anw;
                        if (anw == 'Y') {
                            cout<<"Completed."<<endl;
                            anw='N';
                            del=true;
                        }
                        else if (anw == 'N') {
                            cout << "You have skipped." << endl;
                        }
                        else {
                            cout << "Try again." << endl;
                        }
                    }while (anw != 'N');
                    cout << endl;
                }
            }
       
        InFileType.close();
        if(del==true){
            // -------------------------------------------------------
                deleteProductLine(FileType, TId);
            // -------------------------------------------------------
        }   
    }while(TId!="X");

}

// ---------------------------------------------------------------
// อ่านรายการขาย
void readsale(){
    lastrowsale(t4); 
    cout<<"list sale = "<<t4<<endl;
    InFileSale.open(FileSale,ios::app);
        for(int i=1;i<=t4;i++){
            InFileSale>>SId>>PId>>Samount>>Total;
            cout<<"Here :  "<<SId<<" "<<PId<<" "<<Samount<<" "<<Total<<" "<<endl;
        }
    InFileSale.close();
}

// เพิ่มการขาย
void addsale(){
        string J1,J2,J22,row,targetProductId;
        int J3,amount,numpro,priceHere;
        bool tc=false;
        float J4;
        ofstream OutFile(FileSale, ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
            lastrowsale(t4);
            lastrowproduct(t2);
        do{
            cout<<"Enter 0 to exit."<<endl;
            cout<<"Enter number of sale list : "; cin>>numpro; // เลือกจำนวนที่จะเพิ่มรายการสินค้า


            // ตรวจสอบว่าไฟล์ถูกเปิดหรือไม่
                // เพิ่มข้อมูลต่อจาก record เดิม
                OutFile.is_open();
                for(int i=1;i<=numpro;i++){
                    cout<<endl;

                    InFileSale.open(FileSale,ios::app);
                        for(int p=1;p<=t4;p++){
                            InFileSale>>J1>>J2>>J3>>J4;
                        }
                    InFileSale.close();
                    
                    if(J1==""){
                        J1="S0";
                    }

                    // ดึง string ออกมา
                    string prefix = J1.substr(0, 1);
                    // แปลง string เป็น int
                    int number = stoi(J1.substr(1));
                    
                    stringstream ss;
                    ss << (number+1);
                    J1=prefix+ss.str();

                    cout<<"order = "<<i<<endl; 
                    cout<<"Enter SId : "<<J1<<endl;
                    

                    // PId
                            do{
                                cout<<"Enter PId : "; cin>>J2;
                                    InFile.open(FileProduct, ios::app);
                                    for(int i2=1;i2<=t2;i2++){
                                        InFile>>J22>>Pname>>TId>>Price>>Pamount;
                                        if(J22==J2){ 
                                            priceHere=Price;
                                            if(Pamount!=0){
                                                tc=true;
                                            }
                                            
                                        }
                                    }
                                    InFile.close();
                                    if(tc==false){ cout<<"Try again."<<endl; }
                            }while(tc!=true);
                            tc=false;
                    // Pamount
                             do{
                                cout<<"Enter amount : "; cin>>J3;
                                    InFile.open(FileProduct, ios::app);
                                    for(int i2=1;i2<=t2;i2++){
                                        InFile>>J22>>Pname>>TId>>Price>>Pamount;
                                        if(J22==J2){ 
                                            if(J3<=Pamount){
                                                tc=true;
                                            }
                                            
                                        }
                                    }
                                    InFile.close();
                                    if(tc==false){ cout<<"Over limit."<<endl; }
                            }while(tc!=true);
                            tc=false; 
                    
                    J4=J3*priceHere;
                    cout<<"Total = "<<J4<<endl;

                    OutFile << J1 << " " << J2 << " ";
                    OutFile << J3 << " " << J4 << endl;

                    stringstream price_in,amount_in;
                    price_in <<(Price);
                    amount_in <<(Pamount-J3);

                    row=J22+" "+Pname+" "+TId+" "+price_in.str()+" "+amount_in.str();
                    targetProductId=J22;
                    
                    // cout<<row<<endl;
                    
                    cout<<"Complete!"<<endl;
                    t4++;

                // ปิดไฟล์
                
 
                }
                    OutFile.close();
                    editProductLine(FileProduct, targetProductId, row);

        }while(numpro!=0);
        


}
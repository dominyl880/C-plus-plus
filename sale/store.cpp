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
        cout<<"=============================|   General Store   |============================="<<endl;
        cout<<setw(56)<<"Pass [lp] To Show List Product."<<endl;
        cout<<setw(53)<<"Pass [lt] To Show List Type."<<endl;
        cout<<setw(53)<<"Pass [ls] To Show List Sale."<<endl;
        cout<<setw(50)<<"Pass [ap] To Add Product."<<endl;
        cout<<setw(47)<<"Pass [at] To Add Type."<<endl;
        cout<<setw(47)<<"Pass [as] To Add Sale."<<endl;
        cout<<setw(51)<<"Pass [ep] To Edit Product."<<endl;
        cout<<setw(48)<<"Pass [et] To Edit Type."<<endl;
        cout<<setw(53)<<"Pass [dp] To Delete Product."<<endl;
        cout<<setw(50)<<"Pass [dt] To Delete Type."<<endl;
        cout<<"==============================================================================="<<endl;


        cout<<setw(45)<<"Enter choice -> "; cin>>sell;
        cout<<endl;
        //cout<<"-------------------------------------------------------------------------------"<<endl;
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
    int n=1,d,e;
    string a,b,c,a2;
    bool ra=false;
    InFile.open(FileProduct.c_str());
        while(ra!=true){
            InFile>>a>>b>>c>>d>>e;
            // cout<<a<<" : "<<a2<<endl;
                if(a2==a){
                    t2=n-1;
                    ra=true;
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
    cout<<setw(60)<<"===============================> List Product <================================"<<endl;  
    cout<<"list product = "<<t2<<endl;
    // cout<<"list type = "<<t3<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<setw(8)<<"PId"<<setw(16)<<"Name"<<setw(18)<<"Type"<<setw(18)<<"Price"<<setw(14)<<"Amount"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    //cout<<"PID      Pname         Type         Price   Amount"<<endl;

    // แสดงผล
    InFile.open(FileProduct,ios::app);
        for(int i=1;i<=t2;i++){
            InFile>>PId>>Pname>>TId>>Price>>Pamount;
            cout<<setw(8)<<PId<<setw(16)<<Pname;

                InFileType.open(FileType,ios::app);
                    for(int i2=1;i2<=t3;i2++){
                        InFileType>>TId2>>Tname;
                        if(TId==TId2){
                            cout<<setw(20)<<Tname;
                        }
                    }
                InFileType.close();

            cout<<setw(14)<<Price<<setw(14)<<Pamount<<endl;
        }
    InFile.close();
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

// เพิ่มข้อมูล product
void addProduct(){
        string name,type_id,Rid,Rid2,Rid3;
        int price,amount,numpro;
        bool tc=false;

        ofstream OutFile(FileProduct, ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
        do{
            cout<<setw(60)<<"================================> Add Product <================================"<<endl;
            cout<<"Enter 0 To Exit."<<endl;
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

                    cout<<setw(45)<<"order : "<<i<<endl; 
                    cout<<setw(45)<<"Enter PId : "<<Rid<<endl;
                    cout<<setw(45)<<"Enter name : "; cin>>name;

                    // type_id
                            do{
                                cout<<setw(45)<<"Enter type_id : "; cin>>type_id;
                                    InFileType.open(FileType, ios::app);
                                    for(int i2=1;i2<=t3;i2++){
                                        InFileType>>TId2>>Tname;
                                        if(TId2==type_id){ 
                                            tc=true;
                                        }
                                    }
                                    InFileType.close();
                                    if(tc==false){ cout<<setw(45)<<"Try again."<<endl; }
                            }while(tc!=true);
                            tc=false;
                    
                    cout<<setw(45)<<"Enter price : "; cin>>price;
                    cout<<setw(45)<<"Enter amount : "; cin>>amount;

                    OutFile << Rid << " " << name << " "<<type_id<<" ";
                    OutFile << price << " " << amount << endl;

                    cout<<setw(45)<<"Complete!"<<endl;
                    cout<<endl;
                    t2++;
                }

                // ปิดไฟล์
                OutFile.close();
            }

        }while(numpro!=0);
      cout<<"-------------------------------------------------------------------------------"<<endl;  
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
        cout<<setw(60)<<"================================> Edit Product <==============================="<<endl;
        cout<<"Enter X To Exit."<<endl;

        cout << "Enter PId : ";
        cin >> PId;
        InFile.open(FileProduct.c_str());

        for (int i = 1; i <= t2; i++) {
            InFile >> PId2 >> Pname >> TId >> Price >> Pamount;

            if (PId == PId2) {
                cout<<"-------------------------------------------------------------------------------"<<endl;
                cout<<setw(8)<<"PId"<<setw(16)<<"Name"<<setw(18)<<"Type"<<setw(18)<<"Price"<<setw(14)<<"Amount"<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
                //cout<<"PID      Pname         Type         Price   Amount"<<endl;

                cout <<setw(8)<<PId2<<setw(16)<<Pname<<setw(14)<<TId;
                            InFileType.open(FileType);
                                for (int i5 = 1; i5 <= t3; i5++) {
                                    InFileType >> TId2 >> Tname;
                                    if (TId2 == TId) {
                                        cout<<"("<<Tname<<")";
                                        tc = true;
                                    }
                                }
                            InFileType.close();
                
                
                cout<<setw(13)<<Price<<setw(14)<<Pamount;
                cout<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
                cout<<endl;
                cout<<setw(60)<<"==================================> New Data <================================="<<endl;

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
                        tc = false;

                        // type_id
                        do {
                            cout << "New TId : ";
                            cin >> TId;
                            InFileType.open(FileType);
                                for (int i2 = 1; i2 <= t3; i2++) {
                                    InFileType >> TId2 >> Tname;
                                    // cout<<TId<<endl;
                                    if (TId2 == TId) {
                                        cout<<TId<<"  : "<<TId2<<endl;
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
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

void delproduct(){
    char anw;
    bool del=false;
    do{
        cout<<setw(60)<<"===============================> Delete Product <=============================="<<endl;
        cout<<"Enter X To Exit."<<endl;
        lastrowproduct(t2);
        cout<<"Enter PId : "; cin>>PId;
        InFile.open(FileProduct.c_str());
            for (int i = 1; i <= t2; i++) {
                InFile >> PId2 >> Pname >> TId >> Price >> Pamount;
                // cout<<PId2<<endl;
                if(PId == PId2) {
                    // cout << PId2 << " " << Pname << " " << TId <<" "<< Price << " " << Pamount<<endl;
                    // cout<<setw(60)<<"================================> Delete Data <================================"<<endl;
                    do{
                        cout << "Do you want to delete "<<Pname<<" ? (Y/N) : ";
                        cin >> anw;
                        if(anw == 'Y') {
                            cout<<"Completed."<<endl;
                            anw='N';
                            del=true;
                        }else if(anw == 'N') {
                            cout << "You have skipped." << endl;
                            del=false;
                        }else{
                            cout << "Try again." << endl;
                            del=false;
                        }
                    }while(anw!='N');
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
    cout<<"-------------------------------------------------------------------------------"<<endl;
    del=false;

}

// -----------------------------------------------------

// อ่าน product
void ReadType(){
    lastrowtype(t3);
    cout<<setw(60)<<"=================================> List Type <================================="<<endl;
    cout<<"list type = "<<t3<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<setw(8)<<"TId"<<setw(18)<<"Name"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl; 
    //cout<<"TID         Tname"<<endl;
    InFileType.open(FileType,ios::app);
        for(int i=1;i<=t3;i++){
            InFileType>>TId>>Tname;
            cout<<setw(8)<<TId<<setw(20)<<Tname<<endl;
        }
    InFileType.close();
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

// เพิ่มข้อมูล product
void addType(){
        string name,Rid,Rid2;
        int numpro;

        ofstream OutFileType(FileType, ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
        do{
            cout<<setw(60)<<"==================================> Add Type <================================="<<endl;
            cout<<"Enter 0 To Exit."<<endl;
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

                    //cout<<endl;

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

                    cout<<setw(45)<<"order : "<<i<<endl; 
                    cout<<setw(45)<<"Enter TId : "<<Rid<<endl;
                    cout<<setw(45)<<"Enter name : "; cin>>name;
    

                    OutFileType << Rid << " " << name <<" "<<endl;

                    cout<<setw(45)<<"Complete!"<<endl;
                    cout<<endl;

                    t3++;

                }
                // ปิดไฟล์
                OutFileType.close();
            }
        }while(numpro!=0);
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

// แก้ไขประเภท
void edittype(){
    bool ep = false, tc = false;
    char anw;
    string targetProductId;
    string row; 
    
    lastrowtype(t3);

    do {
        cout<<setw(60)<<"=================================> Edit Type <================================="<<endl;
        cout<<"Enter X To Exit."<<endl;
        cout<< "Enter TId : "; cin >> TId;

        InFile.open(FileType.c_str());

        for (int i = 1; i <= t3; i++) {
            InFile >> TId2 >> Pname ;

            if (TId == TId2) {
                cout<<"-------------------------------------------------------------------------------"<<endl;
                cout<<setw(8)<<"TId"<<setw(18)<<"Name"<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl; 
                cout<<setw(8)<<TId2<<setw(18)<<Pname<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
                cout<< endl;
                cout<<setw(60)<<"==================================> New Data <================================="<<endl;

                do {
                    cout<<"Do you want to edit Name? (Y/N) : ";
                    cin>>anw;
                    if(anw == 'Y'){
                        cout << "New Name : ";
                        cin >> Pname;
                        cout << "Completed." << endl;
                        anw = 'N';
                    }else if(anw == 'N') {
                        cout << "You have skipped." << endl;
                    }else{
                        cout << "Try again." << endl;
                    }
                }while(anw != 'N');
                cout<<endl;
                
                // -------------------------------------------------------
                row=TId+" "+Pname;
                targetProductId=TId;
                // -------------------------------------------------
               
            }
        }
        InFile.close();
                
        editTypeLine("type.txt", targetProductId, row);

    }while(TId!="X");
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

void deltype(){
    char anw;
    bool del=false;

    do{
        cout<<setw(60)<<"================================> Delete Type <================================"<<endl;
        cout<<"Enter X To Exit."<<endl;
        lastrowtype(t3);
        cout<<"Enter TId : "; cin>>TId;
        InFileType.open(FileType.c_str());
            for (int i = 1; i <= t3; i++) {
                InFileType >> TId2 >> Tname;
                // cout<<TId2<<endl;
                if(TId == TId2) {
                    // cout << TId2 << " " << Tname<<endl;
                    // cout<<setw(60)<<"================================> Delete Data <================================"<<endl;
                    do {
                        cout << "Do you want to delete "<<Tname<<" ? (Y/N) : ";
                        cin >> anw;
                        if(anw == 'Y') {
                            cout<<"Completed."<<endl;
                            anw='N';
                            del=true;
                        }else if(anw == 'N') {
                            cout << "You have skipped." << endl;
                            del=false;
                        }else{
                            cout << "Try again." << endl;
                            del=false;
                        }
                    }while(anw!='N');
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
    cout<<"-------------------------------------------------------------------------------"<<endl;
    del=false;

}

// ---------------------------------------------------------------
// อ่านรายการขาย
void readsale(){
    lastrowsale(t4); 
    lastrowproduct(t2);
    lastrowtype(t3);
    string ra1,ra2,r3;
    cout<<setw(60)<<"---------------------------------> List Sale <---------------------------------"<<endl;
    cout<<"list sale = "<<t4<<endl;
    InFileSale.open(FileSale,ios::app);
        cout<<"-------------------------------------------------------------------------------"<<endl;
        cout<<setw(6)<<"SId"<<setw(8)<<"PId"<<setw(12)<<"Name"<<setw(14)<<"Type"<<setw(14)<<"Price"<<setw(12)<<"Amount"<<setw(10)<<"Total"<<endl;
        cout<<"-------------------------------------------------------------------------------"<<endl;
        //cout<<"SID       PID        Pname         Type         Price      Amount      Total    "<<endl;

        for(int i3=1;i3<=t4;i3++){
            InFileSale>>SId>>PId>>Samount>>Total;
            cout<<setw(6)<<SId<<setw(6)<<PId<<"        ";

                    InFile.open(FileProduct,ios::app);
                        for(int i=1;i<=t2;i++){
                            // cout<<i<<" ";
                            InFile>>ra1>>Pname>>TId>>Price>>Pamount;
                                if(PId==ra1){
                                    cout<<setw(10)<<Pname;
                                        InFileType.open(FileType,ios::app);
                                            for(int i2=1;i2<=t3;i2++){
                                                InFileType>>TId2>>Tname;
                                                if(TId==TId2){
                                                    cout<<setw(12)<<Tname<<" ";
                                                }
                                            }
                                        InFileType.close();
                                    cout<<setw(10)<<Price<<" ";
                                }
                        }
                    InFile.close();

            cout<<setw(10)<<Samount<<setw(11)<<Total<<endl;

        }
    InFileSale.close();
    cout<<"-------------------------------------------------------------------------------"<<endl;
}

// เพิ่มการขาย
void addsale(){
        
        string J1,J2,J22,row,targetProductId,Pname1,Pname2;
        int J3,amount,numpro,priceHere,amo;
        bool tc=false;
        float J4;
        ofstream OutFilesale(FileSale, ios::app);//ต้องมี ถ้าไม่มีจะเขียนทับอันเก่า
            lastrowsale(t4);
            lastrowproduct(t2);
        do{
            ReadProduct();
            cout<<setw(60)<<"---------------------------------> New Sale <----------------------------------"<<endl;
            cout<<"Enter 0 To Exit."<<endl;
            cout<<"Enter number of sale list : "; cin>>numpro; // เลือกจำนวนที่จะเพิ่มรายการสินค้า

                for(int i=1;i<=numpro;i++){
                    OutFilesale.is_open();
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

                        cout<<setw(45)<<"order : "<<i<<endl; 
                        cout<<setw(45)<<"Enter SId : "<<J1<<endl;
                        

                        // PId
                                do{
                                    cout<<setw(45)<<"Enter PId : "; cin>>J2;
                                        InFile.open(FileProduct, ios::app);
                                        for(int i2=1;i2<=t2;i2++){
                                            InFile>>J22>>Pname1>>TId>>Price>>Pamount;
                                            if(J22==J2){ 
                                                priceHere=Price;
                                                if(Pamount!=0){
                                                    tc=true;
                                                    break;

                                                }
                                                
                                            }
                                        }
                                        InFile.close();
                                        if(tc==false){ 
                                        cout<<setw(45)<<"Try again."<<endl; }
                                }while(tc!=true);
                                tc=false;
                        // Pamount
                        // cout<<Pname1<<endl;
                                do{
                                    cout<<setw(45)<<"Enter amount : "; cin>>J3;
                                        InFile.open(FileProduct, ios::app);
                                        for(int i2=1;i2<=t2;i2++){
                                            InFile>>J22>>Pname2>>TId>>Price>>Pamount;
                                            if(J22==J2){ 
                                                if(J3<=Pamount){
                                                    amo=Pamount;
                                                    tc=true;
                                                    break;
                                                }
                                                
                                            }
                                        }
                                        InFile.close();
                                        if(tc==false){ cout<<setw(45)<<"Over limit."<<endl; }
                                }while(tc!=true);
                                tc=false; 
                        // cout<<Pname2<<endl;
                        
                        J4=J3*priceHere;
                        cout<<setw(45)<<"Total : "<<J4<<endl;
                        // cout<<J1<<"  "<<J2<<"  "<<J3<<"  "<<J4<<endl;
                        OutFilesale << J1 << " " << J2 << " ";
                        OutFilesale << J3 << " " << J4 << endl;

                    
                    stringstream price_in,amount_in;
                    price_in <<(Price);
                    amount_in <<(amo-J3);

                    row=J2+" "+Pname1+" "+TId+" "+price_in.str()+" "+amount_in.str();
                    targetProductId=J2;
                    
                    // cout<<row<<endl;
                    
                    
                    cout<<setw(45)<<"Complete!"<<endl;
                    cout<<endl;
                    t4++;

                // ปิดไฟล์
                editProductLine(FileProduct, targetProductId, row);
                
 
                }
                    OutFilesale.close();
                editProductLine(FileProduct, targetProductId, row);

        }while(numpro!=0);
        cout<<"-------------------------------------------------------------------------------"<<endl;
}
#include<iostream>
using namespace std;
#include <sstream>  //แปลง int เป็น string
#include <iomanip>

// file
#include <fstream>
#include <string>



int main(){
    string product[100][3]={{"P1","Pen","T1"},   //สินค้า ตัวอักษร
                            {"P2","Eraser","T1"},
                            {"P3","KKK","T1"},
                            {"P4","WWWW","T1"}

                           },
            sale[100][2]={{"S1","P1"},          //การขาย ตัวอักษร 
                          {"S2","P1"},
                          {"S3","P3"},
                          {"S4","P2"}
                           };
    int price[100][2]={{5,10},                  //สินค้า ตัวเลข 
                        {2,9},
                        {5,5},
                        {5,5}
                      },
        sale_total[100][2]={{2,20},             //การขาย ตัวเลข 
                        {1,10},
                        {3,15},
                        {1,9}
                      }; 
    string select,This,ID,old;
    int c,beforeDel,k,amount,am; //หาตำแหน่ง  , จำนวนข้อมูลก่อนลบ , จำนวนขาย , จำนวนที่เพิ่มสินค้า
    float cash,saletotal;
    char anw; //เช็ค Y N 

    do{
       cout<<"========================================================="<<endl;
       cout<<"S = show"<<endl;
       cout<<"A = add"<<endl;
       cout<<"E = Edit"<<endl;
       cout<<"D = Delete"<<endl;
       cout<<"K = Sale"<<endl;

       cout<<setw(35)<<"--Show List--"<<endl;
       cout<<endl;
       for(int m=0; m<100;m++){
           for(int u=0; u<3;u++){
               if(product[m][u]==""){
                   break; //ข้ามไป
               } 
               c=m+1;
           }
       }
            beforeDel=c; //เพิ่มสำหรับใช้ลบข้อมูล

       for(int i=0;i<c;i++){
           for(int i2=0;i2<3;i2++){
               cout<<setw(8)<<product[i][i2]<<"   ";
           }
           for(int i3=0;i3<2;i3++){
               cout<<setw(8)<<price[i][i3]<<"   ";
           }
           cout<<endl;
           cout<<endl;
       } 
       cout<<"========================================================="<<endl;



       cout<<"Enter choice : "; cin>>select;
        if(select=="S"){
            cout<<"====================SEARCH================================="<<endl;
            cout<<"Enter ID : "; cin>>ID;
            // ตารางรายการทั้งหมด
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(product[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==product[i][i2]){
                        This=product[i][i2];
                        c=i; 
                    }
                }  
            }  

            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"ID : "<<product[c][0]<<endl;
                    cout<<"Name : "<<product[c][1]<<endl;
                    cout<<"Type : "<<product[c][2]<<endl;
                    cout<<"price : "<<price[c][0]<<endl;
                    cout<<"amount : "<<price[c][1]<<endl;
                    cout<<endl; 
            }
            This="";
            cout<<"========================================================="<<endl;


        }else if(select=="A"){
            // =======================Add=================================
                for(int m=0; m<100;m++){
                    for(int u=0; u<3;u++){
                        if(product[m][u]==""){
                            break; //ข้ามไป
                        } 
                        c=m+1;
                    }
                }
                // cout<<"last = "<<c<<endl;
                string Rid;
                stringstream ss;
                ss << (c+1);
                Rid="P"+ss.str();

                cout<<"ID = "<<Rid<<endl; 
                product[c][0]=Rid;
                cout<<"Name : "; cin>>product[c][1];
                cout<<"Type : "; cin>>product[c][2];
                cout<<"Price : "; cin>>price[c][0];
                cout<<"Amount : "; cin>>price[c][1];
                cout<<endl;
                // }
        }else if(select=="E"){
            // =======================Edit=================================
            cout<<"Enter ID : "; cin>>ID;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(product[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==product[i][i2]){
                        This=product[i][i2];
                        c=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"ID = "<<product[c][0]<<endl; //ห้ามแก้ไอดี
                    do{
                        cout<<"Do you want to edit Name? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Name : "; cin>>product[c][1];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');
                    
                    do{
                        cout<<"Do you want to edit Type? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Type : "; cin>>product[c][2];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                    do{
                        cout<<"Do you want to edit Price? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Price : "; cin>>price[c][0];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                     do{
                        cout<<"Do you want to edit Amount? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Amount : "; cin>>price[c][1];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');
                    cout<<endl; 
            }
            This="";
            cout<<"========================================================="<<endl;
            
        }else if(select=="D"){
            // =======================Delete================================= 
            cout<<"Enter ID : "; cin>>ID;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(product[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==product[i][i2]){
                        This=product[i][i2];
                        c=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"---------------------------------------------------"<<endl;
                    do{
                        cout<<"Do you want to delete "<<product[c][0]<<"? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            product[c][0]="";
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                            for(int m=0; m<100;m++){
                                for(int u=0; u<3;u++){
                                    if(product[m][u]==""){
                                        break;
                                        c=m;
                                    } 
                                }
                            }
                            for(int i=0;i<c;i++){
                                for(int i2=0;i2<3;i2++){
                                    if(ID==product[i][i2]){
                                        This=product[i][i2];
                                        c=i; 
                                    }
                                }  
                            }  
            }
            // cout<<c<<endl;
          
            // cout<<beforeDel<<endl;
            for(int i=c;i<beforeDel;i++){
                        product[i][0]="";
                        product[i][1]="";
                        product[i][2]="";
                        price[i][0]=0;
                        price[i][1]=0;
                        
                        string Rid;
                        stringstream ss;
                        ss << (i+1);
                        Rid="P"+ss.str();

                        product[i][0]=Rid;
                        
                        product[i][1]=product[i+1][1];
                        product[i][2]=product[i+1][2];
                        price[i][0]=price[i+1][0];
                        price[i][1]=price[i+1][1];

                        product[i+1][0]="";
                        product[i+1][1]="";
                        product[i+1][2]="";
                        price[i+1][0]=0;
                        price[i+1][1]=0;

                        k=i;
                        
                cout<<endl;
            }
                        product[k][0]="";
                        product[k][1]="";
                        product[k][2]="";
                        price[k][0]=0;
                        price[k][1]=0;

            This="";
            cout<<"========================================================="<<endl;
            
        }else if(select=="K"){                
                // cout<<"===========================Sale=============================="<<endl;
                cout<<"===========================SALE pass X to exit=============================="<<endl;
                cout<<"==========================HISTORY============================"<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
                cout<<setw(8)<<"ID"<<setw(14)<<"ID PRODUCT"<<setw(8)<<"Name"<<setw(12)<<"Price"<<setw(12)<<"Amount"<<setw(10)<<"Total"<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
                    for(int m=0; m<100;m++){
                        for(int u=0; u<2;u++){
                            if(sale[m][u]==""){
                                break; //ข้ามไป
                            } 
                            c=m+1;
                        }
                    }

                    for(int i=0;i<c;i++){
                        cout<<setw(8)<<sale[i][0]<<" | ";
                        cout<<setw(8)<<sale[i][1]<<" | ";
                        for(int i2=0; i2<100;i2++){
                            // cout<<setw(8)<<product[i2][0]<<" | ";
                            if(sale[i][1]==product[i2][0]){
                                cout<<setw(8)<<product[i2][1]<<" | ";
                                cout<<setw(8)<<price[i2][1]<<" | ";
                            }
                        }

                        cout<<setw(8)<<sale_total[i][0]<<" | ";
                        cout<<setw(8)<<sale_total[i][1]<<" | ";
                        
                        cout<<endl;
                        cout<<endl;
                    } 
 
                                    // เพิ่มการขาย
                            do{
                                cout<<"Enter Product ID : "; cin>>ID;
                                        for(int i=0;i<100;i++){
                                            // cout<<product[i][0]<<endl;
                                            if(ID==product[i][0]){
                                                anw='Y';
                                                break;
                                            }else{
                                                anw='N';
                                            }

                                        }
                            }while(anw!='Y');

                            do{
                                cout<<"Enter Amount : "; cin>>amount;
                                for(int i=0;i<100;i++){
                                        if(ID==product[i][0]){
                                            if(amount>price[i][0]){
                                                cout<<"Over limit! Try again."<<endl;
                                                amount=-1;
                                                break;
                                            }
                                        }
                                    }
                            }while(amount==-1);
                                cout<<"------------Sale Slip---------"<<endl;
                                cout<<"Product ID = "<<ID<<endl;
                                for(int i=0;i<100;i++){
                                    if(ID==product[i][0]){
                                        cout<<"Product Name = "<<product[i][1]<<endl;
                                        cout<<"Product Price = "<<price[i][1]<<endl;
                                        cout<<"Amount = "<<amount<<endl;
                                        if(amount>price[i][0]){
                                            cout<<"Over limit! Try again."<<endl;
                                            amount=-1;
                                            break;
                                        }
                                        saletotal=amount*price[i][1];
                                        cout<<"Total cash = "<<saletotal<<endl;
                                        do{
                                            cout<<"Enter cash : "; cin>>cash;
                                            if((cash-(amount*price[i][1]))<0){
                                                anw='N';
                                            }else{
                                                anw='Y';
                                            }
                                        }while(anw!='Y');
                                        cout<<"Change cash = "<<cash-(amount*price[i][1])<<endl;
                                    }
                                }
                                    cout<<"------------Sale Slip---------"<<endl;
                                    // update to array price and insert to sale sale_total 
                                        for(int i=0;i<100;i++){
                                            // cout<<ID<<endl;
                                            // cout<<product[i][0]<<endl;
                                            if(ID==product[i][0]){
                                                price[i][0]=price[i][0]-amount;
                                                break;
                                            }
                                        }
                                    // =======================Add=================================
                                        for(int m=0; m<100;m++){
                                            for(int u=0; u<2;u++){
                                                if(sale[m][u]==""){
                                                    break; //ข้ามไป
                                                } 
                                                c=m+1;
                                            }
                                        }
                                        // cout<<"last = "<<c<<endl;
                                        string Rid;
                                        stringstream ss;
                                        ss << (c+1);
                                        Rid="S"+ss.str();
                        
                                        // cout<<"ID sale = "<<Rid<<endl; 
                                        sale[c][0]=Rid;
                                        sale[c][1]=ID;
                                        sale_total[c][0]=amount;
                                        sale_total[c][1]=saletotal;
                        
                                        cout<<endl;

                          

                            cout<<"========================================================="<<endl;
                            
        }

    }while(select!="x");
}
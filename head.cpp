#include<iostream>//cin cout
using namespace std; //std::

// include อื่นๆ
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h>
#include <iomanip>

#include<iostream>
using namespace std;
#include <sstream>
#include <iomanip>

int main(){
    string product[100][3]={{"P1","Pen","T1"},
                            {"P2","Eraser","T1"},
                            {"P3","KKK","T1"},
                            {"P4","WWWW","T1"}

                           };
    int price[100][2]={{5,10},
                        {2,9},
                        {5,5},
                        {5,5}
                      };
    string select,This,ID;
    int c,beforeDel,k; //หาตำแหน่ง  , จำนวนข้อมูลก่อนลบ 
    char anw; //เช็ค Y N 
    string old; //เก็บไอดีเก่า

    do{
       cout<<"========================================================="<<endl;
       cout<<"S = show"<<endl;
       cout<<"A = add"<<endl;
       cout<<"E = Edit"<<endl;
       cout<<"D = Delete"<<endl;
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
                        // cout<<product[m][u]<<"   ";
                        
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
            
        }
 

    }while(select!="x");


}

#include "head.cpp"
//ไฟล์ sale
 
#include"footer.cpp"
#include"header.cpp"
#include"product.cpp"
#include "sale.cpp"
#include "type.cpp"

  int c,beforeDel,k; //หาตำแหน่ง  , จำนวนข้อมูลก่อนลบ 
  char anw; //เช็ค Y N 
  string old; //เก็บไอดีเก่า

// ================================Type Menu==========================
/*void typeMenu(){
      string This,ID;
      char sell_t;
      int t,t2;
      const int columnWidth = 12;
      string Type_list[10][2]={{"T1","Stationery"},
                                {"T2","Food"},
                                {"T3","Drink"}
                                };
      do{
          headerTable();  //แสดง =======
          cout<<setw(54)<<"---------- Type Menu ----------"<<endl;
          cout<<setw(56)<<"Press [L] to Show List Type"<<endl;
          cout<<setw(53)<<"Press [S] to Search Type"<<endl;
          cout<<setw(50)<<"Press [A] to Add Type"<<endl;  
          cout<<setw(51)<<"Press [E] to Edit Type"<<endl;
          cout<<setw(53)<<"Press [D] to Delete Type"<<endl;
          footerReturn(); //แสดง =======
          cin>>sell_t;
          system("cls");
          sell_t = toupper(sell_t);
          if(sell_t=='L'){ 
              cout<<setw(60)<<"--------------- List Type ---------------"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<setw(8)<<"ID"<<setw(14)<<"Name"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;

                 for(int i=0;i<3;i++){
                      for(int i2=0;i2<2;i2++){
                          cout<<setw(columnWidth)<<Type_list[i][i2]<<" | ";
                      }
                      //cout<<"------------------------------";
                      cout<<endl;
                  }
          }else if(sell_t=='S'){
            cout<<setw(65)<<"--------------- Search Type ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;


            for(int m=0; m<10;m++){
                for(int u=0; u<2;u++){
                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    t=m+1;
                }
                cout<<endl;
            }
            for(int i=0;i<t;i++){
                for(int i2=0;i2<2;i2++){
                    if(ID==Type_list[i][i2]){
                        This=Type_list[i][i2];
                        t=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"ID : "<<Type_list[t][0]<<endl;
                    cout<<"Name : "<<Type_list[t][1]<<endl;
                    cout<<endl; 
            }
            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;

          }else if(sell_t=='A'){
            cout<<setw(60)<<"--------------- Add Type ---------------"<<endl;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    // cout<<product[m][u]<<"   ";
                    
                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    t=m+1;
                }
                // cout<<endl;
            }
                cout<<"last = "<<t<<endl;
                string Rid;
                stringstream ss;
                ss << (t+1);
                Rid="P"+ss.str();

                cout<<"ID = "<<Rid<<endl; 
                Type_list[t][0]=Rid;
                cout<<"Name : "; cin>>Type_list[t][1];
                cout<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
            // }
          }else if(sell_t=='E'){
            cout<<setw(60)<<"--------------- Edit Type ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            //cout<<ID<<endl;
            for(int m=0; m<10;m++){
                for(int u=0;u<2;u++){
                  //cout<<m<<"    "<<u<<" = ";
                  //cout<<Type_list[m][u]<<endl;

                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            //cout<<c<<endl;
            for(int i=0;i<c;i++){
                for(int i2=0;i2<2;i2++){
                    //cout<<Type_list[i][i2]<<endl;
                    if(ID==Type_list[i][i2]){
                        
                      
                        This=Type_list[i][i2];
                        c=i; 
                    }
                }  
            }  
            //cout<<c<<endl;

            //cout<<This<<endl;

            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"ID = "<<Type_list[c][0]<<endl; //ห้ามแก้ไอดี
                    do{
                        cout<<"Do you want to edit Name? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Name : "; cin>>Type_list[c][1];
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
            cout<<"-------------------------------------------------------------------------------"<<endl;
          }else if(sell_t=='D'){
            cout<<setw(60)<<"--------------- Delete Type ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            //cout<<ID<<endl;
            for(int m=0; m<10;m++){
                for(int u=0;u<2;u++){
                  //cout<<m<<"    "<<u<<" = ";
                  //cout<<Type_list[m][u]<<endl;

                    if(Type_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            //cout<<c<<endl;
            for(int i=0;i<c;i++){
                for(int i2=0;i2<2;i2++){
                    //cout<<Type_list[i][i2]<<endl;
                    if(ID==Type_list[i][i2]){
                        
                      
                        This=Type_list[i][i2];
                        c=i; 
                    }
                }  
            }
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"-------------------------------------------------------------------------------"<<endl;
                    do{
                        cout<<"Do you want to delete "<<Type_list[c][0]<<"? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            Type_list[c][0]="";
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');

                            for(int m=0; m<10;m++){
                                for(int u=0; u<2;u++){
                                    if(Type_list[m][u]==""){
                                        break;
                                        c=m;
                                    } 
                                }
                            }
                            for(int i=0;i<c;i++){
                                for(int i2=0;i2<2;i2++){
                                    if(ID==Type_list[i][i2]){
                                        This=Type_list[i][i2];
                                        c=i; 
                                    }
                                }  
                            }  
            }
            // cout<<c<<endl;
          
            // cout<<beforeDel<<endl;
            for(int i=c;i<beforeDel;i++){
                        Type_list[i][0]="";
                        Type_list[i][1]="";
                        
                        string Rid;
                        stringstream ss;
                        ss << (i+1);
                        Rid="P"+ss.str();

                        Type_list[i][0]=Rid;
                        
                        Type_list[i][1]=Type_list[i+1][1];

                        Type_list[i+1][0]="";
                        Type_list[i+1][1]="";

                        k=i;
                        
                cout<<endl;
            }
                        Type_list[k][0]="";
                        Type_list[k][1]="";

            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
            
        }
 

    }while(sell_t!='X');
}
// void ShowProduct(string Product_list[]);

// ================================Sale Menu==========================
void sale(){
      string This,ID;
      char sell_s;
      int s,s2;
      const int columnWidth = 10;
      string Sale_list[100][2]={{"S1","P1"},
                                {"S2","P2"}
                               };
      int Price_list[100][3]={{5,2,10},
                              {5,2,10}
                          };
      do{
          headerTable();  //แสดง =======
          cout<<setw(55)<<"---------- Sale Menu ----------"<<endl;
          cout<<setw(54)<<"Press [L] to Show History"<<endl;
          cout<<setw(55)<<"Press [A] to Add Sale Page"<<endl;  
          cout<<setw(56)<<"Press [E] to Edit Sale page"<<endl;
          cout<<setw(58)<<"Press [D] to Delete Sale page"<<endl;
          footerReturn(); //แสดง =======
          cin>>sell_s;
          system("cls");
          sell_s = toupper(sell_s);
          if(sell_s=='L'){ 
              cout<<setw(60)<<"--------------- History ---------------"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<setw(8)<<"ID"<<setw(12)<<"Name"<<setw(14)<<"Price"<<setw(13)<<"Amount"<<setw(13)<<"Total"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;

                 for(int i=0;i<=5;i++){
                      for(int i2=0;i2<=2;i2++){
                          cout<<setw(columnWidth)<<Sale_list[i][i2]<<" | ";
                      }
                      for(int i2=0;i2<=1;i2++){
                          cout<<setw(columnWidth)<<Price_list[i][i2]<<" | ";
                      }
                      cout<<endl;
                      
                  } 
          }else if(sell_s=='A'){
            cout<<setw(60)<<"--------------- Add Sale ---------------"<<endl;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    // cout<<product[m][u]<<"   ";
                    
                    if(Sale_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    s=m+1;
                }
                // cout<<endl;
            }
                cout<<"last = "<<s<<endl;
                string Rid;
                stringstream ss;
                ss << (s+1);
                Rid="P"+ss.str();

                cout<<"ID = "<<Rid<<endl; 
                Sale_list[s][0]=Rid;
                cout<<"ID Product : "; cin>>Sale_list[s][1];
                cout<<"Price : "; cin>>Price_list[s][0];
                cout<<"Amount : "; cin>>Price_list[s][1];
                cout<<"Total : "; cin>>Price_list[s][2];
                cout<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
            // }
          }else if(sell_s=='E'){
            cout<<setw(60)<<"--------------- Edit Sale ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Sale_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Sale_list[i][i2]){
                        This=Sale_list[i][i2];
                        c=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"ID = "<<Sale_list[c][0]<<endl; //ห้ามแก้ไอดี
                    do{
                        cout<<"Do you want to edit ID Product? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New ID Product : "; cin>>Sale_list[c][1];
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
                            cout<<"New Price : "; cin>>Price_list[c][0];
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
                            cout<<"New Amount : "; cin>>Price_list[c][1];
                            cout<<"Completed."<<endl; 
                            anw='N';
                        }else if(anw=='N'){
                            cout<<"You have skipped."<<endl;
                        }else{
                            cout<<"Try again."<<endl;
                        }
                    }while(anw!='N');
                    
                    do{
                        cout<<"Do you want to edit Total? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Total : "; cin>>Price_list[c][2];
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
            cout<<"-------------------------------------------------------------------------------"<<endl;
          }else if(sell_s=='D'){
            cout<<setw(60)<<"--------------- Delete Sale ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Sale_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Sale_list[i][i2]){
                        This=Sale_list[i][i2];
                        c=i; 
                    }
                }  
            }if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"-------------------------------------------------------------------------------"<<endl;
                    do{
                        cout<<"Do you want to delete "<<Sale_list[c][0]<<"? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            Sale_list[c][0]="";
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
                                    if(Sale_list[m][u]==""){
                                        break;
                                        c=m;
                                    } 
                                }
                            }
                            for(int i=0;i<c;i++){
                                for(int i2=0;i2<3;i2++){
                                    if(ID==Sale_list[i][i2]){
                                        This=Sale_list[i][i2];
                                        c=i; 
                                    }
                                }  
                            }  
            }
            // cout<<c<<endl;
          
            // cout<<beforeDel<<endl;
            for(int i=c;i<beforeDel;i++){
                        Sale_list[i][0]="";
                        Sale_list[i][1]="";
                        Price_list[i][0]=0;
                        Price_list[i][1]=0;
                        Price_list[i][2]=0;
                        
                        string Rid;
                        stringstream ss;
                        ss << (i+1);
                        Rid="P"+ss.str();

                        Sale_list[i][0]=Rid;
                        
                        Sale_list[i][1]=Sale_list[i+1][1];
                        Price_list[i][0]=Price_list[i+1][0];
                        Price_list[i][1]=Price_list[i+1][1];

                        Sale_list[i+1][0]="";
                        Sale_list[i+1][1]="";
                        Price_list[i+1][0]=0;
                        Price_list[i+1][1]=0;
                        Price_list[i+1][2]=0;

                        k=i;
                        
                cout<<endl;
            }
                        Sale_list[k][0]="";
                        Sale_list[k][1]="";
                        Price_list[k][0]=0;
                        Price_list[k][1]=0;
                        Price_list[k][2]=0;

            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
            
        }
      }while(sell_s!='X');
}*/


int main()
{
  char sell;
  do{
      // system("cls"); //ล้างหน้าจอ
      headerTable();  //แสดง =======

      cout<<setw(56)<<"Press [P] to Product Menu Page"<<endl;
      cout<<setw(53)<<"Press [T] to Type Menu Page"<<endl;  
      cout<<setw(53)<<"Press [S] to Sale Menu page"<<endl;

      footerExit();//include มาจาก sale แล้ว sale เอามาจากอื่นๆ อีกที
      cin>>sell;
      system("cls"); //ล้างหน้าจอ

      // puts("");//ไม่ต้องกด enter จะเร็วกว่า cin


      sell = toupper(sell);
      if(sell=='P'){
        product();
      }else if(sell=='T'){
        typeMenu();
      }else if(sell=='S'){
        sale();
      }
  }while(sell != 'X'); //X!=X F
//ออกกด X เล็กใหญ่ก็ได้

  return 0;
}


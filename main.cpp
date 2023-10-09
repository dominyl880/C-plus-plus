#include"head.cpp"
#include"footer.cpp"
#include"header.cpp"

  int c,beforeDel,k; //หาตำแหน่ง  , จำนวนข้อมูลก่อนลบ 
  char anw; //เช็ค Y N 
  string old; //เก็บไอดีเก่า

// ================================Product Menu==========================
void product(){
      string This,ID;
      char sell_p;
      int c,c2,k;
      char anw;
      const int columnWidth = 10;
      int beforeDel;
      string Product_list[100][3]={{"P1","Pen","T1"},
                                   {"P2","Eraser","T1"},
                                   {"P3","Pencil","T1"},
                                   {"P4","Ruler","T1"},
                                   {"P5","Chicken","T2"},
                                   {"P6","Duck","T2"},
                                   {"P7","Pig","T2"},
                                   {"P8","Rice","T2"},
                                   {"P9","Egg","T2"},
                                   {"P10","Coca cola","T3"},
                                   {"P11","Milk","T3"},
                                   {"P12","Water","T3"},
                                   {"P13","Bread","T2"}
                                  };
      int Price_list[100][2]={{5,3},
                              {5,3},
                              {10,5},
                              {10,5},
                              {150,5},
                              {170,5},
                              {195,5},
                              {7,5},
                              {5,5},
                              {15,5},
                              {13,5},
                              {10,5},
                              {20,5}
                          };
      do{
          headerTable();  //แสดง =======

          cout<<setw(55)<<"---------- Product Menu ----------"<<endl;
          cout<<setw(57)<<"Press [L] to Show List Product"<<endl;
          cout<<setw(54)<<"Press [S] to Search Product"<<endl;
          cout<<setw(51)<<"Press [A] to Add Product"<<endl;  
          cout<<setw(52)<<"Press [E] to Edit Product"<<endl;
          cout<<setw(54)<<"Press [D] to Delete Product"<<endl;

          footerReturn(); //แสดง =======
          cin>>sell_p;
          system("cls");
          sell_p = toupper(sell_p);

// beforeDel--
            for(int m=0; m<100;m++){
           for(int u=0; u<3;u++){
               if(Product_list[m][u]==""){
                   break; //ข้ามไป
               } 
               c=m+1;
           }
       }
            beforeDel=c;

          if(sell_p=='L'){ 
              cout<<setw(60)<<"--------------- List Product ---------------"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<setw(8)<<"ID"<<setw(12)<<"Name"<<setw(13)<<"Type"<<setw(14)<<"Price"<<setw(13)<<"Amount"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;

                 for(int i=0;i<=5;i++){
                      for(int i2=0;i2<=2;i2++){
                          cout<<setw(columnWidth)<<Product_list[i][i2]<<" | ";
                      }
                      for(int i2=0;i2<=1;i2++){
                          cout<<setw(columnWidth)<<Price_list[i][i2]<<" | ";
                      }
                      cout<<endl;
                  }
            }else if(sell_p=='S'){
            cout<<setw(65)<<"--------------- Search Product ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            // ID=toupper(ID);

            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Product_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
                cout<<endl;
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Product_list[i][i2]){
                        This=Product_list[i][i2];
                        c=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"ID : "<<Product_list[c][0]<<endl;
                    cout<<"Name : "<<Product_list[c][1]<<endl;
                    cout<<"Type : "<<Product_list[c][2]<<endl;
                    cout<<"price : "<<Price_list[c][0]<<endl;
                    cout<<"amount : "<<Price_list[c][1]<<endl;
                    cout<<endl; 
            }
            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
            footerReturn(); //แสดง =======

          }else if(sell_p=='A'){
            cout<<setw(60)<<"--------------- Add Product ---------------"<<endl;
            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    // cout<<product[m][u]<<"   ";
                    
                    if(Product_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
                // cout<<endl;
            }
                cout<<"last = "<<c<<endl;
                string Rid;
                stringstream ss;
                ss << (c+1);
                Rid="P"+ss.str();

                cout<<"ID = "<<Rid<<endl; 
                Product_list[c][0]=Rid;
                cout<<"Name : "; cin>>Product_list[c][1];
                cout<<"Type : "; cin>>Product_list[c][2];
                cout<<"Price : "; cin>>Price_list[c][0];
                cout<<"Amount : "; cin>>Price_list[c][1];

                cout<<endl;
                cout<<"-------------------------------------------------------------------------------"<<endl;
                footerReturn();
            // }
          }else if(sell_p=='E'){
            cout<<setw(60)<<"--------------- Edit Product ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            // ID=toupper(ID);

            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Product_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Product_list[i][i2]){
                        This=Product_list[i][i2];
                        c=i; 
                    }
                }  
            }  
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"---------------------------------------------------"<<endl;
                    cout<<"ID = "<<Product_list[c][0]<<endl; //ห้ามแก้ไอดี
                    do{
                        cout<<"Do you want to edit Name? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            cout<<"New Name : "; cin>>Product_list[c][1];
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
                            cout<<"New Type : "; cin>>Product_list[c][2];
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
                    cout<<endl; 
            }
            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
          }else if(sell_p=='D'){
            cout<<setw(60)<<"--------------- Delete Product ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;
            // ID=toupper(ID);

            for(int m=0; m<100;m++){
                for(int u=0; u<3;u++){
                    if(Product_list[m][u]==""){
                        break; //ข้ามไป
                    } 
                    c=m+1;
                }
            }
            for(int i=0;i<c;i++){
                for(int i2=0;i2<3;i2++){
                    if(ID==Product_list[i][i2]){
                        This=Product_list[i][i2];
                        c=i; 
                    }
                }  
            }
            if(This==""){
                cout<<"Not Found!"<<endl;
            }else{
                    cout<<"-------------------------------------------------------------------------------"<<endl;
                    do{
                        cout<<"Do you want to delete "<<Product_list[c][0]<<"? (Y/N) : "; cin>>anw;
                        if(anw=='Y'){
                            Product_list[c][0]="";
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
                                    if(Product_list[m][u]==""){
                                        break;
                                        c=m;
                                    } 
                                }
                            }
                            for(int i=0;i<c;i++){
                                for(int i2=0;i2<3;i2++){
                                    if(ID==Product_list[i][i2]){
                                        This=Product_list[i][i2];
                                        c=i; 
                                    }
                                }  
                            }  
            }
            // cout<<c<<endl;
          
            // cout<<beforeDel<<endl;
            for(int i=c;i<beforeDel;i++){
                        Product_list[i][0]="";
                        Product_list[i][1]="";
                        Product_list[i][2]="";
                        Price_list[i][0]=0;
                        Price_list[i][1]=0;
                        
                        string Rid;
                        stringstream ss;
                        ss << (i+1);
                        Rid="P"+ss.str();

                        Product_list[i][0]=Rid;
                        
                        Product_list[i][1]=Product_list[i+1][1];
                        Product_list[i][2]=Product_list[i+1][2];
                        Price_list[i][0]=Price_list[i+1][0];
                        Price_list[i][1]=Price_list[i+1][1];

                        Product_list[i+1][0]="";
                        Product_list[i+1][1]="";
                        Product_list[i+1][2]="";
                        Price_list[i+1][0]=0;
                        Price_list[i+1][1]=0;

                        k=i;
                        
                cout<<endl;
            }
                        Product_list[k][0]="";
                        Product_list[k][1]="";
                        Product_list[k][2]="";
                        Price_list[k][0]=0;
                        Price_list[k][1]=0;

            This="";
            cout<<"-------------------------------------------------------------------------------"<<endl;
            
        }
 

    }while(sell_p!='X');

}

// ================================Type Menu==========================
void typeMenu(){
      string This,ID;
      char sell_t;
      int t,t2;
      const int columnWidth = 12;
      string Type_list[10][2]={{"T1","Stationery"},
                                {"T2","Food"},
                                {"T3","Drink"}
                                };
      do{
          sell_t = toupper(sell_t);
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
      int s,s2,amount,am;
      float cash,total;
      const int columnWidth = 10;
    
      string sale[100][2]={{"S1","P1"},{"S2","P1"},{"S3","P3"},{"S4","P2"}};
      int sale_total[100][2]={{2,20},{1,10},{3,15},{1,9}};
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
          /*if(sell_s=='L'){ 
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
                      
                  }*/ 
          if(sell_s=='L'){                
            cout<<setw(60)<<"--------------- History ---------------"<<endl;
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
                    if(sale[i][1]==Product_list[i2][0]){
                      cout<<setw(8)<<Product_list[i2][1]<<" | ";
                      cout<<setw(8)<<Price_list[i2][1]<<" | ";
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
                  ID=toupper(ID);
                          for(int i=0;i<100;i++){
                              // cout<<product[i][0]<<endl;
                              if(ID==Product_list[i][0]){
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
                    if(ID==Product_list[i][0]){
                        if(amount>Price_list[i][0]){
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
                if(ID==Product_list[i][0]){
                    cout<<"Product Name = "<<Product_list[i][1]<<endl;
                    cout<<"Product Price = "<<Price_list[i][1]<<endl;
                    cout<<"Amount = "<<amount<<endl;
                    if(amount>Price_list[i][0]){
                        cout<<"Over limit! Try again."<<endl;
                        amount=-1;
                        break;
                    }
                    total=amount*Price_list[i][1];
                    cout<<"Total cash = "<<total<<endl;
                    do{
                        cout<<"Enter cash : "; cin>>cash;
                        if((cash-(amount*Price_list[i][1]))<0){
                            anw='N';
                        }else{
                            anw='Y';
                        }
                    }while(anw!='Y');
                    cout<<"Change cash = "<<cash-(amount*Price_list[i][1])<<endl;
                }
            }
                cout<<"------------ Sale Slip ---------"<<endl;
                // update to array price and insert to sale sale_total 
                    for(int i=0;i<100;i++){
                        // cout<<ID<<endl;
                        // cout<<product[i][0]<<endl;
                        if(ID==Product_List[i][0]){
                            Price_list[i][0]=Price_list[i][0]-amount;
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
                    sale_total[C][1]=total;
                        
                    cout<<endl;
          
            cout<<"-------------------------------------------------------------------------------"<<endl;
      }while(sell_s!='X');
      }
}

// ================================Main Menu==========================
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


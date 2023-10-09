#include "head.cpp"

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




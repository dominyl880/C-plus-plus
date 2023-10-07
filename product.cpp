void product(){
      string This,ID;
      char sell_p;
      int c,c2;
      const int columnWidth = 10;
      string Product_list[100][3]={{"P1","Pen","1"},
                                   {"P2","Eraser","1"},
                                   {"P3","Pencil","1"},
                                   {"P4","Ruler","1"},
                                   {"P5","Chicken","2"},
                                   {"P6","Duck","2"},
                                   {"P7","Pig","2"},
                                   {"P8","Rice","2"},
                                   {"P9","Egg","2"},
                                   {"P10","Coca cola","3"},
                                   {"P11","Milk","3"},
                                   {"P12","Water","3"},
                                   {"P13","Bread","2"}
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
          sell_p = toupper(sell_p);
          if(sell_p=='L'){ 
              cout<<setw(60)<<"--------------- List Product ---------------"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;
              cout<<setw(8)<<"ID"<<setw(12)<<"Name"<<setw(13)<<"Type"<<setw(14)<<"Price"<<setw(13)<<"Amount"<<endl;
              cout<<"-------------------------------------------------------------------------------"<<endl;

                 for(int i=0;i<=5;i++){
                      for(int i2=0;i2<=2;i2++){
                          cout<<left<<setw(columnWidth)<<Product_list[i][i2]<<" | ";
                      }
                      for(int i2=0;i2<=1;i2++){
                          cout<<left<<setw(columnWidth)<<Price_list[i][i2]<<" | ";
                      }
                      cout<<endl;
                  }
            }else if(sell_p=='S'){
            cout<<setw(65)<<"--------------- Search Product ---------------"<<endl;
            cout<<"Enter ID : "; cin>>ID;


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
            // }
          }else if(sell_p=='E'){
            // EditProduct();
          }else if(sell_p=='D'){
            // DelProduct();
          }
      }while(sell_p!='X');
}



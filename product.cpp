void product(){
      char sell_p;
      int c,c2;
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
          cout<<setw(55)<<"----------Product Menu----------"<<endl;
          cout<<setw(57)<<"Press [L] to Show List Product"<<endl;
          cout<<setw(54)<<"Press [S] to Search Product"<<endl;
          cout<<setw(51)<<"Press [A] to Add Product"<<endl;  
          cout<<setw(52)<<"Press [E] to Edit Product"<<endl;
          cout<<setw(54)<<"Press [D] to Delete Product"<<endl;
          footerReturn(); //แสดง =======
          cin>>sell_p;
          sell_p = toupper(sell_p);
          if(sell_p=='L'){ 
              cout<<"show_list_in P"<<endl;

                 for(int i=0;i<=5;i++){
                      for(int i2=0;i2<=2;i2++){
                          cout<<Product_list[i][i2]<<"   ";
                      }
                      for(int i2=0;i2<=1;i2++){
                          cout<<Price_list[i][i2]<<"   ";
                      }
                      cout<<endl;
                  }
            
          }else if(sell_p=='S'){
            //search
          }else if(sell_p=='A'){
            // AddProduct();
          }else if(sell_p=='E'){
            // EditProduct();
          }else if(sell_p=='D'){
            // DelProduct();
          }
      }while(sell_p!='X');
}



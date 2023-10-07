#include "head.cpp"

//ไฟล์ sale
// #include "sale.cpp" 
#include"footer.cpp"
#include"header.cpp"
#include"product.cpp"

// ================================Type Menu==========================
void typeMenu(){
      char sell_t;
      int t,t2;
      string Type_list[10][2]={{"T1","Stationery"},
                                {"T2","Food"},
                                {"T3","Drink"}
                                };
      do{
          headerTable();  //แสดง =======
          cout<<setw(54)<<"----------Type Menu----------"<<endl;
          cout<<setw(56)<<"Press [L] to Show List Type"<<endl;
          cout<<setw(53)<<"Press [S] to Search Type"<<endl;
          cout<<setw(50)<<"Press [A] to Add Type"<<endl;  
          cout<<setw(51)<<"Press [E] to Edit Type"<<endl;
          cout<<setw(53)<<"Press [D] to Delete Type"<<endl;
          footerReturn(); //แสดง =======
          cin>>sell_t;
          sell_t = toupper(sell_t);
          if(sell_t=='L'){ 
              cout<<"show_list_in T"<<endl;

                 for(int i=0;i<3;i++){
                      for(int i2=0;i2<2;i2++){
                          cout<<setw(35)<<Type_list[i][i2]<<"   ";
                      }
                      //cout<<"------------------------------";
                      cout<<endl;
                  }
          }else if(sell_t=='S'){
            // searchType();
          }else if(sell_t=='A'){
            // AddType();
          }else if(sell_t=='E'){
            // EditType();
          }else if(sell_t=='D'){
            // DelType();
          }
      }while(sell_t!='X');
}
// void ShowProduct(string Product_list[]);

// ================================Sale Menu==========================
void sale(){
      char sell_s;
      int s,s2;
      string Sale_list[100][2]={{"S1","P1"},
                                   {"S2","P2"}
                                  };
      int Price_list[100][3]={{5,2,10},
                              {5,2,10}
                          };
      do{
          headerTable();  //แสดง =======
          cout<<setw(55)<<"----------Sale Menu----------"<<endl;
          cout<<setw(54)<<"Press [L] to Show History"<<endl;
          cout<<setw(55)<<"Press [A] to Add Sale Page"<<endl;  
          cout<<setw(56)<<"Press [E] to Edit Sale page"<<endl;
          cout<<setw(58)<<"Press [D] to Delete Sale page"<<endl;
          footerReturn(); //แสดง =======
          cin>>sell_s;
          sell_s = toupper(sell_s);
          if(sell_s=='L'){ 
              cout<<"show_list_in S"<<endl;

                 for(int i=0;i<=5;i++){
                      for(int i2=0;i2<=2;i2++){
                          cout<<Sale_list[i][i2]<<"   ";
                      }
                      for(int i2=0;i2<=1;i2++){
                          cout<<Price_list[i][i2]<<"   ";
                      }
                      cout<<endl;
                  }   
          }else if(sell_s=='A'){
            // Addsale();
          }else if(sell_s=='E'){
            // Editsale();
          }else if(sell_s=='D'){
            // Delsale();
          }
      }while(sell_s!='X');
}


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


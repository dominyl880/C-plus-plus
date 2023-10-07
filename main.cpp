#include "head.cpp"

//ไฟล์ sale
#include "sale.cpp" 

int main()
{
  char sel;
  do{
      system("cls"); //ล้างหน้าจอ
      headerTable();  //แสดง =======
      //cout<<setw(4);
      cout<<setw(56)<<"Press [P] to Product Menu Page"<<endl;
      cout<<setw(53)<<"Press [T] to Type Menu Page"<<endl;  
      cout<<setw(54)<<"Press [C] to Stock Menu page"<<endl;
      cout<<setw(53)<<"Press [S] to Sale Menu page"<<endl;

      puts("");//ไม่ต้องกด enter จะเร็วกว่า cin
      // cin>>sel;

      footerExit();//include มาจาก sale แล้ว sale เอามาจากอื่นๆ อีกที

      sel = toupper(getche());
      if(sel=='P'){
        productMenu();
      }else if(sel=='T'){
        typeMenu();
      }else if(sel=='C'){
        stockMenu();
      }else if(sel=='S'){
        saleMenu();
      }
  }while(sel != 'X'); //X!=X F
//ออกกด X เล็กใหญ่ก็ได้

  return 0;
}


#include "stock.cpp"

struct sale
{
  char code[5]; // product code
  char cus[20]; // customer name
  float price;
  int amount;
} sale, saleCP;

FILE *sa, *saCP;

void saleHistory()
{
  bool n = true;
  if ((sa = fopen("sale.dat", "rb")) == NULL){
    cout<<"Open File 'sale.dat' Error!"<<endl;
  }
  else{
    if (fread(&sale, sizeof(sale), 1, sa) != 1){
      if (feof(sa)){
        fclose(sa);
        n = false;
      }
    }
    if (n){
      cout<<setw(45)<<"---| History Sale |---"<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      cout<<"             Customer   Code              Product      Price   Amount        Net"<<endl;
      cout<<"---------------------------------------------------------------------------------"<<endl;
      for (;;){
        printf("%21s%7s%21s%11.2f%9d%11.2f\n", sale.cus, sale.code, productName(sale.code), sale.price, sale.amount, (float)sale.price * sale.amount);

        if (fread(&sale, sizeof(sale), 1, sa) != 1)
        {
          if (feof(sa))
          {
            fclose(sa);
            break;
          }
        }
      }
      cout<<"---------------------------------------------------------------------------------"<<endl;
    }
  }
}

void saleNew()
{

  do
  {
    cout<<setw(52)<<"======>| New Sell |<======"<<endl;
    sa = fopen("sale.dat", "ab");
    int n;
    bool check;
    productList();
    do
    {
      cout<<"Enter Product Code : "<<endl;
      fflush(stdin);
      gets(sale.code);
      n = stockAmount(sale.code);
      if (n < 0)
      {
        check = true;
        cout<<"Search This Code Not Found"<<endl;
      }
      else if (n == 0)
      {
        check = true;
        cout<<"This Product Is Out Of Stock"<<endl;
      }
      else
      {
        check = false;
      }
    } while (check);
    cout<<"Customer Name : ";
    fflush(stdin);
    gets(sale.cus);

    do
    {
      cout<<"Amount : ";
      fflush(stdin);
      scanf("%d", &sale.amount);
      if (sale.amount < 0)
      {
        cout<<"Wrong Number Input!"<<endl;
        check = true;
      }
      else if (sale.amount == 0)
      {
        cout<<"Number Input Must Greater Than Or Equal To 1"<<endl;
        check = true;
      }
      else if (sale.amount > n)
      {
        check = true;
        cout<<"Don't Have Product In Stock Not Enough"<<endl;
      }
      else
      {
        check = false;
      }
    } while (check);

    sale.price = productPrice(sale.code);

    printf("Net Price : %.2f \n", sale.price * sale.amount);

    cout<<"Are You Sure Want To New Sell"<<endl;
    cout<<"Press Y To Confirm!"<<endl;
    fflush(stdin);
    if (toupper(getch()) == 'Y')
    {
      stockDown(sale.code, sale.amount);
      fwrite(&sale, sizeof(sale), 1, sa);
    }
    cout<<"New Sale Success!"<<endl;
    cout<<"Do You To New More Sell"<<endl;
    cout<<"Press Y to New Sell"<<endl;
    fflush(stdin);
  } while (toupper(getch()) == 'Y');
  fclose(sa);

  footerAny();
}

void saleMenu()
{
  char sel;
  do
  {
    system("cls");
    headerTable();

    cout<<setw(49)<<"---| Sale Menu |---"<<endl;
    cout<<setw(50)<<"Press [H] to History"<<endl;
    cout<<setw(47)<<"Press [S] to Sell"<<endl;
    puts("");

    footerReturn();

    fflush(stdin);
    sel = toupper(getche());
    system("cls");
    headerTable();
    switch (sel)
    {
    case 'H':
      saleHistory();
      footerAny();
      break;
    case 'S':
      saleNew();
      break;
    }
  } while (sel != 'X');
}

#include "product.cpp"

int stockAmount(char *code)
{
  pdSE = fopen("product.dat", "rb");
  int n = 0;
  for (;;){
    if (fread(&prodSE, sizeof(prodSE), 1, pdSE) != 1){
      if (feof(pdSE)){
        fclose(pdSE);
        break;
      }
    }
    n++;
    if (strcmp(prodSE.code, code) == 0){
      fclose(pdSE);
      return prodSE.amount;
    }
  }
  return -1;
}

void stockAdd()
{
  if ((pd = fopen("product.dat", "r+b")) == NULL){
    cout<<"Open File 'product.dat' Error!"<<endl;
  }
  else{
    cout<<setw(49)<<"---| Add Stock |---"<<endl;
    char code[5];
    cout<<"Enter Code For Add Stock: "<<endl;
    fflush(stdin);
    gets(code);
    bool n = true;
    int num = sizeof(prod);
    for (;;){
      if (fread(&prod, sizeof(prod), 1, pd) != 1){
        if (feof(pd)){
          fclose(pd);
          break;
        }
      }
      if (strcmp(prod.code, code) == 0){
        int amount = 0;
        bool check;
        do{
          cout<<"Amount For Add In Stock : ";
          fflush(stdin);
          scanf("%d", &amount);
          if (amount >= 1){
            check = false;
          }
          else{
            cout<<"Amount Must Greater Than Or Equal To 1"<<endl;
            check = true;
          }
        } while (check);
        printf("New Total Amount : %d\n", prod.amount + amount);
        cout<<"Are You Sure Want To Add Amount In Stock"<<endl;
        cout<<"Press Y to Confirm!"<<endl;
        fflush(stdin);
        if (toupper(getch()) == 'Y'){
          prod.amount += amount;
          fseek(pd, -(num), SEEK_CUR);
          fwrite(&prod, num, 1, pd);
          fclose(pd);
        }
        else{
          cout<<"Cancel Edit!"<<endl;
        }
        n = false;
        break;
      }
    }
    if (n)
      cout<<"\nThis Code Not Found In Product List!"<<endl;
    footerAny();
  }
}

void stockDown(char *code, int amount)
{
  pd = fopen("product.dat", "r+b");
  int n = stockAmount(code);
  int num = sizeof(prod);
  for (;;){
    if (fread(&prod, sizeof(prod), 1, pd) != 1){
      if (feof(pd)){
        fclose(pd);
        break;
      }
    }
    if (strcmp(prod.code, code) == 0){
      float price = prod.price;
      prod.amount -= amount;
      fseek(pd, -(num), SEEK_CUR);
      fwrite(&prod, num, 1, pd);
      fclose(pd);
      // return price;
      break;
    }
  }
}

void stockEdit()
{
  if ((pd = fopen("product.dat", "r+b")) == NULL){
    cout<<"Open File 'product.dat' Error!"<<endl;
  }
  else{
    cout<<setw(50)<<"---| Edit Stock |---"<<endl;
    char code[5];
    cout<<"Enter Code For Edit Stock: ";
    fflush(stdin);
    gets(code);
    int n = stockAmount(code);
    if (n >= 0){
      int num = sizeof(prod);
      for (;;){
        if (fread(&prod, sizeof(prod), 1, pd) != 1){
          if (feof(pd)){
            fclose(pd);
            break;
          }
        }
        if (strcmp(prod.code, code) == 0){
          bool ab = true;
          do{
            cout<<"Amount For Edit In Stock : ";
            fflush(stdin);
            scanf("%d", &prod.amount);
            if (prod.amount >= 0){
              ab = false;
            }
            else{
              ab = true;
              cout<<"Amount Must Greater Than Or Equal To 0"<<endl;
            }
          } while (ab);
          cout<<"Are You Sure Want To Edit Amount In Stock"<<endl;
          cout<<"Press Y to Confirm!"<<endl;
          fflush(stdin);
          if (toupper(getch()) == 'Y'){
            fseek(pd, -(num), SEEK_CUR);
            fwrite(&prod, num, 1, pd);
            fclose(pd);
          }
          else{
            cout<<"Cancel Edit!"<<endl;
          }
          n = false;
          break;
        }
      }
    }
    else{
      cout<<"\nThis Code Not Found In Product List!"<<endl;
    }
    footerAny();
  }
}

void stockMenu()
{
  char sel;
  do{
    system("cls");
    headerTable();
    cout<<setw(50)<<"---| Stock Menu |---"<<endl;
    cout<<setw(47)<<"Press [A] to Add"<<endl;
    cout<<setw(48)<<"Press [E] to Edit"<<endl;
    puts("");

    footerReturn();

    fflush(stdin);
    sel = toupper(getche());
    system("cls");
    headerTable();
    switch (sel)
    {
    case 'A':
      stockAdd();
      break;
    case 'E':
      stockEdit();
      break;
    }
  } while (sel != 'X');
}

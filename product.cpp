#include "type.cpp"

struct product{
  // char code[8];
  char code[5];
  char name[20];
  float price;
  int amount;
  int type; // type code
} prod,prodCP,prodSE;

FILE *pd, *pdCP, *pdSE;

char *productName(char *code){
  pdSE = fopen("product.dat", "rb");
  int n = 0;
  for(;;){
    if(fread(&prodSE, sizeof(prodSE), 1, pdSE) != 1){
      if(feof(pdSE)){
        fclose(pdSE);
        break;
      }
    }
    n++;
    if(strcmp(prodSE.code, code) == 0){
      fclose(pdSE);
      return prodSE.name;
    }
  }
  char unknow[20];
  strcpy(unknow, "Unknow");

  return unknow;
}

float productPrice(char *code){
  pdSE = fopen("product.dat", "rb");
  int n = 0;
  for(;;){
    if(fread(&prodSE, sizeof(prodSE), 1, pdSE) != 1){
      if(feof(pdSE)){
        fclose(pdSE);
        break;
      }
    }
    n++;
    if(strcmp(prodSE.code, code) == 0){
      fclose(pdSE);
      return prodSE.price;
    }
  }

  return -1;
}

void productList(){
  bool n = true;
  if((pd = fopen("product.dat", "rb")) == NULL){
    printf("Open File 'product.dat' Error!\n");
  }else{
    if(fread(&prod, sizeof(prod), 1, pd) != 1){
      if(feof(pd)){
        fclose(pd);
        n = false;
        cout<<"Don't Have Any Product!"<<endl;
      }
    }
    if(n){
      cout<<setw(45)<<"---| Product List |---"<<endl;
      cout<<"---------------------------------------------------------------------"<<endl;;
      cout<<"   Code                 Name       Price  Amount                 Type"<<endl;
      cout<<"---------------------------------------------------------------------"<<endl;
      for(;;){
        printf("%7s%6s%21s%12.2f%8d%21s\n", " ", prod.code, prod.name, prod.price, prod.amount, typeDisplay(prod.type));

        if(fread(&prod, sizeof(prod), 1, pd) != 1){
          if(feof(pd)){
            fclose(pd);
            break;
          }
        }
      }
      cout<<"---------------------------------------------------------------------"<<endl;
    }
  }
}

void productAdd()
{
  pd = fopen("product.dat", "ab");
  do{
    cout<<setw(45)<<"---| Add New Product |---"<<endl;
    cout<<"Add New Product"<<endl;
    cout<<"Code : ";
    fflush(stdin);
    gets(prod.code);
    cout<<"Name : ";
    fflush(stdin);
    gets(prod.name);
    bool n = true;
    do{
      cout<<"Price : ";
      fflush(stdin);
      scanf("%f", &prod.price);
      if(prod.price >= 1){
        n = false;
      }
      else{
        cout<<"Price Must Greater Than Or Equal To 1"<<endl;
        n = true;
      }
    } while (n);
    do{
      cout<<"Amount : ";
      fflush(stdin);
      scanf("%d", &prod.amount);
      if(prod.amount >= 0){
        n = false;
      }
      else{
        n = true;
        cout<<"Amount Must Greater Than Or Equal To 0"<<endl;
      }
    }while(n);
    cout<<endl;
    typeList();
    cout<<endl;
    n = false;
    do{
      cout<<"\nType : ";
      fflush(stdin);
      scanf("%d", &prod.type);
      int check = typeSearch(prod.type);
      if(check < 0){
        cout<<"\nThis Code Not Found In Type List!"<<endl;
        n = true;
      }
      else{
        n = false;
      }
    }while(n);

    // printf("This Product Will Be Code : %s", prod.code);

    cout<<"Are You Sure Want To Add New Product"<<endl;
    cout<<"Press Y To Confirm!"<<endl;
    fflush(stdin);
    if(toupper(getch()) == 'Y'){
      fwrite(&prod, sizeof(prod), 1, pd);
      cout<<"Add New Product Success!"<<endl;
    }
    else{
      cout<<"Cancel Add New Product!"<<endl;
    }
    cout<<"Do You To Add More New Product?"<<endl;
    cout<<"Press Y to Add More"<<endl;
    fflush(stdin);
  }while(toupper(getch()) == 'Y');
  fclose(pd);

  footerAny();
}

void productEdit(){
  if((pd = fopen("product.dat", "r+b")) == NULL){
    cout<<"Open File 'product.dat' Error!"<<endl;
  }else{
    int num = sizeof(prod);
    cout<<setw(45)<<"---| Edit Product |---"<<endl;
    char code[5];
    cout<<"Enter Code For Edit Product: ";
    fflush(stdin);
    gets(code);
    bool n = true;
    for(;;){
      if(fread(&prod, sizeof(prod), 1, pd) != 1){
        if(feof(pd)){
          fclose(pd);
          break;
        }
      }
      if(strcmp(prod.code, code) == 0){
        cout<<"New Value For Edit!"<<endl;
        cout<<"Do You Want To Edit Code"<<endl;
        cout<<"Press Y To Yes!"<<endl;
        fflush(stdin);
        if(toupper(getch()) == 'Y'){
          cout<<"Code : ";
          fflush(stdin);
          gets(prod.code);
        }
        cout<<"Do You Want To Edit Name"<<endl;
        cout<<"Press Y To Yes!"<<endl;
        fflush(stdin);
        if(toupper(getch()) == 'Y'){
          cout<<"Name : ";
          fflush(stdin);
          gets(prod.name);
        }
        cout<<"Do You Want To Edit Price"<<endl;
        cout<<"Press Y To Yes!"<<endl;
        fflush(stdin);
        if(toupper(getch()) == 'Y'){
          do{
            cout<<"Price : ";
            fflush(stdin);
            scanf("%f", &prod.price);
            if(prod.price >= 1){
              n = false;
            }
            else{
              cout<<"Price Must Greater Than Or Equal To 1"<<endl;
              n = true;
            }
          } while(n);
        }
        cout<<"Do You Want To Edit Type"<<endl;
        cout<<"Press Y To Yes!"<<endl;
        fflush(stdin);
        if(toupper(getch()) == 'Y'){
          bool n = false;
          cout<<endl;
          typeList();
          cout<<endl;
          do{
            fflush(stdin);
            cout<<"\nType : ";
            scanf("%d", &prod.type);
            int check = typeSearch(prod.type);
            // fflush(stdin);
            // gets(prod.type);
            if(check < 0){
              cout<<"\nThis Code Not Found In Type List!"<<endl;
              n = true;
            }
            else{
              n = false;
            }
          } while (n);
        }
        cout<<"Are You Sure Want To Edit Product"<<endl;
        cout<<"Press Y to Confirm!"<<endl;
        fflush(stdin);
        if(toupper(getch()) == 'Y'){
          fseek(pd, -(num), SEEK_CUR);
          fwrite(&prod, num, 1, pd);
          fclose(pd);
          cout<<"Edit Product Success!"<<endl;
        }
        else{
          cout<<"Cancel Edit!"<<endl;
        }
        n = false;
        break;
      }
    }
    if(n)
      cout<<"Search This Code Not Found"<<endl;
  }

  footerAny();
}

void productDel()
{

  pdCP = fopen("backupbreak.dat", "wb");
  if((pd = fopen("product.dat", "rb")) == NULL)
    cout<<"Open File 'product.dat' Error!"<<endl;
  else{
    cout<<"---| Delete Product |---"<<endl;
    bool n = true;
    char code[5];
    cout<<"Code for Delete Product: ";
    fflush(stdin);
    gets(code);
    for (;;){
      if(fread(&prod, sizeof(prod), 1, pd) != 1){
        if(feof(pd)){
          fclose(pd);
          break;
        }
      }
      if(strcmp(prod.code, code) != 0){
        fwrite(&prod, sizeof(prod), 1, pdCP);
      }
      else{
        cout<<"Are You Sure Want To Delete Product"<<endl;
        cout<<"Press Y to Confirm!"<<endl;
        fflush(stdin);
        if(toupper(getch()) != 'Y'){
          fwrite(&prod, sizeof(prod), 1, pdCP);
        }
        n = false;
      }
    }
    if(n)
      cout<<"Search This Code Not Found"<<endl;
  }

  fclose(pdCP);
  remove("product.dat");
  rename("backupbreak.dat", "product.dat");

  cout<<"Delete Product Success!"<<endl;

  footerAny();
}

void productMenu()
{
  char sel;
  do{
    system("cls");
    headerTable();
    cout<<setw(50)<<"---| Product Menu |---"<<endl;
    cout<<setw(46)<<"Press [L] to List"<<endl;
    cout<<setw(45)<<"Press [N] to New"<<endl;
    cout<<setw(46)<<"Press [E] to Edit"<<endl;
    cout<<setw(48)<<"Press [D] to Delete"<<endl;
    puts("");

    footerReturn();

    fflush(stdin);
    sel = toupper(getche());
    system("cls");
    headerTable();
    switch (sel)
    {
    case 'L':
      productList();
      footerAny();
      break;
    case 'N':
      productAdd();
      break;
    case 'E':
      productEdit();
      break;
    case 'D':
      productDel();
      break;
    }
  } while (sel != 'X');
}
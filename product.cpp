
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
        char mes[40] = "Don't Have Any Product!";
        printf("%*s\n", 41 + strlen(mes) / 2, mes, 40 - strlen(mes) / 2, "");
      }
    }
    if(n){
      char head[40] = "---| Product List |---";
      printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
      printf("%6s---------------------------------------------------------------------\n", " ");
      printf("%6s   Code                 Name       Price  Amount                 Type\n", " ");
      printf("%6s---------------------------------------------------------------------\n", " ");
      for(;;){
        printf("%7s%6s%21s%12.2f%8d%21s\n", " ", prod.code, prod.name, prod.price, prod.amount, typeDisplay(prod.type));

        if(fread(&prod, sizeof(prod), 1, pd) != 1){
          if(feof(pd)){
            fclose(pd);
            break;
          }
        }
      }
      printf("%6s---------------------------------------------------------------------\n", " ");
    }
  }
}

void productAdd()
{
  pd = fopen("product.dat", "ab");
  do{
    char head[40] = "---| Add New Product |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    printf("Add New Product\n");
    printf("Code : ");
    fflush(stdin);
    gets(prod.code);
    printf("Name : ");
    fflush(stdin);
    gets(prod.name);
    bool n = true;
    do
    {
      printf("Price : ");
      fflush(stdin);
      scanf("%f", &prod.price);
      if (prod.price >= 1)
      {
        n = false;
      }
      else
      {
        printf("Price Must Greater Than Or Equal To 1\n");
        n = true;
      }
    } while (n);
    do
    {
      printf("Amount : ");
      fflush(stdin);
      scanf("%d", &prod.amount);
      if (prod.amount >= 0)
      {
        n = false;
      }
      else
      {
        n = true;
        printf("Amount Must Greater Than Or Equal To 0\n");
      }
    }while(n);
    printf("\n");
    typeList();
    printf("\n");
    n = false;
    do{
      printf("\nType : ");
      fflush(stdin);
      scanf("%d", &prod.type);
      int check = typeSearch(prod.type);
      if (check < 0){
        printf("\nThis Code Not Found In Type List!\n");
        n = true;
      }
      else{
        n = false;
      }
    }while(n);

    // printf("This Product Will Be Code : %s", prod.code);

    printf("Are You Sure Want To Add New Product\n");
    printf("Press Y To Confirm!\n");
    fflush(stdin);
    if(toupper(getch()) == 'Y'){
      fwrite(&prod, sizeof(prod), 1, pd);
      printf("Add New Product Success!\n\n");
    }
    else{
      printf("Cancel Add New Product!\n\n");
    }
    printf("Do You To Add More New Product?\n");
    printf("Press Y to Add More\n");
    fflush(stdin);
  }while(toupper(getch()) == 'Y');
  fclose(pd);

  footerAny();
}

void productEdit()
{
  if ((pd = fopen("product.dat", "r+b")) == NULL)
  {
    printf("Open File 'product.dat' Error!\n");
  }
  else
  {
    int num = sizeof(prod);
    char head[40] = "---| Edit Product |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    char code[5];
    printf("Enter Code For Edit Product: ");
    fflush(stdin);
    gets(code);
    bool n = true;
    for (;;)
    {
      if (fread(&prod, sizeof(prod), 1, pd) != 1)
      {
        if (feof(pd))
        {
          fclose(pd);
          break;
        }
      }
      if (strcmp(prod.code, code) == 0)
      {
        printf("New Value For Edit!\n");
        printf("Do You Want To Edit Code\n");
        printf("Press Y To Yes!\n");
        fflush(stdin);
        if (toupper(getch()) == 'Y')
        {
          printf("Code : ");
          fflush(stdin);
          gets(prod.code);
        }
        printf("Do You Want To Edit Name\n");
        printf("Press Y To Yes!\n");
        fflush(stdin);
        if (toupper(getch()) == 'Y')
        {
          printf("Name : ");
          fflush(stdin);
          gets(prod.name);
        }
        printf("Do You Want To Edit Price\n");
        printf("Press Y To Yes!\n");
        fflush(stdin);
        if (toupper(getch()) == 'Y')
        {
          do
          {
            printf("Price : ");
            fflush(stdin);
            scanf("%f", &prod.price);
            if (prod.price >= 1)
            {
              n = false;
            }
            else
            {
              printf("Price Must Greater Than Or Equal To 1\n");
              n = true;
            }
          } while (n);
        }
        printf("Do You Want To Edit Type\n");
        printf("Press Y To Yes!\n");
        fflush(stdin);
        if (toupper(getch()) == 'Y')
        {
          bool n = false;
          printf("\n");
          typeList();
          printf("\n");
          do
          {
            fflush(stdin);
            printf("\nType : ");
            scanf("%d", &prod.type);
            int check = typeSearch(prod.type);
            // fflush(stdin);
            // gets(prod.type);
            if (check < 0)
            {
              printf("\nThis Code Not Found In Type List!\n");
              n = true;
            }
            else
            {
              n = false;
            }
          } while (n);
        }
        printf("Are You Sure Want To Edit Product\n");
        printf("Press Y to Confirm!\n");
        fflush(stdin);
        if (toupper(getch()) == 'Y')
        {
          fseek(pd, -(num), SEEK_CUR);
          fwrite(&prod, num, 1, pd);
          fclose(pd);
          printf("Edit Product Success!\n");
        }
        else
        {
          printf("Cancel Edit!\n");
        }
        n = false;
        break;
      }
    }
    if (n)
      printf("Search This Code Not Found\n");
  }

  footerAny();
}

void productDel()
{

  pdCP = fopen("backupbreak.dat", "wb");
  if ((pd = fopen("product.dat", "rb")) == NULL)
    printf("Open File 'product.dat' Error!\n");
  else
  {
    char head[40] = "---| Delete Product |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    bool n = true;
    char code[5];
    printf("Code for Delete Product: ");
    fflush(stdin);
    gets(code);
    for (;;)
    {
      if (fread(&prod, sizeof(prod), 1, pd) != 1)
      {
        if (feof(pd))
        {
          fclose(pd);
          break;
        }
      }
      if (strcmp(prod.code, code) != 0)
      {
        fwrite(&prod, sizeof(prod), 1, pdCP);
      }
      else
      {
        printf("Are You Sure Want To Delete Product\n");
        printf("Press Y to Confirm!\n");
        fflush(stdin);
        if (toupper(getch()) != 'Y')
        {
          fwrite(&prod, sizeof(prod), 1, pdCP);
        }
        n = false;
      }
    }
    if (n)
      printf("Search This Code Not Found\n");
  }

  fclose(pdCP);
  remove("product.dat");
  rename("backupbreak.dat", "product.dat");

  printf("Delete Product Success!\n");

  footerAny();
}

void productMenu()
{
  char sel;
  do
  {
    system("cls");
    headerTable();
    char head[40] = "---| Product Menu |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    char menu1[40] = "Press [L] to List";
    printf("%*s\n", 41 + strlen(menu1) / 2, menu1, 40 - strlen(menu1) / 2, "");
    char menu2[40] = "Press [N] to New";
    printf("%*s\n", 41 + strlen(menu2) / 2, menu2, 40 - strlen(menu2) / 2, "");
    char menu3[40] = "Press [E] to Edit";
    printf("%*s\n", 41 + strlen(menu3) / 2, menu3, 40 - strlen(menu3) / 2, "");
    char menu4[40] = "Press [D] to Delete";
    printf("%*s\n", 41 + strlen(menu4) / 2, menu4, 40 - strlen(menu4) / 2, "");
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
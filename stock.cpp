#include "product.cpp"

int stockAmount(char *code)
{
  pdSE = fopen("product.dat", "rb");
  int n = 0;
  for (;;)
  {
    if (fread(&prodSE, sizeof(prodSE), 1, pdSE) != 1)
    {
      if (feof(pdSE))
      {
        fclose(pdSE);
        break;
      }
    }
    n++;
    if (strcmp(prodSE.code, code) == 0)
    {
      fclose(pdSE);
      return prodSE.amount;
    }
  }
  return -1;
}

void stockAdd()
{
  if ((pd = fopen("product.dat", "r+b")) == NULL)
  {
    printf("Open File 'product.dat' Error!\n");
  }
  else
  {
    char head[40] = "---| Add Stock |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    char code[5];
    printf("Enter Code For Add Stock: ");
    fflush(stdin);
    gets(code);
    bool n = true;
    int num = sizeof(prod);
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
        int amount = 0;
        bool check;
        do
        {
          printf("Amount For Add In Stock : ");
          fflush(stdin);
          scanf("%d", &amount);
          if (amount >= 1)
          {
            check = false;
          }
          else
          {
            printf("Amount Must Greater Than Or Equal To 1\n");
            check = true;
          }
        } while (check);
        printf("New Total Amount : %d\n", prod.amount + amount);
        printf("Are You Sure Want To Add Amount In Stock\n");
        printf("Press Y to Confirm!\n");
        fflush(stdin);
        if (toupper(getch()) == 'Y')
        {
          prod.amount += amount;
          fseek(pd, -(num), SEEK_CUR);
          fwrite(&prod, num, 1, pd);
          fclose(pd);
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
      printf("\nThis Code Not Found In Product List!\n");
    footerAny();
  }
}

void stockDown(char *code, int amount)
{
  pd = fopen("product.dat", "r+b");
  int n = stockAmount(code);
  int num = sizeof(prod);
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
  if ((pd = fopen("product.dat", "r+b")) == NULL)
  {
    printf("Open File 'product.dat' Error!\n");
  }
  else
  {
    char head[40] = "---| Edit Stock |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    char code[5];
    printf("Enter Code For Edit Stock: ");
    fflush(stdin);
    gets(code);
    int n = stockAmount(code);
    if (n >= 0)
    {
      int num = sizeof(prod);
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
          bool ab = true;
          do
          {
            printf("Amount For Edit In Stock : ");
            fflush(stdin);
            scanf("%d", &prod.amount);
            if (prod.amount >= 0)
            {
              ab = false;
            }
            else
            {
              ab = true;
              printf("Amount Must Greater Than Or Equal To 0\n");
            }
          } while (ab);
          printf("Are You Sure Want To Edit Amount In Stock\n");
          printf("Press Y to Confirm!\n");
          fflush(stdin);
          if (toupper(getch()) == 'Y')
          {
            fseek(pd, -(num), SEEK_CUR);
            fwrite(&prod, num, 1, pd);
            fclose(pd);
          }
          else
          {
            printf("Cancel Edit!\n");
          }
          n = false;
          break;
        }
      }
    }
    else
    {
      printf("\nThis Code Not Found In Product List!\n");
    }
    footerAny();
  }
}

void stockMenu()
{
  char sel;
  do
  {
    system("cls");
    headerTable();
    char head[40] = "---| Stock Menu |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    char menu1[40] = "Press [A] to Add";
    printf("%*s\n", 41 + strlen(menu1) / 2, menu1, 40 - strlen(menu1) / 2, "");
    char menu2[40] = "Press [E] to Edit";
    printf("%*s\n", 41 + strlen(menu2) / 2, menu2, 40 - strlen(menu2) / 2, "");
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

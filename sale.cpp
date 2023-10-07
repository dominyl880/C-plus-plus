#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h>
#include <iostream>

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
  if ((sa = fopen("sale.dat", "rb")) == NULL)
  {
    printf("Open File 'sale.dat' Error!\n");
  }
  else
  {
    if (fread(&sale, sizeof(sale), 1, sa) != 1)
    {
      if (feof(sa))
      {
        fclose(sa);
        n = false;
      }
    }
    if (n)
    {
      char head[40] = "---| History Sale |---";
      printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
      printf("---------------------------------------------------------------------------------\n");
      printf("             Customer   Code              Product      Price   Amount        Net\n");
      printf("---------------------------------------------------------------------------------\n");
      for (;;)
      {
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
      printf("---------------------------------------------------------------------------------\n");
    }
  }
}

void saleNew()
{

  do
  {
    char head[40] = "======>| New Sell |<======";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    sa = fopen("sale.dat", "ab");
    int n;
    bool check;
    productList();
    do
    {
      printf("Enter Product Code : ");
      fflush(stdin);
      gets(sale.code);
      n = stockAmount(sale.code);
      if (n < 0)
      {
        check = true;
        printf("Search This Code Not Found\n");
      }
      else if (n == 0)
      {
        check = true;
        printf("This Product Is Out Of Stock\n");
      }
      else
      {
        check = false;
      }
    } while (check);
    printf("Customer Name : ");
    fflush(stdin);
    gets(sale.cus);

    do
    {
      printf("Amount : ");
      fflush(stdin);
      scanf("%d", &sale.amount);
      if (sale.amount < 0)
      {
        printf("Wrong Number Input!\n");
        check = true;
      }
      else if (sale.amount == 0)
      {
        printf("Number Input Must Greater Than Or Equal To 1\n");
        check = true;
      }
      else if (sale.amount > n)
      {
        check = true;
        printf("Don't Have Product In Stock Not Enough\n");
      }
      else
      {
        check = false;
      }
    } while (check);

    sale.price = productPrice(sale.code);

    printf("Net Price : %.2f \n", sale.price * sale.amount);

    printf("Are You Sure Want To New Sell\n");
    printf("Press Y To Confirm!\n");
    fflush(stdin);
    if (toupper(getch()) == 'Y')
    {
      stockDown(sale.code, sale.amount);
      fwrite(&sale, sizeof(sale), 1, sa);
    }
    printf("New Sale Success!\n\n");
    printf("Do You To New More Sell\n");
    printf("Press Y to New Sell\n");
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

    char head[40] = "---| Sale Menu |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    char menu1[40] = "Press [H] to History";
    printf("%*s\n", 41 + strlen(menu1) / 2, menu1, 40 - strlen(menu1) / 2, "");
    char menu2[40] = "Press [S] to Sell";
    printf("%*s\n", 41 + strlen(menu2) / 2, menu2, 40 - strlen(menu2) / 2, "");
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

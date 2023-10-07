#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h> 

FILE *fp, *cp;

struct product
{
  char code[5];
  char name[20];
  float price;
  int amount;
  char type[3]; // type code
} pd;

struct sale
{
  char code[5]; // product code
  char cus[20]; // customer name
  float price;
  int amount;
} sa;

struct type
{
  char code[3];
  char name[20];
} ty;

void backup()
{
  bool n = true;
  char head[40] = "---| Processing Backup |---";
  printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");

  cp = fopen("productbackup.dat", "wb");
  if ((fp = fopen("product.dat", "rb")) == NULL)
    printf("Open File 'product.dat' Error!\n");
  else
  {
    printf("Processing Backup 'product.dat'.....\n");
    for (;;)
    {
      if (fread(&pd, sizeof(pd), 1, fp) != 1)
      {
        if (feof(fp))
        {
          fclose(fp);
          break;
        }
      }
      fwrite(&pd, sizeof(pd), 1, cp);
      n = false;
    }
    if (n)
      printf("Not Thing In File 'product.dat'!..\n");
    else
    {
      printf("Bakcup 'product.dat' Complete.\n");
    }
  }
  fclose(cp);

  n = true;

  cp = fopen("typebackup.dat", "wb");
  if ((fp = fopen("type.dat", "rb")) == NULL)
    printf("Open File 'type.dat' Error!\n");
  else
  {
    printf("Processing Backup 'type.dat'.....\n");
    for (;;)
    {
      if (fread(&ty, sizeof(ty), 1, fp) != 1)
      {
        if (feof(fp))
        {
          fclose(fp);
          break;
        }
      }
      fwrite(&ty, sizeof(ty), 1, cp);
      n = false;
    }
    if (n)
      printf("Not Thing In File 'type.dat'!..\n");
    else
    {
      printf("Bakcup 'type.dat' Complete.\n");
    }
  }
  fclose(cp);

  n = true;

  cp = fopen("salebackup.dat", "wb");
  if ((fp = fopen("sale.dat", "rb")) == NULL)
    printf("Open File 'sale.dat' Error!\n");
  else
  {
    printf("Processing Backup 'sale.dat'.....\n");
    for (;;)
    {
      if (fread(&sa, sizeof(sa), 1, fp) != 1)
      {
        if (feof(fp))
        {
          fclose(fp);
          break;
        }
      }
      fwrite(&sa, sizeof(sa), 1, cp);
      n = false;
    }
    if (n)
      printf("Not Thing In File 'sale.dat'!..\n");
    else
    {
      printf("Bakcup 'sale.dat' Complete.\n");
    }
  }
  fclose(cp);

  printf("Process Backup Done!\n\n");
}

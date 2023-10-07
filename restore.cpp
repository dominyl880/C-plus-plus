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

void restore()
{
  bool n;
  char head[40] = "---| Processing Restore |---";
  printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");

  n = true;

  cp = fopen("productstore.dat", "wb");
  if ((fp = fopen("productbackup.dat", "rb")) == NULL)
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
  }
  fclose(cp);
  remove("product.dat");
  rename("productstore.dat", "product.dat");

  n = true;

  cp = fopen("typestore.dat", "wb");
  if ((fp = fopen("typebackup.dat", "rb")) == NULL)
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
  }
  fclose(cp);
  remove("type.dat");
  rename("typestore.dat", "type.dat");

  n = true;

  cp = fopen("salestore.dat", "wb");
  if ((fp = fopen("salebackup.dat", "rb")) == NULL)
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
  }
  fclose(cp);
  remove("sale.dat");
  rename("salestore.dat", "sale.dat");

  printf("Process Restore Done!\n\n");
}

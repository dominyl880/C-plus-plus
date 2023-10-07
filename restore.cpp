#include "head.cpp"

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
  cout<<"---| Processing Restore |---"<<endl;

  n = true;

  cp = fopen("productstore.dat", "wb");
  if ((fp = fopen("productbackup.dat", "rb")) == NULL)
    cout<<"Open File 'product.dat' Error!"<<endl;
  else{
    cout<<"Processing Backup 'product.dat'....."<<endl;
    for (;;){
      if (fread(&pd, sizeof(pd), 1, fp) != 1){
        if (feof(fp)){
          fclose(fp);
          break;
        }
      }
      fwrite(&pd, sizeof(pd), 1, cp);
      n = false;
    }
    if (n)
      cout<<"Not Thing In File 'product.dat'!.."<<endl; 
  }
  fclose(cp);
  remove("product.dat");
  rename("productstore.dat", "product.dat");

  n = true;

  cp = fopen("typestore.dat", "wb");
  if ((fp = fopen("typebackup.dat", "rb")) == NULL)
    cout<<"Open File 'type.dat' Error!"<<endl;
  else{
    cout<<"Processing Backup 'type.dat'....."<<endl;
    for (;;){
      if (fread(&ty, sizeof(ty), 1, fp) != 1){
        if (feof(fp)){
          fclose(fp);
          break;
        }
      }
      fwrite(&ty, sizeof(ty), 1, cp);
      n = false;
    }
    if (n)
      cout<<"Not Thing In File 'type.dat'!.."<<endl;
  }
  fclose(cp);
  remove("type.dat");
  rename("typestore.dat", "type.dat");

  n = true;

  cp = fopen("salestore.dat", "wb");
  if ((fp = fopen("salebackup.dat", "rb")) == NULL)
    cout<<"Open File 'sale.dat' Error!"<<endl;
  else{
    cout<<"Processing Backup 'sale.dat'....."<<endl;
    for (;;){
      if (fread(&sa, sizeof(sa), 1, fp) != 1){
        if (feof(fp)){
          fclose(fp);
          break;
        }
      }
      fwrite(&sa, sizeof(sa), 1, cp);
      n = false;
    }
    if (n)
      cout<<"Not Thing In File 'sale.dat'!.."<<endl;
  }
  fclose(cp);
  remove("sale.dat");
  rename("salestore.dat", "sale.dat");

  cout<<"Process Restore Done!"<<endl;
}

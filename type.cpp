#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h>
#include <iomanip>
#include <iostream>

#include "header.cpp"
#include "footer.cpp"

struct type
{
  int code;
  char name[20];
} type, typeCP, typeSE;

FILE *ty, *tyCP, *tySE;

int typeLast()
{
  tySE = fopen("type.dat", "rb");
  int n = 1;
  for (;;)
  {
    if (fread(&typeSE, sizeof(typeSE), 1, tySE) != 1)
    {
      if (feof(tySE))
      {
        fclose(tySE);
        break;
      }
    }
    // printf("" + typeSE.code);
    // printf("" + (typeSE.code + 1));

    n = typeSE.code + 1;
  }
  return n;
}

void typeList()
{

  bool n = true;
  if ((ty = fopen("type.dat", "rb")) == NULL)
  {
    printf("Open File 'type.dat' Error!\n");
  }
  else
  {
    if (fread(&type, sizeof(type), 1, ty) != 1)
    {
      if (feof(ty))
      {
        fclose(ty);
        n = false;
        char mes[40] = "Don't Have Any Type!";
        printf("%*s\n", 41 + strlen(mes) / 2, mes, 40 - strlen(mes) / 2, "");
      }
    }
    if (n)
    {
      char head[40] = "---| Type List |---";
      printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
      printf("%28s-------------------------\n", " ");
      printf("%28sCode                 Name\n", " ");
      printf("%28s-------------------------\n", " ");
      for (;;)
      {
        printf("%28s%4d%21s\n", " ", type.code, type.name);

        if (fread(&type, sizeof(type), 1, ty) != 1)
        {
          if (feof(ty))
          {
            fclose(ty);
            break;
          }
        }
      }
      printf("%28s-------------------------\n", " ");
    }
  }
}

void typeAdd()
{

  do
  {
    char head[40] = "---| Add New Type |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    ty = fopen("type.dat", "ab");
    printf("Code : ");
    int code = typeLast();
    printf("%d\n", code);
    type.code = code;
    // fflush(stdin);
    // gets(type.code);

    printf("Name : ");
    fflush(stdin);
    gets(type.name);
    printf("Are you sure want to Add new Type\n");
    printf("Press Y to Confirm!\n");
    fflush(stdin);
    if (toupper(getch()) == 'Y')
    {
      fwrite(&type, sizeof(type), 1, ty);
      printf("Add New Type Success!\n\n");
    }
    else
    {
      printf("Cancel Add New Type!\n\n");
    }
    fclose(ty);
    printf("Do You To Add More New Type?\n");
    printf("Press Y to Add More\n");
    fflush(stdin);
  } while (toupper(getch()) == 'Y');

  footerAny();
}

char *typeDisplay(int code)
{
  tySE = fopen("type.dat", "rb");
  int n = 0;
  for (;;)
  {
    if (fread(&typeSE, sizeof(typeSE), 1, tySE) != 1)
    {
      if (feof(tySE))
      {
        fclose(tySE);
        break;
      }
    }
    n++;
    if (typeSE.code == code)
    {
      fclose(tySE);
      return typeSE.name;
    }
  }
  char unknow[20];
  strcpy(unknow, "Unknow");

  return unknow;
}

int typeSearch(int code)
{
  tySE = fopen("type.dat", "rb");
  int n = 0;
  for (;;)
  {
    if (fread(&typeSE, sizeof(typeSE), 1, tySE) != 1)
    {
      if (feof(tySE))
      {
        fclose(tySE);
        break;
      }
    }
    n++;
    if (typeSE.code == code)
    {
      fclose(tySE);
      return code;
    }
  }
  return -1;
}

// char *typeGetCodeName(int code)
// {
//   tySE = fopen("type.dat", "rb");
//   int n = 0;
//   for (;;)
//   {
//     if (fread(&typeSE, sizeof(typeSE), 1, tySE) != 1)
//     {
//       if (feof(tySE))
//       {
//         fclose(tySE);
//         break;
//       }
//     }
//     n++;
//     if (typeSE.code == code)
//     {
//       fclose(tySE);

//       std::cout << std::setfill('0') << std::setw(2) << code;
//       char typeCodeName[4] = {typeSE.name[0], typeSE.name[1]};
//       return typeCodeName;
//     }
//   }
//   return "99ZZ";
// }

void typeEdit()
{
  int num = sizeof(type);
  if ((ty = fopen("type.dat", "r+b")) == NULL)
  {
    printf("Open File 'type.dat' Error!\n");
  }
  else
  {
    char head[40] = "---| Edit Type |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    int code;
    printf("Enter Code For Edit Type: ");
    fflush(stdin);
    scanf("%d", &code);
    bool n = true;
    for (;;)
    {
      if (fread(&type, sizeof(type), 1, ty) != 1)
      {
        if (feof(ty))
        {
          fclose(ty);
          break;
        }
      }
      if (type.code == code)
      {
        printf("New Value For Edit!\n");
        // printf("Code : ");
        printf("Name : ");
        fflush(stdin);
        gets(type.name);
        printf("Are you sure want to Edit Type?\n");
        printf("Press Y to Confirm!\n");
        fflush(stdin);
        if (toupper(getch()) == 'Y')
        {
          fseek(ty, -(num), SEEK_CUR);
          fwrite(&type, num, 1, ty);
          fclose(ty);
          printf("Edit Type Success!\n");
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

void typeDel()
{

  tyCP = fopen("backupbreak.dat", "wb");
  if ((ty = fopen("type.dat", "rb")) == NULL)
    printf("Open File 'type.dat' Error!\n");
  else
  {
    char head[40] = "---| Delete Type |---";
    printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
    bool n = true;
    int code;
    printf("Code for Delete Type: ");
    fflush(stdin);
    scanf("%d", &code);
    for (;;)
    {
      if (fread(&type, sizeof(type), 1, ty) != 1)
      {
        if (feof(ty))
        {
          fclose(ty);
          break;
        }
      }
      if (type.code != code)
      {
        fwrite(&type, sizeof(type), 1, tyCP);
      }
      else
      {
        printf("Are You Sure Want To Delete Type\n");
        printf("Press Y to Confirm!\n");
        fflush(stdin);
        if (toupper(getch()) != 'Y')
        {
          fwrite(&type, sizeof(type), 1, tyCP);
        }
        n = false;
      }
    }
    if (n)
      printf("Search This Code Not Found\n");
  }

  fclose(tyCP);
  remove("type.dat");
  rename("backupbreak.dat", "type.dat");

  printf("Delete Type Success!\n");

  footerAny();
}

void typeMenu()
{
  char sel;
  do
  {
    system("cls");
    headerTable();
    char head[40] = "---| Type Menu |---";
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
      typeList();
      footerAny();
      break;
    case 'N':
      typeAdd();
      break;
    case 'E':
      typeEdit();
      break;
    case 'D':
      typeDel();
      break;
    }
  } while (sel != 'X');
}

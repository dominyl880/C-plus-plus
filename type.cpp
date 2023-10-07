#include "head.cpp"
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
  for (;;){
    if (fread(&typeSE, sizeof(typeSE), 1, tySE) != 1){
      if (feof(tySE)){
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
  if ((ty = fopen("type.dat", "rb")) == NULL){
    cout<<"Open File 'type.dat' Error!"<<endl;
  }
  else{
    if (fread(&type, sizeof(type), 1, ty) != 1){
      if (feof(ty)){
        fclose(ty);
        n = false;
        cout<<"Don't Have Any Type!"<<endl;
      }
    }
    if (n){
      char head[40] = "---| Type List |---";
      printf("%*s\n", 41 + strlen(head) / 2, head, 40 - strlen(head) / 2, "");
      cout<<"---| Type List |---"<<endl;
      cout<<"-------------------------"<<endl;
      cout<<"Code                 Name"<<endl;
      cout<<"-------------------------"<<endl;
      for (;;){
        printf("%28s%4d%21s\n", " ", type.code, type.name);

        if (fread(&type, sizeof(type), 1, ty) != 1){
          if (feof(ty)){
            fclose(ty);
            break;
          }
        }
      }
      cout<<"-------------------------"<<endl; 
    }
  }
}

void typeAdd()
{

  do{
    cout<<"---| Add New Type |---"<<endl;
    ty = fopen("type.dat", "ab");
    cout<<"Code : ";
    int code = typeLast();
    printf("%d\n", code);
    type.code = code;
    // fflush(stdin);
    // gets(type.code);

    cout<<"Name : ";
    fflush(stdin);
    gets(type.name);
    cout<<"Are you sure want to Add new Type"<<endl;
    cout<<"Press Y to Confirm!"<<endl;
    fflush(stdin);
    if (toupper(getch()) == 'Y'){
      fwrite(&type, sizeof(type), 1, ty);
      cout<<"Add New Type Success!"<<endl;
    }
    else{
      cout<<"Cancel Add New Type!"<<endl;
    }
    fclose(ty);
    cout<<"Do You To Add More New Type?"<<endl;
    cout<<"Press Y to Add More"<<endl;
    fflush(stdin);
  } while (toupper(getch()) == 'Y');

  footerAny();
}

char *typeDisplay(int code)
{
  tySE = fopen("type.dat", "rb");
  int n = 0;
  for (;;){
    if (fread(&typeSE, sizeof(typeSE), 1, tySE) != 1){
      if (feof(tySE)){
        fclose(tySE);
        break;
      }
    }
    n++;
    if (typeSE.code == code){
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
  for (;;){
    if (fread(&typeSE, sizeof(typeSE), 1, tySE) != 1){
      if (feof(tySE)){
        fclose(tySE);
        break;
      }
    }
    n++;
    if (typeSE.code == code){
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
  if ((ty = fopen("type.dat", "r+b")) == NULL){
    cout<<"Open File 'type.dat' Error!"<<endl;
  }
  else{
    cout<<"---| Edit Type |---"<<endl;
    int code;
    cout<<"Enter Code For Edit Type: ";
    fflush(stdin);
    scanf("%d", &code);
    bool n = true;
    for (;;){
      if (fread(&type, sizeof(type), 1, ty) != 1){
        if (feof(ty)){
          fclose(ty);
          break;
        }
      }
      if (type.code == code){
        cout<<"New Value For Edit!"<<endl;
        // printf("Code : ");
        cout<<"Name : ";
        fflush(stdin);
        gets(type.name);
        cout<<"Are you sure want to Edit Type?"<<endl;
        cout<<"Press Y to Confirm!"<<endl;
        fflush(stdin);
        if (toupper(getch()) == 'Y'){
          fseek(ty, -(num), SEEK_CUR);
          fwrite(&type, num, 1, ty);
          fclose(ty);
          cout<<"Edit Type Success!"<<endl;
        }
        else{
          cout<<"Cancel Edit!"<<endl;
        }
        n = false;
        break;
      }
    }
    if (n)
      cout<<"Search This Code Not Found"<<endl;
  }

  footerAny();
}

void typeDel()
{

  tyCP = fopen("backupbreak.dat", "wb");
  if ((ty = fopen("type.dat", "rb")) == NULL)
    cout<<"Open File 'type.dat' Error!"<<endl;
  else{
    cout<<"---| Delete Type |---"<<endl;
    bool n = true;
    int code;
    cout<<"Code for Delete Type: ";
    fflush(stdin);
    scanf("%d", &code);
    for (;;){
      if (fread(&type, sizeof(type), 1, ty) != 1){
        if (feof(ty)){
          fclose(ty);
          break;
        }
      }
      if (type.code != code){
        fwrite(&type, sizeof(type), 1, tyCP);
      }
      else{
        cout<<"Are You Sure Want To Delete Type"<<endl;
        cout<<"Press Y to Confirm!"<<endl;
        fflush(stdin);
        if (toupper(getch()) != 'Y'){
          fwrite(&type, sizeof(type), 1, tyCP);
        }
        n = false;
      }
    }
    if (n)
      cout<<"Search This Code Not Found"<<endl;
  }

  fclose(tyCP);
  remove("type.dat");
  rename("backupbreak.dat", "type.dat");

  cout<<"Delete Type Success!"<<endl;

  footerAny();
}

void typeMenu()
{
  char sel;
  do{
    system("cls");
    headerTable();
    cout<<"---| Type Menu |---"<<endl;
    cout<<"Press [L] to List"<<endl;
    cout<<"Press [N] to New"<<endl;
    cout<<"Press [E] to Edit"<<endl;
    cout<<"Press [D] to Delete"<<endl;
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

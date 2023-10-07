///hello

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string.h>
#include <iostream>

#include "sale.cpp"
// #include "backup.cpp"
// #include "restore.cpp"

int main()
{
  char sel;
  do
  {
    system("cls");
    headerTable();
    char menu1[40] = "Press [P] to Product Menu Page";
    printf("%*s\n", 41 + strlen(menu1) / 2, menu1, 40 - strlen(menu1) / 2, "");
    char menu2[40] = "Press [T] to Type Menu Page";
    printf("%*s\n", 41 + strlen(menu2) / 2, menu2, 40 - strlen(menu2) / 2, "");
    char menu3[40] = "Press [C] to Stock Menu page";
    printf("%*s\n", 41 + strlen(menu3) / 2, menu3, 40 - strlen(menu3) / 2, "");
    char menu4[40] = "Press [S] to Sale Menu page";
    printf("%*s\n", 41 + strlen(menu4) / 2, menu4, 40 - strlen(menu4) / 2, "");
    // char menu5[40] = "Press [B] to Backup";
    // printf("%*s\n", 41 + strlen(menu5) / 2, menu5, 40 - strlen(menu5) / 2, "");
    // char menu5[40] = "Press [R] to Restore";
    // printf("%*s\n", 41 + strlen(menu5) / 2, menu5, 40 - strlen(menu5) / 2, "");
    puts("");

    footerExit();

    sel = toupper(getche());
    switch (sel)
    {
    case 'P':
      productMenu();
      break;
    case 'T':
      typeMenu();
      break;
    case 'C':
      stockMenu();
      break;
    case 'S':
      saleMenu();
      break;
      // case 'B':
      //   system("cls");
      //   headerTable();
      //   backup();
      //   footer();
      //   break;

      // case 'R':
      //   system("cls");
      //   headerTable();
      //   restore();
      //   // backup();
      //   footer();
      //   break;
    }
  } while (sel != 'X');
  return 0;
}

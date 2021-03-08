#include <iostream>
#include <cstring>
#include <conio.h>
#include <ctime>

#include "Lista.h"
#include "Stiva.h"
#include "notepad.h"
#include "CExceptie.h"
#include "CExceptieAlocare.h"
#include "FileStr.h"
#include "backupfile.h"

#define ESC 0x1b
#define line_feed 10

using namespace std;

int notepad::DEBUG = 0;

char* data_curenta(char *s)
{
    char zona[100];
    s[0] ='\0';
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(zona, "Data curenta: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    strcat(s, zona);
    return s;
}

int main(void)
{
    notepad ob1;
    backupfile ob2;
    do
    {
        system("cls");

        cout << "Aplicatie notepad" << endl;

        cout << "A. Deschidere notepad (apasati ESC pentru a iesi ...)" << endl;
        cout << "S. Afisare notepad" << endl;
        cout << "U. Undo" << endl;
        cout << "R. Redo" << endl;
        cout << "C. Cauta sir de caractere" << endl;
        cout << "F. Citire din fisier (import)" << endl;
        cout << "W. Backup (HTML)" << endl;
        cout << "D. Toggle DEBUG ON / OFF" << endl;
        cout << "O. Ora curenta" << endl;
        cout << "H. Meniu HELP" << endl;
        cout << "I. Informatii autor program" << endl;
        cout << "T. Exit" << endl;
        switch(toupper(getch()))
        {
            case 'A': ob1.Open(); getch(); break;
            case 'U': ob1.Undo(); getch(); break;
            case 'R': ob1.Redo(); getch(); break;
            case 'D': ob1.Toggle(); getch(); break;
            case 'S': cout << "Afisare fisier notepad\n" << endl; ob1.Afisare(); getch(); break;
            case 'C': ob1.Cauta("subsir"); getch(); break;
            case 'F': ob1.ReadFileStr("fisierintrare.txt"); getch(); break;
            case 'W': ob2.Backup(ob1); getch(); break;
            case 'O': char buf[100];
                      cout << data_curenta(buf); getch(); break;
            case 'I': cout << "Informatii autor: " << endl;
                      cout << "\tFulga Sergiu-Sebastian" << endl;
                      cout << "\thttps://github.com/sebastianfulga" << endl;
                      getch(); break;
            case 'H': cout << "https://github.com/sebastianfulga" << endl;
                      getch(); break;
            case 'T': cout << "<terminare program>"; exit(0);
            default: cout << "S-a introdus o valoarea gresita din meniu : ("; getch();
        }
    }
    while (true);
    return 0;
}

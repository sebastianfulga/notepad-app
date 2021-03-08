#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <iostream>
#include <cstring>
#include <conio.h>
#include "CExceptie.h"
#include "CExceptieAlocare.h"
#include "FileStr.h"

#include "Lista.h"
#include "Stiva.h"

#define ESC 0x1b
#define line_feed 10

using namespace std;

class notepad///: public stiva
{
    friend class backupfile;
    protected:
        static int DEBUG;
        char *sir;
        Stiva<char> s;
        Lista<char> l;
    public:
        notepad();
        notepad(const notepad &b);
        notepad& operator=(notepad &n);
        void Open(void);
        void Afisare(void);
        void Undo(void);
        void Redo(void);
        void Toggle(void);
        void Cauta(const char *subsir);
        void ReadFileStr(const char *numeFisier);
        ~notepad();
};

#endif // NOTEPAD_H

#ifndef FILESTR_H
#define FILESTR_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>

#define X 10
#define NMAX 100

using namespace std;

class FileStr
{
    protected:
        fstream fp;
        char *nume;
    public:
        FileStr(void);
        FileStr(const char *name);
        operator const char(void);
        void operator = (char c);
        void operator = (const char *str);
        bool eof(void);
        virtual ~FileStr();
};

#endif // FILESTR_H

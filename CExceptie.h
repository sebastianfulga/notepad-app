#ifndef CEXCEPTIE_H
#define CEXCEPTIE_H

#include <iostream>
#include <cstring>
using namespace std;

class CExceptie
{
    protected:
        char *msg;
    public:
        CExceptie(void);
        virtual ~CExceptie();
        void AlocaExceptie(int n);
        void CopieExceptie(const char *mesaj);
        void Print(void);
};

#endif // CEXCEPTIE_H

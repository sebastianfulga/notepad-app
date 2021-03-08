#include "CExceptie.h"

CExceptie::CExceptie(void)
{
    msg = nullptr;
}

CExceptie::~CExceptie()
{
    if (msg)
        delete msg;
}

void CExceptie::AlocaExceptie(int n)
{
    msg = new char[n];
}

void CExceptie::CopieExceptie(const char *mesaj)
{
    strcpy(msg, mesaj);
}

void CExceptie::Print(void)
{
    cout << "Exceptie: " << msg;
}

#include "CExceptieAlocare.h"

CExceptieAlocare::CExceptieAlocare(): CExceptie()
{

}

CExceptieAlocare::~CExceptieAlocare()
{

}

void CExceptieAlocare::SetExceptie(const char *s)
{
    AlocaExceptie(strlen(s));
    CopieExceptie(s);
}

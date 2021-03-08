#ifndef CEXCEPTIEALOCARE_H
#define CEXCEPTIEALOCARE_H

#include "CExceptie.h"

class CExceptieAlocare: public CExceptie
{
    public:
        CExceptieAlocare();
        ~CExceptieAlocare();
        void SetExceptie(const char *s);
};

#endif // CEXCEPTIEALOCARE_H

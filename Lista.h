#ifndef LISTA_H
#define LISTA_H

#define NMAX 100
#define INCREMENT 0

#include <iostream>
using namespace std;

template<class T>
class Lista
{
    private:
        int nmax; // dimensiunea actuala a vectorului (initial = NMAX)
        int liber; // indicele primului element liber din vector(initial = 0)
        int inc; // incrementul cu care este extins vectorul
        T *pv; // pointer catre vector
    public:
        Lista(void);
        void inserare_in_fata(T x);
        void inserare_la_urma(T x);
        bool isFull(void);
        bool isEmpty(void);
        void Print(void);
        char* returnare(void);
        T ultimul(void);
        T primul(void);
        Lista& sterge_ultim(void);
        virtual ~Lista();
};

template<class T>
Lista<T>::Lista(void)
{
    this->nmax = NMAX;
    this->liber = 0;
    this->inc = INCREMENT;
    pv = new T [NMAX];
}

template<class T>
void Lista<T>::inserare_in_fata(T x)
{
    int i;
    if (isFull())
        cout << "Lista plina" << endl;
    if (isEmpty())
        this->pv[this->liber++] = x;
    else
    {
        for (i=this->liber-1; i>=0; i--)
            this->pv[i+1] = this->pv[i];
        this->pv[0] = x;
        this->liber++;
    }
}

template<class T>
Lista<T>::~Lista(void)
{
    delete []this->pv;
}

template<class T> /// cand declaram in afara clasei, punem iar template
void Lista<T>::inserare_la_urma(T x)
{
    if(isFull())
        cout << "Lista plina" << endl;
    this->pv[this->liber++] = x; // se insereaza elementul x
}

template<class T>
bool Lista<T>::isFull(void)
{
    return this->liber == this->nmax;
}

template<class T>
bool Lista<T>::isEmpty(void)
{
    return this->liber == 0;
}

template<class T>
void Lista<T>::Print(void)
{
    if (isEmpty())
    {
        cout << "Lista vida" << endl;
        return ;
    }
    cout << "Lista: ";
    for(int i = 0; i < this->liber; i++)
    {
        cout << this->pv[i]<< "";
    }
}

template<class T>
Lista<T>& Lista<T>::sterge_ultim(void)
{
    if(!isEmpty())
        this->liber--;
    return *this;
}

template<class T>
char* Lista<T>::returnare(void)
{
    char *buff = nullptr;
    int i;
    buff = new char[liber+1];
    for (i=0; i < this->liber; i++)
        buff[i] = this->pv[i];
    buff[i] = '\0';
    return buff;
}

template<class T>
T Lista<T>::ultimul(void)
{
    return this->pv[liber-1]; /// tinem cont ca ultimul caracter este terminatorul de sir
}

template<class T>
T Lista<T>::primul(void)
{
    return isEmpty() ? 0 : this->pv[0];
}

#endif // LISTA_H

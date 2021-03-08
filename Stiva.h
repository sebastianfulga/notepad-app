#ifndef STIVA_H
#define STIVA_H

#include <iostream>
using namespace std;

template<class T>
struct NOD
{
    T info;
    NOD *urm;
};

template<class T>
class Stiva
{
    NOD<T> *head;
    void Destroy( NOD<T> * );

    public:
        void push(T x); /// daca nu este void in realitate ia int
        /// cand aduci functia push in afara clasei trebuie sa pui Template ...
        Stiva(void);
        ~Stiva( ) {}
        void pop(void);
        T top(void);

        int isEmpty(void);

        int isFull(void);
        void Print( char *ob=NULL );
};

template <class T>
Stiva<T>::Stiva()
{
    head = (NOD<T>*)0;
}

template<class T> /// cand declaram in afara clasei, punem iar template
void Stiva<T>::push(T x)
{
    NOD<T> *t;
    t = new NOD<T>;
    if (t == (NOD<T>*)0)
        return ;
    t->info = x;
    t-> urm = head;
    head = t;
}

template<class T>
void Stiva<T>::pop(void)
{
    NOD<T> *t = head;
    if (!isEmpty())
    {
        head = head->urm;
        delete t;
    }
}

template<class T>
T Stiva<T>::top()
{
    if (!isEmpty())
        return head->info;
    else
        return -1;
}

template<class T>
int Stiva<T>::isEmpty(void)
{
    return head == (NOD<T>*)0 ? ~0 : 0;
}

template<class T>
int Stiva<T>::isFull(void)
{
    NOD<T> *t;
    t = new NOD<T>;
    if (t == (NOD<T>*)0)
        return 1;
    else
    {
        delete t;
        return 0;
    }
}

template<class T>
void Stiva<T>::Print(char *ob)
{
    NOD<T> *r = head;
    if (ob == NULL)
        cout << "\nSTIVA: {";
    else
        cout << "\n" << ob << ": {";
    while (r != (NOD<T>*)0)
    {
        cout << r->info << ", ";
        r = r-> urm;
    }
    if (!isEmpty())
        cout << "\b\b };" << endl;
    else
        cout << "\b };" << endl;
}

#endif // STIVA_H

#include "notepad.h"

notepad::notepad()
{
    if (DEBUG)
        cout << "\t[DEBUG ON] Constructorul clasei notepad ..." << endl;

    sir = new char[NMAX];
    strcpy(sir, "");
    sir[1] = '\0';
}

notepad::notepad(const notepad &b)
{
    if (this == &b)
        return ; /// se evita autocopierea
    this->sir = b.sir;
    this->s = b.s;
    this->l = b.l;
}

notepad& notepad::operator=(notepad &n)
{
    if (this == &n)
        return *this;
    this->sir = n.sir;
    this->s = n.s;
    this->l = n.l;
    return *this;
}

notepad::~notepad()
{
    delete sir;
    cout << "\t[DEBUG ON] Destructorul clasei notepad ..." << endl;
}

void notepad::Open(void)
{
    if (DEBUG)
        cout << "\t[DEBUG ON] Ne aflam in metoda Open a clasei notepad ..." << endl;
    cout << "Notepad (press ESC to exit the app): " << endl;
    char c;
    while ((c = getch()) != ESC)
    {
        if (c == '\r')
        {
            cout << endl;
            this->l.inserare_la_urma(line_feed);
            cout << c;
            continue;
        }
        if (c == '\b')
        {
            cout << '\b' << ' ';
            this->l.sterge_ultim();
            cout << c;
            continue;
        }
        cout << c;
        this->l.inserare_la_urma(c);
    }

    /// this->l.inserare_la_urma('\0');

    /// strcat(this->sir, l.returnare());

    cout << "\nIesire notepad ..." << endl;
}

void notepad::Undo(void)
{
    try
    {
        if (this->l.isEmpty())
            throw CExceptieAlocare();
    }
    catch (CExceptieAlocare &e)
    {
        e.SetExceptie("Nu putem face Undo, deoarece stiva este goala !");
        e.Print();
        return ;
    }

    this->s.push(l.ultimul());
    this->l.sterge_ultim();
    this->sir = l.returnare();
    cout << "Undo reusit" << endl;
}

void notepad::Redo(void)
{
    try
    {
        if (this->s.isEmpty())
            throw CExceptieAlocare();
    }
    catch(CExceptieAlocare &e)
    {
        e.SetExceptie("Nu putem face Redo, stiva fiind goala !");
        e.Print();
        return ;
    }

    this->l.inserare_la_urma(this->s.top());
    this->sir = l.returnare();
    this->s.pop();
    cout << "Redo reusit" << endl;
}

void notepad::Afisare(void)
{
    if (DEBUG)
        cout << "Fisierul nostru contine un numar de " << strlen(this->sir) << "octeti ! (un tip de data char are 1 byte)" << endl;

    /// cout << this->sir << endl;

    this->l.Print();
}

void notepad::Toggle(void)
{
    DEBUG = !DEBUG;
    if (DEBUG)
        cout << "DEBUG: ON" << endl;
    else
        cout << "DEBUG: OFF" << endl;
}

void notepad::Cauta(const char *subsir)
{
    char *p = strstr(this->sir, subsir);
    if (p != nullptr)
        cout << "Subsirul se afla pe pozitia " << p - this->sir;
}

void notepad::ReadFileStr(const char *numeFisier)
{
    FileStr f(numeFisier);
    while (!f.eof())
    {
        /// char c = (char)f;
        /// cout << c;
        this->l.inserare_la_urma((char)f);
    }

    /// strcat(this->sir, l.returnare());

    cout << "A avut loc citirea din fisier !" << endl;
}

#include "backupfile.h"

backupfile::backupfile(): notepad()
{
    if (DEBUG)
        cout << "Constructor clasa backupfile" << endl;
}

void backupfile::Backup(notepad &b)
{
    FileStr f("backupfile.html");
    char buff[100];
    strcpy(buff, b.l.returnare());
    int nr = strlen(buff) - 1;

    f = "<doctype html> \
        <style> \
        @import url(https://fonts.googleapis.com/css2?family=Courier+Prime:wght@400;700&display=swap); \
        * { \
            margin: 0; \
            padding: 0; \
            box-sizing: border-box; \
          } \
        body { \
               background-color: #222; \
               color: #fff; \
               font-family: Courier Prime, monospace; \
             } \
        \
        box-shadow: 0 0 10px #2196f3, 0 0 40px #2196f2, 0 0 80px #2196f2; \
        border-radius: 5px; \
        transition-delay: 0.2s; \
    } \
    body::-webkit-scrollbar-thumb:hover { background: linear-gradient(transparent, #f231f8); } \
    body::-webkit-scrollbar { width: 8px; } \
    .container { padding: 2em; min-height: 100vh; } \
    .container .title { font-size: 44px; } \
    .container .subtitle { font-size: 18px; margin-bottom: 30px; } \
    .container p { line-height: 1.5; } \
    </style>";

    f = "<div class=\"container\"><h1 class=\"title\">Backup File</h1><h3 class=\"subtitle\">Fisier HTML pentru backup</h3><p>";

    for (int i = 0; i < nr; i++)
        f = buff[i];
    if (DEBUG)
    {
        cout << "Afisare fisier: " << endl;
        for (int i = 0; i < nr; i++)
            cout << buff[i];
        cout << endl;
    }

    f =  "</p><br /></div>";
    cout << "Backup reusit !" << endl;
}

backupfile::~backupfile()
{
    if (DEBUG)
        cout << "Destructor clasa backupfile" << endl;
}

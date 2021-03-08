#ifndef BACKUPFILE_H
#define BACKUPFILE_H

#include "notepad.h"
#include "FileStr.h"

class backupfile: public notepad, public FileStr
{
    protected:

    public:
        backupfile();
        void Backup(notepad &b);
        ~backupfile();
};

#endif // BACKUPFILE_H

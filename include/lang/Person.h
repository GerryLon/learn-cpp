#ifndef _LANG_PERSON_H
#define _LANG_PERSON_H

#include "common/common.h"

class Person
{
    public:
        Person();
        ~Person();
        void eat();

    protected:
        string m_name;

    private:
};

#endif // _LANG_PERSON_H

#ifndef _LANG_PERSON_H
#define _LANG_PERSON_H

#include "../common/common.h"

class Person
{
    public:
        Person();
        virtual ~Person();
        void eat();


//        Person* p = new Worker("tom", 100);
//        p->print(); // ������virtual, ���ľ���Person��print, ��Ȼ����Worker��print
        /* virtual */ void print();

    protected:
        string m_name;

    private:
};

#endif // _LANG_PERSON_H

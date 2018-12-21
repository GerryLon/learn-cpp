#ifndef _LANG_WORKER_H
#define _LANG_WORKER_H

#include "Person.h"


class Worker : public Person
{
    public:
        Worker();
        virtual ~Worker();
        Worker(string name, int salary);
        virtual void print();

    protected:

    private:
        int m_salary;
};

#endif // _LANG_WORKER_H

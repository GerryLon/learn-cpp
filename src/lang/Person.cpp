#include "Person.h"

Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}

void Person::eat() {
    cout << this->m_name << " eating" << endl;
}

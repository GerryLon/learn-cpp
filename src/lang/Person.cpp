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

void Person::print() {
    cout << "Person::print() " << this->m_name << endl;
}

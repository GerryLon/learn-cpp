#include "Worker.h"
#include <string>

Worker::Worker()
{
    //ctor
}

Worker::Worker(string name, int salary) {
    this->m_name = name;
    this->m_salary = salary;
}

Worker::~Worker()
{
    //dtor
}

void Worker::print() {
    cout << this->m_name << "'s salary is " << this->m_salary << endl;;
}

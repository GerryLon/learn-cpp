#include "Location.h"

Location::Location()
{
    this->x = 0;
    this->y = 0;
}

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

Location::Location(const Location& loc) {
    cout << "Location copy constructor" << endl;
    this->x = loc.x;
    this->y = loc.y;
}

Location::~Location()
{
    // cout << "Location destructor: x=" << this->x << " y=" << this->y << endl;
}

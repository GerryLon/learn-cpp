#ifndef _LOCATION_H
#define _LOCATION_H

#include "common/common.h"

class Location
{
    public:
        Location();
        Location(int x, int y);
        Location(const Location& loc);
        virtual ~Location();

    protected:

    private:
        int x;
        int y;
};

#endif // _LOCATION_H

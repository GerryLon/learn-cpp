#ifndef _LANG_LOCATION_H
#define _LANG_LOCATION_H

#include "../common/common.h"

class Location
{
    public:
        Location();
        Location(int x, int y);
        Location(const Location& loc);
        virtual ~Location();

    protected:
        string name;

    private:
        int x;
        int y;
};

#endif // _LANG_LOCATION_H

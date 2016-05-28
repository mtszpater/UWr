//
// Created by Mateusz Pater on 25.05.2016.
//

#include "index.h"

namespace strumienie {

    ostream &operator<<(ostream &os, const index2 &licz) {
        return os << "[" <<
               setw(licz.w) << licz.x << "]";
    }

    istream &operator>>(istream &os, const ignore2 &licz)  {
        if (licz.x == 0) return os;

        int count = licz.x;

        while (os &&(os.get()!= '\n') && (count > 1)) { --count; }

        return os;

    }


}

    strumienie::index2::index2(int x, int w) {
        this->x = x;
        this->w = w;
    }

    strumienie::ignore2::ignore2(int x) {
        this->x = x;
    }



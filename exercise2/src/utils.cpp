
#include <cassert>  /* assert */
#include "utils.h"  /* utils function prototypes */

bool before(const Date &d1, const Date &d2) {//CAREFUL; THIS IS NEW(THE CONST)
    /* we assume the year is the same */
    assert(d1.year() == d2.year());
    return ((d1.month() < d2.month()) ||
            ((d1.month() == d2.month()) && (d1.day() < d2.day())));
}

int difference(const Date &d1, const Date &d2) {//CAREFUL; THIS IS NEW(THE CONST)
    /* return days(d1 - d2) */
    assert(before(d2, d1));
    return 30*(d1.month() - d2.month()) + (d1.day() - d2.day());
}

int duration(const Date &d1, const Date &d2) {//CAREFUL; THIS IS NEW(THE CONST)
    /* Here we use a ternary conditional:
     * See https://en.wikipedia.org/wiki/%3F:#C++ */
    return (before(d1,d2) ? difference(d2,d1) : difference(d1,d2));
}


/* Always guard a header with an include guard.      *
 * See: https://en.wikipedia.org/wiki/Include_guard  */
#ifndef DATE_H
#define DATE_H

/* ctime is the C++ wrapper of time.h which is a C library.  *
 * Using the C headers in C++ is deprecated.                 *
 * See http://www.cplusplus.com/reference/ctime/             */
#include <ctime>

class Date {
    public:
        Date(int day, int month, int year);
        Date(std::time_t date);

        void print_date();
        void happy_birthday(const char *n, Date b);

        /* Accessors */
        int day() const;//CAREFUL; THIS IS NEW(THE CONST)
        int month() const;//CAREFUL; THIS IS NEW(THE CONST)
        int year() const;//CAREFUL; THIS IS NEW(THE CONST)
    private:
        int m_day, m_month, m_year;
};

#endif /* end of include guard: DATE_H */

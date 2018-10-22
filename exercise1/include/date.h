
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
        Date(int day, int month, int year, const char* dweek);
        Date(std::time_t date,const char* dweek);
        Date(const Date &d);//copy constructor of the whole thing as we have now a pointer
        ~Date();
        void print_date();
        void happy_birthday(const char *n, Date b);
    private:
        int m_day, m_month, m_year;
        char* m_dweek;
};

#endif /* end of include guard: DATE_H */

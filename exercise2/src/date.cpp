
#include <iostream> /* std::cout, std::endl    */
#include <iomanip>  /* std::setfill, std::setw */
#include <cstring>  /* std::strcpy             */

#include "date.h"   /* Date class definition + ctime */

/* First constructor Date(int, int, int) */
Date::Date(int day, int month, int year) {
    if ((day<1) || (day>31) || (month<1) || (month>12) || (year<1900)) {
        m_day   = 1;
        m_month = 1;
        m_year  = 1900;
        std::cerr << "Got bad aguments: "
                  << "(day="    << day
                  << ", month=" << month
                  << ", year="  << year
                  << "), creating default date with Unix Epoch."
                  << std::endl;
    }
    else {
        m_day   = day;
        m_month = month;
        m_year  = year;
    }
}

/* Second constructor Date(std::time_t) */
Date::Date(std::time_t date) {
    /* localtime is a function that converts a std::time_t to a struct tm.    *
     * Beware to the argument type and return type: everything is a pointer.  *
     * We can take the address (pointer on) the variable date by using &date. *
     * See http://www.programiz.com/c-programming/c-pointers for more info    *
     * about pointers.                                                        */
    struct tm *lt = std::localtime(&date);

    /* Extract date, month and year from lt */
    m_day   = 0    + (*lt).tm_mday; /*  (*ptr). is equivalent to ptr->              */
    m_month = 1    + lt->tm_mon;    /*  See struct tm documentation for the offset. */
    m_year  = 1900 + lt->tm_year;   /*  See struct tm documentation for the offset. */

    /* We should not free the pointer lt, see man localtime. */
}

void Date::print_date() {
    /* As we do not know about std::string yet, we use C function strcopy */
    char month[4]; /* array of 3 characters + termination character '\0' */

    switch(m_month) {
        case 1:  std::strcpy(month, "Jan"); break;
        case 2:  std::strcpy(month, "Fev"); break;
        case 3:  std::strcpy(month, "Mar"); break;
        case 4:  std::strcpy(month, "Apr"); break;
        case 5:  std::strcpy(month, "May"); break;
        case 6:  std::strcpy(month, "Jun"); break;
        case 7:  std::strcpy(month, "Jul"); break;
        case 8:  std::strcpy(month, "Aug"); break;
        case 9:  std::strcpy(month, "Sep"); break;
        case 10: std::strcpy(month, "Oct"); break;
        case 11: std::strcpy(month, "Nov"); break;
        default: std::strcpy(month, "Dec"); break;
    } /* do not forget the 'break' in the switch-case. */

    /* std::setfill and std::setw can format the length and prefix of the next *
     * printed variable.                                                       */
    std::cout << std::setfill('0') << std::setw(2) << m_day
              << ' ' << month << ' ' << m_year;
}

void Date::happy_birthday(const char* n, Date b) {
    if ((m_day == b.m_day) && (m_month == b.m_month)) {
        std::cout << "Happy " << m_year - b.m_year << "th birthday " << n << " !";
    }
    else {
        std::cout << "Sorry, no gifts for you " << n << '.';
    }
}

/* Accessors */
int Date::day()  const { return m_day;   }//CAREFUL; THIS IS NEW(THE CONST)
int Date::month() const{ return m_month; }//CAREFUL; THIS IS NEW(THE CONST)
int Date::year() const { return m_year;  }//CAREFUL; THIS IS NEW(THE CONST)

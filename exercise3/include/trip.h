
/* include guard */
#ifndef TRIP_H
#define TRIP_H

#include "date.h" /* defines Date */

class Trip {
    private:
        Date m_start_date, m_end_date;
        float m_price;

    public:
        Trip(Date start_date, Date end_date, float price);
        Trip(int sday, int smonth, int syear,
             int eday, int emonth, int eyear,
             float price);
        void print_trip();
        float price_per_day();
};


#endif /* end of include guard: TRIP_H */


#include <iostream>  /* std::cout, std::endl */
#include <iomanip>   /* std::setprecision */
#include <ios>       /* std::fixed */

#include "trip.h"    /* Trip and Date */
#include "utils.h"   /* duration      */

/* Here we use the initializer list to initialize our object. */
Trip::Trip(Date start_date, Date end_date, float price):
    m_start_date(start_date), m_end_date(end_date), m_price(price) {
}

Trip::Trip(int sday, int smonth, int syear,
     int eday, int emonth, int eyear,
     float price):
    m_start_date(sday, smonth, syear), 
    m_end_date(eday, emonth, eyear),
    m_price(price) {
}

void Trip::print_trip(){
    std::cout << "Trip from ";
    m_start_date.print_date();
    std::cout << " to ";
    m_end_date.print_date();
    std::cout << " priced " << m_price << "€ ("
              << std::fixed << std::setprecision(2) << price_per_day()
              << "€/day)" << std::endl;
}
        
float Trip::price_per_day() {
    int ndays = duration(m_start_date, m_end_date);
    return m_price / ndays;
}

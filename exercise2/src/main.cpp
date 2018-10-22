
#include <iostream>  /* required by std::cout and std::endl */
#include <cstdlib>   /* required by atoi, EXIT_FAILURE, EXIT_SUCCESS */

#include "trip.h"    /* Trip class definition */

int main(int argc, const char *argv[])
{
    if (argc != 7) {
        std::cerr << "Usage " << argv[0] 
                  << " [sday] [smonth] [syear]  [eday] [emonth] [eyear]." 
                  << std::endl;
        return EXIT_FAILURE;
    }
    
    int d[6];
    for (int i=0; i<6; i++) { 
        d[i] = std::atoi(argv[i+1]); 
    }
    
    float price;
    std::cout << "Please specify the price of the trip: ";
    std::cin >> price;

    Trip trip(d[0], d[1], d[2],
              d[3], d[4], d[5], price);
    trip.print_trip();
    return EXIT_SUCCESS;
}

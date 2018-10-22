
#include <iostream>  /* required by std::cout and std::endl */
#include <cstdlib>   /* required by atoi, EXIT_FAILURE, EXIT_SUCCESS */

#include "date.h"    /* Date class definition, also includes ctime */

int main(int argc, const char *argv[]) {
    /* The first argument is the name of the program itself. */
    if (argc != 6) {
        std::cerr << "Usage " << argv[0] << " [name] [day] [month] [year] [dweek]." << std::endl;
        return EXIT_FAILURE;
    }

    /* Extract name, day, month and year arguments */
    const char* name = argv[1];
    int day   = std::atoi(argv[2]); /* atoi converts an array of char to an integer */
    int month = std::atoi(argv[3]);
    int year  = std::atoi(argv[4]);
    const char* dweek = argv[5];
    Date birthday(day, month, year, dweek);

    std::time_t current_time;
    std::time(&current_time);
    Date current_date(current_time, "Monday");
    /* You could also have used:                          *
     *    std::time_t current_time = std::time(nullptr);  */

    std::cout << "Today is ";
    current_date.print_date();
    std::cout << '.' << std::endl;

    current_date.happy_birthday(name, birthday);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

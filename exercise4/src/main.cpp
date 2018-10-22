
#include <iostream>  /* std::cout and std::endl */
#include <iomanip>   /* std::setprecision, std::setw, std::setfill */
#include <ios>       /* std::fixed */
#include <cstdlib>   /* EXIT_FAILURE, EXIT_SUCCESS */

#include "polynomial.h"  /* Polynomial class definition */

int main(int argc, const char *argv[]) {
    
    /* Create an array of polynomials */
    Poly1 polynomials[6]; /* <= this uses the default constructor Poly1() six times */
    float a0[6] = { 1.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
    float a1[6] = { 6.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f };
    for (int i = 0; i < 6; i++) {
        polynomials[i] = Poly1(a0[i], a1[i]); /* <= this uses the (implicit) copy constructor Poly1(poly) */
    }

    float a=-4.0f, b=-0.18f;
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < 6; i++) {
        std::cout << "Created polynomial ";
        polynomials[i].print_polynomial(std::cout);
        std::cout << " which has root " 
                  << std::setw(5) << std::setfill(' ') << polynomials[i].zero(a,b)
                  << " in range [" << a << ", " << b << "]"
                  << " with derivative ";
        polynomials[i].derivative().print_polynomial(std::cout);
        std::cout << "." << std::endl;
    }

    return EXIT_SUCCESS;
}

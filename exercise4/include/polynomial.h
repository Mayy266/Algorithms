#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <ostream>   /* std::ostream */
#include <cmath>     /* defines NAN (Not A Number), a specific float constant *
                        See https://en.wikipedia.org/wiki/NaN                 */

class Poly0 {
    /* P(x) = a0 */
    public:
        /* You can specify default values for parameters in the header.              *
         * A nice side effect in this case is that you define a default constructor: *
         *   Poly0() <=> Poly0(NAN)                                                  */
        Poly0(float a0=NAN);
        Poly0 derivative();
        float val(float x);
        
        /* Here we pass directly an ostream (the type of std::cout) !  *
         * Do not mind the reference (&), you will see what it means   *
         * later.                                                      */
        void print_polynomial(std::ostream &os);
    private:
        float m_a0;
};


class Poly1 {
    /* P(x) = a0 + a1*x */
    public:
        Poly1(float a0=NAN, float a1=NAN); /* also defines a default constructor ! */
        Poly0 derivative();
        float val(float x);
        float zero(float a, float b);
        void print_polynomial(std::ostream &os); /* see Poly0::print_polynomial */
    private:
        float m_a0, m_a1;
};

#endif /* end of include guard: POLYNOMIAL_H */

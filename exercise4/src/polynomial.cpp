
#include <cassert>   /* assert */

#include "polynomial.h"



Poly0::Poly0(float a0): m_a0(a0) {
}

float Poly0::val(float x) { 
    return m_a0; 
}

Poly0 Poly0::derivative() { 
    return Poly0(0.0);
}

void Poly0::print_polynomial(std::ostream &os) { 
    os << "P(x) = " << m_a0;
}



Poly1::Poly1(float a0, float a1): m_a0(a0), m_a1(a1) {
    assert(m_a1 != 0.0f); /* (m_a1 == 0.0f) would imply that this is a Poly0! */
}

float Poly1::val(float x) { 
    return m_a0 + m_a1*x; 
}

Poly0 Poly1::derivative() {
    return Poly0(m_a1);
}

void Poly1::print_polynomial(std::ostream &os) { 
    os << "P(x) = " << m_a1 << "*x" << " + " << m_a0;
}

float Poly1::zero(float a, float b) {
    float root = - m_a0 / m_a1;
    return (((root >= a) && (root <= b)) ? root : NAN);
}


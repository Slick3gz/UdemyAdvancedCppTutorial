//
//  Complex.cpp
//  A Complex Number Class
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#include "Complex.hpp"

Slick::Complex Slick::operator+(const Slick::Complex &c1, const Slick::Complex &c2)
{
    return  Slick::Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
}
Slick::Complex Slick::operator+(const Slick::Complex &c1, double d)
{
    return Slick::Complex(c1.getReal()+d, c1.getImaginary());
}
Slick::Complex Slick::operator+( double d, const Slick::Complex &c1)
{
    return Slick::Complex(c1.getReal()+d, c1.getImaginary());
}
std::ostream &Slick::operator<<(std::ostream &out, const Slick::Complex &c)
{
    out << "(" << c.getReal() << ", " << c.getImaginary() << ")";
    return out;
}

Slick::Complex::Complex(): real(0), imaginary(0)
{
    
}
Slick::Complex::Complex(double real, double imaginary): real(real), imaginary(imaginary)
{
    
}
Slick::Complex::Complex(const Complex &other)
{
    real = other.real;
    imaginary = other.imaginary;
}
const Slick::Complex &Slick::Complex::operator=(const Slick::Complex &other)
{
    real = other.real;
    imaginary = other.imaginary;
    return *this;
}
bool Slick::Complex::operator==(const Slick::Complex &other) const
{
    return (real == other.real) && (imaginary == other.imaginary);
}
bool Slick::Complex::operator!=(const Slick::Complex &other)const
{
    return !(*this == other);
}
Slick::Complex Slick::Complex::operator*() const
{
    return Slick::Complex(real, -imaginary);
}

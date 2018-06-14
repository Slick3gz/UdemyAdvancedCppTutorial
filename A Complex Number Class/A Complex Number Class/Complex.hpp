//
//  Complex.hpp
//  A Complex Number Class
//
//  Created by Slick on 6/13/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <iostream>

namespace Slick {
    class Complex
    {
    private:
        double real;
        double imaginary;
        
    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(const Complex &other);
        const Complex &operator=(const Complex &other);
        
        double getReal() const
        {
            return real;
        }
        double getImaginary() const
        {
            return imaginary;
        }
        bool operator==(const Complex &other)const;
        bool operator!=(const Complex &other)const;
        Complex operator*()const;
    };
    
std::ostream &operator<<(std::ostream &out, const Slick::Complex &c);

Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+( double d, const Complex &c1);
    
}
#endif /* Complex_hpp */

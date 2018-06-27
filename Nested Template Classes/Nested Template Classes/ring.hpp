//
//  ring.hpp
//  Nested Template Classes
//
//  Created by Slick on 6/16/18.
//  Copyright © 2018 Slick Coding. All rights reserved.
//

#ifndef ring_hpp
#define ring_hpp
#include <iostream>

template<class T>
class ring
{
public:
    class iterator;
public:
    ring(int length): length(length)
    {
        buffer = new T[length];
    }
    virtual ~ring()
    {
        delete [] buffer;
    }
    void add(T element)
    {
        if(index > length - 1)
        {
            index = 0;
        }
        buffer[index] = element;
        ++index;
    }
    
    const T &get(int index) const
    {
        
            return buffer[index];
    }
    
    const int size() const
    {
        return length;
    }
    
    iterator begin()
    {
        return iterator(0, *this);
    }
    
    iterator end()
    {
        return iterator(length, *this);
    }
    
    
private:
    int length;
    int index;
    T  *buffer;

};

template<class T>
class ring<T>::iterator
{
private:
    int m_pos;
    ring &m_ring;
public:
    iterator(int pos, ring &aring): m_pos(pos), m_ring(aring)
    {
        
    }
    // post-increment
    iterator &operator++()
    {
        m_pos++;
        return *this;
    }
    
    T operator *() const
    {
        return m_ring.get(m_pos);
    }
    
    bool operator !=(const iterator &other) const
    {
        return m_pos != other.m_pos;
    }
};

#endif /* ring_hpp */

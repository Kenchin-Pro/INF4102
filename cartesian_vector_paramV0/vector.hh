#pragma once

#include <ostream>
#include <cmath>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    // possibly more
    Vector(value pCoor[]) { coor = pCoor; };
    Vector() { coor = value[NDIM]; };

// Public Member functions here
    Vector& operator +=(const Vector& rhs);
    // More to go
    Vector& operator -=(const Vector& rhs);
    Vector& operator + (const Vector& a, const Vector& b);
    Vector& operator - (const Vector& a, const Vector& b);
    Vector& operator * (float a, const Vector& b);
    Vector& operator * (const Vector& a, float b);
    float   operator * (const Vector& a, const Vector& b);
    ostream & operator << (ostream & os, Vector& t);

private:
// Private Member functions here
    float norm()
    {
        value somme = 0;
        for (int i = 0; i < NDIM; i++) 
        {
            somme += coor[i] * coor[i];
        }
        return sqrt(somme);
    }
// Member variables are ALWAYS private, and they go here
    value coor [NDIM]= { };
};

// Nonmember function operators go here
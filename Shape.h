#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

class Shape {
    public:
        double *x;
        double *y;
        string color;

    virtual double area() = 0; 
    virtual string toString() = 0;
};

#endif

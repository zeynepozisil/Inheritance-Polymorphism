#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "Shape.h"

class Triangle: public Shape {
    public:
        Triangle(double x1,double x2,double x3,double y1,double y2,double y3,string c){
            x = (double*) malloc(sizeof(double)*3);
            y = (double*) malloc(sizeof(double)*3);
            x[0] = x1, x[1] = x2, x[2] = x3;
            y[0] = y1, y[1] = y2, y[2] = y3;
            color = c;
        }
        double area(){
            return 0.5*(x[0]*abs(y[1]-y[2]) + x[1]*abs(y[2]-y[1]) + x[2]*abs(y[0]-y[1]));
        }
        string toString(){
            stringstream ss;
        	ss<<"This is a "<<color+" triangle with coordinates \n"<< 
        	    "1:"<<x[0]<<" "<<y[0]<<"\n"<<
        	    "2:"<<x[1]<<" "<<y[1]<<"\n"<<
        	    "3:"<<x[2]<<" "<<y[2];
            return ss.str();
        }
};
#endif

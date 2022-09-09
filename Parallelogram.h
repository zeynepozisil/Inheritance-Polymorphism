#ifndef PARALLEL_H
#define PARALLEL_H

#include "Shape.h"

class Parallelogram : public Shape {
    public:
        Parallelogram(double x1,double x2,double x3,double y1,double y2,double y3,string c){
            
            double x4,y4;
            if (x1!=x2 && x2!=x3 && y1!=y2 && y2!=x3) {
                x = NULL;
                y = NULL;
            } else {
                x4 = x1 + (x3 - x2); 
                y4 = y1 + (y3 - y2);
                x = (double*) malloc(sizeof(double)*4);
                y = (double*) malloc(sizeof(double)*4);
                x[0] = x1, x[1] = x2, x[2] = x3, x[3] = x4;
                y[0] = y1, y[1] = y2, y[2] = y3, y[3] = y4;
                color = c;
            }
        }
        double area(){
            return 0.5*abs((x[0]*y[1])+(x[1]*y[2])+(x[2]*y[3])+(x[3]*y[0])-(x[1]*y[0])-(x[2]*y[1])-(x[3]*y[2])-(x[0]*y[3]));
        }

        string toString(){
        	stringstream ss;
        	ss<<"This is a "<<color+" parallelogram with coordinates \n"<< 
        	    "1:"<<x[0]<<" "<<y[0]<<"\n"<<
        	    "2:"<<x[1]<<" "<<y[1]<<"\n"<<
        	    "3:"<<x[2]<<" "<<y[2]<<"\n"<<
                "4:"<<x[3]<<" "<<y[3];
            return ss.str();
        }
};

class Rectangle : public Parallelogram {
    public: 
        Rectangle(double x1,double x2,double y1,double y2,string c) : 
            Parallelogram(x1,x2,x2,y1,y1,y2,c){}

        double area(){
            return 0.5*abs((x[0]*y[1])+(x[1]*y[2])+(x[2]*y[3])+(x[3]*y[0])-(x[1]*y[0])-(x[2]*y[1])-(x[3]*y[2])-(x[0]*y[3]));
        }
        string toString(){
            stringstream ss;
        	ss<<"This is a "<<color+" rectangle with coordinates \n"<< 
        	    "1:"<<x[0]<<" "<<y[0]<<"\n"<<
        	    "2:"<<x[1]<<" "<<y[1]<<"\n"<<
        	    "3:"<<x[2]<<" "<<y[2]<<"\n"<<
                "4:"<<x[3]<<" "<<y[3];
            return ss.str();
        }
};
#endif

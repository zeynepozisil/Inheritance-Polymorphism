#ifndef LINE_H
#define LINE_H

#include "Shape.h"
using namespace std;

class Line: public Shape {
    public:
        Line(double x1,double x2,double y1,double y2,string c){
            x = (double*) malloc(sizeof(double)*2);
            y = (double*) malloc(sizeof(double)*2);
            x[0] = x1, x[1] = x2;
            y[0] = y1, y[1] = y2;
            color = c;
        }
        double area(){
            return sqrt(pow(y[1]-y[0],2)+pow(x[1]-x[0],2));
        }
        string toString(){
        	stringstream ss;
        	ss<<"This is a "<<color+" line with coordinates \n"<< 
        	    "1:"<<x[0]<<" "<<y[0]<<"\n"<<
        	    "2:"<<x[1]<<" "<<y[1];
            return ss.str();
        }
};

class VerticalLine: public Line {
   public:
        VerticalLine(double length,double y1,double y2,string c) : 
            Line(length,length,y1,y2,c){}

        double area(){
            return sqrt(pow(y[1]-y[0],2)+pow(x[1]-x[0],2));
        }

        string toString(){
        	stringstream ss;
        	ss<<"This is a "<<color+" vertical line with coordinates \n"<< 
        	    "1:"<<x[0]<<" "<<y[0]<<"\n"<<
        	    "2:"<<x[1]<<" "<<y[1];
            return ss.str();
        }
};

class HorizontalLine: public Line {
   public:
        HorizontalLine(double length,double x1,double x2,string c) :
            Line(x1,x2,length,length,c) {}

        double area(){
            return sqrt(pow(y[1]-y[0],2)+pow(x[1]-x[0],2));
        }
        string toString(){
        	stringstream ss;
        	ss<<"This is a "<<color+" horizontal line with coordinates \n"<< 
        	    "1:"<<x[0]<<" "<<y[0]<<"\n"<<
        	    "2:"<<x[1]<<" "<<y[1];
            return ss.str();
        }
};
#endif

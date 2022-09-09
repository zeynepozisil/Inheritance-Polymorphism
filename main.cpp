#include <time.h>
#include <vector>
#include <cmath>

#include "Line.h"
#include "Triangle.h"
#include "Parallelogram.h"

using namespace std;

int main(void) {
    
    srand((unsigned) time(NULL));

    int no = 0, rand_shape, rand_color;
    double rand_x1,rand_x2,rand_x3;
    double rand_y1,rand_y2,rand_y3;

    string colors[5] = {"red","blue","green","pink","yellow"};
    vector<Shape*> shapes;

    while(no<10000){
        rand_shape = (rand() % 6) + 1;
        rand_color = rand() % 4;
        if(rand_shape == 1){
            rand_x1 = ((double)rand()/(double)RAND_MAX);
            rand_x2 = ((double)rand()/(double)RAND_MAX);
            rand_y1 = ((double)rand()/(double)RAND_MAX);
            rand_y2 = ((double)rand()/(double)RAND_MAX);
            shapes.push_back(new Line(rand_x1,rand_x2,rand_y1,rand_y2,colors[rand_color]));
        }else if(rand_shape == 2){
            rand_x1 = ((double)rand()/(double)RAND_MAX);
            rand_y1 = ((double)rand()/(double)RAND_MAX);
            rand_y2 = ((double)rand()/(double)RAND_MAX);
            shapes.push_back(new VerticalLine(rand_x1,rand_y1,rand_y2,colors[rand_color]));
        }else if(rand_shape == 3){
            rand_x1 = ((double)rand()/(double)RAND_MAX);
            rand_x2 = ((double)rand()/(double)RAND_MAX);
            rand_y1 = ((double)rand()/(double)RAND_MAX);
            shapes.push_back(new HorizontalLine(rand_y1,rand_x1,rand_x2,colors[rand_color]));
        }else if(rand_shape == 4){
            rand_x1 = ((double)rand()/(double)RAND_MAX);
            rand_x2 = ((double)rand()/(double)RAND_MAX);
            rand_x3 = ((double)rand()/(double)RAND_MAX);
            rand_y1 = ((double)rand()/(double)RAND_MAX);
            rand_y2 = ((double)rand()/(double)RAND_MAX);
            rand_y3 = ((double)rand()/(double)RAND_MAX);
            shapes.push_back(new Triangle(rand_x1,rand_x2,rand_x3,rand_y1,rand_y2,rand_y3,colors[rand_color]));
        }else if(rand_shape == 5){
            rand_x1 = ((double)rand()/(double)RAND_MAX);
            rand_x2 = ((double)rand()/(double)RAND_MAX);
            rand_x3 = ((double)rand()/(double)RAND_MAX);
            rand_y1 = ((double)rand()/(double)RAND_MAX);
            rand_y2 = ((double)rand()/(double)RAND_MAX);
            rand_y3 = ((double)rand()/(double)RAND_MAX);
            Parallelogram *p = new Parallelogram(rand_x1,rand_x2,rand_x3,rand_y1,rand_y2,rand_y3,colors[rand_color]);
            if(p->x == NULL){ 
            	continue;
			} 
            shapes.push_back(new Parallelogram(rand_x1,rand_x2,rand_x3,rand_y1,rand_y2,rand_y3,colors[rand_color]));
        }else if(rand_shape == 6){
            rand_x1 = ((double)rand()/(double)RAND_MAX);
            rand_x2 = ((double)rand()/(double)RAND_MAX);
            rand_y1 = ((double)rand()/(double)RAND_MAX);
            rand_y2 = ((double)rand()/(double)RAND_MAX);
            shapes.push_back(new Rectangle(rand_x1,rand_x2,rand_y1,rand_y2,colors[rand_color]));
        }
        no++;
    }

    cout << "10000 Shapes are created." << endl << endl;
    no = 5;
    while(no>0){
        rand_shape = rand() % 10000;
        cout << "Shape " << rand_shape<<endl;
        cout <<  shapes.at(rand_shape)->toString()<<endl;
        cout << "Area: " << shapes.at(rand_shape)->area() << endl << endl;
        no--;
    }
    
    no = 9999;
    double sum_areas_triangle = 0.0;
    int no_of_triangle = 0;

    while(no>=0){
        Triangle *t = dynamic_cast<Triangle*>(shapes.at(no));
        if( t != NULL){
            no_of_triangle++;
            sum_areas_triangle += shapes.at(no)->area();
        }
        no--;
    }
    cout << "Number of triangles: " << no_of_triangle << endl;
    cout << "Average area of triangles: " << sum_areas_triangle/no_of_triangle << endl;

    return 0;
}

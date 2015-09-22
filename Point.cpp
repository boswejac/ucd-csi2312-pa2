//
// Created by Home on 9/15/15.
//

#include "Point.h"
#include <cmath>
#include <iostream>


Point::Point(const int dime) {
    pArray = new double[dime];

}

Point::Point(int dime, double *pArr) {
    pArray = new double[dime];
    dim = dime;
    for(int i=0;i<dim;i++)
    {
        pArray[i]=pArr[i];
    }
}


Point::~Point() {
    delete [] pArray;
}


int Point::getDim() const {
    return dim;
}

double Point::getArray(int i)const {
    return pArray[i];
}


double Point::distanceTo(Point &otherPoint) {
    if (otherPoint.getDim() == dim){
        double total = 0;
        double diff;
        for (int i =0; i <dim; i++){
            diff = getArray(i) - otherPoint.getArray(i);
            total = total + (diff*diff);
        };
        return sqrt(total);
    }
    return 0;
}



void Point::setDim(int i) {
    dim = i;

}

void Point::setArray(int i, double x){
    pArray[i]=x;
}


Point &Point::operator*=(double d) {
    for(int i =0;i<dim;i++){
        pArray[i]=(pArray[i]*d);
    };
}

Point &Point::operator/=(double d) {
    for(int i =0;i<dim;i++){
        pArray[i] = pArray[i] / d;
};
}


Point Point::operator*(double d) const {
    Point p(this->getDim());
    for(int i =0;i<dim;i++){
        p.setArray(i,pArray[i]*d);
    };
    return p;
}

Point Point::operator/(double d) const {
    Point p(this->getDim());
    for(int i =0;i<dim;i++){
        p.setArray(i,pArray[i]/d);
    };
    return p;
}


Point &operator+=(Point &point, const Point &point1) {
    for (int i=0;i< point.getDim();i++){
        point.setArray(i,point1.getArray(i)+point.getArray(i));
    }
    return point;
}

Point &operator-=(Point &point, const Point &point1) {
    for (int i=0;i< point.getDim();i++){
        point.setArray(i,point.getArray(i)-point1.getArray(i));
    }
    return point;
}

const Point operator+(const Point &point, const Point &point1) {
    Point p2(point.getDim());
    for (int i=0;i< point.getDim();i++){
        p2.setArray(i,point.getArray(i)+point1.getArray(i));
    }
    return p2;
}

const Point operator-(const Point &point, const Point &point1) {
    Point p2(point.getDim());
    for (int i=0;i< point.getDim();i++){
        p2.setArray(i,point1.getArray(i)+point.getArray(i));
    }
    return p2;
}

bool operator<(const Point &point, const Point &point1) {

    for (int i=0;i< point.getDim();i++){
        if (point.getArray(i) < point1.getArray(i)){
            return true;
        };
        if (point.getArray(i) > point1.getArray(i)){
            return false;
        }

    }
    return false;
}

bool operator>(const Point &point, const Point &point1) {
    for (int i=0;i< point.getDim();i++){
        if (point.getArray(i) > point1.getArray(i)){
            return true;
        };
        if (point.getArray(i) < point1.getArray(i)){
            return false;
        }

    }
    return false;
}

bool operator<=(const Point &point, const Point &point1) {
    for (int i=0;i< point.getDim();i++){
        if ((point.getArray(i) < point1.getArray(i))||(point.getArray(i) == point1.getArray(i))){
            return true;
        };
        if (point.getArray(i) > point1.getArray(i)){
            return false;
        }

    }
    return false;
}

bool operator>=(const Point &point, const Point &point1) {
    for (int i=0;i< point.getDim();i++){
        if ((point.getArray(i) > point1.getArray(i))||(point.getArray(i) == point1.getArray(i))){
            return true;
        };
        if (point.getArray(i) < point1.getArray(i)){
            return false;
        }

    }
    return false;
}

bool operator==(const Point &point, const Point &point1) {
    bool status = false;
    for (int i=0;i< point.getDim();i++){
        if (point.getArray(i) == point1.getArray(i)){
            status = true;
        };
        if (point.getArray(i) != point1.getArray(i)){
            return false;
        }

    }
    return status;
}

bool operator!=(const Point &point, const Point &point1) {
    bool status = false;
    for (int i=0;i< point.getDim();i++){
        if (point.getArray(i) == point1.getArray(i)){
            status = false;
        };
        if (point.getArray(i) != point1.getArray(i)){
            return true;
        }

    }
    return status;
}

std::ostream &operator<<(std::ostream &ostream, const Point &point) {
    ostream << "Dimensions: " << point.getDim() << "\n";
    ostream << "Values: ";
    for (int i=0;i<point.getDim();i++){
        ostream << point.getArray(i) << ", ";
    }
    ostream << "\n";
    return ostream;
}
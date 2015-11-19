//
// Created by Home on 9/15/15.
//


#include <fstream>
#include <cmath>
#include <iostream>

#include "Point.h"
#include "Exceptions.h"



Point::Point(const int dime) {
    dim=dime;
    pArray = new double[dim];
    setID(genID());

};

Point::Point(const Point &p){
    dim = p.getDim();
    pArray = new double[dim];
    setID(genID());
    for (int i=0;i<dim;i++){
        pArray[i]=p.getArray(i);
    }
};

Point::Point(int dime, double *pArr) {
    dim = dime;
    pArray = new double[dim];
    setID(genID());
    for(int i=0;i<dim;i++)
    {
        pArray[i]=pArr[i];
    }
};

Point::~Point() {
    delete [] pArray;
};


int Point::getDim() const {
    return dim;
};

double Point::getArray(int i)const {
    if(i< dim)
        return pArray[i];
    else{
        Clustering::OutOfBoundsEX except(i);
        std::cout << except << std::endl;
    }
};


double Point::distanceTo(Point otherPoint) {
    try{
        if(this->dim!=otherPoint.getDim()){
            Clustering::DimensionalityMismatchEX except(*this, otherPoint);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
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
};



void Point::setDim(int i) {
    dim = i;

};

void Point::setArray(int i, double x){
    pArray[i]=x;
};


Point &Point::operator*=(double d) {
    for(int i =0;i<dim;i++){
        pArray[i]=(pArray[i]*d);
    };
};

Point &Point::operator/=(double d) {
    for(int i =0;i<dim;i++){
        pArray[i] = pArray[i] / d;
    };
};


Point Point::operator*(double d) const {
    Point p(this->getDim());
    for(int i =0;i<dim;i++){
        p.setArray(i,pArray[i]*d);
    };
    int x = p.genID();
    p.setID(x);
    return p;
};

Point Point::operator/(double d) const {
    Point p(this->getDim());
    for(int i =0;i<dim;i++){
        p.setArray(i,pArray[i]/d);
    };
    int x = p.genID();
    p.setID(x);
    return p;
};


Point &operator+=(Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    for (int i=0;i< point.getDim();i++){
        point.setArray(i,point1.getArray(i)+point.getArray(i));
    };
    return point;
};

Point &operator-=(Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    for (int i=0;i< point.getDim();i++){
        point.setArray(i,point.getArray(i)-point1.getArray(i));
    };
    return point;
};

const Point operator+(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    Point p2(point.getDim());
    for (int i=0;i< point.getDim();i++){
        p2.setArray(i,point.getArray(i)+point1.getArray(i));
    };
    int x = p2.genID();
    p2.setID(x);
    return p2;
};

const Point operator-(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    Point p2(point.getDim());
    for (int i=0;i< point.getDim();i++){
        p2.setArray(i,point1.getArray(i)+point.getArray(i));
    };
    int x = p2.genID();
    p2.setID(x);
    return p2;
};

bool operator<(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }

    for (int i=0;i< point.getDim();i++){
        if (point.getArray(i) < point1.getArray(i)){
            return true;
        };
        if (point.getArray(i) > point1.getArray(i)){
            return false;
        };

    };
    return false;
};

bool operator>(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    for (int i=0;i< point.getDim();i++){
        if (point.getArray(i) > point1.getArray(i)){
            return true;
        };
        if (point.getArray(i) < point1.getArray(i)){
            return false;
        };

    };
    return false;
};

bool operator<=(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    for (int i=0;i< point.getDim();i++){
        if ((point.getArray(i) < point1.getArray(i))||(point.getArray(i) == point1.getArray(i))){
            return true;
        };
        if (point.getArray(i) > point1.getArray(i)){
            return false;
        };

    };
    return false;
};

bool operator>=(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    for (int i=0;i< point.getDim();i++){
        if ((point.getArray(i) > point1.getArray(i))||(point.getArray(i) == point1.getArray(i))){
            return true;
        };
        if (point.getArray(i) < point1.getArray(i)){
            return false;
        };

    };
    return false;
};

bool operator==(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
    if (point._id==point1._id)
        return true;
    else
        return false;
};

bool operator!=(const Point &point, const Point &point1) {
    try{
        if(point.getDim()!=point1.getDim()){
            Clustering::DimensionalityMismatchEX except(point, point1);
            throw except;
        }
    }catch(Clustering::DimensionalityMismatchEX exc){
        std::cout<<exc;
    }
   if (point._id!=point1._id)
       return true;
    else
       return false;
};

std::ostream &operator<<(std::ostream &ostream, const Point &point) {

    for (int i=0;i<point.getDim();i++){
        if (i+1 !=point.getDim()) {
            ostream << point.getArray(i) << ", ";
        }
        else {
            ostream << point.getArray(i);
        };
    };

    return ostream;
};

std::istream &operator>>(std::istream &istream, Point &point) {

    std::string value;


    int i = 0;

    double d;
    while (getline(istream, value, ',')) {
        d = stod(value);
        point.setArray(i++, d);
    };
    return istream;
};


unsigned int Point::genID() {
    static int theID = 0;
    return theID++;
}

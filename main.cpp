#include <iostream>
#include <fstream>
#include "Point.h"
#include "Cluster.h"
#include <sstream>

using namespace Clustering;
//Funcs checked
//Point:
//+=,-=,*=,/=,*,/,==,!=,>,<,<<
//notchecked:>>
//Cluster:
//add, remove, ==,+=p,-=p,+=c,-=c,+c,-c,+p,-p

int main() {

//    std::ifstream csv;
//    csv.open("points.txt",std::ifstream::in);
//    std::cout << "file made" << std::endl;
//    std::string line;
//    std::cout << csv.is_open();
//    if (csv.is_open()) {
//        std::cout << "open" << std::endl;
//        while (getline(csv, line)) {
//            std::cout << "Line" << line << std::endl;
//            std::stringstream lineStream(line);
//            std::string value;
//            double d;
//            Point px(5);

//            int i = 1;
//            while (getline(lineStream, value, ',')) {
//                d = std::stod(value);
//                std::cout << "Value: " << d << std::endl;
    //px.setValue(i++,d)
    //           }
    //      }
    // }

    //shared pointers
    double array[] = {0, 1, 2};
    Point p(3, array);
    double array2[] = {3, 4, 5};
    Point p2(3, array2);
    double array3[] = {6, 7, 8};
    Point p3(3, array3);
    double array4[] = {0, 1, 2};
    Point p4(3, array4);
    double array5[] = {3, 4, 5};
    Point p5(3, array5);
    double array6[] = {6, 7, 8};
    Point p6(3, array6);


    Clustering::LNodePtr c1Ptr1 = new Clustering::LNode;
    Clustering::LNodePtr c1Ptr2 = new Clustering::LNode;
    Clustering::LNodePtr c1Ptr3 = new Clustering::LNode;
    Clustering::LNodePtr c2Ptr1 = new Clustering::LNode;
    Clustering::LNodePtr c2Ptr2 = new Clustering::LNode;
    Clustering::LNodePtr c2Ptr3 = new Clustering::LNode;
    Clustering::LNodePtr c3Ptr = new Clustering::LNode;
    c1Ptr1->p = &p;
    c1Ptr2->p = &p2;
    c1Ptr3->p = &p3;
    c2Ptr1->p = &p4;
    c2Ptr2->p = &p5;
    c2Ptr3->p = &p6;

    c1Ptr1->next = c1Ptr2;
    c1Ptr2->next = c1Ptr3;
    c1Ptr3->next = nullptr;
    c2Ptr1->next = c2Ptr2;
    c2Ptr2->next = c2Ptr3;
    c2Ptr3->next = nullptr;

    c3Ptr->p = &p2;
    c3Ptr->next = nullptr;


    Clustering::Cluster clust1(3, c1Ptr1);
    Clustering::Cluster clust2(3, c2Ptr1);
    Clustering::Cluster clust3(1, c3Ptr);

    Clustering::Cluster clust4 = clust2 - &p6;
    if (p>p4)
        clust4 += clust1;


    std::cout << clust4 << std::endl;
}

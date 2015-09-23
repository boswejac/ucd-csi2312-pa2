#include <iostream>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace Clustering;

int main() {
    double array[]={0,1,2};
    Point p(3,array);
    double array2[]={3,4,5};
    Point p2(3,array2);
    double array3[]={6,7,8};
    Point p3(3,array3);
    double array4[]={0,1,2};
    Point p4(3,array4);
    double array5[]={3,4,5};
    Point p5(3,array5);
    double array6[]={6,7,8};
    Point p6(3,array6);

    LNodePtr c1Ptr1 = new LNode;
    LNodePtr c1Ptr2 = new LNode;
    LNodePtr c1Ptr3 = new LNode;
    LNodePtr c2Ptr1 = new LNode;
    LNodePtr c2Ptr2 = new LNode;
    LNodePtr c2Ptr3 = new LNode;

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

    //traverse
    for (LNodePtr current=c1Ptr1;current!=nullptr;current=current->next){
        cout <<  *(current->p) << endl;
    }

    for (LNodePtr current=c2Ptr1;current!=nullptr;current=current->next){
        cout <<  *(current->p) << endl;
    }

    Cluster clust1(3,c1Ptr1);
    Cluster clust2(3,c2Ptr1);

    cout << *(clust1.getPtr()->p) << endl;


}

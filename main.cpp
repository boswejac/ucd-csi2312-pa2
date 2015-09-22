#include <iostream>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace Clustering;

int main() {


    double Array[]={0,1,2,3,4,5};
    double Array2[]={1,2,3,4,5,6};
    Point p(6,Array);

    for (int i=0;i<p.getDim();i++)
        cout << p.getArray(i) << endl;
    p*=3;
    for (int i=0;i<p.getDim();i++)
        cout << p.getArray(i) << endl;
    Point p2(6, Array2);

    LNodePtr paz;
    Cluster c1(6,paz);
    cout << c1.getSize() << endl;
    cout << p << endl;
    c1.add(&p);
    cout << c1 << endl;
}
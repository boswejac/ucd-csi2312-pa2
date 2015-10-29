#include <iostream>
#include <fstream>
#include "Point.h"
#include "Cluster.h"
#include "KMeans.h"
#include <sstream>

using namespace Clustering;
//Funcs checked
//Point:
//+=,-=,*=,/=,*,/,==,!=,>,<,<<
//notchecked:>>
//Cluster:
//add, remove, ==,+=p,-=p,+=c,-=c,+c,-c,+p,-p

int main() {


    KMeans algo(5);
    algo.initialize();



    for(int i = 0; i< algo.getK();i++){
        std::cout<< "INITIAL" << std::endl;
        std::cout << algo.getClusters()[i] << std::endl;
        //std::cout << algo.getClusters()[i].getCentroid() << std::endl;
    }


    algo.letsCluster();

    for(int i = 0; i< algo.getK();i++){
        std::cout<< "FINAL" << std::endl;
        std::cout << algo.getClusters()[i] << std::endl;
        //std::cout << algo.getClusters()[i].getCentroid() << std::endl;
    }


}

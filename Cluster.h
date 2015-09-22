//
// Created by Home on 9/15/15.
//

#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;


    struct LNode {
        PointPtr p;
        LNodePtr next;
    };

    class Cluster {
        int size;
        LNodePtr points;

    public:
        Cluster() : size(0), points(nullptr) {};
        Cluster(int sizee, LNodePtr pt);
        int getSize() const {return size;};
        LNodePtr getPtr() const {return points;};



        Cluster(const Cluster &);
        Cluster &operator=(const Cluster &);
        ~Cluster();


        void add(const PointPtr &);
        const PointPtr &remove(const PointPtr &);



        bool operator==(const Cluster &rhs);


        Cluster &operator+=(const Cluster &rhs);
        Cluster &operator-=(const Cluster &rhs);

        Cluster &operator+=( Point &rhs);
        Cluster &operator-=(Point &rhs);


        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);

    };

}
#endif //CLUSTERING_CLUSTER_H


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
        Point _centroid;
        bool _valid_centroid;
        int _id;


    public:
        Cluster() : size(0), points(nullptr), _id(newID()) {};
        Cluster(int sizee, LNodePtr pt);
        int getSize() const {return size;};
        LNodePtr getPtr() const {return points;};
        void setPtr(LNodePtr pt) {points=pt;};
        void set_valid(bool bl) {_valid_centroid = bl;};
        bool getValid(){return _valid_centroid;};
        void setID(int idea){_id=idea;};
        int getID() const {return _id;};
        int newID();

        class Move {
            PointPtr pptr;
            Cluster* target;
            Cluster* source;
        public:
            Move(const PointPtr &ptr, Cluster *from, Cluster *to){pptr=ptr,target=to,source=from, perform();};
            void perform();
        };

        void setCentroid(PointPtr ptr);
        Point getCentroid() const {return _centroid;};
        void computeCentroid();

        double interClusterDistance(const Cluster &c1, const Cluster &c2);
        double intraClusterDistance();
        int getClusterEdges(){
            return size * (size - 1) / 2;
        };

        int interClusterEdges(const Cluster &c1, const Cluster &c2){
            return c1.getSize() * (c2.getSize()-1)/2;

        }


        Cluster(const Cluster &);
        Cluster &operator=(const Cluster &);
        ~Cluster();


        void add(const PointPtr &);
        const PointPtr &remove(const PointPtr &);

        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster &);

        bool operator==(const Cluster &rhs);


        Cluster &operator+=(const Cluster &rhs);
        Cluster &operator-=(const Cluster &rhs);

        Cluster &operator+=(Point &rhs);
        Cluster &operator-=(Point &rhs);


        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);

        void pickPoints(int k, Clustering::PointPtr &pointArray);


    };


    };

#endif //CLUSTERING_CLUSTER_H


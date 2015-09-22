//
// Created by Home on 9/15/15.
//

#include "Cluster.h"

Clustering::Cluster::Cluster(const Clustering::Cluster &cluster) {
    size = cluster.getSize();
    points = cluster.getPtr();
}

Clustering::Cluster &Clustering::Cluster::operator=(const Clustering::Cluster &cluster) {
    Cluster newClust(cluster);
    return newClust;
}

Clustering::Cluster::~Cluster() {

}

void Clustering::Cluster::add(Clustering::PointPtr const &ptr) {
    size+=1;
    LNodePtr newPoint;
    newPoint->p = ptr;
    newPoint->next =nullptr;
    LNodePtr current = points;

    while (current != nullptr){
        if (current->next == nullptr){
            current->next = newPoint;
        }
        current = current->next;
    }
}

Clustering::PointPtr const &Clustering::Cluster::remove(Clustering::PointPtr const &ptr) {
    size-=1;
    LNodePtr newPoint;

    LNodePtr current = points;

    while (current != nullptr){
        if (current->p == ptr){
            return current->p;
        }
        current = current->next;
    }
}

Clustering::Cluster::Cluster(int sizee, Clustering::LNodePtr pt) {
    size = sizee;
    points = pt;
}

bool Clustering::Cluster::operator==(const Cluster &rhs) {
    LNodePtr c1 = points;
    LNodePtr c2 = rhs.getPtr();
    bool status;

    while (c1 != nullptr){
        if (c1->p == c2->p){
            status = true;
        }
        if (c1->p != c2->p){
            return false;
        }
        c1=c1->next;
        c2=c2->next;
    }
}

//appends second cluster to end of first
Clustering::Cluster &Clustering::Cluster::operator+=(const Cluster &rhs){
    LNodePtr current = points;
    for (int i=0;i<size; i++){

        if (current->next == nullptr){
            current->next = rhs.getPtr();
        }
        current = current->next;
    }
    return *this;
};


Clustering::Cluster &Clustering::Cluster::operator-=(const Cluster &rhs){
    LNodePtr current = points;
    LNodePtr previous;
    LNodePtr currentrh = rhs.getPtr();

    while (current != nullptr){
        for (int i=0; i < rhs.getSize();i++){
            if (current == currentrh) {
                previous->next = current->next;
            }
            currentrh = currentrh->next;
            }
        previous = current;
        current = current->next;
    }


    return *this;
};

Clustering::Cluster &Clustering::Cluster::operator+=(Point &rhs){
    LNodePtr current = points;
    LNodePtr newNode;
    newNode->p = &rhs;
    newNode->next = nullptr;
    for (int i=0;i<size; i++){

        if (current->next == nullptr){
            current->next = newNode;
        }
        current = current->next;
    }
    return *this;
};

Clustering::Cluster &Clustering::Cluster::operator-=( Point &rhs){
    LNodePtr current = points;
    LNodePtr previous;


    while (current != nullptr){

            if (current->p == &rhs) {
                previous->next = current->next;
            }

        previous = current;
        current = current->next;
    }


    return *this;
};

const Clustering::Cluster operator+(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs) {
    Clustering::Cluster newClust((lhs.getSize() + rhs.getSize()),lhs.getPtr());
    Clustering::LNodePtr current = newClust.getPtr();
    for (int i=0;i<lhs.getSize(); i++){

        if (current->next == nullptr){
            current->next = rhs.getPtr();
        }
        current = current->next;
    }
    return newClust;
}

const Clustering::Cluster operator-(const Clustering::Cluster &lhs, const Clustering::Cluster &rhs){
    Clustering::LNodePtr current = lhs.getPtr();
    Clustering::LNodePtr previous;
    Clustering::LNodePtr currentrh = rhs.getPtr();
    int count = 0;
    while (current != nullptr){
        for (int i=0; i < rhs.getSize();i++){
            if (current == currentrh) {
                previous->next = current->next;
                count++;
            }
            currentrh = currentrh->next;
        }
        previous = current;
        current = current->next;
    }
    Clustering::Cluster newClust(lhs.getSize()-count,lhs.getPtr());

    return newClust;
};

const Clustering::Cluster operator+(const Clustering::Cluster &lhs, const Clustering::PointPtr &rhs){
    Clustering::Cluster newClust(lhs.getSize() + 1,lhs.getPtr());
    Clustering::LNodePtr current = newClust.getPtr();
    Clustering::LNodePtr newNode;
    newNode->p = rhs;
    newNode->next = nullptr;
    for (int i=0;i<lhs.getSize(); i++){

        if (current->next == nullptr){
            current->next = newNode;
        }
        current = current->next;
    }
    return newClust;
}

const Clustering::Cluster operator-(const Clustering::Cluster &lhs, const Clustering::PointPtr &rhs){
    Clustering::LNodePtr current = lhs.getPtr();
    Clustering::LNodePtr previous;
    Clustering::Cluster newClust(lhs.getSize()-1,lhs.getPtr());


    while (current != nullptr) {
        if (current->p == rhs) {
            previous->next = current->next;
        }


        previous = current;
        current = current->next;
    }



    return newClust;
}
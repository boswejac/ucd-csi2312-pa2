//
// Created by Home on 11/2/15.
//

#ifndef PA2_INT_EXCEPTIONS_H
#define PA2_INT_EXCEPTIONS_H

#include <iostream>
#include "Point.h"
#include "Cluster.h"

namespace Clustering {
    class DimensionalityMismatchEX {
    private:
        Point p1;
        Point p2;
        std::string name;
    public:

        DimensionalityMismatchEX(const Point &p1, const Point &p2) : p1(p1), p2(p2) { }

        Point getP1() { return p1; };

        Point getP2() { return p2; };

        void setP1(Point dat1) { p1 = dat1; };

        void setP2(Point dat2) { p2 = dat2; };

        std::string getName() { return name; };

        void setName(std::string nams) { name = nams; };

        friend std::ostream &operator<<(std::ostream &ostream, const DimensionalityMismatchEX &input) {

            ostream << "Between points: " << input.p1 << " and " << input.p2 << std::endl;
            return ostream;

        };
    };

    class OutOfBoundsEX {
    private:
        int index;
        std::string name;
    public:

        OutOfBoundsEX(int dat) : index(dat) { }

        int getIndex() { return index; };

        std::string getName() { return name; };

        friend std::ostream &operator<<(std::ostream &ostream, const OutOfBoundsEX &input) {

            ostream << "Out of bounds exception thrown: " << input.index << " is not a valid index" << std::endl;
            return ostream;

        };
    };

    class RemoveFromEmptyEX {
    private:
        double data;
        std::string name;
    public:
        double getData() { return data; };

        std::string getName() { return name; };

        friend std::ostream &operator<<(std::ostream &ostream, const RemoveFromEmptyEX &input) {

            ostream << "Cluster is already empty" << std::endl;
            return ostream;

        };
    };


}


#endif //PA2_INT_EXCEPTIONS_H

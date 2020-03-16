#ifndef INFINITEBINARYSEARCH_H
#define INFINITEBINARYSEARCH_H

#include <vector>

#include "../search/binarysearch.h"

using std::vector;

template <typename T>
class InfiniteBinarySearch {
    public:
        int operator()(vector<T> & v, int value) const;
};

// 2 * O(lg(p)) = O(lg(p)) time complexity and O(1) space complexity
template <typename T>
int InfiniteBinarySearch<T>::operator()(vector<T> & v, int value) const {
    int l = 0;
    int r = 1;
    int r_value = v[r];

    // if the value is not part of this interval [l, r] 
    // then the interval size gets doubled [r, r*2]
    // finding the interval has O(lg(p)) with p being the index of the value to find
    while(r_value < value) {
        l = r;
        r *= 2;
        r_value = v[r];
    }

    // the # of elements between l and r [r/2, r] is O(p)
    // binary search on this interval is O(lg(p))
    BinarySearch<T> s;
    return s.binary_search_iterative(v, l, r, value);
}

#endif

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

using std::vector;

template <typename T>
class BinarySearch {
    public:
        int operator()(vector<T> & v, int value);
    private:
        int binary_search_recursive(vector<T> & v, int l, int r, int value);
        int binary_search_iterative(vector<T> & v, int l, int r, int value);
};

template <typename T>
int BinarySearch<T>::operator()(vector<T> & v, int value) {
    return binary_search_iterative(v, 0, v.size()-1, value);
}

// O(lg(N)) time complexity and O(1) space complexity
template <typename T>
int BinarySearch<T>::binary_search_recursive(vector<T> & v, int l, int r, int value) {
    if(l <= r) {
        int mid = l+(r-l) / 2;

        if(value == v[mid]) {
            return mid;
        } else if (value < v[mid]) {
            return binary_search(v, l, mid-1, value);
        }

        return binary_search(v, mid+1, r, value);
    }
    return -1;
}

// O(lg(N)) time complexity and O(1) space complexity
// this has the same theoretical performance as the recursive version 
// but it has a better practical performance because it doesn't use recursive function calls
template <typename T>
int BinarySearch<T>::binary_search_iterative(vector<T> & v, int l, int r, int value) {
    while(l <= r) {
        int mid = l+(r-l) / 2;

        if(value == v[mid]) {
            return mid;
        } else if (value < v[mid]) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

#endif

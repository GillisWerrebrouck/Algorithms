#ifndef HEAPVECTOR_H
#define HEAPVECTOR_H

#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <cassert>
#include <cmath>

#include "./extendedvector.h"

using std::vector;
using std::ostream;

template <class T>
class HeapVector : public ExtendedVector<T> {
    public:
        HeapVector(int);

        HeapVector(const HeapVector<T>& v) = delete;
        HeapVector<T>& operator=(const HeapVector<T>& v) = delete;
        HeapVector<T>& operator=(HeapVector<T>&& v) = delete;
        HeapVector(HeapVector<T>&& v) = delete;

        void top_down_heapify();
        void bottom_up_heapify();
        void add(int, int);
        void remove(int);
        void remove_root();
        void replace_root(int);

    private:
        void top_down_heapify(vector<T> &, int, int);
};

template <class T>
HeapVector<T>::HeapVector(int size) : ExtendedVector<T>(size) {}

// O(N*lg(N))
template <class T>
void HeapVector<T>::top_down_heapify() {
    int n = this->size();
    // iterate over all parent nodes
    for (int i = n/2-1; i >= 0; i--) {
        top_down_heapify(*this, n, i);
    }
}

template <class T>
void HeapVector<T>::top_down_heapify(vector<T> & v, int n, int i) {
    int max = i;
    int left_child = 2*i+1;
    int right_child = 2*i+2;

    // check heap condition on possible child nodes
    if(left_child < n && v[left_child] > v[max]) {
        max = left_child;
    }
    if(right_child < n && v[right_child] > v[max]) {
        max = right_child;
    }

    // check if the root changed
    if(max != i) {
        swap(v[max], v[i]);
        top_down_heapify(v, n, max);
    }
}

// O(N)
template <class T>
void HeapVector<T>::bottom_up_heapify() {
    int n = this->size();
    int parent = n/2-1;

    for(int i = parent; i>=0; i--) {
        int k = i;
        int v = (*this)[k];
        bool isHeap = false;

        // check if the heap condition is met and 
        // if the node with index k has a child (k is not a leaf)
        while(!isHeap && 2*k+1<=n) {
            // left child of k
            int j = 2*k+1;

            // if two child nodes
            if(j<(n-1)) {
                // find max child node
                if((*this)[j] < (*this)[j+1]) j++;
            }

            // check heap condition
            if(v >= (*this)[j]) {
                isHeap = true;
            } else {
                swap((*this)[k], (*this)[j]);
                // next node to be heapified due to change
                k = j;
            }
        }
    }
}

#endif

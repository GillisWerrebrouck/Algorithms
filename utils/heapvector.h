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
        void insert(int);
        int extract(int);
        int extract_root();
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

    for(int i = parent; i >= 0; i--) {
        int k = i;
        int v = (*this)[k];
        bool isHeap = false;

        // check if the heap condition is met and 
        // if the node with index k has a child (k is not a leaf)
        while(!isHeap && 2*k+1 <= n) {
            // left child of k
            int j = 2*k+1;

            // if two child nodes
            if(j < (n-1)) {
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

// O(lg(N))
template <class T>
void HeapVector<T>::insert(int value) {
    (*this).push_back(value);
    int i = this->size()-1;
    int parent = (i-1)/2;

    // trickle-up the new value
    while(0 <= parent && (*this)[parent] < (*this)[i]) {
        swap((*this)[parent], (*this)[i]);

        i = parent;
        parent = (parent-1)/2;
    }
}

// O(lg(N))
template <class T>
int HeapVector<T>::extract(int index) {
    // replace the ndoe to extract with the last node
    int extracted = (*this)[index];
    int n = this->size();
    (*this)[index] = (*this)[n-1];
    (*this).pop_back();

    int i = index;
    int left_child = 2*i+1;
    int right_child = 2*i+2;

    // trickle-down the new value
    while(left_child < n && (*this)[left_child] > (*this)[i] || 
            right_child < n && (*this)[right_child] > (*this)[i]) {
        if((*this)[left_child] > (*this)[right_child]) {
            swap((*this)[left_child], (*this)[i]);

            i = left_child;
            left_child = 2*i+1;
            right_child = 2*i+2;
        } else {
            swap((*this)[right_child], (*this)[i]);

            i = right_child;
            left_child = 2*i+1;
            right_child = 2*i+2;
        }
    }

    return extracted;
}

// O(lg(N))
template <class T>
int HeapVector<T>::extract_root() {
    return extract(0);
}

#endif

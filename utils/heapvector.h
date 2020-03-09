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
        void insert(T);
        int extract(int);
        int extract_root();
        void replace(int, T);
        void replace_root(T);
        void trickle_up(int);
        void trickle_down(int, int);
        void heap_sort();

    private:
        void top_down_heapify(int, int);
};

template <class T>
HeapVector<T>::HeapVector(int size) : ExtendedVector<T>(size) {
    bottom_up_heapify();
}

// O(N*lg(N))
template <class T>
void HeapVector<T>::top_down_heapify() {
    int n = this->size();
    // iterate over all parent nodes
    for (int i = n/2-1; i >= 0; i--) {
        top_down_heapify(n, i);
    }
}

// O(lg(N))
template <class T>
void HeapVector<T>::top_down_heapify(int n, int i) {
    int max = i;
    int left_child = 2*i+1;
    int right_child = 2*i+2;

    // check heap condition on possible child nodes
    if(left_child < n && (*this)[left_child] > (*this)[max]) {
        max = left_child;
    }
    if(right_child < n && (*this)[right_child] > (*this)[max]) {
        max = right_child;
    }

    // check if the root changed
    if(max != i) {
        swap((*this)[max], (*this)[i]);
        top_down_heapify(n, max);
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
void HeapVector<T>::insert(T value) {
    (*this).push_back(value);
    int i = this->size()-1;

    // trickle-up the new value
    trickle_up(i);
}

// O(lg(N))
template <class T>
int HeapVector<T>::extract(int index) {
    // replace the node to extract with the last node
    int extracted = (*this)[index];
    int n = this->size();

    if(index >= n) throw std::out_of_range ("index out of range for heap");

    (*this)[index] = (*this)[n-1];
    (*this).pop_back();

    // trickle-down the new value
    trickle_down(n, index);

    return extracted;
}

// O(lg(N))
template <class T>
int HeapVector<T>::extract_root() {
    return extract(0);
}

// O(lg(N))
template <class T>
void HeapVector<T>::replace(int index, T value) {
    int n = this->size();
    int i = index;

    if(i >= n) throw std::out_of_range ("index out of range for heap");

    int oldValue = (*this)[i];
    (*this)[i] = value;

    if(oldValue > value) {
        // trickle-down the new value
        trickle_down(n, i);
    } else if(oldValue < value) {
        // trickle-up the new value
        trickle_up(i);
    }
}

// O(lg(N))
template <class T>
void HeapVector<T>::replace_root(T value) {
    int n = this->size();
    (*this)[0] = value;

    trickle_down(n, 0);
}

// O(lg(N))
template <class T>
void HeapVector<T>::trickle_up(int i) {
    int parent = (i-1)/2;

    while(0 <= parent && (*this)[parent] < (*this)[i]) {
        swap((*this)[parent], (*this)[i]);

        i = parent;
        parent = (parent-1)/2;
    }
}

// O(lg(N))
template <class T>
void HeapVector<T>::trickle_down(int n, int i) {
    top_down_heapify(n, i);
}

// O(N + N*lg(N)) = O(N*lg(N))
template <class T>
void HeapVector<T>::heap_sort() {
    // O(N)
    bottom_up_heapify();
    int n = this->size();

    // O(N*lg(N))
    for (int i = n-1; i > 0; i--) {
        swap((*this)[0], (*this)[i]);
        // O(lg(N))
        trickle_down(i, 0);
    }
}

#endif

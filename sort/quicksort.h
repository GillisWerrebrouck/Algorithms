#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class Quicksort {
    public:
        void operator()(vector<T> & v);

    private:
        void quicksort(vector<T> &, int, int);
};

template <typename T>
void Quicksort<T>::operator()(vector<T> & v) {
	quicksort(v, 0, v.size());
}

template <typename T>
void Quicksort<T>::quicksort(vector<T> & v, int l, int r) {
    if(l < r-1) {
        T pivot = v[l];

        int i = l;
        int j = r-1;

        while(v[j] > pivot) {
            j--;
        }

        while(i < j) {
            swap(v[i], v[j]);
            i++;
            while(v[i] < pivot) {
                i++;
            }
            j--;
            while(v[j] > pivot) {
                j--;
            }
        }

        quicksort(v, l, j+1);
        quicksort(v, j+1, r);
    }
}

#endif

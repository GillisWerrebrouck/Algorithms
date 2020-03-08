#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class SelectionSort {
    public:
        void operator()(vector<T> & v) const;
};

template <typename T>
void SelectionSort<T>::operator()(vector<T> & v) const{
    for(int i = v.size(); i>0; i--) {
        int maxIndex = i;
        for(int j = 0; j<i; j++) {
            if(v[maxIndex]<v[j]) {
                maxIndex = j;
            }
        }
        swap(v[i], v[maxIndex]);
    }
}

#endif

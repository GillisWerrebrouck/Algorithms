#ifndef TOPDOWNMERGESORT_H
#define TOPDOWNMERGESORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class TopDownMergeSort {
    public:
        void operator()(vector<T> & v);

    private:
        void merge_sort(vector<T> &, int, int, vector<T> &);
        void merge(vector<T> &, int, int, int, vector<T> &);
};

template <typename T>
void TopDownMergeSort<T>::operator()(vector<T> & v) {
    vector<T> temp(v.size()/2);
    merge_sort(v, 0, v.size(), temp);
}

// O(N*lg(N)) time complexity and O(N/2) = O(N) space complexity
template <typename T>
void TopDownMergeSort<T>::merge_sort(vector<T> & v, int l, int r, vector<T> & temp) {
    if(l < r-1) {
        int m = l+(r-l)/2;
        merge_sort(v, l, m, temp);
        merge_sort(v, m, r, temp);
        merge(v, l, m, r, temp);
    }
}

template <typename T>
void TopDownMergeSort<T>::merge(vector<T> & v, int l, int m, int r, vector<T> & temp) {
    int i = l;
    int j = m;
    int p = l;

    // copy first part to temp vector
    for(int k = 0; k < (m-l); k++) {
        swap(v[k+l], temp[k]);
    }

    while(p < r) {
        // as long as both parts have elements to merge
        if(i < m && j < r) {
            // swap the smallest value into the vector
            if(temp[i-l] <= v[j]) {
                swap(v[p], temp[i-l]);
                i++;
            } else {
                swap(v[p], v[j]);
                j++;
            }
        // if the first part still has elements, swap them into the vector
        } else if (i < m) {
            swap(v[p], temp[i-l]);
            i++;
        // if the second part still has elements, swap them into the vector
        } else if (j < r) {
            swap(v[p], v[j]);
            j++;
        }
        p++;
    }
}

#endif

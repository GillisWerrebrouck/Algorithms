#ifndef BOTTOMUPMERGESORT_H
#define BOTTOMUPMERGESORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class BottomUpMergeSort {
    public:
        void operator()(vector<T> & v);

    private:
        void merge_sort(vector<T> &, int, int);
        void merge(vector<T> &, int, int, int);
};

int min(int x, int y) { return (x < y) ? x : y; }

template <typename T>
void BottomUpMergeSort<T>::operator()(vector<T> & v) {
    merge_sort(v, 0, v.size());
}

// O(N*lg(N)) time complexity and O(N) space complexity
template <typename T>
void BottomUpMergeSort<T>::merge_sort(vector<T> & v, int l, int r) {
    // loop over all subparts starting at size 1
    for (int curr_size = 1; curr_size <= v.size()-1; curr_size *= 2) {
        // loop over all left part start positions
        for (int l = 0; l < v.size()-1; l += 2*curr_size) {
            // find middle of left subpart
            int m = min(l + curr_size -1, v.size()-1);
            int r = min(l + 2*curr_size-1, v.size()-1);

            // merge left and right subpart
            merge(v, l, m, r);
        }
    }
}

template <typename T>
void BottomUpMergeSort<T>::merge(vector<T> & v, int l, int m, int r) {
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;
    vector<T> L(n1), R(n2);

    // copy both parts to a temp vector
    for (i = 0; i < n1; i++) {
        L[i] = v[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = v[m + 1 + j];
    }

    // merge both temp vectors in the initial vector
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            swap(v[k], L[i++]);
        } else {
            swap(v[k], R[j++]);
        }
        k++;
    } 
  
    // swap the remaining elements of the left subpart
    while (i < n1) {
        swap(v[k++], L[i++]);
    }

    // swap the remaining elements of the right subpart
    while (j < n2) {
        swap(v[k++], R[j++]);
    }
}

#endif

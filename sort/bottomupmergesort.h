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
        void merge_sort(vector<T> &, int, int, vector<T> &);
        void merge(vector<T> &, int, int, int, vector<T> &);
};

int min(int x, int y) { return (x < y) ? x : y; }

template <typename T>
void BottomUpMergeSort<T>::operator()(vector<T> & v) {
    vector<T> temp(v.size()/2);
    merge_sort(v, 0, v.size(), temp);
}

// O(N*lg(N)) time complexity and O(N/2) = O(N) space complexity
template <typename T>
void BottomUpMergeSort<T>::merge_sort(vector<T> & v, int l, int r, vector<T> & temp) {
    // loop over all subparts starting at size 1
    for (int curr_size = 1; curr_size <= v.size()-1; curr_size *= 2) {
        // loop over all left part start positions
        for (int l = 0; l < v.size()-1; l += 2*curr_size) {
            // find middle of left subpart
            int m = l + curr_size;
            int r = min(l + 2*curr_size, v.size());

            // merge left and right subpart
            merge(v, l, m, r, temp);
        }
    }
}

template <typename T>
void BottomUpMergeSort<T>::merge(vector<T> & v, int l, int m, int r, vector<T> & temp) {
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

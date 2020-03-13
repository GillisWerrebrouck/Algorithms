#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class ShellSort {
    public:
        void operator()(vector<T> & v);
};

template <typename T>
void ShellSort<T>::operator()(vector<T> & v) {
    // The Sedgewick's sequence (O(N^4/3) in case of big N)
    int gaps[] = { 929, 505, 209, 109, 41, 19, 5, 1 };

    for(int k : gaps) {
        for(int i = k; i<v.size(); i+=k) {
            int j = i-k;
            while(j>-1 && v[j]>v[j+1]) {
                swap(v[j], v[j+1]);
                j-=k;
            }
        }
    }
}

#endif

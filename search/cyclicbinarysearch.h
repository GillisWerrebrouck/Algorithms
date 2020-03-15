#ifndef CYCLICBINARYSEARCH_H
#define CYCLICBINARYSEARCH_H

#include <vector>

using std::vector;

template <typename T>
class CyclicBinarySearch {
    public:
        int operator()(vector<T> & v, int value);
    private:
        int cyclic_binary_search(vector<T> v, int l, int r, int value);
};

template <typename T>
int CyclicBinarySearch<T>::operator()(vector<T> & v, int value) {
    return cyclic_binary_search(v, 0, v.size()-1, value);
}

// O(lg(N)) time complexity and O(1) space complexity
template <typename T>
int CyclicBinarySearch<T>::cyclic_binary_search(vector<T> v, int l, int r, int value) {
    if(l > r) return -1;

    int m = l + (r-l) / 2;
    if(v[m] == value)
        return m;
    
    if(v[l] <= v[m]) {
        if(v[l] <= value && value <= v[m])
            return cyclic_binary_search(v, l, m-1, value);
        
        return cyclic_binary_search(v, m+1, r, value);
    }

    if(v[m] <= value && value <= v[r]) {
        return cyclic_binary_search(v, m+1, r, value);
    }
    return cyclic_binary_search(v, l, m-1, value);
}

#endif

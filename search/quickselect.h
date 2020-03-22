#ifndef QUICKSELECT_H
#define QUICKSELECT_H

#include <vector>

using std::vector;

template <typename T>
class Quickselect {
    public:
        T operator()(vector<T> & v, int k) const;
    private:
        T quick_select(vector<T> & v, int k, int l, int r) const;
};

template <typename T>
T Quickselect<T>::operator()(vector<T> & v, int k) const {
    if(k < 0 || v.size() <= k) {
        throw "index k is out of range";
    }
    vector<T> copy(v);
    return quick_select(copy, k, 0, v.size());
}

// O(nk) time complexity
template <typename T>
T Quickselect<T>::quick_select(vector<T> & v, int k, int l, int r) const {
    if(l == r-1)
        return v[l];

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

    if(j == k) {
        return v[j];
    } else if (j > k) {
        return quick_select(v, k, l, j+1);
    } else {
        return quick_select(v, k, j+1, r);
    }
}

#endif

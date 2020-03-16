#ifndef INTERPOLATEDSEARCH_H
#define INTERPOLATEDSEARCH_H

#include <vector>

using std::vector;

template <typename T>
class InterpolatedSearch {
    public:
        int operator()(vector<T> & v, int value) const;
};

// O(lg(lg(N))) time complexity if elements are uniformly distributed or O(N) in the worst case
// O(1) space complexity
template <typename T>
int InterpolatedSearch<T>::operator()(vector<T> & v, int value) const {
    int n = v.size();
    int l = 0;
    int r = n-1;

    while (l <= r && v[l] <= value && value <= v[r]) {
        if (l == r) {
            if (v[l] == value)
                return l;
            return -1;
        }

        int pos = l + (((r - l) / (v[r] - v[l])) * (value - v[l]));

        if (v[pos] == value)
            return pos;
        
        if (v[pos] < value)
            l = pos + 1;
        else
            r = pos - 1;
    }
    return -1;
}

#endif

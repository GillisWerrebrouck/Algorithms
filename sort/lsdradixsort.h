#ifndef LSDRADIXSORT_H
#define LSDRADIXSORT_H

#include <vector>

using std::vector;
using std::swap;
using std::move;

template <typename T>
class LSDRadixSort {
    public:
        void operator()(vector<T> & v);
};

// O(N lg_m(N)) time complexity with N being the number of elements and m the radix
template <typename T>
void LSDRadixSort<T>::operator()(vector<T> & v) {
    int max = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > max) {
			max = v[i];
		}
	}

	for (int exp = 1; max/exp > 0; exp *= 10) {
		radix_counting_sort(v, exp);
	}
}

#endif

#ifndef RADIXEXCHANGESORT_H
#define RADIXEXCHANGESORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class RadixExchangeSort {
    public:
        void operator()(vector<T> & v);
    private:
        void radix_exchange_sort(vector<T> &v, int l, int r, int bitnr);
};

template <typename T>
void RadixExchangeSort<T>::operator()(vector<T> & v) {
    radix_exchange_sort(v, 0, v.size() - 1, 0);
}

unsigned int get_digit(unsigned long value, unsigned int d) {
	return (value>>64-d-1)&1;
}

// O(nk) time complexity with n being the number of elements and k the max digit count
// O(1) space complexity
template <typename T>
void RadixExchangeSort<T>::radix_exchange_sort(vector<T> &v, int l, int r, int bit) {
    int i = l;
	int j = r;
	
	if (r <= l || bit > (64*8)) return;
	
	while (j != i) {
		while (get_digit(v[i], bit) == 0 && i < j) {
			i++;
		}
		while (get_digit(v[j], bit) == 1 && j > i) {
			j--;
		}
		swap(v[i], v[j]);
	}
	
	if (get_digit(v[r], bit) == 0) j++;
	
	radix_exchange_sort(v, l, j-1, bit+1);
	radix_exchange_sort(v, j, r, bit+1);
}

#endif

#ifndef TERNARYRADIXQUICKSORT_H
#define TERNARYRADIXQUICKSORT_H

// helper macros
#define BIT 8
#define R (1 << BIT)
#define digit(A, B) ((A >> (BIT-(B+1)*BIT)) & (R-1))

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class TernaryRadixQuicksort {
    public:
        void operator()(vector<T> & v);
	private:
		void ternary_radix_quicksort(vector<T> & v, int l, int r, int bit);
};

template <typename T>
void TernaryRadixQuicksort<T>::operator()(vector<T> & v) {
    ternary_radix_quicksort(v, 0, v.size()-1, 0);
}

template <typename T>
void TernaryRadixQuicksort<T>::ternary_radix_quicksort(vector<T> & v, int l, int r, int bit) {
    int i, j, k, p, q;
	int w;

	w = digit(v[r], bit);
	i = l-1;
	j = r;
	p = l-1;
	q = r;

	// partitioning in 3 parts
	while (i < j) {
		while (digit(v[++i], bit) < w);

		while (w < digit(v[--j], bit))
			if (j == l) break;

		if (i > j) break;
		
		swap(v[i], v[j]);

		if (digit(v[i], bit) == w) {
			p++;
			swap(v[p], v[i]);
		}

		if (w == digit(v[j], bit)) {
			q--;
			swap(v[j], v[q]);
		}
	}

	if (p == q) {
		if (w != '\0')
			ternary_radix_quicksort(v, l, r, bit+1);
		return;
	}

	if (digit(v[i], bit) < w) i++;

	for (k = l; k <= p; k++, j--)
		swap(v[k], v[j]);

	for (k = r; k >= q; k--, i++)
		swap(v[k], v[i]);

	ternary_radix_quicksort(v, l, j, bit);

	if ((i == r) && (digit(v[i], bit) == w)) i++;

	if (w != '\0')
		ternary_radix_quicksort(v, j+1, i-1, bit+1);

	ternary_radix_quicksort(v, i, r, bit);
}

#endif

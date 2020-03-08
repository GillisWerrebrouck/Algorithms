#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class InsertionSort {
    public:
        void operator()(vector<T> & v) const;
};

template <typename T>
void InsertionSort<T>::operator()(vector<T> & v) const{
    for(int i = 1; i<v.size(); i++) {
    	int j = i-1;
    	while(j>-1 && v[j]>v[j+1]) {
			swap(v[j], v[j+1]);
    		j--;
		}
	}
}

#endif

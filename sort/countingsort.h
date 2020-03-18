#ifndef COUNTINGNSORT_H
#define COUNTINGNSORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class CountingSort {
    public:
        void operator()(vector<T> & v);
};

template <typename T>
void getMinAndMax(vector<T> & v, T & min, T & max) {
    if(v.size() == 0) return;

    min = max = v[0];
    for(int i = 1; i < v.size()-1; i++) {
        if(min > v[i]) {
            min = v[i];
        } else if(max < v[i]) {
            max = v[i];
        }
    }
}

template <typename T>
void CountingSort<T>::operator()(vector<T> & v) {
    T min, max;
    getMinAndMax(v, min, max);
    T range = max - min + 1;

    vector<T> count(range), output(v.size()); 

    // count relative frequency of each element
    for(int i = 0; i < v.size(); i++)
        count[v[i]-min]++;
    
    // count cumulative frequency of each element
    for(int i = 1; i < count.size(); i++)
        count[i] += count[i-1];
    
    for(int i = v.size()-1; i >= 0; i--) {
        output[ count[v[i]-min] -1 ] = v[i];
        count[v[i]-min]--;
    }
      
    for(int i=0; i < v.size(); i++)
        v[i] = output[i];
}

#endif

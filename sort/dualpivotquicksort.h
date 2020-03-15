#ifndef DUALPIVOTQUICKSORT_H
#define DUALPIVOTQUICKSORT_H

#include <vector>

using std::vector;
using std::swap;

template <typename T>
class DualPivotQuicksort {
    public:
        void operator()(vector<T> & v);

    private:
        void dualpivotquicksort(vector<T> &, int, int);
};

template <typename T>
void DualPivotQuicksort<T>::operator()(vector<T> & v) {
    dualpivotquicksort(v, 0, v.size()-1);
}

template <typename T>
void DualPivotQuicksort<T>::dualpivotquicksort(vector<T> & v, int l, int r) {
    if(l < r) {
        int lp, rp;

        // the left pointer needs to be the lowest value
        if(v[l] > v[r]) {
            swap(v[l], v[r]);
        }

        // j will be used to know the last element of the first part (0 - left pivot)
        int j = l+1;
        // k through j is the fourth part which has non classified values
        // which means this part has values which haven't yet been assigned 
        // to any part divided by the pivots
        int k = l+1;
        int g = r-1;

        T leftPivot = v[l];
        T rightPivot = v[r];

        // while the fourth part still has unclassified elements
        while(k <= g) {
            // if elements are less than the left pivot
            if(v[k] < leftPivot) {
                swap(v[k], v[j]);
                j++;
            }
            // if elements are greater than or equal to the right pivot
            else if(v[k] >= rightPivot) {
                while (v[g] > rightPivot && k < g) {
                    g--;
                }
                swap(v[k], v[g]);
                g--;
                if (v[k] < leftPivot) {
                    swap(v[k], v[j]);
                    j++;
                }
            }
            k++;
        }
        j--;
        g++;

        // swap the last elements of part 1 with the left pivot
        swap(v[l], v[j]);
        // swap the last elements of part 2 (between left and right pivot) with the right pivot
        swap(v[r], v[g]);

        // set the new indices for the left and right pivot
        lp = j;
        rp = g;

        // repeat this for each part recursively
        dualpivotquicksort(v, l, lp-1);
        dualpivotquicksort(v, lp+1, rp-1);
        dualpivotquicksort(v, rp+1, r);
    }
}

#endif

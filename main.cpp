#include <iostream>

#include "utils/extendedvector.h"

using std::cout;

int main() {
    ExtendedVector<int> data(100);
    cout << data;
    data.selection_sort();
    cout << data;

    return 0;
}
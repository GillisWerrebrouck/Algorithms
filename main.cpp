#include <iostream>

#include "utils/extendedvector.h"

using std::cout;

int main() {
    ExtendedVector<int> data(15);
    cout << data;
    data.insertion_sort();
    cout << data;

    return 0;
}
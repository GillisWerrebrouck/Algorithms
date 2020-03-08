#include <iostream>

#include "utils/extendedvector.h"

using std::cout;

int main() {
    ExtendedVector<int> data(10000);
    cout << data;
    data.shell_sort();
    cout << data;

    return 0;
}
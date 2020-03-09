#include <iostream>

#include "utils/extendedvector.h"
#include "utils/heapvector.h"

using std::cout;

int main() {
    ExtendedVector<int> data(10);
    cout << data;
    data.top_down_merge_sort();
    cout << data;

    return 0;
}
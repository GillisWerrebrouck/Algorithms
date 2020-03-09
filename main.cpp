#include <iostream>

#include "utils/extendedvector.h"
#include "utils/heapvector.h"

using std::cout;

int main() {
    ExtendedVector<int> data(10);
    cout << data;
    data.botom_up_merge_sort();
    cout << data;

    return 0;
}
#include <iostream>

#include "utils/extendedvector.h"
#include "utils/heapvector.h"

using std::cout;

int main() {
    HeapVector<int> data(10);
    cout << data;
    data.heap_sort();
    cout << data;

    return 0;
}
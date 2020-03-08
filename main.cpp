#include <iostream>

#include "utils/extendedvector.h"
#include "utils/heapvector.h"

using std::cout;

int main() {
    HeapVector<int> data(100);
    data.fill_range();
    cout << data;
    data.bottom_up_heapify();
    cout << data;

    return 0;
}
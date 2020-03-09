#include <iostream>

#include "utils/extendedvector.h"
#include "utils/heapvector.h"

using std::cout;
using std::endl;
using std::string;

void test_sort_methods(int);
void print_sorted(const string&, ExtendedVector<int> &);

int main() {
    test_sort_methods(25);

    return 0;
}

void test_sort_methods(int size) {
    ExtendedVector<int> data(size);

    data.insertion_sort();
    print_sorted("insertion sort", data);
    data.fill_random();

    data.shell_sort();
    print_sorted("shell sort", data);
    data.fill_random();

    data.selection_sort();
    print_sorted("selection sort", data);
    data.fill_random();

    data.top_down_merge_sort();
    print_sorted("top-down merge sort", data);
    data.fill_random();

    data.botom_up_merge_sort();
    print_sorted("bottom-up merge sort", data);


    HeapVector<int> heap(size);

    heap.heap_sort();
    print_sorted("heap sort", heap);
}

void print_sorted(const string& tag, ExtendedVector<int> & v) {
    cout << "[ " << tag << (v.is_sorted() ? " ✔️" : " ❌") << " ]" << endl;
    cout << v << endl;
}

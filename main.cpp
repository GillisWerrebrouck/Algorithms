#include <iostream>

#include "utils/extendedvector.h"
#include "utils/heapvector.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void test_sort_methods(int);
void test_search_methods();
template <class T>
void print_sorted(const string&, ExtendedVector<T> &);
template <class T>
void print_search(const string&, ExtendedVector<T> &, T, int);

int main() {
    test_sort_methods(25);
    test_search_methods();

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
    data.fill_random();

    data.quicksort();
    print_sorted("quicksort", data);
    data.fill_random();

    data.dual_pivot_quicksort();
    print_sorted("dual pivot quicksort", data);
    data.fill_random();


    HeapVector<int> heap(size);

    heap.heap_sort();
    print_sorted("heap sort", heap);


    data.counting_sort();
    print_sorted("counting sort", data);
    data.fill_random();

    data.radix_exchange_sort();
    print_sorted("radix exchange sort", data);
    data.fill_random();

    data.msd_radix_sort();
    print_sorted("MSD radix sort", data);
    data.fill_random();

    // current implementation of ternary radix quicksort is limited
    ExtendedVector<int> data_trq(25);
    data_trq.ternary_radix_quicksort();
    print_sorted("ternary radix quicksort", data_trq);
}

void test_search_methods() {
    ExtendedVector<int> data(50);
    data.quicksort();
    cout << "search vector: " << data;

    int value = 41;
    int index;

    index = data.sequential_search(value);
    print_search("sequential search", data, value, index);

    index = data.binary_search(value);
    print_search("binary search", data, value, index);

    data.rotate_left(20);
    cout << "cyclical ordered search vector: " << data;
    index = data.cyclic_binary_search(value);
    print_search("cyclic binary search", data, value, index);

    // "infinite" vector
    ExtendedVector<int> infinite_data(10'000);
    infinite_data.quicksort();
    value = 2'000;
    index = infinite_data.infinite_binary_search(value);
    print_search("infinite binary search", infinite_data, value, index);

    // an ordered range has a uniform distribution of values
    // which is suitable for interpolation search
    data.fill_range();
    value = 41;
    index = data.interpolation_search(value);
    print_search("interpolation search", data, value, index);

}

template <class T>
void print_sorted(const string& tag, ExtendedVector<T> & v) {
    cout << "[ " << tag << (v.is_sorted() ? " ✔️" : " ❌") << " ]" << endl;
    cout << v << endl;
}

template <class T>
void print_search(const string& tag, ExtendedVector<T> & v, T value, int index) {
    cout << "[ " << tag << " ] Value " << value;
    if(index == -1) {
        cout << " not found";
    } else {
        cout << " found at index " << index;
    }
    cout << endl;
}

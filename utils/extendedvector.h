#ifndef EXTENDEDVECTOR_H
#define EXTENDEDVECTOR_H

#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <cassert>

#include "../sort/insertionsort.h"
#include "../sort/shellsort.h"
#include "../sort/selectionsort.h"

using std::vector;
using std::ostream;

template <class T>
class ExtendedVector : public vector<T> {
    public:
        ExtendedVector(int);

        ExtendedVector(const ExtendedVector<T>& v) = delete;
        ExtendedVector<T>& operator=(const ExtendedVector<T>& v) = delete;
        ExtendedVector<T>& operator=(ExtendedVector<T>&& v) = delete;
        ExtendedVector(ExtendedVector<T>&& v) = delete;

        void fill_range();
        void reverse();
        void reverse_fill();
        void shuffle();
        void fill_random_without_doubles();
        void fill_random();

        void insertion_sort();
        void shell_sort();
        void selection_sort();

        bool is_sorted() const;
        bool is_range() const;

        friend ostream& operator<<(ostream& os, const ExtendedVector<T>& v) {
            v.write(os);
            return os;
        }

    private:
        void write(ostream & os)const;
};

template <class T>
ExtendedVector<T>::ExtendedVector(int size) : std::vector<T>(size) {
    if (size > 0) {
        fill_random();
    }
}

template <class T>
void ExtendedVector<T>::fill_range() {
	int i = 0;
	std::generate(this->begin(), this->end(), [&i]() { return i++; });
}

template <class T>
void ExtendedVector<T>::reverse() {
	reverse(this->begin(), this->end());
}

template <class T>
void ExtendedVector<T>::reverse_fill() {
	int i = (*this).size()-1;
	std::generate(this->begin(), this->end(), [&i]() { return i--; });
}

template <class T>
void ExtendedVector<T>::shuffle() {
	std::random_shuffle(this->begin(), this->end());
}

template <class T>
void ExtendedVector<T>::fill_random_without_doubles() {
	this->vul_range();
	this->shuffle();
}

template <class T>
void ExtendedVector<T>::fill_random() {
    if (this->empty()) {
        return;
    }

    std::random_device rd;
    std::mt19937 eng{rd()};
    const auto max_value = (this->size() - 1);
    assert(max_value < std::numeric_limits<int>::max());
    std::uniform_int_distribution<int> dist{0, static_cast<int>(max_value)};

    std::generate(this->begin(), this->end(), [&dist, &rd]() { return dist(rd); });
}

template <class T>
void ExtendedVector<T>::insertion_sort() {
    InsertionSort<T> s;
    s(*this);
}

template <class T>
void ExtendedVector<T>::shell_sort() {
    ShellSort<T> s;
    s(*this);
}

template <class T>
void ExtendedVector<T>::selection_sort() {
    SelectionSort<T> s;
    s(*this);
}

template <class T>
bool ExtendedVector<T>::is_sorted() const {
	return std::is_sorted(this->begin(), this->end());
}

template <class T>
bool ExtendedVector<T>::is_range() const {
    int value = 0;
	for(auto it = this->begin(); it != this->end(); ++it) {
		if(*it != value++) {
			return false;
		}
	}
	return true;
}

template <class T>
void ExtendedVector<T>::write(ostream & os) const {
    for(auto&& t : *this) {
        os<<t<<" ";
    }
    os<<"\n";
}

#endif

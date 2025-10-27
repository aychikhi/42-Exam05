#include "set.hpp"

set::set(searchable_bag& other) : bag_ptr(other) {
}


void	set::insert(int value) {
	if (!bag_ptr.has(value)) {
		bag_ptr.insert(value);
	}
}

void	set::insert(int *array, int size) {
	for (int i = 0; i < size; i++) {
		if (!bag_ptr.has(array[i]))
			bag_ptr.insert(array[i]);
	}
}

void	set::print() const {
	bag_ptr.print();
}

void	set::clear() {
	bag_ptr.clear();
}


bool	set::has(int value) const {
	return (bag_ptr.has(value));
}


searchable_bag&	set::get_bag() const {
	return (bag_ptr);
}

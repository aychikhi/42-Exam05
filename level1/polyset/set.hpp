#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"
#include "array_bag.hpp"
#include "tree_bag.hpp"

class set {
	private:
		searchable_bag& bag_ptr;

	public:
		set(searchable_bag& other);

		void insert(int value);
		void insert(int *array, int size);
		void print() const;
		void clear();

		bool has(int value) const;

		searchable_bag& get_bag() const;

};

#endif

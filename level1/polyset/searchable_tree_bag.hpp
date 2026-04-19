#pragma once

#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag : public tree_bag , public searchable_bag
{
    public:
        searchable_tree_bag() {};
        searchable_tree_bag(const searchable_tree_bag& obj) : tree_bag(obj){};
        searchable_tree_bag operator=(const searchable_tree_bag& obj)
        {
            if (this != &obj)
            {
                tree_bag::operator=(obj);
            }
            return *this;
        };
        ~searchable_tree_bag(){};

        bool has( int value) const
        {
            node *current = tree;
            while (current)
            {
                if (current->value == value)
                    return true;
                else if( current->value > value)
                    current =current->l;
                else
                    current = current->r;
            }
            return false;
        };

};
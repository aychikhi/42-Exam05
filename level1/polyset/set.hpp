#pragma once

#include "searchable_bag.hpp"
class set
{
    private:
        searchable_bag &bag;
    public:
        set(searchable_bag &bag) : bag(bag) {};
        set(const set& obj) : bag(obj.bag) {};
        ~set() {};

        void insert(int value)
        {
            if(!bag.has(value))
                bag.insert(value);
        };
	    void insert(int *data, int size) 
        {
            for (int i = 0; i < size; i++)
            {
                if(!bag.has(data[i]))
                    bag.insert(data[i]);
            }
            
        };
	    void print() const
        {
            bag.print();
        };
	    void clear()
        {
            bag.clear();
        };

        bool has(int value)const 
        {
            return(bag.has(value));
        };
        const searchable_bag &get_bag() const
        {
            return(bag);
        };
};
#pragma once

#include <iostream>

class vect2
{
    private:
        int x, y;
    public:
        vect2() : x(0) , y(0) {};
        vect2(int x, int y) : x(x) , y(y) {};
        vect2(const vect2& obj) : x(obj.x) , y(obj.y){};
        vect2 operator=(const vect2& obj) 
        {
            if(this != &obj)
            {
                x = obj.x;
                y = obj.y;
            }
            return *this;
        };

        int& operator[](int i)
        {
            if(i == 0)
                return x;
            else
                return y;
        };
        int operator[](int i) const
        {
            if(i == 0)
                return x;
            else
                return y;
        };

        vect2& operator++()
        {
            x++;
            y++;
            return *this;
        };
        vect2 operator++(int)
        {
            vect2 tmp = *this;
            x++;
            y++;
            return tmp;
        };
        vect2& operator--()
        {
            x--;
            y--;
            return *this;
        };
        vect2 operator--(int)
        {
            vect2 tmp = *this;
            x--;
            y--;
            return tmp;
        };
        
        vect2& operator+=(const vect2& obj)
        {
            x += obj.x;
            y += obj.y;
            return *this;
        };
        vect2& operator-=(const vect2& obj)
        {
            x -= obj.x;
            y -= obj.y;
            return *this;
        };
        vect2& operator*=(int v)
        {
            x *= v;
            y *= v;
            return *this;
        };

        vect2 operator+(const vect2 &obj) const
        {
            return(vect2(x + obj.x , y + obj.y));
        };
        vect2 operator-(const vect2 &obj) const
        {
            return(vect2(x - obj.x , y - obj.y));
        };
        vect2 operator*(int v) const
        {
            return(vect2(x * v , y * v));
        };

        vect2 operator-()
        {
            return(vect2(-x, -y));
        }

        bool operator==(const vect2 &obj)
        {
            return(x == obj.x && y == obj.y);
        };
        bool operator!=(const vect2 &obj)
        {
            return(x != obj.x && y != obj.y);
        };

        friend vect2 operator*(int v, const vect2 &obj)
        {
            return(vect2(obj.x * v , obj.y * v));
        }
        friend std::ostream& operator<<(std::ostream &os , const vect2 &obj)
        {
            os << "{" << obj[0] << ", " << obj[1] << "}";
            return(os);
        };
};
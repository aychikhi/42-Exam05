#pragma once

#include <string>
#include <iostream>
#include <algorithm>
class bigint
{
    private:
        std::string nbr;
    public:
        bigint() : nbr("0") {}
        bigint(size_t num) : nbr(std::to_string(num)){}
        bigint(std::string num)
        {
            nbr = num;
        }
        friend std::ostream &operator<<(std::ostream &os , const bigint &b)
        {
            return os << b.nbr;
        }
        std::string add_string(const std::string s1, const std::string s2) const
        {
            int size1 = s1.size() - 1;
            int size2 = s2.size() - 1;
            int carr = 0;
            std::string res;
            int a ,b;
            while (size1 >= 0 || size2 >= 0 || carr)
            {
                if (size1 >= 0)
                    a = s1[size1] - '0';
                else
                    a = 0;
                if (size2 >= 0)
                    b = s2[size2] - '0';
                else
                    b = 0;
                int sum = a + b + carr;
                res.push_back(sum % 10 + '0');
                carr = sum / 10;
                size1--;
                size2--;
            }
            std::reverse(res.begin(),res.end());
            return res;
        }
        bigint operator+(const bigint b) const
        {
            return (bigint(add_string(this->nbr, b.nbr)));
        }
        bigint operator+=(bigint b)
        {
            nbr = add_string(nbr, b.nbr);
            return (*this);
        }
        bigint& operator++()
        {
            *this += bigint(1);
            return (*this);
        }
        bigint operator++(int)
        {
           bigint tmp = bigint(nbr);
           ++(*this);
           return tmp;
        }
        bigint operator<<(size_t sh) const
        {
            if (nbr == "0")
                return bigint(nbr);
            return (bigint(nbr + std::string(sh,'0')));
        }
        bigint &operator<<=(size_t sh)
        {
            if (nbr != "0")
                nbr += std::string(sh,'0');
            return (*this);
        }
        bigint &operator>>=(const bigint shift)
        {
            if (bigint(nbr.size()) < shift)
                nbr = "0";
            else
            {
                bigint i(0);
                while (i < shift)
                {
                    nbr = nbr.substr(0,nbr.size() - 1);
                    ++i;
                }
            }
            if(nbr.empty())
                nbr = "0";
            return (*this);
        }
        bool operator<(const bigint &b) const
        {
            if (nbr.size() < b.nbr.size())
                return true;
            else if (nbr.size() > b.nbr.size())
                return false;
            return (nbr < b.nbr);
        }
        bool operator>(const bigint &b) const
        {
            return (b < *this);
        }
        bool operator==(const bigint &b) const
        {
            return (b.nbr == this->nbr);
        }
        bool operator!=(const bigint &b) const
        {
            return (!(b == *this));
        }
        bool operator>=(const bigint &b) const
        {
            return (!(*this < b));
        }
        bool operator<=(const bigint &b) const
        {
            return (!(*this > b));
        }
};

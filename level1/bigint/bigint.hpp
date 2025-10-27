#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
	private:
		std::string	digit;
		std::string addNumbers(const std::string& a, const std::string& b) const;

	public:
		bigint();
		bigint(size_t n);
		bigint(const std::string& s);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);

		bigint operator+(const bigint& other) const;
		bigint operator-(const bigint& other) const;
		bigint& operator+=(const bigint& other);

		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(int shift) const;
		bigint& operator<<=(int shift);
		bigint& operator>>=(const bigint& shift);

		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;

		friend std::ostream& operator<<(std::ostream& os, const bigint& other);
};

#endif
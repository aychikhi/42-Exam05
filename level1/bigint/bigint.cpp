#include "bigint.hpp"

bigint::bigint() : digit("0") {
}

bigint::bigint(size_t n) : digit(std::to_string(n)) {
}

bool	iszero(int c) {
	return (c == '0');
}

bigint::bigint(const std::string& s) {
	if (s.empty() || !std::all_of(s.begin(), s.end(), ::isdigit) || std::all_of(s.begin(), s.end(), iszero)) {
		digit = "0";
	}
	else {
		size_t	non_zero = s.find_first_not_of('0');
		digit = s.substr(non_zero);
	}
}

bigint::bigint(const bigint& other) : digit(other.digit) {
}

bigint&	bigint::operator=(const bigint& other) {
	if (this != &other) {
		digit = other.digit;
	}
	return (*this);
}


std::string	bigint::addNumbers(const std::string& a, const std::string& b) const {
	std::string	result;
	int	carry = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry) {
		int	first = 0;
		int	secnd = 0;
		if (i >= 0) {
			first = a[i--] - 48;
		}
		if (j >= 0) {
			secnd = b[j--] - 48;
		}
		int res = first + secnd + carry;
		carry = res / 10;
		result.push_back(res % 10 + 48);
	}
	std::reverse(result.begin(), result.end());
	return (result);
}

bigint	bigint::operator+(const bigint& other) const {
	return (bigint(addNumbers(digit, other.digit)));
}

bigint	bigint::operator-(const bigint& other) const {
	(void)other;
	return (bigint());
}

bigint&	bigint::operator+=(const bigint& other) {
	digit = addNumbers(digit, other.digit);
	return (*this);
}


bigint&	bigint::operator++() {
	*this = *this + bigint(1);
	return (*this);
}

bigint	bigint::operator++(int) {
	bigint	temp(*this);
	++(*this);
	return (temp);
}


bigint	bigint::operator<<(int shift) const {
	return (bigint(digit + std::string(shift, '0')));
}

bigint&	bigint::operator<<=(int shift) {
	digit += std::string(shift, '0');
	return (*this);
}

bigint&	bigint::operator>>=(const bigint& shift) {
	// if (bigint(digit.size()) <= shift) {
	// 	digit = "0";
	// }
	// else {
	// 	for (bigint i(0); i < shift; i++) {
	// 		digit = digit.substr(0, digit.size() - 1);
	// 	}
	// }
	size_t	shift_value = std::stoull(shift.digit);
	if (digit.size() <= shift_value) {
		digit = "0";
	}
	else {
		digit = digit.substr(0, digit.size() - shift_value);
	}
	return (*this);
}

bool	bigint::operator<(const bigint& other) const {
	if (digit.size() < other.digit.size()) {
		return (true);
	}
	if (digit.size() > other.digit.size()) {
		return (false);
	}
	return (digit < other.digit);
}

bool	bigint::operator>(const bigint& other) const {
	return (!(*this < other));
}

bool	bigint::operator==(const bigint& other) const {
	return (digit == other.digit);
}

bool	bigint::operator!=(const bigint& other) const {
	return (!(*this == other));
}

bool	bigint::operator<=(const bigint& other) const {
	return (!(*this > other));
}

bool	bigint::operator>=(const bigint& other) const {
	return (!(*this < other));
}


std::ostream& operator<<(std::ostream& os, const bigint& other) {
	os << other.digit;
	return (os);
}

#include "vect2.hpp"

//	Canonical form
vect2::vect2() : x(0), y(0) {
}

vect2::vect2(int x, int y) : x(x), y(y) {
}

vect2::vect2(const vect2& other) : x(other.x), y(other.y) {
}

vect2&  vect2::operator=(const vect2& other) {
	if (this != &other) {
		x = other.x;
		y = other.y;
	}
	return (*this);
}

vect2::~vect2() {
}

//	Element access
int&    vect2::operator[](int index) {
	if (index == 0) {
		return (x);
	}
	return (y);
}

const int&  vect2::operator[](int index) const {
	if (index == 0) {
		return (x);
	}
	return (y);
}

//	Increment
vect2&	vect2::operator++() {
	++x;
	y++;
	return (*this);
}

vect2&	vect2::operator--() {
	x--;
	--y;
	return (*this);
}

vect2	vect2::operator++(int) {
	vect2	tmp(x, y);
	operator++();
	return (tmp);
}

vect2	vect2::operator--(int) {
	vect2	tmp(x, y);
	operator--();
	return (tmp);
}

//	Comparisons
vect2&	vect2::operator+=(const vect2& other) {
	x += other.x;
	y += other.y;
	return (*this);
}

vect2&	vect2::operator-=(const vect2& other) {
	x -= other.x;
	y -= other.y;
	return (*this);
}

vect2&	vect2::operator*=(int t) {
	x *= t;
	y *= t;
	return (*this);
}

vect2	vect2::operator+(const vect2& other) const {
	return (vect2(x + other.x, y + other.y));
}

vect2	vect2::operator-(const vect2& other) const {
	return (vect2(x - other.x, y - other.y));
}

vect2	vect2::operator*(int t) const {
	return (vect2(x * t, y * t));
}

vect2	vect2::operator-() const {
	return (vect2(-x, -y));
}

bool	vect2::operator==(const vect2& other) const {
	return (x == other.x && y == other.y);
}

bool	vect2::operator!=(const vect2& other) const {
	return (!(this == &other));
}

vect2	operator*(int t, const vect2& other) {
	return (vect2(t * other.x, t* other.y));
}

std::ostream&	operator<<(std::ostream& os, const vect2& other) {
	os << "{" << other[0] << ", " << other[1] << "}";
	return (os);
}

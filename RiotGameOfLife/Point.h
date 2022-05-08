#pragma once
#include <cstdint>
#include <set>
#include <tuple>
#include <vector>
#include <string>

struct Point
{
	int64_t x;
	int64_t y;

	Point() = default;
	Point(int64_t aX, int64_t aY);
	
	const std::vector<Point> neighbours() const;

	//write my own hash function and compare time to this.
	bool operator< (const Point& rhs) const;
	bool operator> (const Point& rhs) const;
	bool operator<= (const Point& rhs) const;
	bool operator>= (const Point& rhs) const;
	bool operator== (const Point& rhs) const;
	bool operator!= (const Point& rhs) const;
};
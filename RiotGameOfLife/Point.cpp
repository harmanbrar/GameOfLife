#include "Point.h"

Point::Point(int64_t aX, int64_t aY)
	:x(aX), y(aY)
{
}

const std::vector<Point> Point::neighbours() const
{
	return
	{
		Point(x - 1, y - 1), //bl
		Point(x - 1, y),     //l
		Point(x - 1, y + 1), //tl
		Point(x, y + 1),     //t
		Point(x + 1, y + 1),  //tr
		Point(x + 1, y),     //r
		Point(x + 1, y - 1), //br
		Point(x, y - 1)     //b		
	};
}

//TODO: could be faster to make custom hash?
bool Point::operator<(const Point& rhs) const
{
	return std::tie(x, y) < std::tie(rhs.x, rhs.y);
}

bool Point::operator> (const Point& rhs) const
{
	return std::tie(x, y) > std::tie(rhs.x, rhs.y);
}

bool Point::operator<= (const Point& rhs) const
{
	return std::tie(x, y) <= std::tie(rhs.x, rhs.y);
}

bool Point::operator>= (const Point& rhs) const
{
	return std::tie(x, y) >= std::tie(rhs.x, rhs.y);
}

bool Point::operator==(const Point& rhs) const
{
	return std::tie(x, y) == std::tie(rhs.x, rhs.y);
}

bool Point::operator!=(const Point& rhs) const
{
	return !(std::tie(x, y) == std::tie(rhs.x, rhs.y));
}

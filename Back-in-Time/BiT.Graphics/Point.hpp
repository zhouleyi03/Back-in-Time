#pragma once

namespace BiT
{
	namespace graphics
	{
		class Point
		{
		public:
			Point() = default;
			Point(const int &x, const int &y, const int &color, const int &type):
				_x(x), _y(y), _color(color), _type(type) {}
			int _x = 0;
			int _y = 0;
			int _color = 0;
			int _type = 0;
		};
	}
}
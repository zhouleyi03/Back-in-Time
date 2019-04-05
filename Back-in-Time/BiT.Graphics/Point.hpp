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
			inline int getX()  const { return _x; }
			inline int getY()  const { return _y; }
			inline int getColor()  const { return _color; }
			inline int getType()  const { return _type; }
		private:
			int _x = 0;
			int _y = 0;
			int _color = 0;
			int _type = 0;
		};
	}
}
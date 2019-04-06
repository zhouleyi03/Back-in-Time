#pragma once
#include "Point.hpp"
#include "../PlatformAPI.hpp"
#include "../BiT.GUI/Button.hpp"

#include <string>
#include <array>
#include <iostream>

namespace BiT
{
	namespace graphics
	{
		class Pen
		{
		public:
			void printPoint(const Point &p)  const
			{
				moveCursor(p._x + p._x, p._y);
				setColor(p._color);
				std::cout << point_types[p._type];
			}
			void printButton(const gui::Button &b)  const
			{
				moveCursor(b.getX(), b.getY());
				setColor(b.getColor());
				std::cout << b.getText();
			}
			std::array<std::string, 10> getReflector()  const { return point_types; }
		private:
			const std::array<std::string, 10> point_types = { "█","■","▲","▼","★" };
		};
	}
}
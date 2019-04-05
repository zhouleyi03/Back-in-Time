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
				moveCursor(p.getX(), p.getY());
				setColor(p.getColor());
				std::cout << point_types[p.getType()];
			}
			void printButton(const gui::Button &b)  const
			{
				moveCursor(b.getX(), b.getY());
				setColor(b.getColor());
				std::cout << b.getText();
			}
		private:
			const std::array<std::string, 10> point_types = { "█","■","▲","▼","★" };
		};
	}
}
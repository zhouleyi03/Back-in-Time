#pragma once
#include "../BiT.Graphics/Point.hpp"
#include <string>

namespace BiT
{
	namespace gui
	{
		class Button
		{
		public:
			Button(const int &x, const int &y, const int &color, const std::string &t) :
				text(t), attr(graphics::Point(x, y, color, 0)) {}
			std::string getText()  const { return text; }
			inline int getX()  const { return attr._x; }
			inline int getY()  const { return attr._y; }
			inline int getColor()  const { return attr._color; }
			inline int getType()  const { return attr._type; }

			void toggleSelect()
			{
				if (attr._color > 240)
					attr._color -= 240;  // 此处曾有一个BUG。
				else
					attr._color += 240;
			}
		private:
			std::string text;
			graphics::Point attr;
		};
	}
}
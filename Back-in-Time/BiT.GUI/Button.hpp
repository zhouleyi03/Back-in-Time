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
			inline int getX()  const { return attr.getX(); }
			inline int getY()  const { return attr.getY(); }
			inline int getColor()  const { return attr.getColor(); }
			inline int getType()  const { return attr.getType(); }

			void toggleSelect()
			{
				if (attr.getColor() > 240)
					attr = graphics::Point(attr.getX(), attr.getY(), attr.getColor() - 240, 0);
				else
					attr = graphics::Point(attr.getX(), attr.getY(), attr.getColor() + 240, 0);
			}
		private:
			std::string text;
			graphics::Point attr;
		};
	}
}
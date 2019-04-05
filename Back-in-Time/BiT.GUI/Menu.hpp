#pragma once
#include "Button.hpp"
#include "../BiT.Core/ObjectHandler.hpp"

#include <string>
#include <vector>
#include <conio.h>
#include <array>

namespace BiT
{
	namespace gui
	{
		class Menu
		{
		public:
			Menu(const int &xx, const int &yy) :x(xx), y(yy) {}
			void addButton(const std::string &text)
			{
				int size = buttons.size();
				Button b(x, y + 3 * size, 11, text);
				if (size == 0)
					b.toggleSelect();
				buttons.push_back(b);
			}
			void registerFunc(void *func, const int &pos)
			{
				if (pos < 0 || pos>15)
					return;
				funcs[pos] = func;
			}
			void printSelf()  const
			{
				if (buttons.empty()) return;
				for (std::size_t i = 0; i < buttons.size(); i++)
					core::objh6.getPen()->printButton(buttons[i]);
			}
			void onUse()
			{
				int inputed = 0;
				while (true)
				{
					inputed = _getch();
					switch (inputed)
					{
					case 119:
						if (current_pos > 0)
						{
							buttons[current_pos].toggleSelect();
							core::objh6.getPen()->printButton(buttons[current_pos]);
							--current_pos;
							buttons[current_pos].toggleSelect();
							core::objh6.getPen()->printButton(buttons[current_pos]);
						}
						break;
					case 115:
						if (current_pos < buttons.size() - 1)
						{
							buttons[current_pos].toggleSelect();
							core::objh6.getPen()->printButton(buttons[current_pos]);
							++current_pos;
							buttons[current_pos].toggleSelect();
							core::objh6.getPen()->printButton(buttons[current_pos]);
						}
						break;
					case 13:

						break;
					default:
						break;
					}
				}
			}
		private:
			std::vector<Button> buttons;
			std::array<void*, 16> funcs;

			std::size_t current_pos = 0;
			int x = 0;
			int y = 0;
		};
	}
}
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
		typedef void(*menu_func)(void);
		class Menu
		{
		public:
			Menu(const int &xx, const int &yy, const bool &mode = true) :x(xx), y(yy), func_mode(mode) {}
			void addButton(const std::string &text)
			{
				int size = buttons.size();
				Button b(x, y + 3 * size, 11, text);
				if (size == 0)
					b.toggleSelect();
				buttons.push_back(b);
			}
			void registerFunc(menu_func func, const int &pos)
			{
				if (pos < 0 || pos > 15)
					return;
				funcs[pos] = func;
			}
			void printSelf()  const
			{
				if (buttons.empty()) return;
				for (std::size_t i = 0; i < buttons.size(); i++)
					core::objh6.getPen()->printButton(buttons[i]);
			}
			std::size_t onUse()
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
						else
						{
							buttons[current_pos].toggleSelect();
							core::objh6.getPen()->printButton(buttons[current_pos]);
							current_pos = buttons.size() - 1;
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
						else
						{
							buttons[current_pos].toggleSelect();
							core::objh6.getPen()->printButton(buttons[current_pos]);
							current_pos = 0;
							buttons[current_pos].toggleSelect();
							core::objh6.getPen()->printButton(buttons[current_pos]);
						}
						break;
					case 13:
						if (funcs[current_pos] != nullptr)
							funcs[current_pos]();
						else if (!func_mode)
							return current_pos;
						break;
					default:
						break;
					}
				}
				return 0;
			}
		private:
			std::vector<Button> buttons;
			std::array<menu_func, 16> funcs;
			bool func_mode = true;  // 默认直接执行函数，如值为false，按Enter时返回值给调用者处理。

			std::size_t current_pos = 0;
			int x = 0;
			int y = 0;
		};
	}
}
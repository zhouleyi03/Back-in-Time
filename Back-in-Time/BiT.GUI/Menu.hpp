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
				auto size = static_cast<int>(buttons.size());
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
				for (int i = 0; i < buttons.size(); i++)
					core::global::handler.getPen()->printButton(buttons[i]);
			}
			int onUse()
			{
				int inputed = 0;
				int button_num = static_cast<int>(buttons.size() - 1);

				while (true)
				{
					inputed = _getch();
					switch (inputed)
					{
					case 119:
						if (current_pos > 0)
						{
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
							--current_pos;
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
						}
						else
						{
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
							current_pos = button_num;
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
						}
						break;
					case 115:
						if (current_pos < button_num)
						{
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
							++current_pos;
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
						}
						else
						{
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
							current_pos = 0;
							buttons[current_pos].toggleSelect();
							core::global::handler.getPen()->printButton(buttons[current_pos]);
						}
						break;
					case 13:
						if (!func_mode)
							return current_pos;
						else if (funcs[current_pos] != nullptr)
							funcs[current_pos]();
						break;
					default:
						break;
					}
				}
				return 0;
			}
		private:
			std::vector<Button> buttons;
			std::array<menu_func, 16> funcs = { nullptr };
			bool func_mode = false;  // 默认按Enter时返回值给调用者处理，如值为true，直接执行对应pos所绑定的函数。

			int current_pos = 0;
			int x = 0;
			int y = 0;
		};
	}
}
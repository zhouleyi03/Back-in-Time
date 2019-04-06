#pragma once
#include "../BiT.GUI/Menu.hpp"
#include "../PlatformAPI.hpp"
#include "../BiT.Graphics/Point.hpp"

#include <fstream>
#include <vector>

namespace BiT
{
	namespace devkit
	{
		class Devkit
		{
		public:
			void initDk()
			{
				dk_menu.addButton("[1] 绘制静态图像");
				dk_menu.addButton("[2] 绘制帧动画");
				dk_menu.addButton("[3] 加载静态图像");
				dk_menu.addButton("[4] 关于");
				dk_menu.addButton("[5] 退出程序");
				setTitle("Back in Time -Devkit Mode");
				dk_menu.registerFunc([]() {setColor(7); std::exit(0); }, 4); // 注意下标从零开始，所以这里要将对应下标的数字减一。
			}
			void launch()
			{
				while (true)
				{
					clear();
					dk_menu.printSelf();
					int code = dk_menu.onUse();
					if (code == 0)
						staticImage();
					else if (code == 3)
						MessageBoxA(nullptr, "zhouleyi03制作 \n-2019/4/5 21:33", "About", 0);
					else if (code == 2)
						loadImage("out.bitimg");
				}
			}
			void staticImage()
			{
				// 为了压缩代码量我使用了goto，希望不要介意。
				clear();
				std::system("color 0f");

				int inputed = 0;
				std::vector<graphics::Point> content;
				content.emplace_back(0, 0, 10, 0);  // 第1个对象是画刷，在保存图像时不会被输出到文件。
				content.emplace_back(0, 0, 0, 0);  // 第2个对象用于...不太好解释，它在保存图像时不会被输出到文件。

				moveCursor(0, 26);
				std::cout << "Tips: 使用W,A,S,D来移动画刷，上下箭头来切换颜色，左右箭头来切换画刷类型。" << std::endl;
				std::cout << "对照表：" << std::endl;
				for (int m = 1; m < 16; m++)
				{
					setColor(m);
					std::cout << m << " ";
				}
				std::cout << std::endl;
				for (int n = 0; n < 5; n++)
					std::cout << core::objh6.getPen()->getReflector()[n] << " ";

				while (true)
				{
					inputed = _getch();
					switch (inputed)
					{
					case 97:  // a
						if (content[0]._x > 0)
						{
							content[1]._x = content[0]._x;
							content[1]._y = content[0]._y;
							--content[0]._x;
						}
						break;
					case 115:  // s
						if (content[0]._y < 25)
						{
							content[1]._x = content[0]._x;
							content[1]._y = content[0]._y;
							++content[0]._y;
						}
						break;
					case 100:  // d
						if (content[0]._x < 50)
						{
							content[1]._x = content[0]._x;
							content[1]._y = content[0]._y;
							++content[0]._x;
						}
						break;
					case 119:  // w
						if (content[0]._y > 0)
						{
							content[1]._x = content[0]._x;
							content[1]._y = content[0]._y;
							--content[0]._y;
						}
						break;
					case 13:  // enter
						content.push_back(content[0]);
						break;
					case 27:  // escape
						goto SaveImage;
						break;
					case 72:  // up arrow
						if (content[0]._color > 1)
							--content[0]._color;
						break;
					case 80:  // down arrow
						if (content[0]._color < 15)
							++content[0]._color;
						break;
					case 75:  // left arrow
						break;
					case 77:  // right arrow
						break;
					default:
						break;
					}
					for (int p = 1; p < content.size(); p++)
						core::objh6.getPen()->printPoint(content[p]);
					core::objh6.getPen()->printPoint(content[0]);
				}
			SaveImage:
				std::ofstream out("out.bitimg", std::ios::trunc);
				for (std::size_t i = 2; i < content.size(); i++)
				{
					out << content[i]._x << " " << content[i]._y << " " << content[i]._color << " " << content[i]._type << " ";
				}
			}
			void loadImage(const std::string &img_path)
			{
				std::system("color 0f");
				clear();
				std::vector<graphics::Point> buf;
				std::ifstream in(img_path, std::ios::in);
				int p_buf[4] = { 0 };
				while (in)
				{
					in >> p_buf[0] >> p_buf[1] >> p_buf[2] >> p_buf[3];
					buf.emplace_back(p_buf[0], p_buf[1], p_buf[2], p_buf[3]);
				}
				for (const auto &p : buf)
					core::objh6.getPen()->printPoint(p);
				moveCursor(0, 26);
				setColor(10);
				std::cout << "按任意键继续...";
				std::cin.get();
			}
		private:
			gui::Menu dk_menu = gui::Menu(5, 1, false);
		};
	}
}
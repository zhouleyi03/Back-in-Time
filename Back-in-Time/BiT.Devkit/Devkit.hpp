#pragma once
#include "../BiT.GUI/Menu.hpp"
#include "../PlatformAPI.hpp"
#include "../BiT.Graphics/Point.hpp"
#include "../BiT.Graphics/Effects.hpp"

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
				dk_menu.addButton("[1] ���ƾ�̬ͼ��");
				dk_menu.addButton("[2] ����֡����");
				dk_menu.addButton("[3] ���ؾ�̬ͼ��");
				dk_menu.addButton("[4] ����");
				dk_menu.addButton("[5] �˳�����");
				dk_menu.addButton("[6] (Test)�ܽ���Ч");
				setTitle("Back in Time -Devkit Mode");
				//dk_menu.registerFunc([]() {setColor(7); std::exit(0); }, 4); // ע���±���㿪ʼ����������Ҫ����Ӧ�±�����ּ�һ��
			}
			void launch()
			{
				while (true)
				{
					setColor(10);
					clear();
					dk_menu.printSelf();
					int code = dk_menu.onUse();
					if (code == 0)
						staticImage();
					else if (code == 3)
						MessageBoxA(nullptr, "zhouleyi03���� \n-2019/4/5 21:33", "About", 0);
					else if (code == 2)
						loadImage("out.bitimg");
					else if (code == 4)
						std::exit(0);
					else if (code == 5)
						loadImage("out.bitimg", 1);
				}
			}
			void staticImage()
			{
				// Ϊ��ѹ����������ʹ����goto��ϣ����Ҫ���⡣
				clear();
				std::system("color 0f");

				int inputed = 0;
				std::vector<graphics::Point> content;
				content.emplace_back(0, 0, 10, 0);  // ��1�������ǻ�ˢ���ڱ���ͼ��ʱ���ᱻ������ļ���
				content.emplace_back(0, 0, 0, 0);  // ��2����������...��̫�ý��ͣ����ڱ���ͼ��ʱ���ᱻ������ļ���

				moveCursor(0, 26);
				std::cout << "Tips: ʹ��W,A,S,D���ƶ���ˢ�����¼�ͷ���л���ɫ�����Ҽ�ͷ���л���ˢ���͡�" << std::endl;
				std::cout << "���ձ�" << std::endl;
				for (int m = 1; m < 16; m++)
				{
					setColor(m);
					std::cout << m << " ";
				}
				std::cout << std::endl;
				for (int n = 0; n < 5; n++)
					std::cout << core::global::handler.getPen()->getReflector()[n] << " ";

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
						if (content[0]._type > 0)
							--content[0]._type;
						break;
					case 77:  // right arrow
						if (content[0]._type < 5)
							++content[0]._type;
						break;
					default:
						break;
					}
					for (std::size_t p = 1; p < content.size(); p++)
						core::global::handler.getPen()->printPoint(content[p]);
					core::global::handler.getPen()->printPoint(content[0]);
				}
			SaveImage:
				std::ofstream out("out.bitimg", std::ios::trunc);
				for (std::size_t i = 2; i < content.size(); i++)
				{
					out << content[i]._x << " " << content[i]._y << " " << content[i]._color << " " << content[i]._type << " ";
				}
			}
			void loadImage(const std::string &img_path, int effect_mode = 0)
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

				if (effect_mode == 1)
					graphics::effects::dissolution(buf, 5);
				else
					core::global::handler.getPen()->printPoints(buf);
				moveCursor(0, 26);
				setColor(10);
				std::cout << "�����������...";
				std::cin.get();
			}
		private:
			gui::Menu dk_menu = gui::Menu(5, 1, false);
		};
	}
}
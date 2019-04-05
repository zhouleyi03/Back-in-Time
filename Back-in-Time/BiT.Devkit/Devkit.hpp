#pragma once
#include "../BiT.GUI/Menu.hpp"
#include "../PlatformAPI.hpp"

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
				dk_menu.addButton("[3] 关于");
				dk_menu.addButton("[4] 退出程序");
				setTitle("Back in Time -Devkit Mode");
				dk_menu.registerFunc([]() {setColor(7); std::exit(0); }, 3); // 注意下标从零开始，所以这里要将对应下标的数字减一。
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
					else if (code == 2)
						MessageBoxA(nullptr, "zhouleyi03制作 \n-2019/4/5 21:33", "About", 0);
					dk_menu.onUse();
				}
			}
			void staticImage()
			{
				clear();
				std::cout << "helloworld";
			}
		private:
			gui::Menu dk_menu = gui::Menu(5, 1, false);
		};
	}
}
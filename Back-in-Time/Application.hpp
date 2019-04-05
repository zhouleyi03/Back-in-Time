#pragma once
#include "BiT.Core/ObjectHandler.hpp"
#include "BiT.GUI/Menu.hpp"
#include "BiT.Devkit/Devkit.hpp"

namespace BiT
{
	class Application
	{
	public:
		void init()
		{
			core::objh6.initObjects();
		}
		int linkstart()
		{
			init();
			devkit::Devkit dk;
			dk.initDk();
			dk.launch();

			return 0;
		}
	private:
	};
}
#pragma once
#include "Button.hpp"
#include "../BiT.Core/ObjectHandler.hpp"

#include <string>

namespace BiT
{
	namespace gui
	{
		class InputBox
		{
		public:
			void printSelf()
			{

			}
		private:
			std::string title;
			int x = 0;
			int y = 0;
		};
	}
}
#pragma once
#include "../BiT.Graphics/Pen.hpp"

#include <memory>

namespace BiT
{
	namespace core
	{
		class ObjectHandler
		{
		public:
			void initObjects()
			{
				pen = std::make_shared<graphics::Pen>();
			}
			inline decltype(auto) getPen() { return pen; }
		private:
			std::shared_ptr<graphics::Pen> pen;
		};
		namespace global
		{
			namespace
			{
				ObjectHandler handler;
			}
		}
	}
}
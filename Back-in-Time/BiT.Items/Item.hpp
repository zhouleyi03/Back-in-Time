#pragma once

namespace BiT
{
	namespace item
	{
		class Item
		{
		public:
			int getValue()  const{ return value; }
			int getWeight()  const { return weight; }

			bool stackable = true;
		protected:
			int value = 1;
		private:
			int weight = 1;
		};
	}
}
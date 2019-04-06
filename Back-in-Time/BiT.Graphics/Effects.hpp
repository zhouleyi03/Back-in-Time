#pragma once
#include "Point.hpp"
#include "../BiT.Core/ObjectHandler.hpp"

#include <vector>
#include <Windows.h>
#include <string>
#include <ctime>
#include <random>

namespace BiT
{
	namespace graphics
	{
		namespace effects
		{
			namespace
			{
				void dissolution(std::vector<Point> &v , const int &velocity = 0)
				{
					std::default_random_engine e;
					std::size_t size = v.size() - 1;
					int randomized_pos = 0;

					for (std::size_t i = 0; i < size; i++)
					{
						std::uniform_int_distribution<int> u(i, size);
						e.seed(std::time(nullptr));
						randomized_pos = u(e);

						auto current_point = v[i];
						v[i] = v[randomized_pos];
						v[randomized_pos] = current_point;
					}

					if (velocity == 0)
						core::objh6.getPen()->printPoints(v);
					else
						for (std::size_t j = 0; j < v.size(); j++)
						{
							core::objh6.getPen()->printPoint(v[j]);
							Sleep(velocity);
						}
				}
				void horizontalCharRain(const std::string &protagonist)
				{

				}
			}
		}
	}
}
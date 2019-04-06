#pragma once
#include "Point.hpp"
#include "../BiT.Core/ObjectHandler.hpp"
#include "../PlatformAPI.hpp"

#include <vector>
#include <Windows.h>
#include <sstream>
#include <fstream>
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
				template <typename T>
				void randomizeArray(std::vector<T> &v, std::size_t dest_pos = 0)
				{
					std::default_random_engine e;
					std::size_t size = v.size() - 1;
					int randomized_pos = 0;
					if (dest_pos == 0)
						dest_pos = size;

					for (std::size_t i = 0; i < dest_pos; i++)
					{
						std::uniform_int_distribution<int> u(i, size);
						e.seed(std::time(nullptr));
						randomized_pos = u(e);

						auto current_point = v[i];
						v[i] = v[randomized_pos];
						v[randomized_pos] = current_point;
					}
				}
				void dissolution(std::vector<Point> &v , const int &velocity = 0)
				{
					randomizeArray(v);
					if (velocity == 0)
						core::objh6.getPen()->printPoints(v);
					else
						for (std::size_t j = 0; j < v.size(); j++)
						{
							core::objh6.getPen()->printPoint(v[j]);
							Sleep(velocity);
						}
				}
				void horizontalCharRain(const std::string &protagonist, const std::string &background_path)
				{
					std::ifstream *in = new std::ifstream(background_path, std::ios::in);
					std::stringstream *ssm = new std::stringstream();
					*ssm << in->rdbuf();
					delete in;
					std::string bg = ssm->str();
					delete ssm;

					std::default_random_engine e;
					std::size_t size = bg.size() - 1;
					int randomized_pos = 0;
					std::string back = bg;

					auto f = &bg;
					auto b = &back;
					auto c = f;
					setColor(6);
					while(1)
					for (std::size_t i = 0; i < size; i++)
					{
						static std::uniform_int_distribution<int> u(i, size);
						randomized_pos = u(e);
						
						std::cout << *f;
						c = b;
						b = f;
						f = c;
						moveCursor(0, 0);

						//auto current_point = bg[i];
						//bg[i] = bg[randomized_pos];
						//bg[randomized_pos] = current_point;
						(*f)[randomized_pos] = '1';
						(*f)[randomized_pos + 1] = '0';
					}
					moveCursor(60, 13);
				}
			}
		}
	}
}
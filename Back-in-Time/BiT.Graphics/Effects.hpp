#pragma once
#include "Point.hpp"
#include "../BiT.Core/ObjectHandler.hpp"
#include "../PlatformAPI.hpp"

#include <vector>
#include <chrono>
#include <Windows.h>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <thread>
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
					int size = static_cast<int>(v.size() - 1);
					int randomized_pos = 0;
					if (dest_pos == 0)
						dest_pos = size;

					for (int i = 0; i < dest_pos; i++)
					{
						std::uniform_int_distribution<int> u(i, size);
						e.seed(static_cast<unsigned>(std::time(nullptr)));
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
						core::global::handler.getPen()->printPoints(v);
					else
						for (std::size_t j = 0; j < v.size(); j++)
						{
							core::global::handler.getPen()->printPoint(v[j]);
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
					auto size = static_cast<int>(bg.size() - 1);
					int randomized_pos = 0;
					std::string back = bg;

					setColor(10);
					while(1)
					for (int i = 0; i < size; i++)
					{
						static std::uniform_int_distribution<int> u(i, size);
						randomized_pos = u(e);
						
						std::ios::sync_with_stdio(false);
						std::cout << bg;
						std::this_thread::sleep_for(std::chrono::milliseconds(15));
						moveCursor(0, 0);

						//auto current_point = bg[i];
						//bg[i] = bg[randomized_pos];
						//bg[randomized_pos] = current_point;
						bg[randomized_pos] = '1';
						bg[randomized_pos + 1] = '0';
					}
					moveCursor(60, 13);
				}
			}
		}
	}
}
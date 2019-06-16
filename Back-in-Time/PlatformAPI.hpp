#pragma once
#include <Windows.h>
#include <cstdlib>

namespace
{
	HANDLE handle;

	void initWinapi()
	{
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	inline void moveCursor(const short &x, const short &y)
	{
		SetConsoleCursorPosition(handle, COORD{ x,y });
	}

	inline void setColor(const short &color)
	{
		SetConsoleTextAttribute(handle, color);
	}

	void clear()
	{
		std::system("cls");
	}

	void setTitle(const char *title)
	{
		SetConsoleTitle(title);
	}
}
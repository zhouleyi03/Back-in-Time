#include "PlatformAPI.hpp"
#include "Application.hpp"

#include "BiT.Graphics/Effects.hpp"

int main(int argc, char *argv[])
{
	initWinapi();
	setTitle("Back in Time");
	std::cin.get();
	BiT::graphics::effects::horizontalCharRain("Back in Time", "BiT.Resource/ui/char_bg.txt");
	//BiT::Application app;
	//return app.linkstart();
}
#include "PlatformAPI.hpp"
#include "Application.hpp"

int main(int argc, char *argv[])
{
	initWinapi();
	setTitle("Back in Time");

	BiT::Application app;
	app.run();
	return 0;
}
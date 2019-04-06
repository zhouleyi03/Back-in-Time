#include "PlatformAPI.hpp"
#include "Application.hpp"

#include "BiT.Graphics/Effects.hpp"

int main(int argc, char *argv[])
{
	initWinapi();
	setTitle("Back in Time");

	BiT::Application app;
	return app.linkstart();
}
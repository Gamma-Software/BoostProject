// boost_project.cpp : Defines the entry point for the application.
//

#include "boost_project.h"
#include "graphic_engine.h"

using namespace std;

int main()
{

	GraphicEngine engine = GraphicEngine();
	if (engine.init())
	{
		engine.addPrimitive();

		while(engine.isRunning())
		{
			engine.clear();
			engine.update();
			engine.eventHandling();
		}
		engine.kill();
	}

	return 0;
}

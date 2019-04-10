#pragma once
#include "SDL.h"
#undef main

class GraphicEngine
{
public:
	GraphicEngine();
	~GraphicEngine();

	bool init();
	bool clear();
	bool addPrimitive();
	bool update();
	void eventHandling();

	bool isRunning();

	void kill();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Event m_event;
	bool m_done;
};
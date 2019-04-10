#include "graphic_engine.h"
#include <boost/geometry/geometry.hpp>



GraphicEngine::GraphicEngine()
{
	init();
}

GraphicEngine::~GraphicEngine()
{
}

bool GraphicEngine::init()
{
	m_window = NULL;
	m_renderer = NULL;
	m_done = false;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		kill();
		return false;
	}
	if (SDL_CreateWindowAndRenderer(640, 480, 0, &m_window, &m_renderer) != 0)
	{
		kill();
		return false;
	}
	return true;
}

bool GraphicEngine::addPrimitive()
{
	namespace bg = boost::geometry;

	typedef bg::model::point<double, 2, bg::cs::cartesian> Point;
	typedef bg::model::linestring <Point> Line;

	Line line;
	line.push_back(Point(0., 0.));
	line.push_back(Point(100., 10.));
	line.push_back(Point(100., 100.));
	return true;
}

void GraphicEngine::eventHandling()
{
	while (SDL_PollEvent(&m_event)) {
		switch (m_event.type)
		{
		case SDL_WINDOWEVENT: // Événement de la fenêtre
			if (m_event.window.event == SDL_WINDOWEVENT_CLOSE) // Fermeture de la fenêtre
			{
				m_done = true;
			}
			break;
		case SDL_KEYUP: // Événement de relâchement d'une touche clavier
			if (m_event.key.keysym.sym == SDLK_ESCAPE) // C'est la touche Échap
			{
				m_done = true;
			}
			break;
		}
	}
}

bool GraphicEngine::clear()
{
	if (m_window)
	{
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(m_renderer);
	}
	else
	{
		kill();
		return false;
	}
	return true;
}

bool GraphicEngine::update()
{
	if (m_window)
	{
		// Add primitives
		// TODO

		// Background
		SDL_SetRenderDrawColor(m_renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderPresent(m_renderer);
	}
	else
	{
		kill();
		return false;
	}
	return true;
}

void GraphicEngine::kill()
{
	if (m_renderer) {
		SDL_DestroyRenderer(m_renderer);
	}
	if (m_window) {
		SDL_DestroyWindow(m_window);
	}
	SDL_Quit();
}

bool GraphicEngine::isRunning()
{
	return !m_done;
}
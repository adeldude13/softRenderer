#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "color.hpp"
#include <SDL2/SDL.h>
#include <iostream>

class Window {
	public:
		Window(const char*, int, int);
		void close();
		void putPixel(int,int,Color);
		void render();
		bool windowShouldClose();
	private:
		int width, height;
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Surface *surface;
		bool isClosed = false;
};


#endif

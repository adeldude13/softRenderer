#include "window.hpp"
#include <stdlib.h>
#include <iostream>

bool resizingEvent = false;

static int resizingEventWatcher(void* data, SDL_Event* event) {
  if (event->type == SDL_WINDOWEVENT && event->window.event == SDL_WINDOWEVENT_RESIZED) {
		resizingEvent = true;
  }
  return 0;
}

int computeColor(double i) {
	if(i>=1){
		return 255;	
	}
	if(i < 0) {
		return 0;
	}
	return i*255;
}

Window::Window(const char *p_title, int p_width, int p_height) {
	width = p_width;
	height = p_height;
	if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		this->close();
		exit(1);
	}
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,  SDL_WINDOW_RESIZABLE);
	if(window == NULL) {
		exit(1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL) {
		exit(1);
	}
	surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	SDL_AddEventWatch(resizingEventWatcher, window);
}

void Window::close() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_FreeSurface(surface);
	SDL_Quit();
}

void Window::putPixel(int x, int y, Color color) {
	x = (width/2)+x;
	y = (height/2)-y;
	if(y == height) {
		y -= 1;
	}
	if(x < 0 || x >= surface->w || y < 0 || y >= surface->h) {
		std::cout << "putPixel: Coordinates is out of bound" << std::endl;
		exit(1);
	}
	unsigned char *pixels = (unsigned char *)this->surface->pixels;
	pixels[4 * (y * width + x) + 0] = computeColor(color.b);
	pixels[4 * (y * width + x) + 1] = computeColor(color.g);
	pixels[4 * (y * width + x) + 2] = computeColor(color.r);
	pixels[4 * (y * width + x) + 3] = 1;
}

void Window::render() {
	if(resizingEvent) {
		resizingEvent = false;
		SDL_GetWindowSize(window, &width, &height);
		SDL_FreeSurface(surface);
		surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	}
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) {
			isClosed = true;
		}
	}
	SDL_Rect dstRect;
	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.w = surface->w;
	dstRect.h = surface->h;
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);
	SDL_DestroyTexture(texture);
	SDL_RenderPresent(renderer);
	SDL_FillRect(surface, NULL, 0x000000);
}

bool Window::windowShouldClose() {
	return isClosed;
}

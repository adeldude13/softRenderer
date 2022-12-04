#include <SDL2/SDL.h>
#include "window.hpp"
#include "color.hpp"
#include "draw.hpp"
#include "vec.hpp"
#include "obj.hpp"

void triangle(Window *window, Vec3 p1, Vec3 p2, Vec3 p3, Color color) {
	draw_line(window, p1, p2, color);
	draw_line(window, p1, p3, color);
	draw_line(window, p2, p3, color);
}

int main() {
	Color color(1, 1, 1);
	Window window("some title", 1600, 900);
	Model model("african_head.obj");
	unsigned int delta = 0;
	unsigned int b = 0;
	unsigned int a = 0;
	while(!window.windowShouldClose()) {
		a = SDL_GetTicks();
		delta = a-b;
		if((double)delta >= 1000/15) {
			b = a;
			for(int i=0;i<(int)model.inds.size();i++) {
				std::vector<Vec3> vals(3);
				for(int j=0;j<(int)model.inds[i].size();j++) {
					Vec3 temp = model.verts[model.inds[i][j]-1];
					vals[j] = Vec3(temp.x * (window.width/2), temp.y * (window.height/2), 0);
				}
				triangle(&window, vals[0], vals[1], vals[2], color);
			}
			window.render();
		}
	}
	window.close();
}

#include "window.hpp"
#include "color.hpp"
#include "draw.hpp"
#include "vec.hpp"

#define HEIGHT 900
#define WIDTH 1600

int main() {
	Color color(1, 0, 0);
	Window window("some title", WIDTH, HEIGHT);
	Vec3 p1(-800,-449, 0);
	Vec3 p2(799, 450, 0);
	while(!window.windowShouldClose()) {
		draw_line(&window, p1, p2, color);
		window.render();
	}
	window.close();
}

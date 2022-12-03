#include "draw.hpp"

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

void draw_line(Window *window, Vec3 p1, Vec3 p2, Color color) {
	double dx = (p2.x - p1.x);
	double dy = (p2.y - p1.y);
	if(dx == 0) {
		int y1 = min(p1.y, p2.y);
		int y2 = max(p2.y, p2.y);
		for(int y=y1;y<y2;y++) {
			window->putPixel(p1.x, y, color);
		}
		return;
	} else if(dy == 0) {
		int x1 = min(p1.x, p2.x);
		int x2 = max(p2.x, p2.x);
		for(int x=x1;x<x2;x++) {
			window->putPixel(p1.y, x, color);
		}
		return;
	}
	// draw with respect to X
	if(abs(dx) > abs(dy)) {
		if(p1.x > p2.x) {
			Vec3 temp = p2;
			p2 = p1;
			p1 = temp;
		}
		double m = (double)(dy/dx);
		double y = p1.y;
		for(int x=p1.x;x<p2.x;x++) {
			window->putPixel(x, round(y), color);
			y += m;
		}
	} else {
		if(p1.y > p2.y) {
			Vec3 temp = p2;
			p2 = p1;
			p1 = temp;
		}
		double m = (double)(dx/dy);
		double x = p1.x;
		for(int y=p1.y;y<p2.y;y++) {
			window->putPixel(round(x), y, color);
			x+=m;
		}
	}

}

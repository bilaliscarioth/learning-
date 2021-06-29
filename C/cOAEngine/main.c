#include "include.h"

Display *disp;
Window win;
int screen;
GC gc;

void x_init(){
	unsigned long black, white;

	disp = XOpenDisplay(NULL);
	if (!disp){
		fprintf(stderr , "Display unknown");	
		exit(1);
	}

	screen = DefaultScreen(disp);

	black = BlackPixel(disp, screen);
	white = WhitePixel(disp, screen);

	win = XCreateSimpleWindow(disp, DefaultRootWindow(disp), 0,0, 800, 600, 5, white, black);
	XSetStandardProperties(disp, win, "cOA Engine", "v001", None, NULL, 0, NULL);

	XSelectInput(disp, win, ExposureMask|ButtonPressMask|KeyPressMask);
	gc=XCreateGC(disp, win, 0,0);
	
	XSetBackground(disp, gc, black);
	XSetForeground(disp, gc, white);

	XMapWindow(disp, win);

};

int main() {
	x_init();
 	XEvent e;
	while (1) {
		XNextEvent(disp, &e);
		if (e.type == KeyPress)	
			XDrawRectangle(disp, win, gc, 200, 300, 100, 100);
		//break;
   }
	XClearWindow(disp, win);
	XMapRaised(disp, win);
}

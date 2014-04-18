#include <stdio.h>
#include <iostream>

class Widget {
	public:
		virtual void render();
};

class Window : Widget {
	public:
		virtual void resize();
};

class ScrollBar : Widget {
	public:
		virtual void scroll();
};

class WidgetFactory {
	public:
		virtual ScrollBar createScrollBar() = 0;
		virtual Window createWindow() = 0;
};

class RealWindow : Window {
	public:
		void render();
		void resize();
};

class RealScrollBar : ScrollBar {
	public:
		void render();
		void scroll();
};

class RealWidgetFactory : WidgetFactory {
	public: 
		RealScrollBar createScrollBar();
		RealWindow createWindow();
};

class FakeScrollBar : ScrollBar {
	public:
		void render();
		void scroll();
};

class FakeWindow : Window {
	public:
		void render();
		void resize();
};

class FakeWidgetFactory : WidgetFactory {
	public:
		FakeScrollBar createScrollBar();
		FakeWindow createWindow();
};
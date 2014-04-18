// A compile-able demonstration of the AbstractFactory design pattern as described in the GoF book (Gang of Four)
#include "AbstractFactory.h"

void RealWindow::render() {
	printf("Rendering real window...\n");
	printf("done!\n");
}

void RealWindow::resize() {
	printf("Resizing real window!\n");
}

void RealScrollBar::render() {
	printf("Rendering real scroll bar!\n");
}

void RealScrollBar::scroll() {
	printf("Scrolling real scroll bar!\n");
}

void FakeWindow::render() {
	printf("Rendering fake window...\n");
	printf("done!\n");
}

void FakeWindow::resize() {
	printf("Resizing fake window!\n");
}

void FakeScrollBar::render() {
	printf("Rendering fake scroll bar!\n");
}

void FakeScrollBar::scroll() {
	printf("Scrolling fake scroll bar!\n");
}

RealScrollBar RealWidgetFactory::createScrollBar() {
	RealScrollBar rs;
	return rs;
}

RealWindow RealWidgetFactory::createWindow() {
	RealWindow rw;
	return rw;
}

FakeScrollBar FakeWidgetFactory::createScrollBar() {
	FakeScrollBar fs;
	return fs;
}

FakeWindow FakeWidgetFactory::createWindow() {
	FakeWindow fw;
	return fw;
}

int main() {

	RealWidgetFactory r;
	FakeWidgetFactory f;

	RealWindow rw = r.createWindow();
	rw.render();
	rw.resize();
	RealScrollBar rs = r.createScrollBar();
	rs.render();
	rs.scroll();

	FakeWindow fw = f.createWindow();
	FakeScrollBar fs = f.createScrollBar();
	fw.render();
	fw.resize();
	fs.render();
	fs.scroll();
}
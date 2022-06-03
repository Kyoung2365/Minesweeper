#include "Window.h"

Window::Window() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(400, 200), wxSize(500, 500)) {
	button = new wxButton(this, wxID_ANY, "", wxPoint(2, 2), wxSize(10, 10));
}
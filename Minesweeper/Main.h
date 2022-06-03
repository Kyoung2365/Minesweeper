#pragma once
#include "wx/wx.h"
#include "Window.h"
class Main : public wxApp
{
	Window* window = nullptr;
public:
	virtual bool OnInit();
};


#pragma once
#include "wx/wx.h"
class Window : public wxFrame
{
private:
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton  **button;
	int* nField = nullptr;
	bool bFirstClick = true;

	void OnButtonClicked(wxCommandEvent& evt);

public:
	Window();
	~Window();
};


#pragma once
#include "wx/wx.h"
class Window : public wxFrame
{
private:
	int CellWidth = 10;
	int CellHeight = 10;
	wxButton  **Button;
	int* Cell = nullptr;
	bool FirstClick = true;

	void OnButtonClicked(wxCommandEvent& evt);

public:
	Window();
	~Window();
};


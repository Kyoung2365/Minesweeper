#include "Window.h"

Window::Window() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(30, 30), wxSize(500, 500)) {
	Button = new wxButton * [CellWidth * CellHeight];
	wxGridSizer* grid = new wxGridSizer(CellWidth, CellHeight, 0, 0);

	Cell = new int[CellWidth * CellHeight];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0; x < CellWidth; x++) {
		for (int y = 0; y < CellHeight; y++) {
			Button[y * CellWidth + x] = new wxButton(this, 10000 + (y * CellWidth + x));
			Button[y * CellWidth + x]->SetFont(font);
			grid->Add(Button[y * CellWidth + x], 1, wxEXPAND | wxALL);

			Button[y * CellWidth + x]->Bind(wxEVT_COMMAND_Button_CLICKED, &Window::OnButtonClicked, this);
			Cell[y * CellWidth + x] = 0;
		}
	}
	this->SetSizer(grid);
	grid->Layout();
}

Window::~Window() {
	delete[]Button;
	delete Cell;
}

void Window::OnButtonClicked(wxCommandEvent& evt) {

	int x = (evt.GetId() - 10000) % CellWidth;
	int y = (evt.GetId() - 10000) / CellWidth;

	if (FirstClick) {
		int mines = 30;

		while (mines) {
			int rx = rand() % CellWidth;
			int ry = rand() % CellHeight;

			if (Cell[ry * CellWidth + rx] == 0 && rx != x && ry != y) {
				Cell[ry * CellWidth + rx] = -1;
				mines--;
			}
		}
		FirstClick = false;
	}
	Button[y * CellWidth + x]->Enable(false);

	if (Cell[y * CellWidth + x] == -1) {
		wxMessageBox("BOOM!! - Game Over :(");

		FirstClick = true;
		for (int x = 0; x < CellWidth; x++)
			for (int y = 0; y < CellHeight; y++){
				Cell[y * CellWidth + x] = 0;
				Button[y * CellWidth + x]->SetLabel("");
				Button[y * CellWidth + x]->Enable(true);
			}
	}
	else {
		int mine_count = 0;
		for(int i = -1; i < 2; i++)
			for (int j = -1; j < 2; j++) {
				if (x + i >= 0 && x + i < CellWidth && y + j >= 0 && y + j < CellHeight) {
					if (Cell[(y + j) * CellWidth + (x + i)] == -1)
						mine_count++;
				}
			}
		if (mine_count > 0) {
			Button[y * CellWidth + x]->SetLabel(std::to_string(mine_count));
		}
	}

	evt.Skip();
}
#pragma once
#include "wx/wx.h"
#include "Board.h"

class Main : public wxFrame
{
private:
	Board board;
	const int rows = 3;
	const int cols = 3;
	wxButton** btn;
	wxDECLARE_EVENT_TABLE();
public:
	Main();
	~Main();
	void onButtonClicked(wxCommandEvent& evt);
	void dialogWinOrTie();
};


#include "Main.h"

wxBEGIN_EVENT_TABLE(Main, wxFrame) wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "Tic tac toe", wxPoint(30, 30), wxSize(400, 300))
{
    btn = new wxButton * [rows * cols];
    wxGridSizer* grid = new wxGridSizer(rows, cols, 0, 0);
    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            btn[j * rows + i] = new wxButton(this, 10000 + (j * rows + i));
            grid->Add(btn[j * rows + i], 1, wxEXPAND | wxALL);
            btn[j * rows + i]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Main::onButtonClicked, this);
            btn[j * rows + i]->SetFont(font);
            btn[j * rows + i]->SetBackgroundColour(wxColour(*wxWHITE));
        }
    }
    this->SetSizer(grid);
    grid->Layout();
}

Main::~Main() { delete[] btn; }

void Main::onButtonClicked(wxCommandEvent& evt)
{
    int row = (evt.GetId() - 10000) % rows;
    int col = (evt.GetId() - 10000) / rows;

    board.mark(row, col);
    btn[col * rows + row]->SetLabel(board.getTileValue(row, col).toString());
    if (board.getTurn() && !board.getTileValue(row, col).isNought()) {
        btn[col * rows + row]->SetForegroundColour(*wxBLUE);
    }
    else if (!board.getTurn() && !board.getTileValue(row, col).isCross()) {
        btn[col * rows + row]->SetForegroundColour(*wxRED);
    }
    if (board.hasWon()) {
        dialogWinOrTie();
    }
    evt.Skip();
}

void Main::dialogWinOrTie()
{
    int answer = 0;
    if (board.hasWon() == 1) {
        answer = wxMessageBox("Player " + board.getTurnString() + " Wins! Play Again?", "Play Again?", wxYES_NO, this);
    }
    else if (board.hasWon() == 2) {
        answer = wxMessageBox("It's a tie! Play Again?", "Play Again?", wxYES_NO, this);
    }
    if (answer == wxNO) {
        this->Close();
    }
    else {
        board.emptyBoard();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                btn[j * rows + i]->SetLabel("");
            }
        }
    }
}

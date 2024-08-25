#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <iostream>

using namespace std;









MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);


	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(350, 50), wxSize(100, 35), wxBU_LEFT);


	CreateStatusBar();

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCTRL - editable", wxPoint(500, 145), wxSize(200, -1));

		button1->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
		// binds the event handler to the button press
		textCtrl->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

		//  wxListBox* listbox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);
		ListBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(125, -1));
		// binds event handler to the button click

		messageField = new wxStaticText(panel, wxID_ANY, "To-Do List", wxPoint(400, 250), wxSize(300, -1));
	// wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE || wxCHK_ALLOW_3RD_STATE_FOR_USER);

	 wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, "StaticText - Not editable", wxPoint(120, 150), wxSize(200, -1), wxALIGN_CENTER_HORIZONTAL);
	// statictext->SetBackgroundColour(*wxLIGHT_GREY);

	




// 	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 250), wxSize(200, -1));
	// gauge->SetValue(50);
 
	wxArrayString choices;
	choices.Add("A");
	choices.Add("B");
	choices.Add("C");
	choices.Add("D");

	
	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	choice->Select(0);

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));
	


//	wxRadioBox* radio = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);


	
};



void MainFrame::OnButtonClicked(wxCommandEvent& evt) {
	messageField->SetLabelText("No no");
	
	wxString hey = messageField->GetLabelText();
	 ListBox->Append(hey);
	 
	wxLogStatus("Button Clicked");
}

void MainFrame::OnTextChanged(wxCommandEvent& evt) {
	wxString str = wxString::Format("Text: %s", evt.GetString());
	wxLogStatus(str);
}
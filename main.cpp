#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <iostream>

using namespace std;





class App : public wxApp {

public:
	bool OnInit();


};

class MainFrame : public wxFrame {

public:
	MainFrame(const wxString& title);

};

wxIMPLEMENT_APP(App);
bool App::OnInit() {
	MainFrame* mainframe = new MainFrame("C++ GUI");
	mainframe->SetClientSize(800, 600);
	mainframe->Center();
	mainframe->Show();

	return true;
}


 MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	 wxPanel* panel = new wxPanel(this);

	 wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35), wxBU_LEFT);
 
	 wxCheckBox* checkbox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550,55), wxDefaultSize, wxCHK_3STATE || wxCHK_ALLOW_3RD_STATE_FOR_USER);

	 wxStaticText* statictext = new wxStaticText(panel, wxID_ANY, "StaticText - Not editable", wxPoint(120, 150));
	

	 wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCTRL - editable", wxPoint(500, 145), wxSize(200, -1));

	


	 wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 250), wxSize(200, -1));
	 gauge->SetValue(50);

	 wxArrayString choices;
	 choices.Add("A");
	 choices.Add("B");
	 choices.Add("C");
	 choices.Add("D");


	 wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices);
	 choice->Select(0);

	 wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1));

	 wxListBox* listbox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

	 wxRadioBox* radio = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);
 }


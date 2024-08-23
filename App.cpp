#include "App.h"
#include <wx/wx.h>
#include "MainFrame.h"


wxIMPLEMENT_APP(App);
bool App::OnInit() {
	MainFrame* mainframe = new MainFrame("C++ GUI");
	mainframe->SetClientSize(800, 600);
	mainframe->Center();
	mainframe->Show();

	return true;
}

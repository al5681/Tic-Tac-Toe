#include "Launcher.h"

wxIMPLEMENT_APP(Launcher);

bool Launcher::OnInit()
{
	frame1 = new Main();
	frame1->Show();
	return true;
}
 
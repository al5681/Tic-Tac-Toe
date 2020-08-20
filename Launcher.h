#pragma once

#include "wx\wx.h"
#include "main.h"

class Launcher : public wxApp
{
private:
	Main* frame1 = nullptr;
public: 
	virtual bool OnInit();
};


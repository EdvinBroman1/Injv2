#include "GUI.h"

using TibiaPrintText = void(_cdecl*)(int vr, int X, int Y, int Font, int Rgb_r, int Rgb_g, int Rgb_b, const char* Text, int Alignment);

DWORD TibiaTextFunctionAddress = Client::BaseAddress + 0xB4DD0;
DWORD PrintTextFunctionAddy = Client::BaseAddress + 0x122A90;
std::vector<Print*> Prints = std::vector<Print*>();
TibiaPrintText TibiaTextPrint = (TibiaPrintText)(TibiaTextFunctionAddress);

Print::Print(const std::string& str, int X, int Y, int B, int G, int R, int FONT) : text(str), x(X), y(Y), b(B), g(G), r(R), font(FONT), alignment(0)
{
	Prints.push_back(this);
}

void PrintAllLabels() {
	if (Prints.size() > 0) {
		for (Print* label : Prints) {
			TibiaTextPrint(1, label->x, label->y, label->font, label->r, label->g, label->b, label->text.c_str(), label->alignment);
		}
	}
	__asm {
		call PrintTextFunctionAddy
	}
}


ContextMenuItem::ContextMenuItem(const char* txt, int eventid, const char* shortcut) : Text(txt), EventID(eventid), Shortcut(shortcut)
{
}
	
void OpenChannel(const char* ChannelName, int ChannelID) {
	DWORD Createfunc = Client::BaseAddress + 0x55A40;
	DWORD GuiPointer = *(DWORD*)(0x64F5C8);
	DWORD pGuiChat = *(DWORD*)(GuiPointer + 0x40);

	using CreateChannel = void(_fastcall*)(DWORD pGui, const char* Text, int recv, int send, int channelID, const char* text);
	CreateChannel CC = (CreateChannel)(0x455A40);

	CC(pGuiChat, ChannelName, 7, 0, ChannelID, ChannelName);
}
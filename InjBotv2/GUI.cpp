#include "GUI.h"

/* GUI Regarding Prints */
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
/* END GUI Regarding Prints */

ContextMenuItem::ContextMenuItem(const char* txt, int eventid, const char* shortcut) : Text(txt), EventID(eventid), Shortcut(shortcut)
{
}
	
/* GUI Regarding Chat */
void GUI::Chat::OpenChannel(const char* ChannelName, int ChannelID) {

	DWORD Createfunc = Client::BaseAddress + 0x55A40;
	DWORD GuiPointer = *(DWORD*)(0x64F5C8);
	DWORD pGuiChat = *(DWORD*)(GuiPointer + 0x40);
    using OpenChannel = void(_fastcall*)(DWORD pGui, const char* channelname, int mode, int recv, int channelid, const char* ChannelName);
    OpenChannel OC = (OpenChannel)(Createfunc);
    OC(pGuiChat, ChannelName, 7, 0, 0x80, ChannelName);
}
/* END GUI Regarding Chat */



/* GUI Regarding Dialogs */

    DWORD CreateElement() {
        DWORD original = 0x5719E2;
        DWORD Pointer = 0x0;
        __asm {
            push 0x38
            call original
            add esp, 0x4
            mov Pointer, eax
        }

        return Pointer;
    }

    DWORD ConstructGuiElement(DWORD element) {
        DWORD Pass = 0x004CCBA0;
        DWORD original = 0x00485850;

        __asm {
            mov ecx, element
            mov edx, 0
            push Pass
            call original
        }

    }
    DWORD CreateElementPointer(DWORD otherPtr) {
        DWORD original = 0x5719E2;
        DWORD Pointer = 0x0;
        __asm {
            push 0xC4
            mov edi, otherPtr
            mov ebx, otherPtr
            call original
            add esp, 0x4
            mov Pointer, eax
        }

        return Pointer;
    }

    void SetPopupTitle(DWORD firstPtr, DWORD secondPtr, const char* title)
    {
        DWORD original = 0x498250;
        __asm {
            push firstPtr
            push title
            mov ecx, secondPtr
            mov edx, 0
            mov edi, secondPtr

            call original
        }
    }

    void SetPopupPlacement(DWORD Popup, int x, int y) {
        DWORD original = 0x00455A10;
        __asm {
            push y
            push x
            mov ecx, Popup
            call original
        }
    }


   void GUI::Dialog::CreatePopup(const std::string& Title, int x, int y) {

        //*Addresses
        DWORD* CurrentlySelectedGUIElement = (DWORD*)0x64F5C4;
        DWORD* GUI_SOMETHING_ID = (DWORD*)0x79CF88;

        DWORD ElementContent = CreateElement();
        ConstructGuiElement(ElementContent); // Decorates The GUI element with various labels & buttons depending on what ID is the GuiElement Ptr

        DWORD GuiBox = CreateElementPointer(ElementContent); // Create a GuiBox from the template...

        SetPopupTitle(ElementContent, GuiBox, Title.c_str());

        *CurrentlySelectedGUIElement = GuiBox;

        SetPopupPlacement(GuiBox, x, y);

        *GUI_SOMETHING_ID = 11;

    }
   /* END GUI Regarding Dialogs */



   /* GUI Essentials */
   
   Position* Tibia::GetCenterOfWindow() {

       int x = *(int*)(Client::BaseAddress + 0x39CF80);
       int y = *(int*)(Client::BaseAddress + 0x39CF7C);

       Position* pos = new Position(x/2, y/2, 0);

       return pos;
   }
   
   /* END GUI Essentials */ 
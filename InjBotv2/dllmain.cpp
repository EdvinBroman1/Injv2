#include "Hook.h"
#include "Player.h"
#include <memory>




DWORD WINAPI InjectThread(HMODULE hModule) {

    enable_hooks();
    int y = 100;
    while (true) {
        if (GetAsyncKeyState(VK_NUMPAD2) & 1) {
            GUI::Chat::OpenChannel("InjBotV2", 0x64);
        }
        if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
            Position* p = Tibia::GetCenterOfWindow();
            GUI::Dialog::CreatePopup("InjBotV2" , p->X, p->Y, 400, 400);
        }
        if (GetAsyncKeyState(VK_NUMPAD7) & 1) {
            Position* p = Tibia::GetCenterOfWindow();
            GUI::Dialog::CreatePopup("Healer", p->X, p->Y, 200, 200);
        }
        if (GetAsyncKeyState(VK_NUMPAD5) & 1) {
            break;
        }

        Sleep(10); 
    }
    FreeLibraryAndExitThread(hModule, 0);
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)InjectThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


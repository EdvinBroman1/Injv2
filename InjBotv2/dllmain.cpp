#include "Hook.h"



DWORD WINAPI InjectThread(HMODULE hModule) {

   // Print HeaderText = Print("BAD EXAMPLE", 10, 10, 190, 220, 90, 2); Don't do this, allocates a pointer on stack and gets cleared after function exits. 
   //In other words inserting into the print list resulting in an iteration over a list of invalid Print Pointers. Instead allocate on the stack.

    Print* HeaderTxt = new Print("This is InjBot", 100, 100, 155, 155, 255, 2);
   //Changing GUI elements is really easy by simply altering the member variables in the instances.
    HeaderTxt->text = "New Value.. ... ..";

    enable_hooks();


    return 0;
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

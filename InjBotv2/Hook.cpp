#include "Hook.h"

BOOL Hook(void* pTarget, void* ourFunct, int len, int Instruction)
{

    if (len < 5) {
        return false;
    }

    DWORD curProtection;
    VirtualProtect(pTarget, len, PAGE_EXECUTE_READWRITE, &curProtection);

    memset(pTarget, 0x90, len);

    DWORD relativeAddress = ((DWORD)ourFunct - (DWORD)pTarget) - 5;
    *(BYTE*)pTarget = Instruction; // E8 == call E9 == JMP
    *(DWORD*)((DWORD)pTarget + 1) = relativeAddress;

    DWORD temp;
    VirtualProtect(pTarget, len, curProtection, &temp);
    return true;
}


void PrintHook()
{

    Hook((void*)(Client::BaseAddress + HookAddress::HookPrintAddy), PrintAllLabels, 5, 0xE8);
}

void enable_hooks()
{
    PrintHook();
    // CreateOptionButtonHook();

}
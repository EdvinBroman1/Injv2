#include "Addresses.h"

DWORD Client::BaseAddress = (DWORD)GetModuleHandle(NULL);

#pragma region Hooks
DWORD HookAddress::HookPrintAddy = 0x5A34A;
DWORD HookAddress::HookContextAdd = Client::BaseAddress + 0x53288;
DWORD HookAddress::HookContextMenuSwitch = Client::BaseAddress + 0xC5BD7;

DWORD HookAddress::HookOptionsButtonCreate = Client::BaseAddress + 0x1719E2;

DWORD HookAddress::HookContextFiller = 0x5FC80;

DWORD HookAddress::DialogChooser = Client::BaseAddress + 0x5A72F;

#pragma endregion Hooks


DWORD Self::LocalPlayer = 0x23FE40;


DWORD GUIAddress::CreateElement = Client::BaseAddress + 0x1719E2;
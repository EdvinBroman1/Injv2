#include "Addresses.h"

intptr_t Client::BaseAddress = (intptr_t)GetModuleHandle(NULL);

#pragma region Hooks
intptr_t HookAddress::HookPrintAddy = 0x5A34A;
intptr_t HookAddress::HookContextAdd = Client::BaseAddress + 0x53288;
intptr_t HookAddress::HookContextMenuSwitch = Client::BaseAddress + 0xC5BD7;

intptr_t HookAddress::HookOptionsButtonCreate = Client::BaseAddress + 0x1719E2;

intptr_t HookAddress::HookContextFiller = 0x5FC80;

#pragma endregion Hooks
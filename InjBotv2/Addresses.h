#pragma once
#include <windows.h>

class Client {
public:
	static intptr_t BaseAddress;
};

class HookAddress {
public:
	static intptr_t HookPrintAddy;
	static intptr_t HookContextFiller;
	static intptr_t HookContextAdd;
	static intptr_t HookContextMenuSwitch;
	static intptr_t HookOptionsButtonCreate;
};
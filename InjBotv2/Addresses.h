#pragma once
#include <windows.h>

class Client {
public:
	static DWORD BaseAddress;
};

class HookAddress {
public:
	static DWORD HookPrintAddy;
	static DWORD HookContextFiller;
	static DWORD HookContextAdd;
	static DWORD HookContextMenuSwitch;
	static DWORD HookOptionsButtonCreate;
};

class Self {
public:
	static DWORD LocalPlayer;
};
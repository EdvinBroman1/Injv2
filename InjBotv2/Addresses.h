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

	static DWORD DialogChooser;
};

class Self {
public:
	static DWORD LocalPlayer;
};
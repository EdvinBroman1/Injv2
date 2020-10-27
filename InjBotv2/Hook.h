#pragma once
#include "GUI.h"

BOOL Hook(void* pTarget, void* ourFunct, int len, int Instruction);
 
void enable_hooks();
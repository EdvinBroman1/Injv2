#pragma once
#include "GUI.h"

BOOL Hook(void* pTarget, void* ourFunct, int len);
 
void enable_hooks();
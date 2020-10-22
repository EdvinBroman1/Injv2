#pragma once
#include "Addresses.h"
#include <iostream>
#include <vector>
void PrintAllLabels();
void OpenChannel(const char* ChannelName, int ChannelID);

class Print {
public:
    std::string text;
    int x, y, r, g, b, font, alignment;

    Print(const std::string& str, int X, int Y, int B, int G, int R, int FONT);
};

class ContextMenuItem {
public:
    const char* Text, *Shortcut;
    int EventID;

    ContextMenuItem(const char* txt, int eventid, const char* shortcut);
};

#pragma once
#include "Position.h"
#include "Addresses.h"
#include <string>


struct PlayerSkills {
public:
	int FistSkill;
	int ClubSkill;
	int SwordSkill;
	int AxeSkill;
	int DistanceSkill;
	int	Shielding;
	int FishSkill;
	char unknown1[0x14];
	int Soul;
	int MaxMana;
	int Mana;
	char unknown2[0x8];
	int MagicLevel;
	int Level;
	int Experience;
	int MaxHealth;
	int	Health;
};

struct PlayerOffsets {
public:
	static const intptr_t CreatureID = 0x58;
	static const intptr_t PositionX = 0x24;
	static const intptr_t PositionY = 0x28;
	static const intptr_t PositionZ = 0x2C;
};

class Player {
public:
	
	int creature_id;
	DWORD PlayerBase;
	std::string Name;

	PlayerSkills* Skills;
	Position* Pos;


	void Say(const std::string& msg, int id);

	bool WalkTo(Position* newPos) const;
	std::string ToString() const;

	Player();
};

DWORD getPlayerPointer(int creature_id = *reinterpret_cast<int*>(Client::BaseAddress + Self::LocalPlayer + PlayerOffsets::CreatureID));

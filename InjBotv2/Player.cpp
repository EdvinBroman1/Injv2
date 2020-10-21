#include "Player.h"
#include "Addresses.h"



Player::Player() :
    Skills(reinterpret_cast<PlayerSkills*>(Client::BaseAddress + Self::LocalPlayer)),
    creature_id(*reinterpret_cast<int*>(Client::BaseAddress + Self::LocalPlayer + PlayerOffsets::CreatureID)),
    PlayerBase(getPlayerPointer(creature_id)),
    Name(reinterpret_cast<char*>(PlayerBase + 0x4)),
    Pos(reinterpret_cast<Position*>(PlayerBase + PlayerOffsets::PositionX))
{
}

std::string Player::ToString() const {
    return "Name: " + this->Name + "\nLevel: " + std::to_string(this->Skills->Level) + "\nHealth: " + std::to_string(this->Skills->Health) + " / " + std::to_string(this->Skills->MaxHealth) + "\n";
}



void Player::Say(const std::string& msg, int id) {

    using sayFunc = void(cdecl*)(std::string mMsg, int ID);
    sayFunc sF = (sayFunc)(Client::BaseAddress + 0x73F0);

    sF(msg, id);

}

bool Player::WalkTo(Position* newPos) const
{
    intptr_t functionadr = Client::BaseAddress + 0xD0E20;
    int x = newPos->X - this->Pos->X;
    int y = newPos->Y - this->Pos->Y;
    int z = newPos->Z - this->Pos->Z;


    __asm {
        push z
        push y
        push x
        call functionadr
    }

    if (newPos->X == this->Pos->X && newPos->Y == this->Pos->Y && newPos->Z == this->Pos->Z)
        return true;
    else
        return false;
}


DWORD getPlayerPointer(int creature_id)
{
    DWORD function_adr = Client::BaseAddress + 0x5E720;

    DWORD pPlayer = 0x0;

    using getPlayerPtr = DWORD(cdecl*)(int CreatureID);
    getPlayerPtr getPlayer = (getPlayerPtr)(function_adr);

    pPlayer = getPlayer(creature_id);

    return pPlayer;
}
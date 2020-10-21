#include "Player.h"
#include "Addresses.h"



Player::Player() :
    Skills(reinterpret_cast<PlayerSkills*>(Client::BaseAddress + Self::LocalPlayer)),
    creature_id(*reinterpret_cast<int*>(Client::BaseAddress + Self::LocalPlayer + PlayerOffsets::CreatureID)),
    Pos(reinterpret_cast<Position*>(this + PlayerOffsets::PositionX))
{
}

std::string Player::ToString() {
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


Player* getPlayerPointer(int creature_id)
{
    intptr_t function_adr = Client::BaseAddress + 0x5E720;
    Player* pointr = nullptr;

    using getPlayerPtr = Player*(cdecl*)(int CreatureID);
    getPlayerPtr getPlayer = (getPlayerPtr)(function_adr);

    pointr = getPlayer(creature_id);

    return pointr;
}
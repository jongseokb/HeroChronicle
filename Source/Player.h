//Player.h
#pragma once

#include "StatInfo.h"

// 플레이어 종류
enum class PlayerType
{
	PT_Knight = 1,	// 기사
	PT_Archor,		// 궁수
	PT_Wizard		// 마법사
};

// 플레이어 상세
struct PlayerInfo
{
	// 스탯 변수 선언
	StatInfo Stat;
	PlayerType Type;
};










//Monster.h
#pragma once

#include "StatInfo.h"

// 몬스터 종류
enum class MonsterType
{
	MT_Orc = 1,		// 오크
	MT_Goblin,		// 고블린
	MT_Skeleton,	// 스켈레톤
	MT_Dragon,		// 드래곤
	MT_DarkKNight	// 다크 나이트
};

// 몬스터 정보
struct MonsterInfo
{
	MonsterType Type;
	StatInfo Stat;

};
// Statinfo.h
#pragma once
#include <string>

using namespace std;

// 스탯 정보
struct StatInfo
{
	string name;			//이름
	int MaxHp;				// 최대 체력
	int Hp;					// 체력
	int Mp;					// 마나
	int AttackDamage;		// 물리 공격력
	int PhysicalDefense;	// 물리 방어력
};


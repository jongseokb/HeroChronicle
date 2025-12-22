#pragma once
#include <string>

using namespace std;

// 아이템 타입
enum class ItemType
{
	Consumable = 1, // 소모품
	Equipment
};

// 아이템 구조
struct Item
{
	ItemType Type;		// 아이템 종류
	int Id;				// 아이템 ID
	string Name;		// 아이템 이름
	int value;			// 아이템 가치(가격)

};
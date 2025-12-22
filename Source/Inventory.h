#pragma once
#include "Item.h"

// 인벤토리 크기 결정
const int MAX_INVENTORY_SIZE = 10;

struct Inventory
{
	Item Items[MAX_INVENTORY_SIZE]; 
	int Count = 0; // 현재 아이템 갯수
};

// Project Start Date: 2025.12.15
// Copyright (c) 2025 HeroChronicle Project by Jongseokb.

using namespace std;

#include <iostream>
#include "GameBase.h"


int main()
{
	// 랜덤 함수 사용
	srand((unsigned int)time(nullptr));

	GameBase Game;

	while (!Game.IsGameEnd())
	{
		system("cls");

		Game.CurrentLocation();


	}

}


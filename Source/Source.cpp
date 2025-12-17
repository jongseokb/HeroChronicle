// Project Start Date: 2025.12.15
// Copyright (c) 2025 HeroChronicle Project by Jongseokb.

using namespace std;

#include <iostream>
#include "GameBase.h"

int main()
{
	GameBase Game;

	while (true)
	{
		system("cls");

		// 로비 입장
		Game.EnterLobby();

		// 플레이어 결졍
		Game.PlayerSelect();

		// 마을 입장
		Game.EnterVilage();
	}
	
}


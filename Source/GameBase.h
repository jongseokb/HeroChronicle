//GameBase.h

#pragma once

#include "Player.h"


class GameBase
{

public:
	// 로비 입장
	void EnterLobby();


	// 플레이어 선택 정보
	void PlayerSelect();

	// 이넘값을 문자열로 변환
	const char* PlayerTypeToString(PlayerType type);

	// 플레이어 정보 변수 선언
	PlayerInfo Player;
};

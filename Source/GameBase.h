//GameBase.h

#pragma once

#include "Player.h"
#include "Monster.h"


class GameBase
{

public:
	// 로비 입장
	void EnterLobby();


	// 플레이어 선택 정보
	void PlayerSelect();

	// Enum값을 문자열로 변환
	const char* PlayerTypeToString(PlayerType type);

	// 마을 입장
	void EnterVilage();

	// 기사 스탯 정보
	void KnightStatInfo();

	// 궁수 스탯 정보
	void ArchorStatInfo();

	// 마법사 스탯 정보
	void WizardStatInfo();

	// 현재 캐릭터 스탯 정보
	void CurrentStatInfo();

	// 라인 설정
	void Line();

	// 상점 입장
	void EnterShop();

	// 던전 입장
	void EnterDungeon();

protected:
	// 플레이어 정보 변수 선언
	PlayerInfo Player;

	// 몬스터 정보 변수 선언
	MonsterInfo Monster;

	
	//enum class MonsterType
	//{
	//	MT_Orc = 1,		// 오크
	//	MT_Goblin,		// 고블린
	//	MT_Skeleton,	// 스켈레톤
	//	MT_Dragon,		// 드래곤
	//	MT_DarkNight	// 다크 나이트
	//};

public:
	// 몬스터 정보 - 오크
	void OrcStatInfo();

	// 몬스터 정보 - 고블린
	void GoblinStatInfo();

	// 몬스터 정보 - 스켈레톤
	void SkeletonStatInfo();

	// 몬스터 정보 - 드래곤
	void DragonStatInfo();

	// 몬스터 정보 - 다크나이트
	void DarkKnightStatInfo();
};

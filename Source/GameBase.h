//GameBase.h

#pragma once

#include "Player.h"
#include "Monster.h"
#include "GameStatus.h"
#include "BattleStatus.h"
#include "BattleResult.h"


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
	void EnterTown();

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

	// 게임 종료
	void ExitGame();

	// 전투하기
	void EnterBattle();

	// 상태에 따른 함수 호출
	void CurrentLocation();

	// 로딩 연출
	void PrintWinDots(const string& Text, int DotCount, int Delay);

	// 전투 시작 
	void BattleStart();

	// 전투 진입
	void RunBattle();

	// 전투 중
	void BattleAction();

	// 전투 결과
	void BattleResult(const EBattleResult Result);

	// 게임 종료
	bool IsGameEnd()const;

	// 회복 하기
	void RecoverHp();

protected:

	// 플레이어 정보 변수 선언
	PlayerInfo Player;

	// 플레이어 정보 포인터 선언
	PlayerInfo* PlayerPtr = &Player;

	// 몬스터 정보 변수 선언
	MonsterInfo Monster;

	// 몬스터 정보 포인터 선언
	MonsterInfo* MonsterPtr = &Monster;

	// 게임 상태 변수 선언
	GameStatus Status = GameStatus::LOBBY;

	// .배틀 상태 변수 선언
	BattleStatus BStatus = BattleStatus::BATTLE_SEARCH;

	// 배틀 결과 선언
	EBattleResult BResult = EBattleResult::DRAW;

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

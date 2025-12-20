// GameBase.cpp

using namespace std;

#include <iostream>
#include "GameBase.h"
#include <Windows.h>




// 로비 입장.
void GameBase::EnterLobby()
{
	// 게임 상태 변경
	Status = GameStatus::LOBBY;

	Line();
	cout << "		>>> 환영합니다. 로비에 입장하셨습니다." << endl;
	Line();
}


// 플레이어 선택 정보
void GameBase::PlayerSelect()
{
	// 게임 상태 변경
	Status = GameStatus::LOBBY;

	while (true)
	{
		cout << "		>>> 직업을 선택해주세요 : 기사(1), 궁수(2), 마법사(3), 게임종료(4)" << endl;
		Line();
		cout << "		번호 : ";

		int ChoiceNumber;
		cin >> ChoiceNumber;

		switch (ChoiceNumber)
		{
		case 1:
			KnightStatInfo();
			Status = GameStatus::TOWN;

			return;
		case 2:
			ArchorStatInfo();
			Status = GameStatus::TOWN;

			return;
		case 3:
			WizardStatInfo();
			Status = GameStatus::TOWN;

			return;
		case 4:
			ExitGame();
			return;

		default:
			// 화면 정리
			system("cls");

			Line();
			cout << "		>>> 숫자를 잘못 입력하셨습니다. 다시 입력해주세요." << endl;
			Line();

			break;
		}
	}


}

// enum값을 문자열로 변환
const char* GameBase::PlayerTypeToString(PlayerType type)
{
	switch (type)
	{
	case PlayerType::PT_Knight:
		return "기사";
	case PlayerType::PT_Archor:
		return "궁수";
	case PlayerType::PT_Wizard:
		return "마법사";
	default:
		return "알수 없음";

	}

}

// 마을 입장
void GameBase::EnterTown()
{
	// 게임 상태 확인
	if (Status != GameStatus::TOWN)
	{
		Status = GameStatus::TOWN;
	}

	Line();	cout << "		>>> 이제부터 당신은" << PlayerTypeToString(Player.Type) << "로써 모험을 시작하게됩니다." << endl; Line();

	while (true)
	{
		int ChoiceNumber;

		cout << endl; Line();
		cout << "		>>> 마을에서 할수 있는 일은 다음과 같습니다." << endl; cout << endl;
		cout << "		1. 상태 확인" << endl;
		cout << "		2. 상점 구매" << endl;
		cout << "		3. 던전 입장" << endl;
		cout << "		4. 나가기(로비)" << endl;
		Line();		cout << "		무엇을 할까? (1~4) : ";
		cin >> ChoiceNumber;

		// 선택
		switch (ChoiceNumber)
		{
		case 1:
			// 현재 상태 정보
			CurrentStatInfo();
			break;

		case 2:

			return;

		case 3:
			Status = GameStatus::DUNGEON;
			return;

		case 4:

			return;

		default:

			break;
		}
	}

}

// 기사 스탯 정보
void GameBase::KnightStatInfo()
{
	Player.Type = PlayerType::PT_Knight;
	Player.Stat.Hp = 100;
	Player.Stat.Mp = 50;
	Player.Stat.AttackDamage = 30;
	Player.Stat.PhysicalDefense = 20;

	// 화면 정리
	system("cls");

	Line();
	cout << "		" << PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
	cout << "		- Hp : " << Player.Stat.Hp << endl;
	cout << "		- Mp : " << Player.Stat.Mp << endl;
	cout << "		- 물리 공격력 : " << Player.Stat.AttackDamage << endl;
	cout << "		- 물리 방어력 : " << Player.Stat.PhysicalDefense << endl;
	Line();
}

// 궁수 스탯 정보
void GameBase::ArchorStatInfo()
{
	Player.Type = PlayerType::PT_Archor;
	Player.Stat.Hp = 80;
	Player.Stat.Mp = 50;
	Player.Stat.AttackDamage = 20;
	Player.Stat.PhysicalDefense = 15;

	// 화면 정리
	system("cls");

	Line();
	cout << "		" << PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
	cout << "		- Hp : " << Player.Stat.Hp << endl;
	cout << "		- Mp : " << Player.Stat.Mp << endl;
	cout << "		- 물리 공격력 : " << Player.Stat.AttackDamage << endl;
	cout << "		- 물리 방어력 : " << Player.Stat.PhysicalDefense << endl;
	Line();
}

// 마법사 스탯 정보
void GameBase::WizardStatInfo()
{
	Player.Type = PlayerType::PT_Wizard;
	Player.Stat.Hp = 60;
	Player.Stat.Mp = 50;
	Player.Stat.AttackDamage = 10;
	Player.Stat.PhysicalDefense = 10;

	// 화면 정리
	system("cls");

	Line();
	cout << "		" << PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
	cout << "		- Hp : " << Player.Stat.Hp << endl;
	cout << "		- Mp : " << Player.Stat.Mp << endl;
	cout << "		- 물리 공격력 : " << Player.Stat.AttackDamage << endl;
	cout << "		- 물리 방어력 : " << Player.Stat.PhysicalDefense << endl;
	Line();
}

// 현재 스탯 정보
void GameBase::CurrentStatInfo()
{
	// 화면 정리
	system("cls");

	Line();
	cout << "						>>>> 캐릭터 정보 <<<< " << endl; cout << endl;

	cout << "						- 직업		: " << PlayerTypeToString(Player.Type) << endl;
	cout << "						- Hp		: " << Player.Stat.Hp << endl;
	cout << "						- Mp		: " << Player.Stat.Mp << endl;
	cout << "						- 물리 공격력	: " << Player.Stat.AttackDamage << endl;
	cout << "						- 물리 방어력	: " << Player.Stat.PhysicalDefense << endl;
	Line();

}

// 줄 삽입
void GameBase::Line()
{
	cout << "------------------------------------------------------------------------------------------" << endl;
}

// 상정 정보
void GameBase::EnterShop()
{
}

// 던전 정보
void GameBase::EnterDungeon()
{
	system("cls");
	while (true)
	{
		Line();
		cout << "당신은 " << PlayerTypeToString(Player.Type) << "으로써 던전을 모험합니니다." << endl;
		Line();
		cout << "던전안은 음침하고, 소름끼치는 소리가 사방에서 들리고, 누군가 날보고 있는것 처럼 시선이 느껴집니다." << endl;
		cout << "이제 모험을 합니다. 무엇을 하시겠습니까?" << endl;
		Line(); cout << endl;
		Line();
		cout << "		>>> 행동을 선택해주세요 : 탐색(1), 마을로 돌아가기(2)" << endl;
		Line();
		cout << "		번호 : ";
		// 번호 선택
		int choiceNubmer;
		cin >> choiceNubmer;

		switch (choiceNubmer)
		{
		case 1:
			Status = GameStatus::BATTLE;
			return;

		case 2:
			Status = GameStatus::TOWN;
			return;

		default:
			// 화면 정리
			system("cls");

			Line();
			cout << "		>>> 숫자를 잘못 입력하셨습니다. 다시 입력해주세요." << endl;
			Line();

			break;
		}
	}

}

// 게임 종료
void GameBase::ExitGame()
{
	system("cls");
	Line();
	cout << "				>>> 게임을 종료 합니다.감사합니다. <<<				" << endl;
	Line();

	cout.flush();
	Sleep(4000);

	Status = GameStatus::END;

}


// 전투 하기
void GameBase::EnterBattle()
{
	// 게임 상태 확인

	int monsterIndex = rand() % 5;
	switch (monsterIndex)
	{
	case 0:
		OrcStatInfo();
		break;
	case 1:
		GoblinStatInfo();
		break;
	case 2:
		SkeletonStatInfo();
		break;
	case 3:
		DragonStatInfo();
		break;
	case 4:
		DarkKnightStatInfo();
		break;
	default:
		cout << "몬스터를 찾지 못했습니다. 조금 더 헤맵시다." << endl;
		break;
	}

	system("cls");

	PrintWinDots("던전을 탐색중입니다.", 3, 1000);


	BStatus = BattleStatus::BATTLE_START;
}

// 전투 시작
void GameBase::BattleStart()
{
	Line();
	cout << "				>>> 전투를 시작합니다. <<<				" << endl;
	Line();
	cout << "		당신은 던전을 탐색하던중," << Monster.Stat.name << "과(와) 마주쳤습니다." << endl;
	Line();
	cout << "- 이름 : " << Monster.Stat.name <<
		"						- 이름 : " << PlayerTypeToString(Player.Type) << endl;
	cout << "- Hp : " << Monster.Stat.Hp <<
		"						- Hp : " << Player.Stat.Hp << endl;
	cout << "- Mp : " << Monster.Stat.Mp <<
		"						- Mp : " << Player.Stat.Mp << endl;
	cout << "- 물리 공격력 : " << Monster.Stat.AttackDamage <<
		"				- 물리 공격력 : " << Player.Stat.AttackDamage << endl;
	cout << "- 물리 방어력 : " << Monster.Stat.PhysicalDefense <<
		"				- 물리 방어력 : " << Player.Stat.PhysicalDefense << endl;
	Line();
	cout << "긴장된 순간, 적이 당신을 공격해옵니다." << endl;
	Line(); cout << endl;
	cout << "당신은 무엇을하시겠습니까? (1)싸운다. (2)도망친다." << endl; cout << endl;
	Line();
	cout << "		번호 : ";
	// 번호 선택
	int choiceNubmer;
	cin >> choiceNubmer;

	switch (choiceNubmer)
	{
	case 1:
		BStatus = BattleStatus::BATTLE_ING;
		return;
	case 2:
		Status = GameStatus::DUNGEON;
		BStatus = BattleStatus::BATTLE_SEARCH;
		return;
	default:

		break;
	}

}



// 전투 중
void GameBase::BattleAction()
{

	// 인간의 데미지
	int HeroDamage = Player.Stat.AttackDamage - Monster.Stat.PhysicalDefense;

	// 데미지가 0보다 작으면
	if (HeroDamage < 0)
	{
		HeroDamage = 1;
	}

	// 몬스터 데미지
	int MonsterDamage = Monster.Stat.AttackDamage - Player.Stat.PhysicalDefense;

	// 데미지가 0보다 작으면
	if (MonsterDamage < 0)
	{
		MonsterDamage = 1;
	}

	while (Player.Stat.Hp > 0 && Monster.Stat.Hp > 0)
	{
		// 몬스터 HP에 데미지 적용
		Monster.Stat.Hp -= HeroDamage;
		if (Monster.Stat.Hp <= 0)
		{
			Monster.Stat.Hp = 0;
			BStatus = BattleStatus::BATTLE_END;
			BResult = EBattleResult::PLAYER_WIN;

			return;
		}

		system("cls");

		cout << endl;  cout << PlayerTypeToString(Player.Type) << "는 칼을 들어 " <<
			Monster.Stat.name << "을(를) 공격합니다." << endl;

		cout << Monster.Stat.name << "가" << HeroDamage << "만큼 피해를 입었다." << endl; cout << endl;

		Line();

		cout << PlayerTypeToString(Player.Type) << "의 남은 Hp: " << Player.Stat.Hp <<
			"          " << Monster.Stat.name << "의 남은 Hp: " << Monster.Stat.Hp << endl;

		cout.flush();
		Sleep(1000);

		// 플레이어 Hp에 데미지 적용
		Player.Stat.Hp -= MonsterDamage;

		if (Player.Stat.Hp <= 0)
		{
			Player.Stat.Hp = 0;

			BStatus = BattleStatus::BATTLE_END;
			BResult = EBattleResult::PLAYER_LOSE;

			//cout << PlayerTypeToString(Player.Type) << " 은(는) 쓰러지고 말았다..." << endl;
			////Status = GameStatus::END;

			//cout.flush();
			//Sleep(1000);
			return;
		}

		system("cls");

		cout << endl; cout << Monster.Stat.name << "가 발톱으로 " <<
			PlayerTypeToString(Player.Type) << "를(을) 공격합니다." << endl;

		cout << PlayerTypeToString(Player.Type) << "는" << MonsterDamage << "만큼의 피해를 입었다." << endl;
		cout << endl;

		Line();

		cout << PlayerTypeToString(Player.Type) << "의 남은 Hp: " << Player.Stat.Hp <<
			"          " << Monster.Stat.name << "의 남은 Hp: " << Monster.Stat.Hp << endl;

		cout.flush();
		Sleep(1000);
	}

}

// 전투 결과
void GameBase::BattleResult(const EBattleResult Result)
{
	switch (Result)
	{
	case EBattleResult::PLAYER_WIN:
		cout << endl;	Line();
		cout << "				>>> 축하합니다! 당신은 " << Monster.Stat.name << " 을(를) 물리쳤습니다! <<<				" << endl;
		Line(); cout << endl;

		PrintWinDots("잠시 후 던전으로 이동합니다.", 5, 1000);
		

		// 전투 상태 초기화
		BStatus = BattleStatus::BATTLE_SEARCH;
		// 던전 상태로 복귀
		Status = GameStatus::DUNGEON;
		return;

	case EBattleResult::PLAYER_LOSE:
		cout << endl;	Line();
		cout << "				>>> 당신은 " << Monster.Stat.name << " 에게 패배하고 말았습니다... <<<				" << endl;
		Line(); cout << endl;

		cout.flush();
		Sleep(4000);

		PrintWinDots("잠시 후 로비로 이동합니다..", 5, 1000);

		// 게임 종료
		Status = GameStatus::LOBBY;
		BStatus = BattleStatus::BATTLE_SEARCH;

		return;

	case EBattleResult::DRAW:
		return;
	case EBattleResult::ESCAPE:
		return;
	default:
		break;
	}
}

bool GameBase::IsGameEnd() const
{
	return Status == GameStatus::END;
}


// 전투 진입
void GameBase::RunBattle()
{
	switch (BStatus)
	{
	case BattleStatus::BATTLE_SEARCH:
		EnterBattle();
		break;

	case BattleStatus::BATTLE_START:
		BattleStart();
		break;

	case BattleStatus::BATTLE_ING:
		BattleAction();
		break;

	case BattleStatus::BATTLE_END:
		BattleResult(BResult);
		break;

	default:
		break;
	}
}

// 상태에 따른 함수 호출
void GameBase::CurrentLocation()
{
	switch (Status)
	{
	case GameStatus::LOBBY:
		EnterLobby();
		PlayerSelect();
		return;

	case GameStatus::TOWN:
		EnterTown();
		return;

	case GameStatus::DUNGEON:
		EnterDungeon();
		return;

	case GameStatus::BATTLE:
		RunBattle();
		return;

	case GameStatus::END:
		ExitGame();
		return;

	default:
		break;
	}
}

// 로딩 연출
void GameBase::PrintWinDots(const string& Text, int DotCount, int Delay)
{
	cout << endl;

	cout << Text;
	for (int i = 0; i < DotCount; i++)
	{
		cout << ".";
		cout.flush();
		Sleep(Delay);

	}
	system("cls");
}



// 몬스터 정보 - 오크
void GameBase::OrcStatInfo()
{
	Monster.Type = MonsterType::MT_Orc;
	Monster.Stat.name = "오크";
	Monster.Stat.Hp = 100;
	Monster.Stat.Mp = 10;
	Monster.Stat.AttackDamage = 28;
	Monster.Stat.PhysicalDefense = 10;
}

// 몬스터 정보 - 고블린
void GameBase::GoblinStatInfo()
{
	Monster.Type = MonsterType::MT_Goblin;
	Monster.Stat.name = "고블린";
	Monster.Stat.Hp = 80;
	Monster.Stat.Mp = 15;
	Monster.Stat.AttackDamage = 15;
	Monster.Stat.PhysicalDefense = 9;
}

// 몬스터 정보 - 스켈레톤
void GameBase::SkeletonStatInfo()
{
	Monster.Type = MonsterType::MT_Skeleton;
	Monster.Stat.name = "스켈레톤";
	Monster.Stat.Hp = 110;
	Monster.Stat.Mp = 15;
	Monster.Stat.AttackDamage = 20;
	Monster.Stat.PhysicalDefense = 8;
}

// 몬스터 정보 - 드래곤
void GameBase::DragonStatInfo()
{
	Monster.Type = MonsterType::MT_Dragon;
	Monster.Stat.name = "드래곤";
	Monster.Stat.Hp = 120;
	Monster.Stat.Mp = 200;
	Monster.Stat.AttackDamage = 45;
	Monster.Stat.PhysicalDefense = 6;
}

// 몬스터 정보 - 다크나이트
void GameBase::DarkKnightStatInfo()
{
	Monster.Type = MonsterType::MT_DarkKNight;
	Monster.Stat.name = "다크나이트";
	Monster.Stat.Hp = 120;
	Monster.Stat.Mp = 140;
	Monster.Stat.AttackDamage = 38;
	Monster.Stat.PhysicalDefense = 5;
}



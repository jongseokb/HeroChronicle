// GameBase.cpp

using namespace std;

#include <iostream>
#include "GameBase.h"



// 로비 입장.
void GameBase::EnterLobby()
{
	Line();
	cout << "		>>> 환영합니다. 로비에 입장하셨습니다." << endl;
	Line();
}


// 플레이어 선택 정보
void GameBase::PlayerSelect()
{
	while (true)
	{
				
		int ChoiceNumber;

		cout << "		>>> 직업을 선택해주세요 : 기사(1), 궁수(2), 마법사(3)" << endl; 
		Line();
		cout << "		번호 : ";
		cin >> ChoiceNumber;

		switch (ChoiceNumber)
		{
		case 1:
			KnightStatInfo();
			return;
		case 2:
			ArchorStatInfo();
			return;
		case 3:
			WizardStatInfo();
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
void GameBase::EnterVilage()
{
	// 화면 정리
	system("cls");
	Line();
	cout << "		>>> 이제부터 당신은" << PlayerTypeToString(Player.Type) << "로써 모험을 시작하게됩니다." << endl;
	Line();
	while (true)
	{
		int ChoiceNumber;

		cout << endl;
		Line();
		cout << "		>>> 마을에서 할수 있는 일은 다음과 같습니다." << endl; cout << endl;
		cout << "		1. 상태 확인" << endl;
		cout << "		2. 상점 구매" << endl;
		cout << "		3. 던전 입장" << endl;
		cout << "		4. 나가기(로비)" << endl;
		Line();
		cout << "		무엇을 할까? (1~4) : ";
		cin >> ChoiceNumber;

		// 선택
		switch (ChoiceNumber)
		{
		case 1:
			// 현재 상태 정보
			CurrentStatInfo();
			break;

		case 2:
			EnterShop();
			return;

		case 3:
			EnterDungeon();
			return;

		case 4:

			return;

		default:

			break;
		}
	}

}

void GameBase::KnightStatInfo()
{
	// 기사 스탯 정보
	Player.Type = PlayerType::PT_Knight;
	Player.Stat.Hp = 500;
	Player.Stat.Mp = 300;
	Player.Stat.AttackDamage = 30;
	Player.Stat.PhysicalDefense = 20;

	// 화면 정리
	system("cls");

	Line();
	cout << "		"<< PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
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
	Player.Stat.Hp = 300;
	Player.Stat.Mp = 50;
	Player.Stat.AttackDamage = 20;
	Player.Stat.PhysicalDefense = 15;

	// 화면 정리
	system("cls");

	Line();
	cout << "		"<< PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
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
	Player.Stat.Hp = 200;
	Player.Stat.Mp = 400;
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
	cout << "		>>> 캐릭터 정보 : " << endl; 
	cout << "		- 직업 : " << PlayerTypeToString(Player.Type) << endl;
	cout << "		- Hp : " << Player.Stat.Hp << endl;
	cout << "		- Mp : " << Player.Stat.Mp << endl;
	cout << "		- 물리 공격력 : " << Player.Stat.AttackDamage << endl;
	cout << "		- 물리 방어력 : " << Player.Stat.PhysicalDefense << endl; 
	Line();
	
}

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
}

// 몬스터 정보 - 오크
void GameBase::OrcStatInfo()
{
	Monster.Type = MonsterType::MT_Orc;
	Monster.Stat.name = "오크";
	Monster.Stat.Hp = 400;
	Monster.Stat.Mp = 10;
	Monster.Stat.AttackDamage = 28;
	Monster.Stat.PhysicalDefense = 32;
}

// 몬스터 정보 - 고블린
void GameBase::GoblinStatInfo()
{
	Monster.Type = MonsterType::MT_Goblin;
	Monster.Stat.name = "고블린";
	Monster.Stat.Hp = 120;
	Monster.Stat.Mp = 15;
	Monster.Stat.AttackDamage = 15;
	Monster.Stat.PhysicalDefense = 30;
}

// 몬스터 정보 - 스켈레톤
void GameBase::SkeletonStatInfo()
{
	Monster.Type = MonsterType::MT_Goblin;
	Monster.Stat.name = "스켈레톤";
	Monster.Stat.Hp = 240;
	Monster.Stat.Mp = 15;
	Monster.Stat.AttackDamage = 20;
	Monster.Stat.PhysicalDefense = 24;
}

// 몬스터 정보 - 드래곤
void GameBase::DragonStatInfo()
{
	Monster.Type = MonsterType::MT_Goblin;
	Monster.Stat.name = "드래곤";
	Monster.Stat.Hp = 600;
	Monster.Stat.Mp = 200;
	Monster.Stat.AttackDamage = 45;
	Monster.Stat.PhysicalDefense = 40;
}

// 몬스터 정보 - 다크나이트
void GameBase::DarkKnightStatInfo()
{
	Monster.Type = MonsterType::MT_Goblin;
	Monster.Stat.name = "다크나이트";
	Monster.Stat.Hp = 500;
	Monster.Stat.Mp = 140;
	Monster.Stat.AttackDamage = 38;
	Monster.Stat.PhysicalDefense = 32;
}



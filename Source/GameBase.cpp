// GameBase.cpp

using namespace std;

#include <iostream>
#include "GameBase.h"



// 로비 입장.
void GameBase::EnterLobby()
{
	cout << "---------------------------------------------" << endl; cout << endl;
	cout << "환영합니다. 로비에 입장하셨습니다." << endl; cout << endl;
	cout << "---------------------------------------------" << endl; cout << endl;

}


// 플레이어 선택 정보
void GameBase::PlayerSelect()
{
	while (true)
	{
		int ChoiceNumber;

		cout << "직업을 선택해주세요 : 기사(1), 궁수(2), 마법사(3)" << endl;
		cout << "번호 : ";
		cin >> ChoiceNumber;

		switch (ChoiceNumber)
		{
		case 1:
			// 기사 스탯 정보
			Player.Type = PlayerType::PT_Knight;
			Player.Stat.Hp = 500;
			Player.Stat.Mp = 300;
			Player.Stat.AttackDamage = 30;
			Player.Stat.PhysicalDefense = 20;

			cout << "---------------------------------------------" << endl; cout << endl;
			cout << PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
			cout << "Hp : " << Player.Stat.Hp << endl;
			cout << "Mp : " << Player.Stat.Mp << endl;
			cout << "물리 공격력 : " << Player.Stat.AttackDamage << endl;
			cout << "물리 방어력 : " << Player.Stat.PhysicalDefense << endl;
			cout << "---------------------------------------------" << endl; cout << endl;
			return;
		case 2:
			// 궁수 스탯 정보
			Player.Type = PlayerType::PT_Archor;
			Player.Stat.Hp = 300;
			Player.Stat.Mp = 50;
			Player.Stat.AttackDamage = 20;
			Player.Stat.PhysicalDefense = 15;

			cout << "---------------------------------------------" << endl; cout << endl;
			cout << PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
			cout << "Hp : " << Player.Stat.Hp << endl;
			cout << "Mp : " << Player.Stat.Mp << endl;
			cout << "물리 공격력 : " << Player.Stat.AttackDamage << endl;
			cout << "물리 방어력 : " << Player.Stat.PhysicalDefense << endl;
			cout << "---------------------------------------------" << endl; cout << endl;
			return;
		case 3:
			// 마법사 스탯 정보
			Player.Type = PlayerType::PT_Wizard;
			Player.Stat.Hp = 200;
			Player.Stat.Mp = 400;
			Player.Stat.AttackDamage = 10;
			Player.Stat.PhysicalDefense = 10;

			cout << "---------------------------------------------" << endl; cout << endl;
			cout << PlayerTypeToString(Player.Type) << "를 선택하셨습니다." << endl;
			cout << "Hp : " << Player.Stat.Hp << endl;
			cout << "Mp : " << Player.Stat.Mp << endl;
			cout << "물리 공격력 : " << Player.Stat.AttackDamage << endl;
			cout << "물리 방어력 : " << Player.Stat.PhysicalDefense << endl;
			cout << "---------------------------------------------" << endl; cout << endl;
			return;

		default:
			cout << "---------------------------------------------" << endl; cout << endl;
			cout << "숫자를 잘못 입력하셨습니다. 다시 입력해주세요." << endl;
			cout << "---------------------------------------------" << endl; cout << endl;
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



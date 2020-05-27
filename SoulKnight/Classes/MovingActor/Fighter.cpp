#include"MovingActor/MovingActor.h"
#include"Fighter.h"
#include"MovingActor/Constant.h"
#include<set>
#include "Fighter.h"
//

Fighter* Fighter::create(HelloWorld* Scene ,std::string fighterName)
{

	Fighter* fighter = new Fighter();
	if (fighter && fighter->init(Scene, fighterName))
	{

		fighter->autorelease();
		return fighter;					//	？？？？波浪线原因未知
	}

	CC_SAFE_DELETE(fighter);
	return nullptr;


}




bool Fighter::init(HelloWorld* Scene, std::string fighterName)
{
	if (!Sprite::init())
	{
		return false;
	}

	initHeroData( Scene, fighterName);
	//其他初始定义待补充

	return true;

}


bool Fighter::initHeroData(HelloWorld* Scene, std::string Name)
{
	ValueMap value = FileUtils::getInstance()->getValueMapFromFile("FightersData.plist");
	initFighterData = value.at(Name).asValueMap();

	exploreScene = Scene;

	fighterName = Name;

	hitPoints = initFighterData["hitPoints"].asInt();     //利用plist的键值对
	moveSpeed = initFighterData["MovingSpeed"].asFloat();
	shield = initFighterData["shield"].asInt();
	acRcoverSpeed = initFighterData["ACRecoverRate"].asInt();
	manaPoints = initFighterData["manaPoints"].asInt();
	critRate = initFighterData["critRate"].asFloat();
  lastSkillTime = initFighterData["skillLastTime"].asFloat();
	skillCDTime = initFighterData["skillCD"].asFloat();

	identityRadius = INIT_ID_RADIUS;//初始感知半径500，boss可能会更大
  

	equipNumber = INIT_EQUIP_NUMBER;

	alreadyDead = false;
	attackSpeed = 0.f;
	attackMode = MIX;
	lastTimeInjured = 0.f;
	//lastSkillTime = 0.f;

	curHitPoints = hitPoints;         //初始设定为满值
	curShield = shield;		
	curManaPoints = manaPoints;
			
	for (int i = 0; i < INIT_EQUIP_NUMBER; ++i)    //++i???不甚理解可能存在bug
	{
		equips[i] = nullptr;

	}
	return true;


}

bool Fighter::isFullEquipments()
{
	for (int i = 0; i < INIT_EQUIP_NUMBER; ++i)    //++i???不甚理解可能存在bug
	{
		if (equips[i] = nullptr)
		{
			return false;
		}

	}
	return true;
}

Equipment* Fighter::changeMainEquip()    //待添加切换武器的音效
{
	if (isFullEquipments() == false)
	{
		return equips[0];
	}
	else
	{
		return equips[1];
	}
}

bool Fighter::attack()
{
	return false;
}




bool Fighter::isInMelee()           //判断enemy位于范围内，暂时不会写
{
	return false;
}




void Fighter::fighterMove()      //
{
	Vec2 current = this->getPosition();
	switch (direction)
	{
	case EDirection::UP:
		current.y += INIT_MOVESPEED;
		break;
	case EDirection::UPLEFT:
		current.x -= INIT_MOVESPEED;
		current.y += INIT_MOVESPEED;
		break;
	case EDirection::UPRIGHT:
		current.x += INIT_MOVESPEED;
		current.y += INIT_MOVESPEED;
		break;
	case EDirection::LEFT:
		current.x -= INIT_MOVESPEED;
		break;
	case EDirection::DOWN:
		current.y -= INIT_MOVESPEED;
		break;
	case EDirection::DOWNLEFT:
		current.x -= INIT_MOVESPEED;
		current.y -= INIT_MOVESPEED;
		break;
	case EDirection::DOWNRIGHT:
		current.x += INIT_MOVESPEED;
		current.y -= INIT_MOVESPEED;
		break;
	case EDirection::RIGHT:
		current.x += INIT_MOVESPEED;
		break;
	case EDirection::NODIR:
		break;
	default:
		break;
	}
	this->setPosition(current);
}



void Fighter::playAttackAnimation()
{
}


bool Fighter::isZeroSheild()
{
	if (curShield == 0 && curHitPoints != 0)
	{
		return true;
	}
	return false;
}


void Fighter::die()
{
	//添加英雄死亡时的音效和图像
	//if(this == _combatScene->getMyHero())
	//{
	//	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("Audio/YouHaveBeenSlained.wav", false, 1, 0, 1.2);
	//}
	//学长的参考代码

	//setVisible(false);或是显示英雄倒地变黑不再战斗


	alreadyDead = true;
	//进入结算页面
}

void Fighter::releaseSkill()
{
//继承下至具体英雄写	
}
#include"MovingActor/MovingActor.h"
#include"MovingActor/Fighter.h"
#include"MovingActor/Constant.h"
#include"MovingActor/Bullet.h"
#include"Scene/GameScene.h"

#include<set>


Fighter* Fighter::create(GameScene* Scene ,std::string fighterName)
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




bool Fighter::init(GameScene* Scene, std::string fighterName)
{
	if (!Sprite::init())
	{
		return false;
	}

	initHeroData( Scene, fighterName);
	//其他初始定义待补充

	return true;

}


bool Fighter::initHeroData(GameScene* Scene, std::string Name)
{
	//ValueMap value = FileUtils::getInstance()->getValueMapFromFile("FightersData.plist");
	//initFighterData = value.at(Name).asValueMap();

	exploreScene = Scene;
	fighterName = Name;
	camp = AllCamp::FRIENDLY;

	//hitPoints = initFighterData["hitPoints"].asInt();     //利用plist的键值对
	//moveSpeed = initFighterData["MovingSpeed"].asFloat();
	//shield = initFighterData["shield"].asInt();
	//acRcoverSpeed = initFighterData["ACRecoverRate"].asInt();
	//manaPoints = initFighterData["manaPoints"].asInt();
	//critRate = initFighterData["critRate"].asFloat();
 // lastSkillTime = initFighterData["skillLastTime"].asFloat();
	//skillCDTime = initFighterData["skillCD"].asFloat();


	//测试用
	setTexture(StringUtils::format("downDir.png"));

	identityRadius = INIT_ID_RADIUS;//初始感知半径500，boss可能会更大
  

	equipNumber = INIT_EQUIP_NUMBER;

	alreadyDead = false;
	attackSpeed = 0.f;
	attackMode = MIX;
	attackTarget = NULL;
	lastTimeInjured = 0.f;
	isMoving = false;
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

	//暂时没有攻击目标，所有先不用更新
	//updateTarget();
	if (attackTarget)
	{
		//图片路径尚未填写
		auto bulletSprite = Bullet::create("", damageAbility, flySpeed, this, attackTarget);
		bulletSprite->giveOut();
		//bulletSprite->setPosition(this->getPosition());
		//bulletSprite->setScale();
		exploreScene->getMap()->addChild(bulletSprite);
		exploreScene->flyingItem.pushBack(bulletSprite);
		return true;
	}
	else if(!attackTarget)
	{
		auto bulletSprite = Bullet::create("11.png", damageAbility, 10, this, attackTarget);
		if (!isMoving)
			bulletSprite->giveOut(ldirection);
		else
			bulletSprite->giveOut(direction);
		//bulletSprite->setPosition(this->getPosition());
		//bulletSprite->setScale();
		exploreScene->addChild(bulletSprite);
		exploreScene->flyingItem.pushBack(bulletSprite);
		return true;
	}

	return false;
}




bool Fighter::isInMelee()           //判断enemy位于范围内，暂时不会写
{
	return false;
}




void Fighter::fighterMove()      //
{
	isMoving = true;
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

void Fighter::stand()
{
	isMoving = false;
	switch (fdirection)
	{
	case EDirection::UP:
		//setTexture();
		break;
	case EDirection::DOWN:
		//setTexture();
		break;
	case EDirection::LEFT:
		//setTexture();
		break;
	case EDirection::RIGHT:
		//setTexture();
		break;
	}
	direction = EDirection::NODIR;
}

void Fighter::updateTarget()
{
	MovingActor* tempTarget = NULL;
	Vector<MovingActor*>& allEnemySoldier = exploreScene->enemySoldier;
	Vector<MovingActor*>& allEnemyBoss = exploreScene->enemyBoss;

	auto temp = allEnemyBoss.begin();
	if (!(*temp)->getAlreadyDead() && !allEnemyBoss.empty())
	{
		tempTarget = *temp;
	}
	if (!tempTarget)
	{
		float tempRadius = identityRadius;
		for (auto tempSoldier = allEnemySoldier.begin(); temp != allEnemySoldier.end(); ++tempSoldier)
		{
			float calRadius= (*tempSoldier)->getPosition().getDistance(this->getPosition());
			if (calRadius < tempRadius)
			{
				tempTarget = *tempSoldier;
				tempRadius = calRadius;
			}
		}
	}
	attackTarget = tempTarget;
}


void Fighter::playAttackAnimation()
{
	//这个东西不好写啊
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
#include"MovingActor/Enemy.h"
#include"Enemy/Dragon.h"
#include"MovingActor/Constant.h"
#include"MovingActor/Bullet.h"
#include"Scene/GameScene.h"
#include<vector>

Dragon* Dragon::create(GameScene* Scene, std::string Name)
{
	Dragon* enemy = new Dragon();
	if (enemy && enemy->init(Scene, Name));
	{
		enemy->autorelease();
		return enemy;
	}

	CC_SAFE_DELETE(enemy);
	return nullptr;
}

bool Dragon::init(GameScene* Scene, std::string Name)
{
	if (!Enemy::init(Scene,Name))
		return false;

	initData(Scene, Name);
	return true;
}

bool Dragon::initData(GameScene* Scene, std::string Name)
{
	exploreScene = Scene;
	enemyName = Name;
	camp = AllCamp::ENEMY;

	setTexture("ArtDesigning\\Sprite\\Enemy\\Dragon\\dragon1.png");

	alreadyDead = false;
	attackSpeed = 0.f;

	curHitPoints = hitPoints;
	attackRadius = 500;
	level = SOLDIER;


	this->runAction(normal);

	return true;
}

bool Dragon::loadAnimation()
{
	Vector<SpriteFrame*> normalFrames;
	for (int i = 0; i < 2; i++)
	{
		SpriteFrame* frame = NULL;
		frame = SpriteFrameCache::sharedSpriteFrameCache()->
								  spriteFrameByName(CCString::createWithFormat("ArtDesigning\\Sprite\\Enemy\\Dragon\\dragon%d.png",i)->
								  getCString());
		normalFrames.pushBack(frame);
	}
	CCAnimation* normalAnimation = NULL;
	normalAnimation = CCAnimation::createWithSpriteFrames(normalFrames,1.0/15.0);
	this->setNormal(CCRepeatForever::create(CCAnimate::create(normalAnimation)));

	return true;
}
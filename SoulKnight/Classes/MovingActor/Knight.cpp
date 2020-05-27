#include"Knight.h"
//#include "HelloWorldScene.h"



Knight* Knight::create(HelloWorld* Scene, std::string Name)
{
	Knight* knight = new Knight();
	if (knight && knight->init(Scene, Name))
	{
		knight->autorelease();
		return knight;
	}

	CC_SAFE_DELETE(knight);
	return nullptr;
}



bool Knight::init(HelloWorld* Scene, std::string Name)
{
	if (!Fighter::init(Scene, Name))
	{
		return false;
	}
	//待初始化数据

	//TBD

	return true;
}



bool Knight::isAlreadyDead()
{
	if (curHitPoints == 0)
	{
		return true;
	}

	return false;
}



void Knight::setPosition(const cocos2d::Vec2& newPosition)
{


};




void Knight::releaseSkill()
{
	
	//双枪目前还不知怎么写
	//攻速加成buff和移速buff将会在buff类之后更新

	
	
}



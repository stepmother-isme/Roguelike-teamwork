#include"Knight.h"
#include "cocos2d.h"

Knight* Knight::createWithSpriteFrameName(const char* spriteFrameName)
{
	Knight* knight = new Knight();
	if (knight && knight->initWithSpriteFrameName(spriteFrameName))
	{
		knight->autorelease();




		//物理引擎
		return knight;
	}
	CC_SAFE_DELETE(knight);
	return NULL;

}


void Knight::setPosition(const cocos2d::Vec2& newPosition)
{
	//架构然后放在中心位置


}

bool Knight::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	hitPoints = 5;
	shield = 5;
	manaPoints = 180; //初始化血量、护甲、法力值，后期也可选择传参进行改值.
	//lastSkillTime = 5.0f 
	return true;
}

bool Knight::isAlreadyDead()//用于判断主角是否已死，待添加回调函数
{
	if (hitPoints <= 0)
	{
		return true;
	}
	return false;
}


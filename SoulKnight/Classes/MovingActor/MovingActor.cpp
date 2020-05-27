#include"MovingActor/MovingActor.h"
#include"MovingActor/Constant.h"

//待添加其他内容

MovingActor* MovingActor::create(const std::string& filename, HelloWorld* Scene)
{
	MovingActor* sprite = new  MovingActor();
	if (sprite && sprite->init(filename, Scene))
	{
		sprite->autorelease();
		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}


bool MovingActor::init(const std::string& filename, HelloWorld* Scene)
{
	if (!Sprite::initWithFile(filename))
	{
		return false;
	}

	initData(Scene);


}

void MovingActor::initData(HelloWorld* Scene)
{
	exploreScene = Scene;
	hitPoints = INIT_HITPOINTS;      //初始生命值5
	curHitPoints = hitPoints;       //当前生命值为满值
	identityRadius = INIT_ID_RADIUS;//初始感知半径500，boss可能会更大
	moveSpeed = INIT_MOVESPEED; 
	attackSpeed = 0.f;           //主角和enemy攻击机制不同，暂时设为0
	alreadyDead = false;


}

void MovingActor::die()
{
	alreadyDead = true;
}

//buff类待添加
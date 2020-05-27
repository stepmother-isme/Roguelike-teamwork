#pragma once
#ifndef __MOVINGACTOR_H__
#define __MOVINGACTOR_H__
#include<iostream>
#include <string>
#include <time.h>
#include "cocos2d.h"
#include"Constant.h"

USING_NS_CC;

class HelloWorld;

class MovingActor :public cocos2d::Sprite
{

	CC_SYNTHESIZE(int, maxHitPoints, MaxHitpoints);   //生命值上限
	CC_SYNTHESIZE(int,curHitPoints,CurHitPoints) //当前生命值

	CC_SYNTHESIZE(AllCamp, camp, Camp);//阵营
	CC_SYNTHESIZE(INT32, hitPoints, Hitpoints);   //生命值

	CC_SYNTHESIZE(float, identityRadius, IdentityRadius); //识别半径用于感知范围
	CC_SYNTHESIZE(float, moveSpeed, MoveSpeed); //移动速度
	CC_SYNTHESIZE(float, attackSpeed, AttackSpeed); //攻击速度/攻击频次
	CC_SYNTHESIZE(bool, alreadyDead, AlreadyDead); //死亡判定
	CC_SYNTHESIZE(HelloWorld*, exploreScene, ExploreScene);   //加入场景
	CC_SYNTHESIZE(MovingActor*,attackFrom, AttackFrom);//伤害来源
	CC_SYNTHESIZE(MovingActor*, attackTarget, AttackTarget);//攻击目标

protected:

	virtual void initData(HelloWorld* Scene);  //防止空定义

	//virtual void removeBuff(Buff* buff);
public:

	virtual bool init(const std::string& filename, HelloWorld* Scene);
	virtual void updateTarget();
	virtual void die();
	virtual void takeDamage(DamageMode type, INT32 damage, MovingActor* enemy);
	static MovingActor* create(const std::string& filename, HelloWorld* Scene);
};





#endif // !__MOVINGACTOR_H__

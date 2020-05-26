#pragma once
#ifndef __MOVINGACTOR_H__
#define __MOVINGACTOR_H__
#include<iostream>
#include <iostream>
#include <string>
#include <time.h>
#include "cocos2d.h"
#include"Constant.h"

USING_NS_CC;

class HelloWorld;

class MovingActor :public cocos2d::Sprite
{
	CC_SYNTHESIZE(INT32, hitPoints, Hitpoints);   //生命值
	CC_SYNTHESIZE(float, identityRadius, IdentityRadius); //识别半径用于感知范围
	CC_SYNTHESIZE(float, moveSpeed, MoveSpeed); //移动速度
	CC_SYNTHESIZE(float, attackSpeed, AttackSpeed); //攻击速度/攻击频次
	CC_SYNTHESIZE(bool, alreadyDead, AlreadyDead); //死亡判定
	CC_SYNTHESIZE(HelloWorld*, exploreScene, ExploreScene);   //加入场景


protected:

	virtual void initData(HelloWorld* Scene);  //防止空定义

	//virtual void removeBuff(Buff* buff);
public:

	virtual bool init(const std::string& filename, HelloWorld* Scene);
	//
	static MovingActor* create(const std::string& filename, HelloWorld* Scene);

};





#endif // !__MOVINGACTOR_H__

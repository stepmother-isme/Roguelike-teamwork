#pragma once
#ifndef __UNMOVINGACTOR_H__
#define __UNMOVINGACTOR_H__
#include<iostream>
#include <string>
#include <time.h>
#include "cocos2d.h"
#include "Constant.h"
#include"Buff.h"
#include"MovingActor.h"
#include"Equipment.h"
USING_NS_CC;

class GameScene;
enum TOTALNPC
{
	BloodBox,
	ManaBox,
	CoinBox,
	Businessman,
	Statue,
	Vending

};


class UnMovingActor :public cocos2d::Sprite
{

	CC_SYNTHESIZE(float, touchRadius, TouchRadius);    //触发半径大小设定 用于角色是否在触发范围内
	CC_SYNTHESIZE(bool, isExploreBox, IsExploreBox);    //是否为通关后的宝箱
	CC_SYNTHESIZE(TOTALNPC, npcName, NPCName);            //npc名字


public:

	static UnMovingActor* create(const std::string& filename, GameScene* Scene, TOTALNPC NPC,float radius);

	virtual bool init(const std::string& filename, GameScene* Scene, TOTALNPC NPC, float radius);

	virtual bool isInRadius(MovingActor* fighter);                 //判断角色是否在范围内

	virtual String talkFirstBack();				  //返回NPC说的话

	virtual String talkSecondBack();				  //返回NPC说的话

	void StartAnimation();                //播放动画

	Buff* buffBack();                       //内置buff类型

	Equipment* equipBack();             //买武器用
};












#endif // !__UNMOVINGACTOR_H__

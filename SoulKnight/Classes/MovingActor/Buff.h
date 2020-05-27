#pragma once
#ifndef __BUFF_H__
#define __BUFF_H__
#include "cocos2d.h"
USING_NS_CC;

enum BuffType
{
	VERTIGO,	//眩晕
	FROZEN,     //冰冻
	BURN,       //灼烧
	POISON,     //中毒
	SPEEDUP,    //加速
	SPEEDDOWN   //减速

};
//捡药瓶可归于buff类中
class Buff :public cocos2d::Sprite
{
	//CC_SYNTHESIZE(int, hp, HP);                          
	//CC_SYNTHESIZE(float, buffMoveSpeed, BuffMoveSpeed);

	CC_SYNTHESIZE(float, duration, Duration);   //持续时间
	CC_SYNTHESIZE(float, beginTime, BeginTime); //开始时间
	CC_SYNTHESIZE(float, endTime, EndTime);		//结束时间

	

};




#endif // !__BUFF_H__

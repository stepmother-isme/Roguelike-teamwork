#pragma once
#ifndef __FIGHTER_H__
#define __FIGHTER_H__

#include"cocos2d.h"
#include"MovingActor.h"

USING_NS_CC;

class Fighter :public MovingActor
{
	CC_SYNTHESIZE(INT32, magicPoint, MagicPoint);//能量
	CC_SYNTHESIZE(INT32, shield, Shield);//护盾
	CC_SYNTHESIZE(INT32, shieldFix, ShieldFix);//护盾的回复速度
	CC_SYNTHESIZE(String, fighterName, FighterName);//英雄名字
	CC_SYNTHESIZE(float, calmTime, CalmTime);//技能冷却时间
	CC_SYNTHESIZE(float, lastTime, LastTime);//技能持续时间
public:
	//virtual void getEquipment(Equipment* Eq);  //获取武器
	//virtual void exchangeEquipment(Equipment* Eq) //交换武器
	virtual void takeDamage(DamageMode type, INT32 damage, MovingActor* enemy);
	virtual void skill();
	virtual void reborn();
	virtual void move();
	virtual void stopMove();
	virtual void movingAnimation();
	virtual void attackAnimation();
};



#endif // !__FIGHTER_H__

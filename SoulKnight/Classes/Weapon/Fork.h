#pragma once

#ifndef __FORK_H__
#define __FORK_H__

#include "cocos2d.h"
#include "MovingActor/Equipment.h"


USING_NS_CC;

class Fork :public Equipment
{
	CC_SYNTHESIZE(cocos2d::CCRect, onwerRect, OnwerRect);
	CC_SYNTHESIZE(cocos2d::CCRect,damageRect,DamageRect);

public:

	virtual bool init(EAttackMode _equipType, EEQUIPMENT _equipname, int _attack,
		float _attackSpeed, int _attackRadius, int _manaConsume
	);


	virtual bool init(ValueVector& data, EAttackMode _equipType, EEQUIPMENT _equipname);   


	static Fork* create(EAttackMode _equipType, EEQUIPMENT _equipname, int _attack,
		float _attackSpeed, int _attackRadius, int _manaConsume
	);

	virtual bool cut();
};



#endif //
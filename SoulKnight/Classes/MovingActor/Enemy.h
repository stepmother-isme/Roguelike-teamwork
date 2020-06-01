#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include"cocos2d.h"
#include"MovingActor/MovingActor.h"

USING_NS_CC;

class Enemy :public MovingActor
{
	CC_SYNTHESIZE(String, enemyName, EnemyName);
	CC_SYNTHESIZE(Vec2, destination, Destination);
	CC_SYNTHESIZE(MovingActor*, fromFighter, FromFighter);

public:
	static Enemy* create(GameScene* Scene, std::string fighterName);
	void initData(GameScene* Scene, std::string fighterName);
	void updateDirection();

};


#endif // !__ENEMY_H__

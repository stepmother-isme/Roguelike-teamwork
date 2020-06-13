#pragma once
#ifndef __DRAGON_H__
#define __DRAGON_H__

#include"MovingActor/Enemy.h"
#include"cocos2d.h"

USING_NS_CC;

class GameScene;

class Dragon :public Enemy
{
	CC_SYNTHESIZE(cocos2d::CCAction*,normal,Normal);
public:
	static Dragon* create(GameScene* Scene, std::string fighterName);
	bool init(GameScene* Scene, std::string fighterName);
	bool initData(GameScene* Scene, std::string fighterName);
	bool loadAnimation();

	virtual void chaosBullets();
	virtual void roundBullets();
	virtual void groundFlame();
	virtual void releaseSkill();
	//给可怜的龙放几个技能


};


#endif // !__DRAGON_H__

#pragma once
#ifndef __DRAGON_H__
#define __DRAGON_H__

#include"MovingActor/Enemy.h"
#include"cocos2d.h"

USING_NS_CC;


class Dragon :public Enemy
{
	CC_SYNTHESIZE(cocos2d::CCAction*,normal,Normal);
public:
	static Dragon* create(GameScene* Scene, std::string fighterName);
	bool init(GameScene* Scene, std::string fighterName);
	bool initData(GameScene* Scene, std::string fighterName);
	bool loadAnimation();
};


#endif // !__DRAGON_H__

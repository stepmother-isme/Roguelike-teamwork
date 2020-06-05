#pragma once
#ifndef __TESTMAN_H__
#define __TESTMAN_H__


#include"cocos2d.h"
#include"MovingActor/Fighter.h"
#include"Scene/GameScene.h"
#include"MovingActor/Constant.h"

USING_NS_CC;

class Testman :public Fighter
{
public:
	virtual bool init(GameScene* Scene, std::string fighterName);
	static Testman* create(GameScene* Scene, std::string fighterName);
};

#endif // !__TESTMAN_H__

#pragma once
#ifndef __SAFETYMAP_SCENE_H__
#define __SAFETYMAP_SCENE_H__

#include "cocos2d.h"

class SafetyMap :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	// a selector callback
	//void menuCloseCallback(cocos2d::Ref* pSender);


	CREATE_FUNC(SafetyMap);
};


#endif
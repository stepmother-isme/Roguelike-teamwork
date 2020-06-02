#pragma once
#ifndef __SAFETYMAP_SCENE_H__
#define __SAFETYMAP_SCENE_H__

#include "cocos2d.h"
#include <map>

class SafetyMap :public cocos2d::Scene
{
	//CC_SYNTHESIZE(TMXTiledMap*, _map, Map);
	cocos2d::TMXTiledMap* _tileMap;
private:
	//≥ı ºªØ
	void initMapLayer();
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void initFighter();
	void menuAudioCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(SafetyMap);
};


#endif
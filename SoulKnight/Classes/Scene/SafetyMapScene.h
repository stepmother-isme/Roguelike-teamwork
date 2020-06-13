#pragma once
#ifndef __SAFETYMAP_SCENE_H__
#define __SAFETYMAP_SCENE_H__

#include "cocos2d.h"
#include <map>

USING_NS_CC;
class SafetyMap :public cocos2d::Scene
{
	CC_SYNTHESIZE(cocos2d::TMXTiledMap*, _map, Map);
	cocos2d::TMXTiledMap* _tileMap;

	

private:
	//��ʼ��
	void initMapLayer();
	void initDiamond();//���Ͻǵ���ʯ
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuAudioCallBack(cocos2d::Ref* pSender);
	void menuTestManCallBack(cocos2d::Ref* pSender);
	void menuMenuCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(SafetyMap);
};


#endif
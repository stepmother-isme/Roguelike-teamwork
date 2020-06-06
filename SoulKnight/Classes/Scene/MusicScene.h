#pragma once

#ifndef __MUSIC_SCENE_H__
#define __MUSIC_SCENE_H__

#include "cocos2d.h"

class Music : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuMusicCallBack(cocos2d::Ref* pSender);
	
	CREATE_FUNC(Music);

};

#endif
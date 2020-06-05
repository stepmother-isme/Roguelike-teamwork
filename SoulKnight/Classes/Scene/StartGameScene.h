#pragma once

#ifndef __STARTGAME_SCENE_H__
#define __STARTFAME_SCENE_H__

#include "cocos2d.h"

class StartGame : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//ø™ º°¢Ω· ¯°¢∞Ô÷˙°¢“Ù¿÷
	void menuStartCallBack(cocos2d::Ref* pSender);
	void menuHelpCallBack(cocos2d::Ref* pSender);
	void menuExitCallBack(cocos2d::Ref* pSender);
	void menuAudioCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(StartGame);

};

#endif



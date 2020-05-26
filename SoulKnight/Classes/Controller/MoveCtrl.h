#pragma once
#ifndef __MOVECTRL_H__
#define __MOVECTRL_H__

#include "cocos2d.h"
#include "MovingActor/Constant.h"
#include <functional>

USING_NS_CC;

class MoveController :public Layer
{
	CC_SYNTHESIZE(bool,isCanMove,IsCanMove);
public:
	static MoveController* createMoveController();
	EventListenerKeyboard* listener;
	bool isPressW, isPressS, isPressD, isPressA;
	EDirection direction;
	void ctrlInit();
	virtual bool onKeyPress(EventKeyboard::KeyCode keycode,Event *event);
	virtual bool onKeyRelease(EventKeyboard::KeyCode keycode, Event* event);
	virtual bool update(EventKeyboard::KeyCode keycode,keyPress type);
	virtual bool updateDir();
	CREATE_FUNC(MoveController);
};





#endif // !__MOVECTRL_H__

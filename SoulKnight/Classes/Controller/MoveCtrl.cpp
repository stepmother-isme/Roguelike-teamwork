#include "Controller/MoveCtrl.h"
#include "MovingActor/Constant.h"
#include <functional>

MoveController* MoveController::createMoveController()
{
	MoveController* layer = MoveController::create();
	if(layer)
	{
		layer->ctrlInit();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}

void MoveController::ctrlInit()
{
	listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(MoveController::onKeyPress, this);
	listener->onKeyReleased = CC_CALLBACK_2(MoveController::onKeyReleased, this);
}

bool MoveController::update(EventKeyboard::KeyCode keycode, keyPress type)
{
	switch (keycode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		if (type = PRESS)
			pressW = true;
		else
			pressW = false;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (type = PRESS)
			pressS = true;
		else
			pressS = false;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (type = PRESS)
			pressA = true;
		else
			pressA = false;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (type = PRESS)
			pressD = true;
		else
			pressD = false;
	}
	updateDir();
	return true;
}

bool MoveController::updateDir()
{
	if (pressW)
	{
		if (pressA)
			direction = EDirection::UPLEFT;
		else if (pressD)
			direction = EDirection::UPRIGHT;
		else if (pressS)
			direction = EDirection::NODIR;
		else
			direction = EDirection::UP;
	}
	else if (pressS)
	{
		if (pressA)
			direction = EDirection::DOWNLEFT;
		else if (pressD)
			direction = EDirection::DOWNRIGHT;
		else if (pressW)
			direction = EDirection::NODIR;
		else
			direction = EDirection::DOWN;
	}
	else
	{
		if (pressA)
		{
			if (pressD)
				direction = EDirection::NODIR;
			else
				direction = EDirection::LEFT;
		}
		else if (pressD)
		{
			if (pressA)
				direction = EDirection::NODIR;
			else
				direction = EDirection::RIGHT;
		}
		else
			direction = EDirection::NODIR;
	}
	return true;
}

bool MoveController::onKeyPress(EventKeyboard::KeyCode keycode, Event* event)
{
	update(keycode,keyPress::PRESS);
	return true;
}

bool MoveController::onKeyRelease(EventKeyboard::KeyCode keycode, Event* event)
{
	update(keycode,keyPress::RELEASE);
	return true;
}
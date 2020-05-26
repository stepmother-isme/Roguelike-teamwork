#include "MoveCtrl.h"
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
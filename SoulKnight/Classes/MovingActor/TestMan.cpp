#include"TestMan.h"
#include"Scene/GameScene.h"

Testman* Testman::create(GameScene* Scene, std::string fighterName)
{
	Testman* testman = new Testman;
	if (testman && testman->init(Scene, fighterName))
	{
		testman->autorelease();
		return testman;
	}
	CC_SAFE_DELETE(testman);
	return nullptr;
}

bool Testman::init(GameScene* Scene, std::string fighterName)
{
	if (!Fighter::init(Scene, fighterName))
	{
		return false;
	}
	return true;
}
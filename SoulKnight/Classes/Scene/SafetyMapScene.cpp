#include "SafetyMapScene.h"
#include "StartGameScene.h"
#include "SimpleAudioEngine.h" 
#include "cocos2d.h"

USING_NS_CC;

Scene* SafetyMap::createScene()
{
	return SafetyMap::create();
}
//错误提示
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in SafetyMapScene.cpp\n");
}

bool SafetyMap::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (!audio->isBackgroundMusicPlaying()) {
		audio->playBackgroundMusic("SafetyMap.mp3", true);
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();//得到屏幕大小
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//获得可视区域的出发点坐标，在处理相对位置时，确保节点在不同分辨率下的位置一致。


	
}


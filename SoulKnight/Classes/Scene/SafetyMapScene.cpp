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
	audio->playBackgroundMusic("ArtDesigning/Audio/SafetyMap.mp3", true);

	initMapLayer();

	auto visibleSize = Director::getInstance()->getVisibleSize();//得到屏幕大小
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//获得可视区域的出发点坐标，在处理相对位置时，确保节点在不同分辨率下的位置一致。

	_tileMap = CCTMXTiledMap::create("ArtDesigning/SceneAndMap/SafetyMap/SafetyMap1.tmx");
	_tileMap->setPosition(Vec2(visibleSize.width / 6 + origin.x - 20, visibleSize.height / 6 + origin.y + 20));
	addChild(_tileMap, 0, 10000);//#define TAG_MAP 10000

	auto offMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/on.png", "on.png");
	auto onMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/off.png", "off.png");
	offMusic->setScale(0.5);
	onMusic->setScale(0.5);
	MenuItemToggle* audioMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(SafetyMap::menuAudioCallBack, this),
		offMusic, onMusic, NULL
	);
	audioMenu->setPosition(Vec2(visibleSize.width / 6 * 5 + 40, visibleSize.height - 180));


	Menu* mu = Menu::create(audioMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);


}
void SafetyMap::initMapLayer()
{

	//auto wallLayer = _map->getLayer("Wall");
	//wallLayer->setZOrder(0);

	//auto collisionLayer = _map->getLayer("collision");
	//collisionLayer->setVisible(false);




}

void SafetyMap::initFighter()
{
	//Fighter*
}
/*void StartGame::menuStartCallBack(cocos2d::Ref* pSender)
{

	//转到安全地图
	auto nextScene = SafetyMap::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch Start Menu Item %p", item);
}*/
void SafetyMap::menuAudioCallBack(cocos2d::Ref* pSender)
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (audio->isBackgroundMusicPlaying()) {
		audio->pauseBackgroundMusic();
	}
	else {
		audio->resumeBackgroundMusic();
	}
}

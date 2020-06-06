#include "StartGameScene.h"
#include "SafetyMapScene.h"
#include "HelpScene.h"
#include "SimpleAudioEngine.h" 

USING_NS_CC;

Scene* StartGame::createScene()
{
	return StartGame::create();
}

//Promble loading
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool StartGame::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (!audio->isBackgroundMusicPlaying()) {
		audio->playBackgroundMusic("ArtDesigning/Audio/StartGame.mp3", true);
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//得到屏幕大小
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//获得可视区域的出发点坐标，在处理相对位置时，确保节点在不同分辨率下的位置一致。

	//Start Bottom
	MenuItemImage* startMenu = MenuItemImage::create(
		"ArtDesigning/SceneAndMap/StartGame/START.png",
		"ArtDesigning/SceneAndMap/StartGame/STARTchosen.png",
		CC_CALLBACK_1(StartGame::menuStartCallBack, this)
	);
	if (startMenu == nullptr ||
		startMenu->getContentSize().width <= 0 ||
		startMenu->getContentSize().height <= 0)
	{
		problemLoading("'startMenu.png'");
	}
	else
	{
		float x = visibleSize.width / 2;
		float y = visibleSize.height - 550;
		startMenu->setPosition(Vec2(x, y));
	}

	MenuItemImage* helpMenu = MenuItemImage::create(
		"ArtDesigning/SceneAndMap/StartGame/HELP.png",
		"ArtDesigning/SceneAndMap/StartGame/HELPchosen.png",
		CC_CALLBACK_1(StartGame::menuHelpCallBack, this)
	);

	if (helpMenu == nullptr ||
		helpMenu->getContentSize().width <= 0 ||
		helpMenu->getContentSize().height <= 0)
	{
		problemLoading("'helpMenu.png'");
	}
	else
	{
		float x = visibleSize.width / 4*3;
		float y = visibleSize.height - 550;
		helpMenu->setPosition(Vec2(x, y));
	}

	MenuItemImage* exitMenu = MenuItemImage::create(
		"ArtDesigning/SceneAndMap/StartGame/EXIT.png",
		"ArtDesigning/SceneAndMap/StartGame/EXITchosen.png",
		CC_CALLBACK_1(StartGame::menuExitCallBack, this)
	);

	if (exitMenu == nullptr ||
		exitMenu->getContentSize().width <= 0 ||
		exitMenu->getContentSize().height <= 0)
	{
		problemLoading("'exitMenu.png'");
	}
	else
	{
		float x = visibleSize.width / 4;
		float y = visibleSize.height - 550;
		exitMenu->setPosition(Vec2(x, y));
	}

	
	auto offMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/on.png", "on.png");
	auto onMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/off.png", "off.png");
	offMusic->setScale(0.5);
	onMusic->setScale(0.5);
	MenuItemToggle* audioMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(StartGame::menuAudioCallBack, this),
		offMusic, onMusic, NULL
	);
	audioMenu->setPosition(Vec2(visibleSize.width / 6*5+30, visibleSize.height - 180));

	
	Menu* mu = Menu::create(startMenu, helpMenu, exitMenu,audioMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	auto background = CCTMXTiledMap::create("ArtDesigning/SceneAndMap/StartGame/StartGameBackground.tmx");
	if (background == nullptr)
	{
		problemLoading("'StartGameBackground.png'");
	}
	else
	{
		background->setAnchorPoint(Vec2(0.5, 0.5));
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	    this->addChild(background, 0);
	}
	return true;
}

void StartGame::menuStartCallBack(cocos2d::Ref* pSender)
{
	
	//转到安全地图
	auto nextScene = SafetyMap::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch Start Menu Item %p", item);
}

void StartGame::menuHelpCallBack(cocos2d::Ref* pSender)
{
	//转到help scene
	auto nextScene = Help::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch Start Menu Item %p", item);
//游戏规则最后写	
}
void StartGame::menuExitCallBack(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();//退出
}

void StartGame::menuAudioCallBack(cocos2d::Ref* pSender)
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (audio->isBackgroundMusicPlaying()) {
		audio->pauseBackgroundMusic();
	}
	else {
		audio->resumeBackgroundMusic();
	}
}


#include "StartGameScene.h"
#include "SafetyMapScene.h"
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
		audio->playBackgroundMusic("StartGame.mp3", true);
	}


	auto visibleSize = Director::getInstance()->getVisibleSize();//得到屏幕大小
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//获得可视区域的出发点坐标，在处理相对位置时，确保节点在不同分辨率下的位置一致。

	auto background = Sprite::create("StartGameBackground.png");
	if (background == nullptr)
	{
		problemLoading("'StartGameBackground.png'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}
	
	//Start Bottom
	MenuItemImage* startMenu = MenuItemImage::create(
		"START.png",
		"START.png",
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
		float y = visibleSize.height - 453.0;
		startMenu->setPosition(Vec2(x, y));
	}

	MenuItemImage* helpMenu = MenuItemImage::create(
		"HELP.png",
		"HELP.png",
		CC_CALLBACK_1(StartGame::menuEndCallBack, this)
	);

	if (helpMenu == nullptr ||
		helpMenu->getContentSize().width <= 0 ||
		helpMenu->getContentSize().height <= 0)
	{
		problemLoading("'helpMenu.png'");
	}
	else
	{
		float x = visibleSize.width / 2;
		float y = visibleSize.height - 584.0;
		helpMenu->setPosition(Vec2(x, y));
	}


	auto offMusic = MenuItemImage::create("AUDIO.png", "AUDIO.png");
	auto onMusic = MenuItemImage::create("AUDIO.png", "ic.png");

	MenuItemToggle* musicMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(StartGame::menuMusicCallBack, this),
		offMusic, onMusic, NULL
	);
	musicMenu->setPosition(Vec2(1221.0, visibleSize.height - 680.5));

	Menu* mu = Menu::create(startMenu, helpMenu, musicMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	
	return true;
}

void StartGame::menuStartCallBack(cocos2d::Ref* pSender)
{
	//转到安全地图
	auto nextScene = SafetyMap::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch Helo Menu Item %p", item);
}

void StartGame::menuEndCallBack(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}

void StartGame::menuMusicCallBack(cocos2d::Ref* pSender)
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (audio->isBackgroundMusicPlaying()) {
		audio->pauseBackgroundMusic();
	}
	else {
		audio->resumeBackgroundMusic();
	}
}


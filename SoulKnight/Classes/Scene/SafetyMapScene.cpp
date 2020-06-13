#include "SafetyMapScene.h"
#include "StartGameScene.h"
#include "testmanSelectScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h" 
#include "MovingActor/Constant.h"
#include "cocos2d.h"

USING_NS_CC;


Scene* SafetyMap::createScene()
{
	return SafetyMap::create();
}
//������ʾ
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

	scheduleUpdate();

	auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ÿ�������ĳ��������꣬�ڴ������λ��ʱ��ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�


	MenuItemImage* testManMenu = MenuItemImage::create(
		"ArtDesigning/Sprite/Fighter/hero.png",
		"ArtDesigning/Sprite/Fighter/hero.png",
		CC_CALLBACK_1(SafetyMap::menuTestManCallBack, this)
	);

	if (testManMenu == nullptr ||
		testManMenu->getContentSize().width <= 0 ||
		testManMenu->getContentSize().height <= 0)
	{
		problemLoading("'testManMenu .png'");
	}
	else
	{
		float x = visibleSize.width / 4*3;
		float y = visibleSize.height - 300;
		testManMenu->setPosition(Vec2(x, y));
	}

	MenuItemImage* menuMenu = MenuItemImage::create(
		"ArtDesigning/Word&Others/button/MENU.png",
		"ArtDesigning/Word&Others/button/MENU.png",
		CC_CALLBACK_1(SafetyMap::menuMenuCallBack, this)
	);

	if (menuMenu == nullptr ||
		menuMenu->getContentSize().width <= 0 ||
		menuMenu->getContentSize().height <= 0)
	{
		problemLoading("'menuMenu .png'");
	}
	else
	{
		float x = visibleSize.width / 4 * 3;
		float y = visibleSize.height - 300;
		menuMenu->setPosition(Vec2(visibleSize.width / 6 * 5 + 30, visibleSize.height - 180));
	}
	
	auto offMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/on.png", "on.png");
	auto onMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/off.png", "off.png");
	offMusic->setScale(0.5);
	onMusic->setScale(0.5);
	MenuItemToggle* audioMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(SafetyMap::menuAudioCallBack, this),
		offMusic, onMusic, NULL
	);
	audioMenu->setPosition(Vec2(visibleSize.width / 6 * 5 + 30, visibleSize.height - 180));


	Menu* mu = Menu::create(testManMenu,menuMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);


	return true;
}

void SafetyMap::initMapLayer()
{

	auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ÿ�������ĳ��������꣬�ڴ������λ��ʱ��ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�
 
	_map = CCTMXTiledMap::create("ArtDesigning/SceneAndMap/SafetyMap/SafetyMap.tmx");
	auto size = _map->getBoundingBox().size;
    _map->setAnchorPoint(Vec2(0.5, 0.5));
    _map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	
	 addChild(_map, 0, 10000);//
}

void SafetyMap::menuMenuCallBack(cocos2d::Ref* pSender)
{
	//ת���˵���(�ɷ���)
	auto nextScene = MenuScene::create();
	Director::getInstance()->pushScene(nextScene);
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch Menu Menu Item %p", item);
}

void SafetyMap::initDiamond() 
{
	auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ÿ�������ĳ��������꣬�ڴ������λ��ʱ��ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�

}

void SafetyMap::menuTestManCallBack(cocos2d::Ref* pSender)
{
	//ת��testmanSelect
	auto nextScene = testmanSelect::create();
	Director::getInstance()->pushScene(nextScene);
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch testmanSelect Menu Item %p", item);
}

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

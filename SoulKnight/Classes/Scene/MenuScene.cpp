#include "MenuScene.h"
#include "StartGameScene.h"
#include "SimpleAudioEngine.h" 
#include "cocos2d.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
	return MenuScene::create();
}
//������ʾ
// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelpScene.cpp\n");
}

bool MenuScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ÿ�������ĳ��������꣬�ڴ������λ��ʱ��ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�

	//menu
	MenuItemImage* exitMenu = MenuItemImage::create(
		"ArtDesigning/SceneAndMap/StartGame/EXIT.png",
		"ArtDesigning/SceneAndMap/StartGame/EXITchosen.png",
		CC_CALLBACK_1(MenuScene::menuExitCallBack, this)
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

	MenuItemImage* cancelMenu = MenuItemImage::create(
		"ArtDesigning/Word&Others/button/CANCEL.png",
		"ArtDesigning/Word&Others/button/CANCEL.png",
		CC_CALLBACK_1(MenuScene::menuCancelCallBack, this)
	);

	if (cancelMenu == nullptr ||
		cancelMenu->getContentSize().width <= 0 ||
		cancelMenu->getContentSize().height <= 0)
	{
		problemLoading("'cancelMenu.png'");
	}
	else
	{
		float x = visibleSize.width / 2;
		float y = visibleSize.height - 550;
		cancelMenu->setPosition(Vec2(x, y));
	}



	auto offMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/on.png", "on.png");
	auto onMusic = MenuItemImage::create("ArtDesigning/SceneAndMap/StartGame/off.png", "off.png");
	MenuItemToggle* audioMenu = MenuItemToggle::createWithCallback(
		CC_CALLBACK_1(MenuScene::menuAudioCallBack, this),
		offMusic, onMusic, NULL
	);
	audioMenu->setPosition(Vec2(visibleSize.width / 4*3, visibleSize.height - 550));


	Menu* mu = Menu::create(exitMenu, audioMenu, cancelMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	//background
	auto background = Sprite::create("ArtDesigning/SceneAndMap/StartGame/Setting.png");
	if (background == nullptr)

	{
		problemLoading("'Setting.png'");
	}
	else
	{
		background->setAnchorPoint(Vec2(0.5, 0.5));
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	return true;
}
void MenuScene::menuExitCallBack(cocos2d::Ref* pSender)
{
	//ת��start��ͼ
	auto nextScene = StartGame::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem* item = static_cast<MenuItem*>(pSender);


	log("Touch Exit Menu Item %p", item);
}
void MenuScene::menuCancelCallBack(cocos2d::Ref* pSender)
{
	//������һ����
	Director::getInstance()->popScene();
	MenuItem* item = static_cast<MenuItem*>(pSender);

	log("Touch Cancel Menu Item %p", item);
}
void MenuScene::menuAudioCallBack(cocos2d::Ref* pSender)
{
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	if (audio->isBackgroundMusicPlaying()) {
		audio->pauseBackgroundMusic();
	}
	else {
		audio->resumeBackgroundMusic();
	}
}

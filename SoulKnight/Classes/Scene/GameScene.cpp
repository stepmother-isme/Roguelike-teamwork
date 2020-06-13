#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Controller/MoveCtrl.h"
#include "cocos2d.h"
//#include "Const/MapInfo.h"
#include"MovingActor/Knight.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	return GameScene::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in GameSceneScene.cpp\n");

}


bool GameScene::init()
{
	if (!Scene::init())
	{
		return false;

	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	loadingAnimation();
	initMapLayer();

	initFighter();
	initListener();
	scheduleUpdate();

	auto rocker = MoveController::createMoveController();
	this->addChild(rocker);
	_rocker = rocker;



	

	/*��������
	for (int i = 0; i < 4; i++)
	{
		auto soldier = Soldier::create(EAttackMode::REMOTE, ECamp::BLUE, ERoad::MIDWAY, this);
		_map->addChild(soldier);
		soldier->setPosition(200, 200 + rand() % 100 * 10);
		soldier->setScale(0.3);
		_soldiers.pushBack(soldier);
	}*/




	return true;
}

// https://blog.csdn.net/oyangyufu/article/details/26468973
void GameScene::setViewpointCenter(Vec2 position)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	float x = MAX(position.x, visibleSize.width / 2);
	float y = MAX(position.y, visibleSize.height / 2);
	x = MIN(x, (_map->getMapSize().width * _map->getTileSize().width) - visibleSize.width / 2);
	y = MIN(y, (_map->getMapSize().height * _map->getTileSize().height) - visibleSize.height / 2);
	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);//��Ļ���ĵ�
	Vec2 pointB = Vec2(x, y);//ʹ���鴦����Ļ���ģ��ƶ���ͼĿ��λ�ã�
	log("Ŀ��λ��(%f,%f)", pointB.x, pointB.y);

	//��ͼ�ƶ�ƫ����
	Vec2 offset = pointA - pointB;

	log("offset(%f,%f)", offset.x, offset.y);
	this->setPosition(offset);
}

void GameScene::initMapLayer()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	_map = CCTMXTiledMap::create("ArtDesigning/SceneAndMap/GameMap/GameMap1/GameMap1.tmx");
	auto size = _map->getBoundingBox().size;
	_map->setAnchorPoint(Vec2(0.5, 0.5));
	_map->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	_map->setScale(0.5);

	_collidable = _map->getLayer("collision");
	_collidable->setVisible(false);

	addChild(_map, 0, 10000);//TAG_MAP
}

CCPoint GameScene::tileCoordForPosition(CCPoint position)
{
	int x = position.x / _map->getTileSize().width;
	int y = ((_map->getMapSize().height * _map->getTileSize().height) - position.y) / _map->getTileSize().height;
	return ccp(x, y);
}

//ˢ�µ��ˣ�
void GameScene::generateEnemies(float delta)
{
	
}

//��ʼ������,Ŀǰ�ٽ�ɫ�ࣨ�ڶ��ɫ��ѡ��ǰ���£�
void GameScene::initFighter()
{

	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	//_myHero->setTag(TAG_MYHERO);
	
	//�������
	//addFighter Դ�� https://blog.csdn.net/u010778159/article/details/43956151?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-2
	CCSprite* playerSprite = CCSprite::create("ArtDesigning/Sprite/Fighter/downDir.png");
	fighter = Knight::create(this, "Ranger");
	fighter->bindSprite(playerSprite);

	//���ض����
	CCTMXObjectGroup* objGroup = _map->objectGroupNamed("objects");
	//��������������
	ValueMap  playerPointDic = objGroup->objectNamed("SpawnPoint");
	float playerX = playerPointDic.at("x").asFloat();
	float playerY = playerPointDic.at("y").asFloat();
	CCLOG("sprite postion x: %f, %f", playerX, playerY);
	fighter->setPosition(ccp(playerX, playerY));
	_map->addChild(fighter, 1);
	_myFighter = fighter;

}

void GameScene::initListener()
{
	//�������̼�����
	listenerKeyBoard = EventListenerKeyboard::create();
	//�󶨼����¼�
	listenerKeyBoard->onKeyPressed = CC_CALLBACK_2(GameScene::onPressKey, this);
	listenerKeyBoard->onKeyReleased = CC_CALLBACK_2(GameScene::onReleaseKey, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyBoard, this);
}

//���ض�����һ������״��
void GameScene::loadingAnimation()
{
	
}

//��������λ��
void GameScene::updateFighterPosition()
{
	auto nowTime = GetCurrentTime() / 1000.f;
	if (!_myFighter->getAlreadyDead())
	{
		_myFighter->setFDirection(_rocker->getFirstDirection());
		_myFighter->setLDriection(_rocker->getLastDirection());
		_myFighter->setDirection(_rocker->getDirection());	
	}
	auto newPosition = _myFighter->updateDestination();
	//��ײ���
	/*int tileGid = _collidable->getTileGIDAt(newPosition);//�����Ƭ��GID
	if (tileGid > 0) 
	{
		Value prop = _map->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();

		std::string collision = propValueMap["Collidable"].asString();

		if (collision == "true")
		{
			return;
		}
	}*/
	_myFighter->fighterMove(newPosition);
	_myFighter->stand();
}

void GameScene::updateFlyingItem()
{
	for (auto current = flyingItem.begin(); current != flyingItem.end();)
	{
		(*current)->fly();
		current++;
	}
}

//֡����
void GameScene::update(float delta)
{
	updateFighterPosition();
	updateFlyingItem();



	/*�ӵ������ж�
	for (auto it = _bullets.begin(); it != _bullets.end();)
	{
		if (!(*it)->getTarget()->getAlreadyDead())
		{
			if ((*it)->calculateDistance() < (*it)->getTarget()->getBoundingBox().size.height / 2)
			{
				auto target = (*it)->getTarget();
				target->takeDamage((*it)->getDamage(), (*it)->getFromActor());
				removeChild(*it);
				it = _bullets.erase(it);
			}
			else
			{
				(*it)->calculatePosition();
				++it;
			}
		}
		else
		{
			removeChild(*it);
			it = _bullets.erase(it);
		}
	}*/

	/*���������ж�
	for (auto it = _enemies.begin(); it != _enemies.end(); ++it)
	{
		if ((*it)->getAlreadyDead())
		{
			(*it)->setVisible(false);
		}
	}*/
}

void GameScene::updateEnemiesAttackTarget()
{



}

//������Χ
void GameScene::CircleDamage(Point point, float radius, float damage)
{

}


bool GameScene::onPressKey(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto test = dynamic_cast<Knight*>(_myFighter);
	if (keyCode == EventKeyboard::KeyCode::KEY_J)
	{
		test->attack();
	}
	keys[keyCode] = true;
	return true;
}


bool GameScene::onReleaseKey(EventKeyboard::KeyCode keyCode, Event* event)
{
	//keys[keyCode] = false;
	return true;
}


bool GameScene::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}
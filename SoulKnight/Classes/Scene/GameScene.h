#ifndef __GameScene_SCENE_H__
#define __GameScene_SCENE_H__

#include "cocos2d.h"
#include "MovingActor/Fighter.h"
#include "MovingActor/MovingActor.h"
#include "MovingActor/Bullet.h"
#include "Controller/MoveCtrl.h"
#include <vector>

USING_NS_CC;

class Record;
class MovingActor;

class GameScene : public cocos2d::Scene
{

	/*
	CC_SYNTHESIZE(varType, varName, funName)�����������
	�������varName��������ΪvarType����������get/set�������ֱ�Ϊ��
		getfunName() �� setfunName(varType var) ��
	*/

	//CC_SYNTHESIZE(Vector<Projectile*>, _bullets, Bullets);      �ӵ�
	//CC_SYNTHESIZE(std::vector<Damage>, _damages, AllDamages);   �˺�
	CC_SYNTHESIZE(Record*, _labelRecord, LabelRecord);
	CC_SYNTHESIZE(Fighter*, _myFighter, MyFighter);
	CC_SYNTHESIZE(MoveController*, _rocker, Rocker);
	CC_SYNTHESIZE(Size, _visibleSize, VisibleSize);
	CC_SYNTHESIZE(Vec2, _origin, Origin);
	CC_SYNTHESIZE(TMXTiledMap*, _map, Map);
	//CC_SYNTHESIZE(MapInfo, _mapInformation, MapInformation);
	cocos2d::TMXLayer* _collidable;
	Fighter* fighter;
private:
	//��ʼ��
	void generateEnemies(float delta);
	void initMapLayer();
	void initFighter();
	void initListener();
	//���½�ɫλ��
	void updateFighterPosition();
	void updateFlyingItem();

	//���¹���Ŀ��
	void updateEnemiesAttackTarget();

	//������
	EventListenerTouchOneByOne* listenerTouch;
	EventListenerKeyboard* listenerKeyBoard;

	//�����¼�
	virtual bool onPressKey(EventKeyboard::KeyCode keyCode, Event* event);
	virtual bool onReleaseKey(EventKeyboard::KeyCode keyCode, Event* event);

	//�ж��Ƿ�һֱ����ס
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	bool isKeyPressed(EventKeyboard::KeyCode keyCode);
	
	void setViewpointCenter(Vec2);
	cocos2d::Vec2 tileCoordForPosition(cocos2d::Vec2 position);


public:
	//���Թ���ʹ�õ�һЩ����
	Vector<MovingActor*> enemySoldier;
	Vector<MovingActor*> enemyBoss;
	Vector<MovingActor*> allFighter;
	Vector<Equipment*>allWeapon;
	Vector<Bullet*> flyingItem;
	//Vector<UnMovingActor*> allNpc;


	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void loadingAnimation();
	virtual void update(float delta);
	void CircleDamage(Point point, float radius, float damage);
	
	CREATE_FUNC(GameScene);
};



#endif 
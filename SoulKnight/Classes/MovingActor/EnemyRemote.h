#pragma once
#ifndef __ENEMYREMOTE_H__
#define __ENEMYREMOTE_H__

#include"cocos2d.h"
#include"Enemy.h"
#include"Fighter.h"
#include"Constant.h"

USING_NS_CC;

class GameScene;

class EnemyRemote :public Enemy
{
	CC_SYNTHESIZE(float, lastAttackTime, LastAttackTime);




public:


	virtual bool attack();   //�����������д��ڶ���,�˴�ΪԶ�̹���

	static EnemyRemote* create(GameScene* Scene, std::string enemyName);
	bool init(GameScene* Scene, std::string enemyName);
	bool initData(GameScene* Scene, std::string enemyName);

	//�����Ⱦ��廯���常������걸



};






#endif // !__ENEMYREMOTE_H__

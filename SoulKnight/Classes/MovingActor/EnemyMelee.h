#pragma once
#ifndef __ENEMYMELEE_H__
#define __ENEMYMELEE_H__

#include"cocos2d.h"
#include"Enemy.h"
#include"Fighter.h"
#include"Constant.h"

USING_NS_CC;

class GameScene;

class EnemyMelee :public Enemy
{
	CC_SYNTHESIZE(float, lastAttackTime, LastAttackTime);




public:


	virtual bool attack();   //�����������д��ڶ��壬�˴�Ϊ��ս���������ӵ�����

	static EnemyMelee* create(GameScene* Scene, std::string enemyName);
	bool init(GameScene* Scene, std::string enemyName);
	bool initData(GameScene* Scene, std::string enemyName);

	//��buffЧ�����Ű�
	



};






#endif // !__ENEMYMELEE_H__

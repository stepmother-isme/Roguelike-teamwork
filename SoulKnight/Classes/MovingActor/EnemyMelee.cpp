#include"EnemyMelee.h"
#include "GameScene.h"
#include"Fighter.h"
EnemyMelee* EnemyMelee::create(GameScene* Scene, std::string enemyName)
{


	EnemyMelee* enemyMelee = new EnemyMelee();
	if (enemyMelee && enemyMelee->init( Scene,  enemyName))
	{
		enemyMelee->autorelease();
		return enemyMelee;
	}
	CC_SAFE_DELETE(enemyMelee);
	return nullptr;
}

bool EnemyMelee::init(GameScene* Scene, std::string enemyName)
{
	if (!Enemy::init(Scene, enemyName))
	{
		return false;
	}

	initData(Scene, enemyName);
	return true;
}

bool EnemyMelee::initData(GameScene* Scene, std::string enemyName)
{
	enemyName = enemyName;

	attackSpeed = 1.0f;
	hitPoints = 50;
	curHitPoints = hitPoints;    //���ݾ��廯��������plist

	damageAbility = 1;
	moveSpeed = 2;
	identityRadius = 400;

	alreadyDead = false;

	lastAttackTime = 0.f;
	return false;
}



bool  EnemyMelee::attack()
{
	auto nowTime = GetCurrentTime() / 1000.f;

	if (attackTarget)
	{
		//�������֮��������Χ���ڣ��򴥷������������б���Ҫ����һ�ι�����ʱ����֮��
		if (nowTime - lastAttackTime > (1.0f / attackSpeed))
		{
			if ((Fighter*)attackTarget/*->curHitPoints*/)//���Fighter���˺��������Ƿ��л����жϵ�Ѫ.�˴�attackTarget����fighter��ģ�����ǿת������������
			{
			}

		}

	}
	return true;
	
}
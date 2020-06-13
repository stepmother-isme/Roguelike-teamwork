#include"MovingActor/Enemy.h"
#include"MovingActor/Constant.h"
#include"MovingActor/Bullet.h"
#include"Scene/GameScene.h"
#include<random>

Enemy*Enemy::create(GameScene* Scene,std::string Name)
{
	Enemy* enemy = new Enemy();
	if (enemy && enemy->init(Scene, Name));
	{
		enemy->autorelease();
		return enemy;
	}

	CC_SAFE_DELETE(enemy);
	return nullptr;
}

bool Enemy::init(GameScene* Scene, std::string Name)
{
	if (!Sprite::init())
		return false;

	initData(Scene,Name);
	return true;
}

bool Enemy::initData(GameScene* Scene, std::string Name)
{
	exploreScene = Scene;
	enemyName = Name;
	camp = AllCamp::ENEMY;
	

	alreadyDead = false;
	attackSpeed = 0.f;

	curHitPoints = hitPoints;
	attackRadius = 500;
	return true;
}

void  Enemy::updateTarget()
{
	MovingActor* tempTarget = NULL;
	Vector<MovingActor*>& allFighter = exploreScene->allFighter;

	//�Ȱ���ֻ��һ����Ҵ���
	auto temp = allFighter.begin();
	auto tempRadius = identityRadius;


	if (!(*temp)->getAlreadyDead() && tempRadius > (*temp)->getPosition().getDistance(this->getPosition()))
		tempTarget = *temp;


	attackTarget = tempTarget;
}

void Enemy::updateDestination()
{
	Vec2 tempDes;
	if (!attackTarget)
	{
		float tempX, tempY;

		tempX = random(-200, 200) / moveSpeed;
		tempY = random(-200, 200) / moveSpeed;

		if (tempY >= 0)
			fDirecition = EDirection::RIGHT;
		else
			fDirecition = EDirection::LEFT;

		tempDes.x = getPosition().x + tempX;
		tempDes.y = getPosition().y + tempY;
	}
	else
	{
		if (attackTarget->getPosition().getDistance(this->getPosition()) > attackRadius)
		{
			tempDes = attackTarget->getPosition();
		}
	}
	destination = tempDes;
}

void Enemy::enemyMove()
{
	updateDestination();
	setPosition(destination);
}

bool Enemy::attack()
{

	if (attackTarget)
	{
		auto bulletSprite = Bullet::create(CCString::createWithFormat("%sBullet",enemyName)->getCString(), damageAbility, flySpeed, this, attackTarget);
		
		//�Է�����ĵ���
		bulletSprite->setPosition(this->getPosition());
		//bulletSprite->setScale();
		
		//����������볡��������֮��
		exploreScene->getMap()->addChild(bulletSprite);
		exploreScene->flyingItem.pushBack(bulletSprite);
		
		return true;
	}
	return true;
}

void Enemy::die()
{
	setVisible(false);
	alreadyDead = true;
}
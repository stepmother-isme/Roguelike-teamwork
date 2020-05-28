#include"MovingActor/Bullet.h"
#include"MovingActor/MovingActor.h"

#define PI 3.14

Bullet* Bullet::create(const std::string& filename, INT32 damage, float flySpeed, MovingActor* owner, MovingActor* victim)
{
	Bullet* bullet = new Bullet;
	if (bullet && bullet->init(filename, damage, flySpeed, owner, victim))
	{
		bullet->autorelease();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return NULL;
}

bool Bullet::init(const std::string& filename, INT32 damage, float flySpeed, MovingActor* owner, MovingActor* victim)
{
	if (!Sprite::init())
		return false;

	setTexture(filename);
	setPosition(owner->getPosition());
	//setScale();

	_damage = damage;
	_flySpeed = flySpeed;
	_owner = owner;
	_victim = victim;

	return true;
}
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

void Bullet::giveOut()
{
	auto velocityVector = _victim->getPosition() - getPosition();
	setRotation(acos(velocityVector.x/velocityVector.getLength())/M_PI*180);
}

void Bullet::giveOut(EDirection Dir)
{
	int sita;

	switch (Dir)
	{
	case EDirection::RIGHT:
		sita = 0;
		break;
	case EDirection::UPRIGHT:
		sita = 1;
		break;
	case EDirection::UP:
		sita = 2;
		break;
	case EDirection::UPLEFT:
		sita = 3;
		break;
	case EDirection::LEFT:
		sita = 4;
		break;
	case EDirection::DOWNLEFT:
		sita = 5;
		break;
	case EDirection::DOWN:
		sita = 6;
		break;
	case EDirection::DOWNRIGHT:
		sita = 7;
		break;
	default:
		break;
	}
	
	setRotation(sita / 4 * 180);
}

void Bullet::fly()
{
	auto velocityVector = _victim->getPosition() - getPosition();
	
	auto velocityX = velocityVector.x / velocityVector.getLength() * getFlySpeed();
	auto velocityY = velocityVector.y / velocityVector.getLength() * getFlySpeed();

	setPosition(getPosition()+Vec2(velocityX,velocityY));
}
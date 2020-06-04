#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "cocos2d.h"
#include "Fighter.h"


USING_NS_CC;

class HelloWorld;

class Knight :public Fighter
{
	

	//Crit rate
public:

	void setPosition(const cocos2d::Vec2& newPosition);//放置角色初始位置

	virtual bool isAlreadyDead();  //添加父类后继承用于判断是否GG

	virtual bool init(GameScene* Scene, std::string Name);

	static Knight* create(GameScene* Scene,std::string Name);

	virtual void releaseSkill();               //发起技能


	 //没搞武器暂时不写
	//virtual bool attack();  

	//virtual void getEquip(Equipment* equip);                  //手持两把武器，主武/副武的切换

	//virtual void changeEquip(Equipment* equip);

	//virtual void fighterMove();

	//virtual void stopMove();

	//virtual void playAttackAnimation();
};


#endif //!__KNIGHT_H__
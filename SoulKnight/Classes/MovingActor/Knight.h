#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "cocos2d.h"


USING_NS_CC;

class Knight :public cocos2d::Sprite
{
	CC_SYNTHESIZE(INT32, hitPoints, HitPoints);    //生命值
	CC_SYNTHESIZE(INT32, manaPoints, ManaPoints);  //法力值
	CC_SYNTHESIZE(INT32, shield, Shield);		   //护甲值	
	CC_SYNTHESIZE(float, critRate, CritRate);	   //暴击率
	CC_SYNTHESIZE(float, lastSkillTime, LastSkillTime); //技能持续时间

	//Crit rate
public:

	void setPosition(const cocos2d::Vec2& newPosition);//放置角色初始位置
	static Knight* createWithSpriteFrameName(const char* spriteFrameName);
	virtual bool init();//可能需要添加的Scene参数
	virtual bool isAlreadyDead();  //添加父类后继承用于判断是否GG

	 //没搞武器暂时不写
	//virtual bool attack();  

	//virtual void getEquip(Equipment* equip);                  //手持两把武器，主武/副武的切换

	//virtual void changeEquip(Equipment* equip);

	//virtual void fighterMove();

	//virtual void stopMove();

	//virtual void playAttackAnimation();
};


#endif //!__KNIGHT_H__
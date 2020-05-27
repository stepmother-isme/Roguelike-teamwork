#pragma once
#ifndef __FIGHTER_H__
#define __FIGHTER_H__
#include "cocos2d.h"
#include "MovingActor/MovingActor.h"

USING_NS_CC;

class Equipment;

class Fighter :public MovingActor
{
	CC_SYNTHESIZE(EAttackMode, attackMode, AttackMode);//设置攻击模式的切换 近战/远程
	CC_SYNTHESIZE(EDirection, direction, Direction);//人物的移动方向
	CC_SYNTHESIZE(EDirection, fdirection, FDirection);//人物的面向

	CC_SYNTHESIZE(int, shield, Shield);                //护甲值上限
	CC_SYNTHESIZE(int, curShield, CurShield);		   //当前护甲值
	CC_SYNTHESIZE(float, acRcoverSpeed, ACRcoverSpeed); //护甲刷新时间
	CC_SYNTHESIZE(float, lastTimeInjured, LastTimeInjured); //最后受到伤害的时间，用于刷新护盾

	CC_SYNTHESIZE(int, manaPoints, ManaPoints);			//法力值上限
	CC_SYNTHESIZE(int, curManaPoints, CurManaPoints);	//当前法力值

	CC_SYNTHESIZE(float, critRate, CritRate);              //暴击率

	CC_SYNTHESIZE(String, fighterName, FighterName);	//获取角色名
	CC_SYNTHESIZE(int, equipNumber, EquipNumber);     //所能携带的武器数量

	//5.27从子类移至父类
	CC_SYNTHESIZE(float, lastSkillTime, LastSkillTime);      //技能持续时间
	CC_SYNTHESIZE(float, skillCDTime, SkillCDTime);			//技能冷却时间

	

public:

	virtual bool isFullEquipments();               //判断是否带满武器

	//Equipment* getEquipByNumber(int equipNumber);  //获得武器

	Equipment* changeMainEquip();  //切换主武器

	virtual bool attack();						  //是否攻击

	//virtual void takeBuff(Buff* buff);			//获得buff  TBD

	virtual void releaseSkill();               //发起技能

	virtual void fighterMove();               //发起移动

	virtual bool isInMelee();                  //是否在近战范围

	virtual bool init(HelloWorld* Scene, std::string fighterName);

	static Fighter* create(HelloWorld* Scene, std::string fighterName);   //Unknown

	virtual void playAttackAnimation();   //？？？ Unknown

	virtual bool isZeroSheild();           //判定护甲值是否为0

protected:


	ValueMap initFighterData;

	Equipment* equips[INIT_EQUIP_NUMBER];  //武器栏初始化

	virtual void die();                  //角色死亡时进行的操作

	//virtual void removeAllBuff();			

	//virtual void removeBuff(Buff* buff);

	//virtual void updateDirection();
	//※※此处参照学长所做修正方向的函数，如有需要待定义，待编写

	virtual bool initHeroData(HelloWorld* Scene, std::string fighterName);
};



#endif // !__FIGHTER_H__

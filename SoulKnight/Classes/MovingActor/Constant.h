#pragma once
#ifndef __CONSTANT_H_
#define __CONSTANT_H_

#include"cocos2d.h"

#define INIT_HITPOINTS 5			//初始化生命值
#define INIT_SHIELD 5				//初始化护盾值
#define INIT_MANAPOINTS 180			//初始化法力值

#define SHIELD_RECOVER_TIME 1.0f     //主角护盾击破后刷新时间初始化1.0f
#define INIT_ID_RADIUS 500        //移动角色的感应半径，探知范围内是否有其他移动物体  
#define MELEE_RADUIS 50    //无近武时的近战半径
/* 
*没有具体测量，暂时设置500  
*/
#define INIT_MOVESPEED 1.0
#define INIT_EQUIP_NUMBER 2

enum EAttackMode	//	攻击模式,可以是武器的攻击模式，也可是怪物的攻击模式
{
	MELEE,			//	近战
	REMOTE,			//	远程
	MIX				//  混合
};
enum DamageMode      //伤害类型	
{
	//瞬时伤害
	//持续伤害
};

enum AllCamp        //阵营
{
	FRIENDLY,
	ENEMY
};
//可能会定义的
enum EEQUIPMENT
{
	POJIUDESHOUQIANG,
	AK47,
	GANCAOCHA,
	NOTHING
	//TBD
};

//可能会定义的方向枚举类型
enum EDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT,
	NODIR
};

enum keyPress
{
	PRESS,
	RELEASE
};


//可能会






#endif //!__CONSTANT_H_
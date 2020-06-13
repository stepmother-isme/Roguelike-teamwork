#pragma once
#ifndef __CONSTANT_H_
#define __CONSTANT_H_

#include"cocos2d.h"

#define INIT_HITPOINTS 5			//��ʼ������ֵ
#define INIT_SHIELD 5				//��ʼ������ֵ
#define INIT_MANAPOINTS 180			//��ʼ������ֵ

#define SHIELD_RECOVER_TIME 1.0f     //���ǻ��ܻ��ƺ�ˢ��ʱ���ʼ��1.0f
#define INIT_ID_RADIUS 500        //�ƶ���ɫ�ĸ�Ӧ�뾶��֪̽��Χ���Ƿ��������ƶ�����  
#define MELEE_RADUIS 50    //�޽���ʱ�Ľ�ս�뾶
/* 
*û�о����������ʱ����500  
*/
#define INIT_MOVESPEED 3.0
#define INIT_EQUIP_NUMBER 2


enum EAttackMode	//	����ģʽ,�����������Ĺ���ģʽ��Ҳ���ǹ���Ĺ���ģʽ
{
	MELEE,			//	��ս
	REMOTE,			//	Զ��
	MIX				//  ���
};

enum WeaponStatus
{
	GROUND,
	TAKEN
};

enum EnemyLevel
{
	SOLDIER,
	BOSS
};

enum DamageMode      //�˺�����	
{
	POISONING,
	COMMON,
};

enum AllCamp        //��Ӫ
{
	FRIENDLY,
	ENEMY
};
//���ܻᶨ���
enum EEQUIPMENT
{
	POJIUDESHOUQIANG,
	AK47,
	GANCAOCHA,
	NOTHING
	//TBD
};

//���ܻᶨ��ķ���ö������
enum EDirection
{
	NODIR,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT
};

enum keyPress
{
	PRESS,
	RELEASE
};


//���ܻ�
typedef std::vector<std::vector<bool>> DyaDicVector;
typedef struct PointINT
{
	INT32 x, y;

	PointINT(INT32 x = 0, INT32 y = 0) :x(x), y(y) {}

	PointINT& operator = (const cocos2d::Vec2& point)
	{
		x = static_cast<INT32>(point.x);
		y = static_cast<INT32>(point.y);
		return *this;
	}


}SizeINT;





#endif //!__CONSTANT_H_
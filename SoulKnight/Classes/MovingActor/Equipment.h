#pragma once
#ifndef __EQUIPMENT_H__
#define __EQUIPMENT_H__
#include<iostream>
#include"cocos2d.h"
#include"Constant.h"

USING_NS_CC;
                                      //���ڲ��ɽ�������⣬������ö������
class Fighter;

class Equipment :public cocos2d::Sprite
{
public:

	CC_SYNTHESIZE(Fighter*, onwer, Onwer);
	CC_SYNTHESIZE(EAttackMode, equipType, EquipType);    //�����������ͣ�Զ��or��ս
	CC_SYNTHESIZE(EEQUIPMENT, equipName, EquipName);	   //��������
	
	CC_SYNTHESIZE(String,weaponName,WeaponName);									//����
	CC_SYNTHESIZE(int, attackNumber, AttackNumber);					 //��������ֵ
	CC_SYNTHESIZE(float, attackSpeedNumber, AttackSpeedNumber);		//�����ٶ���ֵ
	CC_SYNTHESIZE(float, flySpeed, FlySpeed);						//���ӵ��ķ����ٶ�
	CC_SYNTHESIZE(WeaponStatus, status, Status);					//������λ�ã������ϻ����

	//����ǽ�ս��������Ӧ��
	CC_SYNTHESIZE(int, attackRadius, AttackRadius);               //�����뾶
	//�����Զ����������Ӧ�У�Ԫ��ò������Զ���룩������ʧ/����
	CC_SYNTHESIZE(int, manaConsume, ManaConsume);         //����ֵ����

	//TBD
	//�������

	//EQUIPMENT��ʼ�������Ƚ϶࣬Ϊ�˲����ڰѴ��������Ū�죬���»���������
	virtual bool init(EAttackMode _equipType, EEQUIPMENT _equipname, int _attack,
		float _attackSpeed, int _attackRadius,int _manaConsume
	);


	virtual bool init(ValueVector& data, EAttackMode _equipType, EEQUIPMENT _equipname);   //��plist�ļ�ֱ�ӽ��ж���


	static Equipment* create(EAttackMode _equipType, EEQUIPMENT _equipname, int _attack,
		float _attackSpeed, int _attackRadius, int _manaConsume
	);


};






#endif // !__EQUIPMENT_H__

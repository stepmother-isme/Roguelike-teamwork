#pragma once
#ifndef __FIGHTER_H__
#define __FIGHTER_H__
#include "cocos2d.h"
#include "MovingActor/MovingActor.h"
#include "MovingActor/Constant.h"
#include "MovingActor/Enemy.h"
#include "MovingActor/Equipment.h"

USING_NS_CC;


class Fighter :public MovingActor
{
	CC_SYNTHESIZE(EAttackMode, attackMode, AttackMode);//���ù���ģʽ���л� ��ս/Զ��
	CC_SYNTHESIZE(EDirection, direction, Direction);//������ƶ�����
	CC_SYNTHESIZE(EDirection, fdirection, FDirection);//���������
	CC_SYNTHESIZE(EDirection, ldirection, LDriection);//
	CC_SYNTHESIZE(bool, isMoving, IsMoving);

	CC_SYNTHESIZE(int, shield, Shield);                //����ֵ����
	CC_SYNTHESIZE(int, curShield, CurShield);		   //��ǰ����ֵ
	CC_SYNTHESIZE(float, acRcoverSpeed, ACRcoverSpeed); //����ˢ��ʱ��
	CC_SYNTHESIZE(float, lastTimeInjured, LastTimeInjured); //����ܵ��˺���ʱ�䣬����ˢ�»���

	CC_SYNTHESIZE(int, manaPoints, ManaPoints);			//����ֵ����
	CC_SYNTHESIZE(int, curManaPoints, CurManaPoints);	//��ǰ����ֵ

	CC_SYNTHESIZE(float, critRate, CritRate);              //������

	CC_SYNTHESIZE(String, fighterName, FighterName);	//��ȡ��ɫ��
	CC_SYNTHESIZE(int, equipNumber, EquipNumber);     //����Я������������
	CC_SYNTHESIZE(Equipment*, currentWeapon, CurrentWeapon);  //��ǰ����

	//5.27��������������
	CC_SYNTHESIZE(float, lastAttackTime, LastAttackTime);    
	CC_SYNTHESIZE(float,lastReleaseTime,LastReleaseTime);
	CC_SYNTHESIZE(float, lastSkillTime, LastSkillTime);      //���ܳ���ʱ��
	CC_SYNTHESIZE(float, skillCDTime, SkillCDTime);			//������ȴʱ��

	CCSprite *m_sprite;

public:

	Vector<Equipment*> myWeapon;

	virtual bool isFullEquipments();               //�ж��Ƿ��������

	virtual void getWeapon(Equipment* available);  //�������

	Equipment* changeMainEquip();  //�л�������

	virtual bool attack();						  //�Ƿ񹥻�

	//virtual void takeBuff(Buff* buff);			//���buff  TBD

	virtual void releaseSkill();               //������

	virtual void fighterMove(Vec2);               //�����ƶ�

	virtual Vec2 updateDestination();      

	virtual void stand();                     //ֹͣ�ƶ���Ӣ�۵�����

	virtual bool isInMelee();                  //�Ƿ��ڽ�ս��Χ

	virtual bool init(GameScene* Scene, std::string fighterName);

	static Fighter* create(GameScene* Scene, std::string fighterName);   //Unknown

	virtual void playAttackAnimation();   //������ Unknown

	virtual bool isZeroSheild();           //�ж�����ֵ�Ƿ�Ϊ0
	
	virtual void updateTarget();            //ˢ�¹���Ŀ��

	virtual void hurt(INT32 damage);                    //����

	void bindSprite(CCSprite* sprite);
protected:


	ValueMap initFighterData;

	Equipment* equips[INIT_EQUIP_NUMBER];  //��������ʼ��

	virtual void die();                  //��ɫ����ʱ���еĲ���

	//virtual void removeAllBuff();			

	//virtual void removeBuff(Buff* buff);

	//virtual void updateDirection();
	//�����˴�����ѧ��������������ĺ�����������Ҫ�����壬����д

	virtual bool initHeroData(GameScene* Scene, std::string fighterName);
};



#endif // !__FIGHTER_H__

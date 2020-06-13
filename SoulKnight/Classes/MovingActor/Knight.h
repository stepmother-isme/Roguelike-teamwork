#ifndef __KNIGHT_H__
#define __KNIGHT_H__
#include "cocos2d.h"
#include "Fighter.h"
#include"MovingActor/Constant.h"

USING_NS_CC;


class GameScene;

class Knight :public Fighter
{
	
	CC_SYNTHESIZE(bool,isRelease,IsRelease);
	//Crit rate
public:

	virtual bool init(GameScene* Scene, std::string Name);

	static Knight* create(GameScene* Scene,std::string Name);

	virtual void releaseSkill();               //发起技能

	virtual void fullForce();                 //技能

	virtual void stopSkill();

	virtual bool attack();
};


#endif //!__KNIGHT_H__
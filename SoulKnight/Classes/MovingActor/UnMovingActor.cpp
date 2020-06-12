#include"UnMovingActor.h"
//#include"GameScene"


//
//触发条件:
//1.站在一定范围内
//2.click - 次 / 攻击键点击 - 次
//3跳出提示语言(商人 / 雕像 / 贩卖机) / 播放动画(宝箱)
//4.再click - 次 / 攻击键点击 - 次表示确认
//5.播放动画 / 隐藏精灵
//6.获得bufF效果 / 扣除金钱获得武器 / 扣除金钱获得随机道具


UnMovingActor* UnMovingActor::create(const std::string& filename, GameScene* Scene, TOTALNPC NPC, float radius)
{
	UnMovingActor* unmovingactor = new UnMovingActor();
	if (unmovingactor && unmovingactor->init(filename, Scene,NPC,radius))
	{
		unmovingactor->autorelease();
		return unmovingactor;
	}

	CC_SAFE_DELETE(unmovingactor);
	return nullptr;

}

bool UnMovingActor::init(const std::string& filename, GameScene* Scene, TOTALNPC NPC, float radius)
{
	if (!Sprite::init())
	{
		return false;
	}

	npcName = NPC;
	if (NPC == BloodBox|| NPC == ManaBox || NPC == CoinBox)
	{
		isExploreBox == true;
	}
	else { isExploreBox == false; }

	touchRadius = radius;


}

bool UnMovingActor::isInRadius(MovingActor* fighter)  //写距离
{
	//if(){	//if(figher)




	//return true;
 //   }
	//else { return false; }
	return false;
}

String UnMovingActor::talkFirstBack()             //不知道中文能不能使用
{
	switch (npcName)
	{
	case TOTALNPC::Businessman:
		return "万水千山总是情，买个装备行不行";
		
	case TOTALNPC::Statue:
		return "我在佛前苦苦求了几千年，就为了给你加个Buff";

	case TOTALNPC::Vending:
		return "是欧皇就来搞我";
	case TOTALNPC::BloodBox:
		return "(￣▽￣)";
	case TOTALNPC::ManaBox:
		return "(￣▽￣)";
	case TOTALNPC::CoinBox:
		return "(￣▽￣)";
	}
	return "Unknown Wrong";
}

String UnMovingActor::talkSecondBack()        //二次对话，显示需要花的金币以及其他内容,注意此处宝箱应当直接跳过不调用该函数
{
	//待补充
	return "Unknown Wrong";
}



void UnMovingActor::StartAnimation()                  
{

	auto animation = Animation::create();
	//
}

Buff* UnMovingActor::buffBack()
{
	Buff* newbuff;
	switch (npcName)
	{
	case TOTALNPC::BloodBox:
		Buff* newbuff = Buff::create(SPEEDUP, 2, 0, 0.f, 0);
		return newbuff;
	case TOTALNPC::ManaBox:
		Buff* newbuff = Buff::create(SPEEDUP, 0, 60, 0.f, 0);
		return newbuff;
	case TOTALNPC::CoinBox:
		//Buff* newbuff = Buff::create(SPEEDUP, 2, 0, 0.f, 0);
		return newbuff;
	//buff类待添加的东西还很多

	}
}

Equipment* UnMovingActor::equipBack()
{
	return nullptr;
}






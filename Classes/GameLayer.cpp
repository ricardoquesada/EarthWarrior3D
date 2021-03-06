//
//  ScrollingBackground.cpp
//  Moon3d
//
//  Created by Hao Wu on 2/24/14.
//
//

#include "GameLayer.h"
#include "Player.h"
#include "Enemies.h"
#include "PublicApi.h"
#include "GameControllers.h"
#include "consts.h"
#include "Bullets.h"
//#include "EnemyManager.h"
#include "Effects.h"
#include "GameEntity.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace std;

bool GameLayer::init()
{
    // variable init
    //_collisionTree = new QuadTree(0, BOUND_RECT);
    
    
    _spr = Sprite::create("groundLevel.jpg");
    _cloud = Sprite::create("cloud.png");
    addChild(_spr, -2);
    //addChild(_cloud);
    Texture2D::TexParams texRepeat = {GL_LINEAR, GL_LINEAR, GL_CLAMP_TO_EDGE, GL_REPEAT};
    _spr->getTexture()->setTexParameters(texRepeat);
    _cloud->getTexture()->setTexParameters(texRepeat);
    _cloud->setScale(2.8);
    setRotation3D(Vertex3F(-30.0,0.0f,0.0f));
    _spr->setScale(1.4);
    _spr->setPosition(0.0f,400.0f);
    
    _player = Player::create();
    
    _streak = MotionStreak::create(0.4, 1, 15, Color3B(82,255,253), "streak.png");
    _player->setTrail(_streak);
    addChild(_streak,1);
    _emissionPart = ParticleSystemQuad::create("emissionPart.plist");
    _player->setEmissionPart(_emissionPart);
    addChild(_emissionPart,2);
    _emissionPart->setPositionType(tPositionType::FREE);
    addChild(_player,3);
    EffectManager::setLayer(this);
    auto Audio = CocosDenshion::SimpleAudioEngine::getInstance();
    Audio->preloadEffect("explodeEffect.mp3");
    Audio->preloadEffect("hit.mp3");
    Audio->preloadEffect("boom2.mp3");
    // Music By Matthew Pable (http://www.matthewpablo.com/)
    // Licensed under CC-BY 3.0 (http://creativecommons.org/licenses/by/3.0/)
    Audio->playBackgroundMusic("Flux.mp3");

    this->schedule(schedule_selector(GameLayer::gameMaster) , 1.5, -1, 0.0);

    BulletController::init(this);
    EnemyController::init(this);
    scheduleUpdate();
    
    
    _player->setPosition(Point(0,-1000));
    _player->runAction(Sequence::create(
                       Spawn::create(
                                     EaseBackOut::create(MoveTo::create(1.7,Point(0,-200))),
                                     EaseSineOut::create(RotateBy::create(1.7,Vertex3F(0,720,0))),
                                     nullptr
                                     ),
                       CallFunc::create(this,callfunc_selector(GameLayer::schedulePlayer)),nullptr));
    return true;
}

void GameLayer::schedulePlayer()
{
    _player->scheduleUpdate();
}
void GameLayer::gameMaster(float dt)
{
    _elapsed+=dt;
    int enemyCount =EnemyController::enemies.size();
    //if(_elapsed < 10 && enemyCount < 5)
    if(enemyCount < 5)
    {
        Point random = Point(100*CCRANDOM_MINUS1_1(), BOUND_RECT.size.height/2+200);
        for(int i=0; i < 5; i++)
        {
            auto enemy1 = EnemyController::spawnEnemy(kEnemyFodder);
            enemy1->setPosition(random + Point(60,60)*(i+1));
            static_cast<Fodder*>(enemy1)->setMoveMode(moveMode::kDefault);
            auto enemy2 = EnemyController::spawnEnemy(kEnemyFodder);
            enemy2->setPosition(random + Point(-60,60)*(i+1));
            static_cast<Fodder*>(enemy2)->setMoveMode(moveMode::kDefault);
            enemy1->setRotation3D(Vertex3F(0,0,0));
            enemy2->setRotation3D(Vertex3F(0,0,0));
        }
        auto leader = EnemyController::spawnEnemy(kEnemyFodderL);
        leader->setPosition(random);
        leader->setRotation3D(Vertex3F(0,0,0));
        static_cast<FodderLeader*>(leader)->setMoveMode(moveMode::kDefault);
    }
    //else if(_elapsed < 20 && enemyCount <5)
    if(_elapsed > 4 && enemyCount <3)
    {
        Point random = Point(-240-200, BOUND_RECT.size.height/2*CCRANDOM_MINUS1_1());
        for(int i=0; i < 3; i++)
        {
            float randomAngle = CCRANDOM_MINUS1_1()*90;
            auto enemy = EnemyController::spawnEnemy(kEnemyFodder);
            enemy->setPosition(random + Point(60,60)*(i+1));
            static_cast<Fodder*>(enemy)->setTurnRate(randomAngle);
            enemy->setRotation(-randomAngle);
            auto enemy2 = EnemyController::spawnEnemy(kEnemyFodder);
            enemy2->setPosition(random + Point(-60,60)*(i+1));
            static_cast<Fodder*>(enemy2)->setTurnRate(randomAngle);
            enemy2->setRotation(-randomAngle);
        }
        auto leader = EnemyController::spawnEnemy(kEnemyFodderL);
        leader->setPosition(random);
        static_cast<FodderLeader*>(leader)->setTurnRate(45);
        leader->setRotation(-45);
        //enemy->runAction(EaseBackOut::create(MoveTo::create(2, _player->getPosition())));
    }
}

void GameLayer::update(float dt)
{
    xScroll += speed*dt;
    _spr->setTextureRect(Rect(0,((int)xScroll)%2048,512,1200));
    //_cloud->setTextureRect(Rect(0,((int)xScroll)%1024, 256, 1024));
    GameController::update(dt);
}



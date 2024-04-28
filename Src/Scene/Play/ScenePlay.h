#pragma once
#include "../manager/Scene.h"
#include "../../Mapchip/MapChip.h"
#include "../../Screen/Screen.h"
#include "../../Enemy/EnemyBase.h"

class cPlay : public cSceneBase {
private:
	MapChip mapchip;
	Screen screen;
	EnemyBase enemy;
	EnemyBase::Enemy Ground[GROUND_MAX_NUM];
public:
	void Init();
	void Step();
	void Draw();
	void Fin();

	void MapCollision();
	void MapCollisionEnemy();
};
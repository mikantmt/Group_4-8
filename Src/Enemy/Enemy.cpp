#include "EnemyBase.h"

void EnemyBase::Init() {
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].Handle = LoadGraph(EnemyPath[FLY_ENEMY]);

		Fly[FlyIndex].EnemyX = random.ScopingRand(25.0f* (float)MAPCIP_X_SIZE, (float)(MAPCIP_X_MAXNUM * MAPCIP_X_SIZE));
		Fly[FlyIndex].EnemyY = 128;

		Fly[FlyIndex].EnemySaveX = Fly[FlyIndex].EnemyX;
		Fly[FlyIndex].EnemySaveY = Fly[FlyIndex].EnemyY;

		Fly[FlyIndex].IsActive = false;
		Fly[FlyIndex].FlipFlg  = false;
		Fly[FlyIndex].DetecFlg = false;

		Fly[FlyIndex].SetSpace(Fly[FlyIndex].EnemyX);
	}

	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Ground[GroundIndex].Handle = LoadGraph(EnemyPath[GROUND_ENEMY]);

		Ground[GroundIndex].EnemyX = random.ScopingRand(25.0f * (float)MAPCIP_X_SIZE, (float)(MAPCIP_X_MAXNUM * MAPCIP_X_SIZE));
		Ground[GroundIndex].EnemyY = 128;

		Ground[GroundIndex].EnemySaveX = Ground[GroundIndex].EnemyX;
		Ground[GroundIndex].EnemySaveY = Ground[GroundIndex].EnemyY;

		Ground[GroundIndex].FlipFlg = false;
		Ground[GroundIndex].DetecFlg = false;
	}
}

void EnemyBase::Step() {
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].Flip();//”½“]Ø‚è‘Ö‚¦
		if (!Fly[FlyIndex].DetecFlg) {//ƒvƒŒƒCƒ„[‚ð”­Œ©‚µ‚Ä‚¢‚È‚¯‚ê‚Î
			if (Fly[FlyIndex].FlipFlg) {//”½“]‚³‚¹‚é
				Fly[FlyIndex].EnemySaveX--;
			}
			else {
				Fly[FlyIndex].EnemySaveX++;
			}
		}
	}
}

void EnemyBase::Draw(int X) {
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		DrawGraph(Fly[FlyIndex].EnemyX - X, Fly[FlyIndex].EnemyY, Fly[FlyIndex].Handle, true);
	}
}

void EnemyBase::Enemy::SetSaveX(float EnemyX) {
	EnemySaveX = EnemyX;
}

void EnemyBase::Enemy::SetSaveY(float EnemyY) {
	EnemySaveY = EnemyY;
}

void EnemyBase::Enemy::GetMoveDirection(bool* dirArray) {
	if (EnemySaveY < EnemyY) {
		dirArray[0] = true;
	}
	if (EnemySaveY > EnemyY) {
		dirArray[1] = true;
	}
	if (EnemySaveX < EnemyX) {
		dirArray[2] = true;
	}
	if (EnemySaveX > EnemyX) {
		dirArray[3] = true;
	}
}

void EnemyBase::Enemy::SetSpace(float X) {
	SpaceMinX = X - MOVE_RANGE;
	SpaceMaxX = X + MOVE_RANGE;
}

void EnemyBase::Enemy::Flip() {
	if (SpaceMinX > GetPosX()) {
		FlipFlg = false;
	}
	if (SpaceMaxX < GetPosX()) {
		FlipFlg = true;
	}
}

void EnemyBase::Update(){
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].EnemyX = Fly[FlyIndex].EnemySaveX;
		Fly[FlyIndex].EnemyY = Fly[FlyIndex].EnemySaveY;
	}

	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Fly[GroundIndex].EnemyX = Fly[GroundIndex].EnemySaveX;
		Fly[GroundIndex].EnemyY = Fly[GroundIndex].EnemySaveY;
	}
}
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
		Fly[FlyIndex].PlayerHide = false;
	}

	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Ground[GroundIndex].Handle = LoadGraph(EnemyPath[GROUND_ENEMY]);

		Ground[GroundIndex].EnemyX = random.ScopingRand(10.0f * (float)MAPCIP_X_SIZE, (float)(MAPCIP_X_MAXNUM * MAPCIP_X_SIZE));
		Ground[GroundIndex].EnemyY = 608;

		Ground[GroundIndex].EnemySaveX = Ground[GroundIndex].EnemyX;
		Ground[GroundIndex].EnemySaveY = Ground[GroundIndex].EnemyY;

		Ground[GroundIndex].FlipFlg = false;
		Ground[GroundIndex].DetecFlg = false;

		Ground[GroundIndex].SetSpace(Ground[GroundIndex].EnemyX);
	}
}

void EnemyBase::Step(float X,float Y,bool hide) {

	//空上の敵
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].FlipPlus();//反転切り替え
		Fly[FlyIndex].FindPlayer(X,10);//プレイヤーを探す
		Fly[FlyIndex].GetHide(hide);
		
		if (!Fly[FlyIndex].DetecFlg) {//プレイヤーを発見していなければ
			if (!Fly[FlyIndex].FlipFlg) {//反転させる
				Fly[FlyIndex].EnemySaveX--;
			}
			else {
				Fly[FlyIndex].EnemySaveX++;
			}
		}
		else {//プレイヤーを発見していれば
			if (Fly[FlyIndex].PlayerHide) {//プレイヤーが隠れていれば動かす
				if (Fly[FlyIndex].FlipFlg) {//反転させる
					Fly[FlyIndex].EnemySaveX--;
				}
				else {
					Fly[FlyIndex].EnemySaveX++;
				}
			}
		}
	}

	//陸上の敵
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Ground[GroundIndex].FlipMinus();
		Ground[GroundIndex].FindPlayer(X,7);//プレイヤーを探す
		if (!Ground[GroundIndex].DetecFlg) {//プレイヤーを発見していなければ
			
		}
		else {//発見していれば
			if (!Ground[GroundIndex].FlipFlg) {
				Ground[GroundIndex].EnemySaveX -= 3;
			}
			else
				Ground[GroundIndex].EnemySaveX += 3;
		}
	}
}

void EnemyBase::Draw(int X) {
	//空上
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		DrawGraph(Fly[FlyIndex].EnemyX - X, Fly[FlyIndex].EnemyY, Fly[FlyIndex].Handle, true);
	}
	//陸上
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		DrawGraph(Ground[GroundIndex].EnemyX - X, Ground[GroundIndex].EnemyY, Ground[GroundIndex].Handle, true);
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

void EnemyBase::Enemy::FlipPlus() {
	if (SpaceMinX > GetPosX()) {
		FlipFlg = false;
	}
	if (SpaceMaxX < GetPosX()) {
		FlipFlg = true;
	}
}

void EnemyBase::Enemy::FlipMinus() {
	if (SpaceMinX > GetPosX()) {
		FlipFlg = true;
	}
	if (SpaceMaxX < GetPosX()) {
		FlipFlg = false;
	}
}

void EnemyBase::Enemy::FindPlayer(float X,float Scale) {
	if (EnemyX + MAPCIP_X_SIZE * Scale > X && EnemyX - MAPCIP_X_SIZE * Scale < X) {
		DetecFlg = true;
	}
	else
		DetecFlg = false;
}

void  EnemyBase::Enemy::GetHide(bool hide) {
	PlayerHide = hide;
}

void EnemyBase::Update(){
	for (int FlyIndex = 0; FlyIndex < FLY_MAX_NUM; FlyIndex++) {
		Fly[FlyIndex].EnemyX = Fly[FlyIndex].EnemySaveX;
		Fly[FlyIndex].EnemyY = Fly[FlyIndex].EnemySaveY;
	}

	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {
		Ground[GroundIndex].EnemyX = Ground[GroundIndex].EnemySaveX;
		Ground[GroundIndex].EnemyY = Ground[GroundIndex].EnemySaveY;
	}
}
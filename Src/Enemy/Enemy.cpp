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
		Ground[GroundIndex].EnemyY = 100;

		Ground[GroundIndex].EnemySaveX = Ground[GroundIndex].EnemyX;
		Ground[GroundIndex].EnemySaveY = Ground[GroundIndex].EnemyY;
		Ground[GroundIndex].YSpeed = 0.0f;

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
		Ground[GroundIndex].YSpeed += MOVE_YSPEED;
		Ground[GroundIndex].EnemySaveY += Ground[GroundIndex].YSpeed;
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

void EnemyBase::MapToEnemyY(int X, int Y) {
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {

		bool dirArray[4] = { false,false,false,false };
		Ground[GroundIndex].GetMoveDirection(dirArray);

		// ★ここを考える
		// 矩形の当たり判定用のデータを準備
		// プレイヤーの情報
		float Ax = Ground[GroundIndex].GetPosX();
		float Ay = Ground[GroundIndex].GetPosY();
		float Aw = 32;
		float Ah = 32;

		// オブジェクトの情報
		int Bx = X * MAPCIP_X_SIZE;
		int By = Y * MAPCIP_Y_SIZE;
		int Bw = MAP_SIZE;
		int Bh = MAP_SIZE;

		// ※Y方向のみに移動したと仮定した座標で当たり判定をチェックします
		Ay = Ground[GroundIndex].GetSavePosY();
		Ax = Ground[GroundIndex].GetPosX();

		// 当たっているかチェック
		if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
			// 上方向の修正
			if (dirArray[0]) {
				// ★ここを考える
				// めり込み量を計算する
				float overlap = By + Bh - Ay;
				Ground[GroundIndex].SetSaveY(Ay + overlap);
			}

			// 下方向の修正
			if (dirArray[1]) {
				// ★ここを考える
				// めり込み量を計算する
				float overlap = Ay + Ah - By;
				Ground[GroundIndex].SetSaveY(Ay - overlap);
				Ground[GroundIndex].YSpeed = 0.0f;
			}
		}
	}
}

void EnemyBase::MapToEnemyX(int X, int Y) {
	for (int GroundIndex = 0; GroundIndex < GROUND_MAX_NUM; GroundIndex++) {

		bool dirArray[4] = { false,false,false,false };
		Ground[GroundIndex].GetMoveDirection(dirArray);

		// ★ここを考える
		// 矩形の当たり判定用のデータを準備
		// プレイヤーの情報
		float Ax = Ground[GroundIndex].GetPosX();
		float Ay = Ground[GroundIndex].GetPosY();
		float Aw = 32;
		float Ah = 32;

		// オブジェクトの情報
		int Bx = X * MAPCIP_X_SIZE;
		int By = Y * MAPCIP_Y_SIZE;
		int Bw = MAP_SIZE;
		int Bh = MAP_SIZE;

		// ※Y方向のみに移動したと仮定した座標で当たり判定をチェックします
		Ay = Ground[GroundIndex].GetSavePosY();
		Ax = Ground[GroundIndex].GetSavePosX();

		// 当たっているかチェック
		if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
			// 上方向の修正
			if (dirArray[2]) {
				// ★ここを考える
				// めり込み量を計算する
				float overlap = Bx + Bw - Ax;
				Ground[GroundIndex].SetSaveX(Ax + overlap);
			}

			// 下方向の修正
			if (dirArray[3]) {
				// ★ここを考える
				// めり込み量を計算する
				float overlap = Ax + Aw - Bx;
				Ground[GroundIndex].SetSaveX(Ax - overlap);
			}
		}
	}
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
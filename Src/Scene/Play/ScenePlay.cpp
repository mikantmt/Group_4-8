#include "ScenePlay.h"
//清水
void cPlay::Init()
{
	sound.Init();
	player.Init();
	enemy.Init();
	mapchip.Init();
}

void cPlay::Step()
{
	screen.StepScreen(player.GetPosX(), player.GetPosY());

	player.Step();
	enemy.Step((float)player.GetNextPosX(), (float)player.GetNextPosY());

	MapCollision();

	MapCollisionEnemy();

	enemy.Step((float)player.GetNextPosX(), (float)player.GetNextPosY(), player.IsHide);

	player.UpdatePos();

	enemy.Update();

	GetDeath();

	if(player.ActiveFlg) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
	}
}

void cPlay::Draw()
{
	mapchip.Draw((int)screen.GetScreenX());

	enemy.Draw((int)screen.GetScreenX());

	player.Draw((int)screen.GetScreenX());
}

void cPlay::Fin()
{
	sound.Fin();
	player.Fin();
	
	cScene::SceneID = SCENE_ID::SCENE_ID_RESULT;
}

void cPlay::MapCollision() {
	// Y方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (mapchip.m_FileReadMapData[mapIndexY][mapIndexX] != 0)
				continue;

			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			float Ax = player.GetPosX();
			float Ay = player.GetPosY();
			float Aw = PLAYER_WIDTH;
			float Ah = PLAYER_HEIGHT;

			// オブジェクトの情報
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ※Y方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = (float)player.GetNextPosY();
			Ax = (float)player.GetPosX();

			// 当たっているかチェック
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, (float)Bx, (float)By, (float)Bw, (float)Bh)) {
				// 上方向の修正
				if (dirArray[0]) {
					// ★ここを考える
					// めり込み量を計算する
					float overlap = By + Bh - Ay;
					player.SetNextPosY((int)(Ay + overlap));
				}

				// 下方向の修正
				if (dirArray[1]) {
					// ★ここを考える
					// めり込み量を計算する
					float overlap = Ay + Ah - By;
					player.SetNextPosY((int)(Ay - overlap));
					player.Yspeed = 0.0f;
				}
			}
		}
	}

	// X方向のみ当たり判定をチェックする
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (mapchip.m_FileReadMapData[mapIndexY][mapIndexX] != 0)
				continue;

			// ★ここを考える
			// どの方向に進んでいたかチェック
			// ※Playerクラスに進む方向をチェックする関数を準備しています。
			bool dirArray[4] = { false,false,false,false };
			player.GetMoveDirection(dirArray);

			// ★ここを考える
			// 矩形の当たり判定用のデータを準備
			// プレイヤーの情報
			float Ax = player.GetPosX();
			float Ay = player.GetPosY();
			float Aw = PLAYER_WIDTH;
			float Ah = PLAYER_HEIGHT;

			// オブジェクトの情報
			int Bx = mapIndexX * MAPCIP_X_SIZE;
			int By = mapIndexY * MAPCIP_Y_SIZE;
			int Bw = MAP_SIZE;
			int Bh = MAP_SIZE;

			// ※X方向のみに移動したと仮定した座標で当たり判定をチェックします
			Ay = (float)player.GetNextPosY();
			Ax = (float)player.GetNextPosX();

			// 当たっているかチェック
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, (float)Bx, (float)By, (float)Bw, (float)Bh)) {
				if (!dirArray[3]) {
					// 左方向の修正
					if (dirArray[2]) {
						player.IsHide = true;

						// ★ここを考える
						// めり込み量を計算する
						float overlap = Bx + Bw - Ax;
						player.SetNextPosX((int)(Ax + overlap));
					}
					else {
						player.IsHide = false;
					}
				}
				if (!dirArray[2]) {
					// 右方向の修正
					if (dirArray[3]) {
						player.IsHide = true;

						// ★ここを考える
						// めり込み量を計算する
						float overlap = Ax + Aw - Bx;
						player.SetNextPosX((int)(Ax - overlap));
					}
					else {
						player.IsHide = false;
					}
				}
			}
		}
	}

	//とげと灰色箱の当たり判定
	for (int mapIndexY = 0; mapIndexY < MAPCIP_Y_MAXNUM; mapIndexY++)
	{
		for (int mapIndexX = 0; mapIndexX < MAPCIP_X_MAXNUM; mapIndexX++)
		{
			if (mapchip.m_FileReadMapData[mapIndexY][mapIndexX] == 3)
			{
				int Bx = mapIndexX * MAPCIP_X_SIZE;
				int By = mapIndexY * MAPCIP_Y_SIZE;
				int Bw = MAP_SIZE;
				int Bh = MAP_SIZE;

				if (collision.IsHitRect((float)player.GetNextPosX(), (float)player.GetNextPosY(), (float)PLAYER_WIDTH, (float)PLAYER_HEIGHT, (float)Bx, (float)By, (float)Bw, (float)Bh)) {
					player.ActiveFlg = true;
				}
			}

			if (mapchip.m_FileReadMapData[mapIndexY][mapIndexX] == 2)
			{
				int Bx = mapIndexX * MAPCIP_X_SIZE;
				int By = mapIndexY * MAPCIP_Y_SIZE;
				int Bw = MAP_SIZE;
				int Bh = MAP_SIZE;

				if (collision.IsHitRect((float)player.GetNextPosX(), (float)player.GetNextPosY(), (float)PLAYER_WIDTH, (float)PLAYER_HEIGHT, (float)Bx, (float)By + 16, (float)Bw, (float)Bh)) {
					player.ActiveFlg = true;
				}
			}

			if (mapchip.m_FileReadMapData[mapIndexY][mapIndexX] == 1) {
				int Bx = mapIndexX * MAPCIP_X_SIZE;
				int By = mapIndexY * MAPCIP_Y_SIZE;
				int Bw = MAP_SIZE;
				int Bh = MAP_SIZE;

				if (collision.IsHitRect((float)player.GetNextPosX(), (float)player.GetNextPosY(), (float)PLAYER_WIDTH, (float)PLAYER_HEIGHT, (float)Bx, (float)By, (float)Bw, (float)Bh)) {
					cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
				}
			}
		}
	}

	/*Time++;
	if (Time > 60.0f) {
		Time = 0.0f;
		for (int MapChipYIndex = 0; MapChipYIndex < MAPCIP_Y_MAXNUM; MapChipYIndex++) {
			for (int MapChipXIndex = 0; MapChipXIndex < MAPCIP_X_MAXNUM; MapChipXIndex++) {
				if (mapchip.m_FileReadMapData[MapChipYIndex][MapChipXIndex] == 2) {
					mapchip.m_FileReadMapData[MapChipYIndex][MapChipXIndex] = -1;
				}
			}
		}
		
	}*/
}

void cPlay::MapCollisionEnemy() {
	for (int MapChipYIndex = 0; MapChipYIndex < MAPCIP_Y_MAXNUM; MapChipYIndex++) {
		for (int MapChipXIndex = 0; MapChipXIndex < MAPCIP_X_MAXNUM; MapChipXIndex++) {
			if (mapchip.m_FileReadMapData[MapChipYIndex][MapChipXIndex] == -1) 
				continue;
			enemy.MapToEnemyY(MapChipXIndex, MapChipYIndex);
			enemy.MapCollision(MapChipXIndex, MapChipYIndex);
		}
	}

	for (int MapChipYIndex = 0; MapChipYIndex < MAPCIP_Y_MAXNUM; MapChipYIndex++) {
		for (int MapChipXIndex = 0; MapChipXIndex < MAPCIP_X_MAXNUM; MapChipXIndex++) {
			if (mapchip.m_FileReadMapData[MapChipYIndex][MapChipXIndex] == -1)
				continue;
			enemy.MapToEnemyX(MapChipXIndex, MapChipYIndex);
		}
	}
}

void cPlay::GetDeath() {
	if (enemy.PlayerDeath) {
		player.ActiveFlg = true;
	}
}
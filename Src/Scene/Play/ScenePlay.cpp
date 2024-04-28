#include "ScenePlay.h"

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
	enemy.Step(player.GetNextPosX(), player.GetNextPosY(), player.IsHide);

	MapCollision();

	MapCollisionEnemy();

	

	player.UpdatePos();

	enemy.Update();

	if(player.ActiveFlg) {
		cScene::SceneTypeID = SCENE_TYPE::TYPE_ID_FIN;
	}
}

void cPlay::Draw()
{
	mapchip.Draw(screen.GetScreenX());

	DrawFormatString(MID_SCREEN_X, MID_SCREEN_Y, GetColor(0, 255, 255), "プレイ");

	if (player.IsHide) {
		DrawFormatString(0, 0, GetColor(255, 0, 0), "隠れている");
	}
	else
		DrawFormatString(0, 0, GetColor(255, 0, 0), "隠れていない");

	/*DrawFormatString(0, 16, GetColor(0, 255, 255), "%d",player.GetNextPosY());*/



	enemy.Draw(screen.GetScreenX());

	player.Draw(screen.GetScreenX());
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
			Ay = player.GetNextPosY();
			Ax = player.GetPosX();

			// 当たっているかチェック
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
				// 上方向の修正
				if (dirArray[0]) {
					// ★ここを考える
					// めり込み量を計算する
					float overlap = By + Bh - Ay;
					player.SetNextPosY(Ay + overlap);
				}

				// 下方向の修正
				if (dirArray[1]) {
					// ★ここを考える
					// めり込み量を計算する
					float overlap = Ay + Ah - By;
					player.SetNextPosY(Ay - overlap);
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
			Ay = player.GetNextPosY();
			Ax = player.GetNextPosX();

			// 当たっているかチェック
			if (collision.IsHitRect(Ax, Ay, Aw, Ah, Bx, By, Bw, Bh)) {
				if (!dirArray[3]) {
					// 左方向の修正
					if (dirArray[2]) {
						player.IsHide = true;

						// ★ここを考える
						// めり込み量を計算する
						float overlap = Bx + Bw - Ax;
						player.SetNextPosX(Ax + overlap);
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
						player.SetNextPosX(Ax - overlap);
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
			if (mapchip.m_FileReadMapData[mapIndexY][mapIndexX] == 1 
				|| mapchip.m_FileReadMapData[mapIndexY][mapIndexX] == 2 
				|| mapchip.m_FileReadMapData[mapIndexY][mapIndexX] == 3)
			{
				int Bx = mapIndexX * MAPCIP_X_SIZE;
				int By = mapIndexY * MAPCIP_Y_SIZE;
				int Bw = MAP_SIZE;
				int Bh = MAP_SIZE;

				if (collision.IsHitRect(player.GetNextPosX(), player.GetNextPosY(), PLAYER_WIDTH, PLAYER_HEIGHT, Bx, By, Bw, Bh)) {
					player.ActiveFlg = true;
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
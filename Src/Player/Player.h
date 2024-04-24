#pragma once

enum Animation {
	R,//右
	L //左
};

class Player {

protected:
	//プレイヤー変数
	int playerHan = 0;						//プレイヤー画像
	int player_x = 0, player_y = 0;			//プレイヤー座標
	const int Player_Animation = 11;		//プレイヤーのアニメーション数
	const int playerSize = 64;				//プレイヤー画像サイズ

	float BasePlayerSpeed = 0.5f;			//プレイヤー基本移動速度
	float MaxPlayerSpeed = 5.0f;			//プレイヤー最大移動速度

	int animState = 0;						//右向きか左向きか
	int animFlag = 0;						//アニメーションの種類
	int animIndex = 0;						//アニメーションの添え字
	int changeAnimFlame = 0;				//アニメーション切り替え時間
	int animFlameCount = 0;					//切り替え時間カウント
	bool playerOnSwitch = false;			//プレイヤーとスイッチが重なっているか
	bool playerGoalFlag = false;			//プレイヤーがゴールにいるか

public:
	//歩いているときのサウンド
	int Walk_Sound[13] = { 0 };

	Player();
	~Player();

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画処理
	void Draw();

	//終了処理
	void Fin();

	//プレイヤー
	//プレイヤーのｘ座標を得る
	//float GetPlayerPosX() { return m_pos.x; }

	////プレイヤーのｙ座標を得る
	//float GetPlayerPosY() { return m_pos.y; }

	////プレイヤーのＸサイズを得る
	//int GetPlayerSizeX() { return playerSize; }

	////プレイヤーのＹサイズを得る
	//int GetPlayerSizeY() { return playerSize; }

	////プレイヤーの進んでいる方向をチェック
	//void GetMoveDirection(bool* _dirArray);


	////プレイヤーのｘ座標を得る
	//float GetNextPlayerPosX() { return m_next_pos.x; }

	////プレイヤーのｙ座標を得る
	//float GetNextPlayerPosY() { return m_next_pos.y; }

	////プレイヤーのx座標をセット
	//void SetPlayerNextPosX(float new_pos_x) { m_next_pos.x = new_pos_x; }

	////プレイヤーのｙ座標をセット
	//void SetPlayerNextPosY(float new_pos_y) { m_next_pos.y = new_pos_y; }
};

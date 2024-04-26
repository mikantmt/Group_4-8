#pragma once

const int PLAYER_HEIGHT = 32;
const int PLAYER_WIDTH = 32;

enum Animation {
	R,//右
	L //左
};

class Player {

protected:
	//プレイヤー変数
	int playerHan = 0;			//プレイヤー画像
	int playerHideHan = 0;
	int player_x  = 0;			//プレイヤー座標X
	int player_y  = 0;			//プレイヤー座標Y
	int playerNext_x  = 0;			//プレイヤー次座標X
	int playerNext_y  = 0;			//プレイヤー次座標Y
	const int playeranim = 11;	//プレイヤーのアニメーション数
	const int playerSize = 32;	//プレイヤー画像サイズ

	bool isUp		 = false;	//プレイヤーが上昇中か調べるフラグ
	//float Yspeed = 0.0f;	//ジャンプ用
	float jump_power = 7.0f;	//ジャンプ量

	int animState     = 0;		//右向きか左向きか
	int animFlag      = 0;		//アニメーションの種類
	int animIndex	  = 0;		//アニメーションの添え字
	int AnimFlame     = 0;		//アニメーション切り替え時間
	int FlameCount    = 0;		//切り替え時間カウント
	bool playerSwitch = false;	//プレイヤーとスイッチが重なっているか
	bool playerGoal   = false;	//プレイヤーがゴールにいるか

public:
	//歩いているときのサウンド
	int Walk_Sound[13] = { 0 };

	float Yspeed = 0.0f;	//ジャンプ用
	bool  ActiveFlg;		//生存フラグ
	bool  IsHide;			//隠れている(初期値はfalse)

	Player();
	~Player();

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画処理
	void Draw(int X);

	//終了処理
	void Fin();

	//座標の更新
	void SetNextPosX(int _posX);
	void SetNextPosY(int _posX);
	void UpdatePos();

	// 移動後の座標を取得
	int GetNextPosX() { return playerNext_x; }
	int GetNextPosY() { return playerNext_y; }

	// 現在の座標を取得
	float GetPosX() { return player_x; }
	float GetPosY() { return player_y; }

	//プレイヤーの進んでいる方向を取得
	void GetMoveDirection(bool* _dirArray);

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

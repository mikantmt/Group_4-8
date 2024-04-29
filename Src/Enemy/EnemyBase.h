#pragma once
#include "math.h"

#include "../Collision/Collision.h"
#include "../Mapchip/MapChip.h"
#include "../Random/Random.h"
#include "../Mapchip/MapChip.h"
#include "../Player/Player.h"

const int FLY_MAX_NUM	 = 10;	//同時に存在できる敵の数
const int GROUND_MAX_NUM = 10;	//同時に存在できる敵の数

const float MOVE_RANGE  = 240.0f;//敵の移動範囲

const float MOVE_SPEED  = 2.5f;	//敵の移動スピード
const float MOVE_YSPEED = 0.3f;
const float BEAM_SPEED  = 5.0f;	//敵の弾のスピード
const int BEAM_SIZE		= 10;

class EnemyBase {
private:

	enum ENEMY_TYPE {
		FLY_ENEMY,		//空上の敵
		GROUND_ENEMY,	//陸上の敵

		ENEMY_EYPE_NUM, //敵の種類の数
	};

	const char EnemyPath[ENEMY_EYPE_NUM][256]{
		"Data/Enemy/Fly.png",
		"Data/Enemy/Ground.png",
	};

	//今回はランダム生成なので使わない
	//const float EnemyPos[ENEMY_EYPE_NUM][3][2] = {
	//	{ { 0.0f,0.0f}, { 10.0f,0.0f } ,{ 20.0f,0.0f }},	//空上の座標の設定
	//	{ { 0.0f,0.0f}, { 10.0f,0.0f } ,{ 20.0f,0.0f }},	//陸上の座標の設定
	//};

	Collision collision;
	MapChip	  mapchip;
	Random	  random;
	Player	  player;

public:

	class Enemy {
	private:
		
	public:
		int	  Handle;		//画像ハンドル
		float EnemyX;		//敵X座標
		float EnemyY;		//敵Y座標
		float EnemySaveX;	//敵X座標保存用
		float EnemySaveY;	//敵Y座標保存用

		float YSpeed;		//落下スピード

		float SpaceMinX;	//敵の移動幅
		float SpaceMaxX;	//敵の移動幅

		bool IsActive;		//生存フラグ(初期値はfalse)
		bool FlipFlg;		//反転フラグ(初期値はfalse)

		bool DetecFlg;		//プレイヤー発見フラグ(初期値はfalse)
		bool PlayerHide;	//プレイヤーが隠れているか


		int  BeamHandle;	//画像ハンドル
		VECTOR vPos;		//座標
		bool IsShot;		//打っているか
		VECTOR Rot;

		float PlayerSaveX, PlayerSaveY;

		//座標取得
		float GetPosX()		{ return EnemyX; }
		float GetPosY()		{ return EnemyY; }
		float GetSavePosX() { return EnemySaveX; }
		float GetSavePosY() { return EnemySaveY; }
		
		//座標設定
		void SetSaveX(float EnemyX);
		void SetSaveY(float EnemyY);

		//進んでいる方向をチェック
		void GetMoveDirection(bool* dirArray);

		//移動幅を設定
		void SetSpace(float X);	

		void Flip();	//敵の折り返しフラグを切り替える(マイナス方向へ)

		//敵の座標から指定範囲マス以内にいたら発見されたことになる
		void FindPlayer(float X, float Scale); 

		//Hideを取得
		void GetHide(bool hide);

		//弾を打つ処理
		void Shot();

		
	};

	Enemy Fly	[FLY_MAX_NUM];	  //空上の敵宣言
	Enemy Ground[GROUND_MAX_NUM]; //陸上の敵宣言

	//プレイヤー死んだ
	int PlayerDeath;

	void Init();
	void Step(float X, float Y, bool hide);
	void Step(float X, float Y);
	void Draw(int X);

	void MapToEnemyX(int X,int Y);
	void MapToEnemyY(int X, int Y);
	void MapCollision(int X, int Y);

	void Fin();

	// 座標を更新
	void Update();
};
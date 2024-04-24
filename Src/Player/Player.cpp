#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

//ウィンドウサイズを設定
#define WINDOW_Y	(1280)
#define WINDOW_X	(720)

//プレイヤー画像パス
#define PLAYER_PATH "Data/Player/player.h"

#define GRAVITY (0.5f)	//重力加速度

Input input;

//コンストラクタ
Player::Player() {
	
}

//デストラクタ
Player::~Player() {}

//初期化
void Player::Init() {
	playerHan = LoadGraph(PLAYER_PATH);
}

//通常処理
void Player::Step() {
	//プレイヤー左右移動処理
	if (input.IsKeyPush(KEY_INPUT_D)) {
		player_x++;
	}
	else if (input.IsKeyPush(KEY_INPUT_A)) {
		player_x--;
	}

	//スペースキーが押されたらジャンプ
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		isUp = true;
		Yspeed = -jump_power;
	}

	//重力を与える
	isUp = false;
	Yspeed += GRAVITY;
	player_y += Yspeed;
}

//描画
void Player::Draw() {
	//プレイヤーを描画
	DrawGraph(player_x, player_y, playerHan, true);
}

//終了
void Player::Fin() {

}
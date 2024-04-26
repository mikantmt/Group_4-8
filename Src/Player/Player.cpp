#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

//ウィンドウサイズを設定
#define WINDOW_Y	(1280)
#define WINDOW_X	(720)

//プレイヤー画像パス
#define PLAYER_PATH "Data/Player/player.png"

#define GRAVITY (0.3f)	//重力加速度

Input input;

//コンストラクタ
Player::Player() {
	
}

//デストラクタ
Player::~Player() {}

//初期化
void Player::Init() {
	playerHan = LoadGraph(PLAYER_PATH);

	ActiveFlg = false;
	IsHide = false;
}

//通常処理
void Player::Step() {
	playerNext_x = player_x;
	playerNext_y = player_y;

	IsHide = false;

	//プレイヤー左右移動処理
	if (input.IsKeyKeep(KEY_INPUT_D)) {
		playerNext_x += 3;
	}
	else if (input.IsKeyKeep(KEY_INPUT_A)) {
		playerNext_x -= 3;
	}

	//スペースキーが押されたらジャンプ
	if (input.IsKeyPush(KEY_INPUT_SPACE)) {
		isUp = true;
		Yspeed = -jump_power;
	}

	//重力を与える
	isUp = false;
	Yspeed += GRAVITY;
	playerNext_y += Yspeed;
}

//描画
void Player::Draw(int X) {
	//プレイヤーを描画
	DrawGraph(player_x - X, player_y, playerHan, true);
}

//終了
void Player::Fin() {

}

void Player::SetNextPosX(int _posX) {
	playerNext_x = (float)_posX;
}

void Player::SetNextPosY(int _posY) {
	playerNext_y = (float)_posY;
}

void Player::UpdatePos() {
	player_x = playerNext_x;
	player_y = playerNext_y;
}

void Player::GetMoveDirection(bool* _dirArray) {
	// 右方向のチェック
	if (playerNext_x > player_x) {
		_dirArray[3] = true;
	}

	// 左方向のチェック
	if (playerNext_x < player_x) {
		_dirArray[2] = true;
	}

	// 下方向のチェック
	if (playerNext_y > player_y) {
		_dirArray[1] = true;
	}

	// 上方向のチェック
	if (playerNext_y < player_y) {
		_dirArray[0] = true;
	}
}


